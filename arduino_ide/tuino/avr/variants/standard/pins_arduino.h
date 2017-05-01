// This file has been inspired by the Migth1284P project
// https://github.com/maniacbug/mighty-1284p

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define TUINO_VARIANT "STANDARD"

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           4
#define analogInputToDigitalPin(p)  ( (p) < NUM_ANALOG_INPUTS ? (p) + 24 : -1 )
#define digitalPinToAnalogPin(p)    ( (p) >= 24 && (p) <= 27 ? (p) - 24 : -1 )
#define digitalPinHasPWM(p)         ( (p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 31 || (p) == 10 || (p) == 12 || (p) == 13 )

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SCL= 28;
static const uint8_t SDA= 29;


static const uint8_t LED_BUILTIN = 7;

static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;
static const uint8_t D8 = 8;
static const uint8_t D9 = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;

static const uint8_t D14 = 28;
static const uint8_t D15 = 29;


static const uint8_t GMX_GPIO1 = 14;
static const uint8_t GMX_GPIO2 = 15;
static const uint8_t GMX_GPIO3 = 16;
static const uint8_t GMX_GPIO4 = 17;
static const uint8_t GMX_GPIO5 = 18;
static const uint8_t GMX_GPIO6 = 19;
static const uint8_t GMX_GPIO7 = 20;
static const uint8_t GMX_RESET = 21;
static const uint8_t GMX_INT   = 31;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;

static const uint8_t TUINO_INTERRUPT = 30;
static const uint8_t TUINO_RTC_INTERRUPT = 30;
static const uint8_t TUINO_NFC_INTERRUPT = 30;


#define digitalPinToPCICR(p)    ( (p) >= 0 && (p) < NUM_DIGITAL_PINS ? &PCICR : (uint8_t *)0 )


#define digitalPinToPCICRbit(p) \
(\
  (p) == 0 ? 3 : \
  (p) == 1 ? 3 : \
  (p) == 2 ? 3 : \
  (p) == 3 ? 3 : \
  (p) == 4 ? 3 : \
  (p) == 5 ? 3 : \
  (p) == 6 ? 3 : \
  (p) == 7 ? 3 : \
  (p) == 8 ? 1 : \
  (p) == 9 ? 1 : \
  (p) == 10 ? 1 : \
  (p) == 11 ? 1 : \
  (p) == 12 ? 1 : \
  (p) == 13 ? 1 : \
  (p) == 14 ? 0 : \
  (p) == 15 ? 0 : \
  (p) == 16 ? 0 : \
  (p) == 17 ? 0 : \
  (p) == 18 ? 2 : \
  (p) == 19 ? 2 : \
  (p) == 20 ? 2 : \
  (p) == 21 ? 2 : \
  (p) == 22 ? 2 : \
  (p) == 23 ? 2 : \
  (p) == 24 ? 0 : \
  (p) == 25 ? 0 : \
  (p) == 26 ? 0 : \
  (p) == 27 ? 0 : \
  (p) == 28 ? 2 : \
  (p) == 29 ? 2 : \
  (p) == 30 ? 1 : \
  (p) == 31 ? 1 : \
  0)



#define digitalPinToPCMSK(p) \
(\
  (p) == 0 ? &PCMSK3 : \
  (p) == 1 ? &PCMSK3 : \
  (p) == 2 ? &PCMSK3 : \
  (p) == 3 ? &PCMSK3 : \
  (p) == 4 ? &PCMSK3 : \
  (p) == 5 ? &PCMSK3 : \
  (p) == 6 ? &PCMSK3 : \
  (p) == 7 ? &PCMSK3 : \
  (p) == 8 ? &PCMSK1 : \
  (p) == 9 ? &PCMSK1 : \
  (p) == 10 ? &PCMSK1 : \
  (p) == 11 ? &PCMSK1 : \
  (p) == 12 ? &PCMSK1 : \
  (p) == 13 ? &PCMSK1 : \
  (p) == 14 ? &PCMSK0 : \
  (p) == 15 ? &PCMSK0 : \
  (p) == 16 ? &PCMSK0 : \
  (p) == 17 ? &PCMSK0 : \
  (p) == 18 ? &PCMSK2 : \
  (p) == 19 ? &PCMSK2 : \
  (p) == 20 ? &PCMSK2 : \
  (p) == 21 ? &PCMSK2 : \
  (p) == 22 ? &PCMSK2 : \
  (p) == 23 ? &PCMSK2 : \
  (p) == 24 ? &PCMSK0 : \
  (p) == 25 ? &PCMSK0 : \
  (p) == 26 ? &PCMSK0 : \
  (p) == 27 ? &PCMSK0 : \
  (p) == 28 ? &PCMSK2 : \
  (p) == 29 ? &PCMSK2 : \
  (p) == 30 ? &PCMSK1 : \
  (p) == 31 ? &PCMSK1 : \
  &PCMSK0)


#define digitalPinToPCMSKbit(p) \
(\
  (p) == 0 ? 0 : \
  (p) == 1 ? 1 : \
  (p) == 2 ? 2 : \
  (p) == 3 ? 3 : \
  (p) == 4 ? 4 : \
  (p) == 5 ? 5 : \
  (p) == 6 ? 6 : \
  (p) == 7 ? 7 : \
  (p) == 8 ? 0 : \
  (p) == 9 ? 1 : \
  (p) == 10 ? 4 : \
  (p) == 11 ? 5 : \
  (p) == 12 ? 6 : \
  (p) == 13 ? 7 : \
  (p) == 14 ? 4 : \
  (p) == 15 ? 5 : \
  (p) == 16 ? 6 : \
  (p) == 17 ? 7 : \
  (p) == 18 ? 3 : \
  (p) == 19 ? 4 : \
  (p) == 20 ? 5 : \
  (p) == 21 ? 2 : \
  (p) == 22 ? 6 : \
  (p) == 23 ? 7 : \
  (p) == 24 ? 0 : \
  (p) == 25 ? 1 : \
  (p) == 26 ? 2 : \
  (p) == 27 ? 3 : \
  (p) == 28 ? 0 : \
  (p) == 29 ? 1 : \
  (p) == 30 ? 2 : \
  (p) == 31 ? 3 : \
  0)



// return associated INTx number for associated/valid pins,
// otherwise NOT_AN_INTERRUPT
#define digitalPinToInterrupt(p) \
  (\
  (p) == 2 ? 0 : \
  (p) == 3 ? 1 : \
  (p) == 30 ? 2 : \
  NOT_AN_INTERRUPT)


#define PA 1
#define PB 2
#define PC 3
#define PD 4

// specify port for each pin D0-D31
#define PORT_D0 PD        // D0
#define PORT_D1 PD        // D1
#define PORT_D2 PD        // D2
#define PORT_D3 PD        // D3
#define PORT_D4 PD        // D4
#define PORT_D5 PD        // D5
#define PORT_D6 PD        // D6
#define PORT_D7 PD        // D7
#define PORT_D8 PB        // D8
#define PORT_D9 PB        // D9
#define PORT_D10 PB       // D10-SS
#define PORT_D11 PB       // D11-MOSO
#define PORT_D12 PB       // D12-MISO
#define PORT_D13 PB       // D13-SCK

#define PORT_D14 PA       // GMX GPIO1
#define PORT_D15 PA       // GMX GPIO2
#define PORT_D16 PA       // GMX GPIO3
#define PORT_D17 PA       // GMX GPIO4
#define PORT_D18 PC       // GMX GPIO5
#define PORT_D19 PC       // GMX GPIO6  
#define PORT_D20 PC       // GMX GPIO7
#define PORT_D21 PC       // GMX RESET
#define PORT_D22 PC       // NFC IRQ
#define PORT_D23 PC       // GMX NOT CONNECTED

#define PORT_D24 PA       // A0
#define PORT_D25 PA       // A1
#define PORT_D26 PA       // A2
#define PORT_D27 PA       // A3
#define PORT_D28 PC       // SCL
#define PORT_D29 PC       // SDA

#define PORT_D30 PB       // RTC INTERUPT
#define PORT_D31 PB       // GMX_INTERRUPT

// specify port bit for each pin D0-D31
#define BIT_D0 0
#define BIT_D1 1
#define BIT_D2 2
#define BIT_D3 3
#define BIT_D4 4
#define BIT_D5 5
#define BIT_D6 6
#define BIT_D7 7
#define BIT_D8 0
#define BIT_D9 1
#define BIT_D10 4
#define BIT_D11 5
#define BIT_D12 6
#define BIT_D13 7

#define BIT_D14 4
#define BIT_D15 5
#define BIT_D16 6
#define BIT_D17 7
#define BIT_D18 4
#define BIT_D19 3
#define BIT_D20 5
#define BIT_D21 2
#define BIT_D22 6
#define BIT_D23 7

#define BIT_D24 0
#define BIT_D25 1
#define BIT_D26 2
#define BIT_D27 3
#define BIT_D28 0
#define BIT_D29 1

#define BIT_D30 2
#define BIT_D31 3

// macro equivalents of PROGMEM arrays port_to_mode_PGM[] etc. below
#define PORT_TO_MODE(x) (x == 1 ? &DDRA : (x == 2 ? &DDRB : (x == 3 ? &DDRC : (x == 4 ? &DDRD : NOT_A_PORT)))) 
#define PORT_TO_OUTPUT(x) (x == 1 ? &PORTA : (x == 2 ? &PORTB : (x == 3 ? &PORTC : (x == 4 ? &PORTD : NOT_A_PORT))))
#define PORT_TO_INPUT(x) (x == 1 ? &PINA : (x == 2 ? &PINB : (x == 3 ? &PINC : (x == 4 ? &PIND : NOT_A_PORT)))) 
 
#ifdef ARDUINO_MAIN
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[NUM_DIGITAL_PINS] =
{
  PORT_D0,
  PORT_D1,
  PORT_D2,
  PORT_D3,
  PORT_D4,
  PORT_D5,
  PORT_D6,
  PORT_D7,
  PORT_D8,
  PORT_D9,
  PORT_D10,
  PORT_D11,
  PORT_D12,
  PORT_D13,
  PORT_D14,
  PORT_D15,
  PORT_D16,
  PORT_D17,
  PORT_D18,
  PORT_D19,
  PORT_D20,
  PORT_D21,
  PORT_D22,
  PORT_D23,
  PORT_D24,
  PORT_D25,
  PORT_D26,
  PORT_D27,
  PORT_D28,
  PORT_D29,
  PORT_D30,
  PORT_D31
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[NUM_DIGITAL_PINS] =
{
  _BV(BIT_D0),
  _BV(BIT_D1),
  _BV(BIT_D2),
  _BV(BIT_D3),
  _BV(BIT_D4),
  _BV(BIT_D5),
  _BV(BIT_D6),
  _BV(BIT_D7),
  _BV(BIT_D8),
  _BV(BIT_D9),
  _BV(BIT_D10),
  _BV(BIT_D11),
  _BV(BIT_D12),
  _BV(BIT_D13),
  _BV(BIT_D14),
  _BV(BIT_D15),
  _BV(BIT_D16),
  _BV(BIT_D17),
  _BV(BIT_D18),
  _BV(BIT_D19),
  _BV(BIT_D20),
  _BV(BIT_D21),
  _BV(BIT_D22),
  _BV(BIT_D23),
  _BV(BIT_D24),
  _BV(BIT_D25),
  _BV(BIT_D26),
  _BV(BIT_D27),
  _BV(BIT_D28),
  _BV(BIT_D29),
  _BV(BIT_D30),
  _BV(BIT_D31)
};


const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, /* 0  - PD0 */
  NOT_ON_TIMER, /* 1  - PD1 */
  NOT_ON_TIMER, /* 2  - PD2 */
  NOT_ON_TIMER, /* 3  - PD3 */
  TIMER1B,      /* 4  - PD4 */
  TIMER1A,      /* 5  - PD5 */
  TIMER2B,      /* 6  - PD6 */
  TIMER2A,      /* 7  - PD7 */
  NOT_ON_TIMER, /* 8  - PB0 */
  NOT_ON_TIMER, /* 9  - PB1 */
  TIMER0B,      /* 10 - PB4 */
  NOT_ON_TIMER, /* 11 - PB5 */
  TIMER3A,      /* 12 - PB6 */
  TIMER3B,      /* 13 - PB7 */
  NOT_ON_TIMER, /* 14 - PA4 */
  NOT_ON_TIMER, /* 15 - PA5 */
  NOT_ON_TIMER, /* 16 - PA6 */
  NOT_ON_TIMER, /* 17 - PA7 */
  NOT_ON_TIMER, /* 18 - PC3 */
  NOT_ON_TIMER, /* 19 - PC4 */
  NOT_ON_TIMER, /* 20 - PC5 */
  NOT_ON_TIMER, /* 21 - PC2 */
  NOT_ON_TIMER, /* 22 - PC6 */
  NOT_ON_TIMER, /* 23 - PC7 */
  NOT_ON_TIMER, /* 24 - PA0 */
  NOT_ON_TIMER, /* 25 - PA1 */
  NOT_ON_TIMER, /* 26 - PA2 */
  NOT_ON_TIMER, /* 27 - PA3 */
  NOT_ON_TIMER, /* 28 - PC0 */
  NOT_ON_TIMER, /* 29 - PC1 */
  NOT_ON_TIMER, /* 30 - PB2 */
  TIMER0A       /* 31 - PB3 */
};



#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
