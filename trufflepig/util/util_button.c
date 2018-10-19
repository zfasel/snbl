#include "../system.h"

static volatile uint8_t button_state = 0;
static volatile uint8_t button_time = 0;

APP_TIMER_DEF(m_button_timer);
APP_TIMER_DEF(m_button_multiwait);

uint8_t rotationcount, waiting = 0;
uint32_t button_mils = 0;

bool looped;

void buttonCallback(void *p_data) {
	rotationcount++;

	if (rotationcount>4) {
		looped = true;
		apa102_rotate_brightness();
		rotationcount = 0;
	}
}

void buttonRelease(void *p_data) {
	if (waiting == 1) {
		if (!looped) {
			buttonNextSubAnim();
		}
	} else if (waiting ==2) {
		if (!looped) {
			buttonNextAnim();
		}
	} else if (waiting == 5) {
		stopAutoShow();
		Security();
	} else if (waiting == 4) {
		stopAutoShow();
		rainbowPartyStart();
	}
	else if (waiting == 10) {
		apa102_set_brightness(255);
	}
	waiting = 0;
}

void __gpiote_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

	uint8_t state = nrf_gpio_pin_read(pin);
	void *p_timer_data = 0;

	if (state == 0) {
		//button pressed

		app_timer_stop(m_button_multiwait);

		//bsp_board_led_invert(0);
		looped = false;
		rotationcount = 0;

		app_timer_create(&m_button_timer, APP_TIMER_MODE_REPEATED, buttonCallback);
		app_timer_start(m_button_timer, APP_TIMER_TICKS(150), p_timer_data);


	} else {
		//button released
		app_timer_stop(m_button_timer);
		app_timer_create(&m_button_multiwait, APP_TIMER_MODE_SINGLE_SHOT, buttonRelease);
		app_timer_start(m_button_multiwait, APP_TIMER_TICKS(400), p_timer_data);

		waiting++;
    //Todo: things
	}
}

void util_button_init_dead() {
	nrf_gpio_cfg_input(BUTTON_PIN, NRF_GPIO_PIN_PULLDOWN);

	void *p_timer_data = 0;

	app_timer_create(&m_button_timer, APP_TIMER_MODE_REPEATED, buttonCallback);
	app_timer_start(m_button_timer, APP_TIMER_TICKS(100), p_timer_data);

}

void util_button_init() {
	uint32_t err_code;

	nrf_gpio_cfg_input(BUTTON_PIN, NRF_GPIO_PIN_PULLDOWN);

	err_code = nrf_drv_gpiote_init();
	APP_ERROR_CHECK(err_code);

	nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
	in_config.pull = NRF_GPIO_PIN_PULLUP;

	err_code = nrf_drv_gpiote_in_init(BUTTON_PIN, &in_config, __gpiote_handler);
	APP_ERROR_CHECK(err_code);

	nrf_drv_gpiote_in_event_enable(BUTTON_PIN, true);
}
