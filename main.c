#include <msp430.h>

#include "DOUT.h"

// Function prototypes
void ConfigureClockModule(void);

void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();

    InitializeLEDPortPins();

	// Running loop
  	while (1)
  	{
  		int i = 0;
  		while(i < 10)
  		{
  			TURN_ON_DOUT;
			_delay_cycles(TL);
			TURN_OFF_DOUT;
			_delay_cycles(TH);
  			i++;
  		}

  		//This is sending 1
  		TURN_ON_DOUT;
  		_delay_cycles(TH);
  		TURN_OFF_DOUT;
  		_delay_cycles(TL);

  		while(i < 12)
  		{
  			TURN_ON_DOUT;
			_delay_cycles(TL);
			TURN_OFF_DOUT;
			_delay_cycles(TH);
  			i++;
  		}



  		TURN_OFF_DOUT;
  		_delay_cycles(1000); //  us

  	}
}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) for 1 MHz using factory
    // calibrations.
	DCOCTL  = CALDCO_16MHZ;
	BCSCTL1 = CALBC1_16MHZ;
}
