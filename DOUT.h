#ifndef LED_H
#define LED_H

#include <msp430.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 DOUT: Data output to send to LEDs
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.0
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define DOUT_BIT				BIT0
#define DOUT_PORT				P1OUT
#define DOUT_DDR				P1DIR
#define SET_DOUT_AS_AN_OUTPUT	DOUT_DDR |= DOUT_BIT
#define TURN_ON_DOUT			DOUT_PORT |= DOUT_BIT
#define TURN_OFF_DOUT			DOUT_PORT &= ~DOUT_BIT
#define TOGGLE_DOUT				DOUT_PORT ^= DOUT_BIT

#define TH						15      // 15/16 us
#define TL						6		// 6/16 us



/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 "Ground"
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.1
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define GND_BIT					BIT1
#define GND_PORT				P1OUT
#define GND_DDR					P1DIR
#define SET_GND_AS_AN_OUTPUT	GND_DDR |= GND_BIT
#define TURN_ON_GND				GND_PORT |= GND_BIT
#define TURN_OFF_GND			GND_PORT &= ~GND_BIT
#define TOGGLE_GND				GND_PORT ^= GND_BIT


// Prototypes
void InitializeLEDPortPins(void);
void SendOne(void);
void SendZero(void);

#endif
