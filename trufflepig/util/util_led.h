/*****************************************************************************
 * (C) Copyright 2017 AND!XOR LLC (http://andnxor.com/).
 *
 * PROPRIETARY AND CONFIDENTIAL UNTIL AUGUST 1ST, 2017 then,
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 * 	@andnxor
 * 	@zappbrandnxor
 * 	@hyr0n1
 * 	@andrewnriley
 * 	@lacosteaef
 * 	@bitstr3m
 *****************************************************************************/
#ifndef UTIL_LED_H_
#define UTIL_LED_H_


#define LED_COLOR_BLACK				0x000000
#define LED_COLOR_RED				0xFF0000
#define LED_COLOR_GREEN				0x00FF00
#define LED_COLOR_BLUE				0x0000FF
#define LED_COLOR_CORAL				0xFF9963
#define LED_COLOR_GOLD				0xCCAD00
#define LED_COLOR_INDIGO			0xc100e6
#define LED_COLOR_LIGHTBLUE			0x3399FF
#define LED_COLOR_LIGHTGREEN		0x58D68D
#define LED_COLOR_ORANGE			0xFFA500
#define LED_COLOR_PURPLE			0xb000b0
#define LED_COLOR_YELLOW			0xDCDC00
#define LED_COLOR_WHITE				0xDDDDDD

typedef struct {
	uint8_t frames;
	uint8_t frame;
	uint8_t *rgb_data;
	uint16_t size;
} led_anim_t;

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} led_rgb_t;

#define UTIL_LED_ANIM_INIT(anim)					\
	uint8_t rgb_data[6000];					\
    led_anim_t anim = { 0,0, rgb_data, 0 };

extern uint8_t led_order_cw[];
extern uint8_t led_matrix[];

extern uint32_t util_led_565_to_rgb(uint16_t color);
extern void util_led_brightness_set(uint8_t brightness);
extern void util_led_clear();
extern led_rgb_t util_led_get(uint8_t index);
extern uint32_t util_led_to_rgb(uint8_t red, uint8_t green, uint8_t blue);
extern uint32_t util_led_hsv_to_rgb(float H, float S, float V);
extern bool util_led_has_apa102();
extern void util_led_init();
extern void util_led_load_rgb_file(char *filename, led_anim_t *p_anim);
//extern void util_led_play_rgb_frame(led_anim_t *p_anim);
extern void util_led_set(uint32_t index, uint8_t red, uint8_t g, uint8_t b);
extern void util_led_set_all(uint8_t red, uint8_t green, uint8_t blue);
extern void util_led_set_all_rgb(uint32_t rgb);
extern void util_led_set_rgb(uint32_t index, uint32_t rgb);
extern void util_led_show();
extern void util_led_set_blocks(uint8_t red, uint8_t green, uint8_t blue, uint16_t start, uint16_t every);
extern void util_led_set_mirror(uint32_t index, uint8_t r, uint8_t g, uint8_t b);
extern void util_led_addititve(uint8_t red, uint8_t green, uint8_t blue);

extern void util_led_set_l2(uint32_t index, uint8_t r, uint8_t g, uint8_t b);
extern void util_led_set_all_l2(uint8_t r, uint8_t g, uint8_t b);
extern void util_led_clear_l2();

#endif /* UTIL_LED_H_ */
