/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/
/*

****Credits****
work derived from crumbino128 by chip45.com by
sandeep @ exploreembedded.com
 

*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            50
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 43 : -1)
#define digitalPinHasPWM(p)         (((p) >= 3 && (p) <= 6) || ((p) >= 12 && (p)<= 15))

static const uint8_t SS   = 0;
static const uint8_t SCK  = 1;
static const uint8_t MOSI = 2;
static const uint8_t MISO = 3;


static const uint8_t SDA = 8;
static const uint8_t SCL = 9;
static const uint8_t LED_BUILTIN = 15;

static const uint8_t A0 = 40;
static const uint8_t A1 = 41;
static const uint8_t A2 = 42;
static const uint8_t A3 = 43;
static const uint8_t A4 = 44;
static const uint8_t A5 = 45;
static const uint8_t A6 = 46;
static const uint8_t A7 = 47;

 

// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// (I've deliberately left out pin mapping to the Hardware USARTs - seems senseless to me)
// E. Lins: changed this stuff to match the ATmega128, but it doesn't have PCINTs at all
// I eventually added the regular external interrupt stuff, but this has to be adapted in the core code
// Pins: 4, 5, 6, 7, 16, 17, 18, 19

#define digitalPinToPCICR(p)    ( (((p) >= 4) && ((p) <= 7)) ? (&EICRB) : \
                                  (((p) >= 16) && ((p) <= 19)) ? (&EICRA) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) ( (((p) >= 4) && ((p) <= 7)) || (((p) >= 16) && ((p) <= 19)) ? 0 : 0 ) )

#define digitalPinToPCMSK(p)    ( (((p) >= 4) && ((p) <= 7)) || (((p) >= 16) && ((p) <= 19)) ? (&EIMSK) : \
                                ((uint8_t *)0) ) )

#define digitalPinToPCMSKbit(p) ( (((p) >= 4) && ((p) <= 7)) ? ((p)) : \
                                ( (((p) >= 16) && ((p) <= 19))) ? ((p - 16)) : \
                                0 )

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
};


const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		

	PB	, // PB 0 **  0 ** SPI_SS
	PB	, // PB 1 **  1 ** SPI_SCK
	PB	, // PB 2 **  2 ** SPI_MOSI
	PB	, // PB 3 **  3 ** SPI_MISO
	PB	, // PB 4 **  4 ** PWM12
	PB	, // PB 5 **  5 ** PWM13
	PB	, // PB 6 **  6 ** PWM14
	PB	, // PB 7 **  7 ** PWM15	
	PD	, // PD 0 **  8 ** I2C_SCL
	PD	, // PD 1 **  9 ** I2C_SDA
	PD	, // PD 2 ** 10 ** USART1_RX
	PD	, // PD 3 ** 11 ** USART2_TX
	PD	, // PD 4 ** 12 ** D20
	PD	, // PD 5 ** 13 ** D21
	PD	, // PD 6 ** 14 ** D22
	PD	, // PD 7 ** 15 ** D23
	PC	, // PC 0 ** 16 ** D26
	PC	, // PC 1 ** 17 ** D27
	PC	, // PC 2 ** 18 ** D28
	PC	, // PC 3 ** 19 ** D29
	PC	, // PC 4 ** 20 ** D30
	PC	, // PC 5 ** 21 ** D31
	PC	, // PC 6 ** 22 ** D32
	PC	, // PC 7 ** 23 ** D33
	PA	, // PA 7 ** 24 ** D35
	PA	, // PA 6 ** 25 ** D36
	PA	, // PA 5 ** 26 ** D37
	PA	, // PA 4 ** 27 ** D38
	PA	, // PA 3 ** 28 ** D39
	PA	, // PA 2 ** 29 ** D40
	PA	, // PA 1 ** 30 ** D41
	PA	, // PA 0 ** 31 ** D42
	PE	, // PE 7 ** 32 **    
	PE	, // PE 6 ** 33 **    
	PE	, // PE 5 ** 34 ** PWM5        
	PE	, // PE 4 ** 35 ** PWM4       
	PE	, // PE 3 ** 36 ** PWM3       
	PE	, // PE 2 ** 37 **         
	PE	, // PE 1 ** 38 ** USART0_TX         
	PE	, // PE 0 ** 39 ** USART0_RX
    PF	, // PF 0 ** 40 ** A0
	PF	, // PF 1 ** 41 ** A1
	PF	, // PF 2 ** 42 ** A2
	PF	, // PF 3 ** 43 ** A3
	PF	, // PF 4 ** 44 ** A4
	PF	, // PF 5 ** 45 ** A5
	PF	, // PF 6 ** 46 ** A6
	PF	, // PF 7 ** 47 ** A7    
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		

	_BV( 0 )	, // PB 0 **  0 ** SPI_SS
	_BV( 1 )	, // PB 1 **  1 ** SPI_SCK
	_BV( 2 )	, // PB 2 **  2 ** SPI_MOSI
	_BV( 3 )	, // PB 3 **  3 ** SPI_MISO
	_BV( 4 )	, // PB 4 **  4 ** PWM12
	_BV( 5 )	, // PB 5 **  5 ** PWM13
	_BV( 6 )	, // PB 6 **  6 ** PWM14
	_BV( 7 )	, // PB 7 **  7 ** PWM15	
	_BV( 0 )	, // PD 0 **  8 ** I2C_SCL
	_BV( 1 )	, // PD 1 **  9 ** I2C_SDA
	_BV( 2 )	, // PD 2 ** 10 ** USART1_RX
	_BV( 3 )	, // PD 3 ** 11 ** USART2_TX
	_BV( 4 )	, // PD 4 ** 12 ** D20
	_BV( 5 )	, // PD 5 ** 13 ** D21
	_BV( 6 )	, // PD 6 ** 14 ** D22
	_BV( 7 )	, // PD 7 ** 15 ** D23
	_BV( 0 )	, // PC 0 ** 16 ** D26
	_BV( 1 )	, // PC 1 ** 17 ** D27
	_BV( 2 )	, // PC 2 ** 18 ** D28
	_BV( 3 )	, // PC 3 ** 19 ** D29
	_BV( 4 )	, // PC 4 ** 20 ** D30
	_BV( 5 )	, // PC 5 ** 21 ** D31
	_BV( 6 )	, // PC 6 ** 22 ** D32
	_BV( 7 )	, // PC 7 ** 23 ** D33
	_BV( 7 )	, // PA 7 ** 24 ** D35
	_BV( 6 )	, // PA 6 ** 25 ** D36
	_BV( 5 )	, // PA 5 ** 26 ** D37
	_BV( 4 )	, // PA 4 ** 27 ** D38
	_BV( 3 )	, // PA 3 ** 28 ** D39
	_BV( 2 )	, // PA 2 ** 29 ** D40
	_BV( 1 )	, // PA 1 ** 30 ** D41
	_BV( 0 )	, // PA 0 ** 31 ** D42
	_BV( 7 )	, // PE 0 ** 32 ** A0
	_BV( 6 )	, // PE 1 ** 33 ** A1
	_BV( 5 )	, // PE 2 ** 34	** USART0_RX	
	_BV( 4 )	, // PE 3 ** 35	** USART0_TX	
	_BV( 3 )	, // PE 4 ** 36	** D2           
	_BV( 2 )	, // PE 5 ** 37	** PWM3         
	_BV( 1 )	, // PE 6 ** 38	** PWM4         
	_BV( 0 )	, // PE 7 ** 39	** PWM5         
	_BV( 0 )	, // PF 2 ** 40 ** A0
	_BV( 1 )	, // PF 3 ** 41 ** A1
	_BV( 2 )	, // PF 2 ** 42 ** A2
	_BV( 3 )	, // PF 3 ** 43 ** A3
	_BV( 4 )	, // PF 4 ** 44 ** A4
	_BV( 5 )	, // PF 5 ** 45 ** A5
	_BV( 6 )	, // PF 6 ** 46 ** A6
	_BV( 7 )	, // PF 7 ** 47 ** A7      
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, // PE 0 **  0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 **  1 ** USART0_TX	
	NOT_ON_TIMER	, // PE 2 **  2 ** D2
	TIMER3A			, // PE 3 **  3 ** PWM3
	TIMER3B			, // PE 4 **  4 ** PWM4
	TIMER3C			, // PE 5 **  5 ** PWM5
	NOT_ON_TIMER	, // PE 6 **  6 ** D6
	NOT_ON_TIMER	, // PE 7 **  7 ** D7
	NOT_ON_TIMER	, // PB 0 **  8 ** SPI_SS
	NOT_ON_TIMER	, // PB 1 **  9 ** SPI_SCK
	NOT_ON_TIMER	, // PB 2 ** 10 ** SPI_MOSI
	NOT_ON_TIMER	, // PB 3 ** 11 ** SPI_MISO
	TIMER0A			, // PB 4 ** 12 ** PWM12
	TIMER1A			, // PB 5 ** 13 ** PWM13
	TIMER1B			, // PB 6 ** 14 ** PWM14
	TIMER2			, // PB 7 ** 15 ** PWM15	
	NOT_ON_TIMER	, // PD 0 ** 16 ** I2C_SCL
	NOT_ON_TIMER	, // PD 1 ** 17 ** I2C_SDA
	NOT_ON_TIMER	, // PD 2 ** 18 ** USART1_RX
	NOT_ON_TIMER	, // PD 3 ** 19 ** USART2_TX
	NOT_ON_TIMER	, // PD 4 ** 20 ** D20
	NOT_ON_TIMER	, // PD 5 ** 21 ** D21
	NOT_ON_TIMER	, // PD 6 ** 22 ** D22
	NOT_ON_TIMER	, // PD 7 ** 23 ** D23
	NOT_ON_TIMER	, // PG 0 ** 24 ** D24
	NOT_ON_TIMER	, // PG 1 ** 25 ** D25
	NOT_ON_TIMER	, // PC 0 ** 26 ** D26
	NOT_ON_TIMER	, // PC 1 ** 27 ** D27
	NOT_ON_TIMER	, // PC 2 ** 28 ** D28
	NOT_ON_TIMER	, // PC 3 ** 29 ** D29
	NOT_ON_TIMER	, // PC 4 ** 30 ** D30
	NOT_ON_TIMER	, // PC 5 ** 31 ** D31
	NOT_ON_TIMER	, // PC 6 ** 32 ** D32
	NOT_ON_TIMER	, // PC 7 ** 33 ** D33
	NOT_ON_TIMER	, // PG 2 ** 34 ** D34
	NOT_ON_TIMER	, // PA 7 ** 35 ** D35
	NOT_ON_TIMER	, // PA 6 ** 36 ** D36
	NOT_ON_TIMER	, // PA 5 ** 37 ** D37
	NOT_ON_TIMER	, // PA 4 ** 38 ** D38
	NOT_ON_TIMER	, // PA 3 ** 39 ** D39
	NOT_ON_TIMER	, // PA 2 ** 40 ** D40
	NOT_ON_TIMER	, // PA 1 ** 41 ** D41
	NOT_ON_TIMER	, // PA 0 ** 42 ** D42
	NOT_ON_TIMER	, // PF 0 ** 43 ** A0
	NOT_ON_TIMER	, // PF 1 ** 44 ** A1
	NOT_ON_TIMER	, // PF 2 ** 45 ** A2
	NOT_ON_TIMER	, // PF 3 ** 46 ** A3
	NOT_ON_TIMER	, // PF 4 ** 47 ** A4
	NOT_ON_TIMER	, // PF 5 ** 48 ** A5
	NOT_ON_TIMER	, // PF 6 ** 49 ** A6
	NOT_ON_TIMER	, // PF 7 ** 50 ** A7	
};

#endif

#endif