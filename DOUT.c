#include "DOUT.h"

void InitializeLEDPortPins(void)
{
	// Set the initial value and port pin direction for the LEDs.
	TURN_OFF_DOUT;
	SET_DOUT_AS_AN_OUTPUT;
	TURN_OFF_DOUT;
	SET_DOUT_AS_AN_OUTPUT;

}

void SendOne(void)
{
	TURN_ON_DOUT;
	_delay_cycles(TH);
	TURN_OFF_DOUT;
	_delay_cycles(TL);
}
void SendZero(void)
{
	TURN_ON_DOUT;
	_delay_cycles(TL);
	TURN_OFF_DOUT;
	_delay_cycles(TH);
}
