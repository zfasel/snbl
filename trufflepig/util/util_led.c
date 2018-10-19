/*****************************************************************************
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
 *  @zfasel
 *
 *****************************************************************************/
#include "../system.h"

static uint8_t leds[LED_COUNT * 3 * sizeof(uint8_t)];
static uint8_t ledsLayer2[LED_COUNT * 3 * sizeof(uint8_t)];

/*
static const uint8_t gamma_values[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
		2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5,
		5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
		10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
		17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
		25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
		37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
		51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
		69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
		90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
		115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
		144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
		177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
		215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};
*/
/**
 * Converts a 16-bit 565 color to RGB color suitable for LEDs
 */
uint32_t util_led_565_to_rgb(uint16_t color) {
	//Incoming color is assumed to be RGB565
	//LED color is 0x00RRGGBB
	return ((0xF800 & color) << 8) | ((0x07E0 & color) << 5) | (0x1F & color) << 3;
}

inline void util_led_clear() {
	util_led_set_all(0, 0, 0);
	util_led_set_all_l2(0, 0, 0);
	util_led_show();
}

led_rgb_t util_led_get(uint8_t index) {
	led_rgb_t rgb;
	rgb.blue = leds[index * 3];
	rgb.green = leds[(index * 3) + 1];
	rgb.red = leds[(index * 3) + 2];
	return rgb;
}

uint32_t util_led_hsv_to_rgb(float H, float S, float V) {
	float h = H * 6;
	uint8_t i = floor(h);
	float a = V * (1 - S);
	float b = V * (1 - S * (h - i));
	float c = V * (1 - (S * (1 - (h - i))));
	float rf, gf, bf;

	switch (i) {
	case 0:
		rf = V * 255;
		gf = c * 255;
		bf = a * 255;
		break;
	case 1:
		rf = b * 255;
		gf = V * 255;
		bf = a * 255;
		break;
	case 2:
		rf = a * 255;
		gf = V * 255;
		bf = c * 255;
		break;
	case 3:
		rf = a * 255;
		gf = b * 255;
		bf = V * 255;
		break;
	case 4:
		rf = c * 255;
		gf = a * 255;
		bf = V * 255;
		break;
	case 5:
		default:
		rf = V * 255;
		gf = a * 255;
		bf = b * 255;
		break;
	}

	uint8_t R = rf;
	uint8_t G = gf;
	uint8_t B = bf;

	uint32_t RGB = (R << 16) + (G << 8) + B;
	return RGB;
}


void util_led_init() {
	memset(leds, 0x00, sizeof(uint8_t) * LED_COUNT * 3);

	apa102_init();
	util_led_show();

}

void util_led_addititve(uint8_t r, uint8_t g, uint8_t b) {
	uint32_t offset = 0;
	for (uint32_t i = 0; i < LED_COUNT; i++) {
	  leds[offset] += b;
		leds[offset+1] += g;
		leds[offset+2] += r;
		offset += 3;
	}
}

void util_led_set(uint32_t index, uint8_t r, uint8_t g, uint8_t b) {
	uint32_t offset = index * 3;
  leds[offset] = b;
	leds[offset+1] = g;
	leds[offset+2] = r;

	/*
	leds[offset] = gamma_values[b];
	leds[offset + 1] = gamma_values[g];
	leds[offset + 2] = gamma_values[r];*/
}

void util_led_set_l2(uint32_t index, uint8_t r, uint8_t g, uint8_t b) {
	uint32_t offset = index * 3;
  ledsLayer2[offset] = b;
	ledsLayer2[offset+1] = g;
	ledsLayer2[offset+2] = r;

	/*
	leds[offset] = gamma_values[b];
	leds[offset + 1] = gamma_values[g];
	leds[offset + 2] = gamma_values[r];*/
}
void util_led_set_mirror(uint32_t index, uint8_t r, uint8_t g, uint8_t b) {
	if (index <= (LED_COUNT/2)) {
		uint32_t offset = index * 3;
		uint32_t offset2 = ((LED_COUNT-1)*3)-offset;
	  leds[offset] = b;
		leds[offset+1] = g;
		leds[offset+2] = r;
		leds[offset2] = b;
		leds[offset2+1] = g;
		leds[offset2+2] = r;
	}/*
	leds[offset] = gamma_values[b];
	leds[offset + 1] = gamma_values[g];
	leds[offset + 2] = gamma_values[r];*/
}

void util_led_set_all(uint8_t red, uint8_t green, uint8_t blue) {
	for (uint32_t i = 0; i < LED_COUNT; i++) {
		util_led_set(i, red, green, blue);
	}
}

void util_led_set_all_l2(uint8_t red, uint8_t green, uint8_t blue) {
	for (uint32_t i = 0; i < LED_COUNT; i++) {
		util_led_set_l2(i, red, green, blue);
	}
}

void util_led_clear_l2() {
	for (uint32_t i = 0; i < LED_COUNT; i++) {
		util_led_set_l2(i, 0, 0, 0);
	}
}

void util_led_set_blocks(uint8_t red, uint8_t green, uint8_t blue, uint16_t start, uint16_t every) {
	uint16_t subcount = 0;
  for (uint32_t i = start; i < LED_COUNT; i++) {
		util_led_set(i, red, green, blue);
		subcount++;
		if (subcount >= every) {
			subcount = 0;
			i+=every;
		}
	}
}

void util_led_set_all_rgb(uint32_t rgb) {
	for (uint32_t i = 0; i < LED_COUNT; i++) {
		util_led_set_rgb(i, rgb);
	}
}

void util_led_set_rgb(uint32_t index, uint32_t rgb) {
	util_led_set(index, (rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF);
}

void util_led_show() {
		uint8_t tempLEDs[LED_COUNT * 3 * sizeof(uint8_t)];
	  for (uint16_t i = 0; i < LED_COUNT; i++) {
			for (uint8_t x=0; x<3; x++) {
				tempLEDs[(i*3)+x] = leds[(i*3)+x] > ledsLayer2[(i*3)+x] ? leds[(i*3)+x] : ledsLayer2[(i*3)+x];
			}
		}
		apa102_send(tempLEDs);
}

uint32_t util_led_to_rgb(uint8_t red, uint8_t green, uint8_t blue) {
	return ((uint32_t)(0xFF & red) << 16) | ((uint32_t)(0xFF & green) << 8) | (uint32_t)(0xFF & blue);
}
