==================
Quick Start Guide
==================

 - Apply 3.3v to 5v to the exposed leads. Red is Positive, Black is Negative. 3x AAs in series is suffice.
 - Do not tell anyone where you got the lanyard from until after the con. Anyone who asks for one will be turned away.
 - The Per-badge cost is ~$40 in parts and is funded from Scotch and Bubbles' pockets. If you want to contribute your share, please make a donation to a charity in the same or greater ammount.


==================
Congratulations :)
==================

IMPORTANT - PLEASE READ THE ENTIRETY OF THIS.

You have been selected to be the recipient of the DEF CON 26 Scotch and Bubbles Party Lanyard. Some may call it #BadgeLife, but we're our own damn thing ;). Mostly because we couldn't get the rights to use the term BadgeLife, so we're #xxxxxxxxx. You're free to use #ScotchAndBubbles if you post photos on the lines.

The unofficial badge #badgelife chaos has reached a new high this year, with everyone and their mother making some form of circuit blinky board and, in many to most cases, selling them to the masses. Additionally, the creation of "shitty addons" is...well...as cool as LED throwies.

Unofficial badges / tokens used to be a sign of what you've done, who you knew, or even chance encounter, and were not pay-to-play. To bring this back, we've restricted this run to only those we encounter in person and are not selling these in any way. If anyone asks you where you got it, make up a story never mentioning it's true source until after the con.

Some recommendations for the "where":
 - Woke up in a bathtub full of ice with a nasty scar but the lanyard around your neck with a note saying #BioHackingVillageWasHere.
 - Won it in a Rick and Morty style "SHOW ME WHAT YOU GOT" competition in the rock paper scissors village.
 - They were giving them out at the Black and White Ball party, or whatever they're calling it now.
 - Hak5 were selling them for $250. Go ask them.
 - A drone hovering over the pool had one so you dived in with your swimsuit on.
 - Found it in the passenger seat of the squad car you got a ride in last night.
 - Some random person asked you in the bathroom "do you party" and "are you up for anything" and gave it to you as the two of you walked out
 - Found it under your pillow from the LED fairies (or is it furries?).
 - Dan Kaminsky.

After DEF CON is over, you're free to tell others who was behind the badge.

By receiving this badge, you hearby accept the following Terms of Service.
 - You will NEVER sell this lanyard in its entirety or as broken down components. You're free to give it away to someone else who wants to learn.
 - You will always give credit where credit is due with regards to the source of said lanyard, proclaiming a love for Scotch and Bubbles.
 - You will do cool stuff with it, programing it to make it your own.
 - You're responsible if you break it, whether be from nerfing a flash, jumping into the pool with it, or causing smoke to leave.
 - You absolve us of any and all responsibility from your use or in-use of the badge.
 - You will make a best effort attempt to go see Scotch and Bubbles play at the DEFCON evening party, or otherwise make up a worthy excuse on why you couldn't make it.
 - Our privacy policy has been updated, and with it, citizens of the EU are required to expose their privacy policy (herein known as PP) to everyone they encounter. Just no more flooding my inbox with your PP.

===================
The Hardware
===================

Given the limited timeline we put on ourselves in developing this, the badge is 100% Off The Shelf Hardware turned into something neat (or as some call it, hacking shit together). We would have done our own custom PCB, but it was becoming too burdensome.

As such, your lanyard contains the following electronics:
 - 50 Pixels of SparkFun's APA 102 leds @ 60 LEDs/meter
 - SparkFun's NRF 52832 Breakout Board
 - 3x AA Battery Holder
 - 6x AA Batteries (more or less)
 - 2 Protruding Wires, Red (+) and Black (-) (PLEASE READ INFO ON POWER)

And the following non-electronic Hardware
- ~3 feet of 1" wide Tubular Polyester Webbing
- 1 Lanyard Badge Clasp
- 1 Sex Bolt (giggity) - aka The Chicago Screw (giggity goo)

===================
I'VE GOT THE POWER
===================

So... a note about power consumption. Many badges may last days during a con. This lanyard may too...if you give it enough power and reduce the brightness. But you'll probably ignore the brightness statement, turn it to 100, and run through power.

FIRST AND FOREMOST - IMPORTANT!!! - The +/- leads leaving the badge are connected to Vin for the board and directly to the LEDs. NEVER EVER EVER EXCEED 6V. Seriously. The SparkFun NRF breakout only has a voltage regulator for 6v, and there's no voltage reg on the LEDs.

Second, power draw - at the default brightness when you boot, the entirety of the lanyard is brightness-regulated to draw no more than 300ma. This will last you about 8 hours powered independently off 3x AA batteries as the consumption fluctuates.

Now, if you crank it to max brightness and remove any limitations, it has the possibility of drawing just over 3000ma on full brightness all white. Clearly, you won't be able to keep up with that, even with a fancy USB power supply. As such, we've software limited the brightness to pull no more than 975ma at max draw. You're free to remove this limitation if you get yourself one of those high-output fancy USB power packs to power the badge (which ZF uses for his MEGALANYARD) but many of the cheaper USB power packs will only provide 1 amp.

===================
How to use your lanyard
===================

Located at the base of the lanyard is the circuit board on the back side of the LEDs. You'll feel 2 switches next to each other. Ascii art diagram below, indicating the Reset switch (R) and the Option switch (X), which is the button furthest away from your heart, or otherwise the closest to your right hand.

/~~~~~~~~~~~~~/  /
|             | <
|             |  \
|             |
|             |  
|    R   X    |  /
|             | <
|             |  \
\-------------\

By default, your lanyard will launch into a default wave of color. To change your badge's functionality:

 - Brief Press of Option Button - This will cycle the badge through to the next sequence
 - Quick double-tap of option button - This will change the speed of the effect
 - Hold for 2 seconds - this will change the brightness, cycling through 5 different levels. The default is middle.

===================
Why Is My Lanyard Randomly Changing Modes and the button doesn't work?
===================

****** WELCOME TO PARTY MODE *******
Last Login: ScotchAndBubbles
Up Time: 2204 Days, 16 hours, 5 minutes <3
root:#>

If your badge is within an unknown (because who knows how this will perform in the congested 2.4ghz environment that is DC) distance to Scotch or Bubbles, and either one of them are in party mode, your badge will become a slave to the music and dance along in (relative) sync. Find them. Party with them. You'll be glad you did.

===================
Programing / Source
===================

The source will be posted to github.

To program the board, check out http://sfe.io/t549. You will need either a USB->FTDI breakout (which will work with Arduino)
