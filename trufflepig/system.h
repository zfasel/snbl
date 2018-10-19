#ifndef SYSTEM_H_
#define SYSTEM_H_

#define LED_COUNT			  		50
#define LED_PIN_DATA	     	19
#define LED_PIN_SCK		     	12

#define LED_BRIGHTNESS_1    20
#define LED_BRIGHTNESS_2    50
#define LED_BRIGHTNESS_3    80
#define LED_BRIGHTNESS_4    110
#define LED_BRIGHTNESS_5    140
#define LED_BRIGHTNESS_DEFAULT  LED_BRIGHTNESS_3

#define BUTTON_PIN        6

#define SHOW_DURATION    10

#define SECRET_SIG  0xF4531312

#define LED_COUNT_SPLIT (uint8_t)LED_COUNT/2

//Standard
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include <nrf_drv_spi.h>
#include <nrfx_config.h>

#include <util_led.h>
#include <util_button.h>
#include <util_math.h>
#include <util_timers.h>
#include <util_ble.h>
#include <v1.h>
#include <drv_apa102.h>
#include <nrfx_spim.h>

#include "nrf_uart.h"
#include "nrf_delay.h"
// #include "nrf_drv_timer.h"
#include "bsp.h"

#include "app_timer.h"
#include "nrf_drv_clock.h"


#include "nrf_gpiote.h"
#include "nrf_gpio.h"
#include "nrf_drv_gpiote.h"

#include "nrf_sdh.h"
#include "nrf_sdh_ble.h"

#include <nrf_drv_rng.h>
#include <ble_advdata.h>
#include <ble_advertising.h>
#include <ble_conn_params.h>
#include <ble_conn_state.h>
#include <ble_db_discovery.h>
#include <ble_nus.h>
#include <ble_types.h>



#endif /* SYSTEM_H_ */
