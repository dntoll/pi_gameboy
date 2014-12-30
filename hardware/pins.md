PINS AND WIREING
================


ili9341
=======
 * DC   = 4;// # gpio pin 16 = wiringpi no. 4 (BCM 23)
 * RST  = 5;// # gpio pin 18 = wiringpi no. 5 (BCM 24)
 * LED  = 1;// # gpio pin 12 = wiringpi no. 1 (BCM 18)
 * SPI Channel 0
  * SCE  = 10;// # gpio pin 24 = wiringpi no. 10 (CE0 BCM 8) 
  * SCLK = 14;// # gpio pin 23 = wiringpi no. 14 (SCLK BCM 11)
  * DIN  = 12;// # gpio pin 19 = wiringpi no. 12 (MOSI BCM 10)

mpc3008
=======
 * SPI Channel 1.
  * SCE = 11
   * SCLK = 14;// # gpio pin 23 = wiringpi no. 14 (SCLK BCM 11)
   * DIN  = 12;// # gpio pin 19 = wiringpi no. 12 (MOSI BCM 10)
 * MCP3008 index
  * x = 1
  * y = 0
  * Button = 2
