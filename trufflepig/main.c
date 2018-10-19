#include "system.h"
#include <stdbool.h>
#include "boards.h"



//#define ENABLE_LOOPBACK_TEST  /**< if defined, then this example will be a loopback test, which means that TX should be connected to RX to get data loopback. */

#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

#define BTN_MAIN    0

//APP_TIMER_DEF(m_timer_0);


/**
 * @brief Function for application main entry.
 */

void timer_handle(void * p_context) {
 UNUSED_PARAMETER(p_context);
 bsp_board_led_invert(0);
}
/*
void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
  //uint8_t state = nrf_gpio_pin_read(pin);

  for (uint32_t i = 0; i < LED_COUNT; i++) {
    //util_led_set(i, 0, 255, 0);
  }
  util_led_show();
}

static void gpio_init(void)
{
    ret_code_t err_code;

    err_code = nrf_drv_gpiote_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    in_config.pull = NRF_GPIO_PIN_PULLUP;

    err_code = nrf_drv_gpiote_in_init(BSP_BUTTON_0, &in_config, in_pin_handler);
    APP_ERROR_CHECK(err_code);

    nrf_drv_gpiote_in_event_enable(BSP_BUTTON_0, true);
}
*/

int main(void)
{

    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    util_timers_init();
    util_led_init();
    util_button_init();



    for (uint32_t i = 0; i < LED_COUNT; i++) {
      util_led_set(i, 0, 0, 255);
    }
    util_led_show();
    nrf_delay_ms(1000);

    /* Toggle LEDs. */

    startShow();
    util_ble_init();


    while (true)
    {
        //nrf_delay_ms(1000);
        // everything is in timers
    }
}
