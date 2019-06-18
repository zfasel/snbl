=============
The Scotch and Bubbles Lanyard
#lanyardlife #bodgelyfe #DoYouSellAAs
=============

Functionality
=============

Manufacturer Specific Data in GAP
 - Up to 26bytes

Button Commands:
 - Tap - change animation nuance (color, rotation, speed)
 - Double Tap - change annimation
 - 5x Tap - stop listening to broadcasts
 - Hold 2 seconds - brightness loop (increase then jump to 0)

CnC Structure:
  0x1312 - ManuID
  0x00 - Priority 2
  0x0000 - CnCSeq 3/4
  0x00 - Command
  0x0000 checksum
  ....8 bytes

Command:
 * 0xDD - Release (you're on your own)
 * 0x01 - Lanuch Anim Default
 * 0x02 - Launch Anim Custom
 * 0x03 - Modify Current Anim
 * 0xf4 - Solid Color
 * 0xFF - Sleep BLE

0x01 - Lanuch Anim Default
 * 0x00 - Animation Number

Animation:
 * 0x00 - Animation number
 * 0x00 - animCountDelay
 * 0x0000 - animCount1
 * 0x0000 - animCount2
 * 0x00 - animRed
 * 0x00 - animGreen
 * 0x00 - animBlue
 * 0x00 - animBool1
 * 0x00 - animBool2

Brightness Only (0xFD)
 - 0x00 - Zero

Solid Color:
 * 0x00 red
 * 0x00 green
 * 0x00 blue

 * 0x00 - Off
 * 0x01 - Solid Color
 * Fade between Colors
 * Circular Loop
 * Chase (ColorSnake)
 * The Challenge (static)
 * SEKURITY MAKE A HOLE
 * Sparkle / Glitter
 * Fire
 * Alternating marque chase
 * rainbow pride
 * from zero to hero

Challenge:
  - 3 pixels = 11 11 11 = Base 32 = 1 letter
  - 50 Pixels = 48/3 = 16 chars = RINGX3123133333
  - R - 10001 - R Z R
  - I - 1000 - Z G Z
  - N - 1101 - Z B R
  - G - 110 - Z R G
  - X - 10111 - R R B
  - 3 - 11011 - R G B
  - I - 1000 - Z G Z
  - 2 - 11010 - R G G
  - 7 -
  - Zero - 00
  - Red - 01
  - Green - 10
  - Blue - 11

OR
  - RGB - 3 bits single pixel - 180 bits max - ascii
  - ":) urba.ne/dc26Lanyard"
  - 00111010001010010010000001110101011100100110001001100001001011100110111001100101001011110110010001100011001100100011011001001100011000010110111001111001011000010111001001100100
  - Red / Green / Blue
  - FF0 = Yellow
  - 0FF = cyaN
  - F0F = Purple
  - 000 = X
  - BYRGRRRXNPGWBBRGNXGGWBPYNBGGWPRRNXYNBXYYGNXYXPPYNYGYXPYGNBX

====== Annimation ideas ====

https://www.youtube.com/watch?v=578hrnxruuI
https://www.youtube.com/watch?v=H8Cmht5duso
https://www.youtube.com/watch?v=lU1GVVU9gLU

===== Tweet MD5 ====
whiterose:~ zfasel$ echo -n "Scotch and Bubbles (aka zfasel and secbarbie) are the creators behind the LED Lanyard. Posting this on July 20, 2018." | md5
aa8b29405a95331421e221f649ce4a21

=== COMPANY ID ====
0X1312
