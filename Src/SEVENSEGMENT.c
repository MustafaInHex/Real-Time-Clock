#include<avr/io.h>
#include"DIO.h"
#define CC
 
void SEVENSEGMENT_initialize(unsigned char port)
{
	DIO_portdirection(port,0xFF);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SEVENSEGMENT_write(unsigned char port , unsigned char val)
{
	#if defined CC
unsigned char segment[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

#else
		unsigned char segment[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
		
		#endif
		
	DIO_writeport(port,segment[val]);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BCDSEVENSEGMENT_initialize(unsigned char port , unsigned char nibble) // initialize the 4 pins in which the BCD will be connected
{
	int i;
	if (nibble==0) // low nibbles=first 4 pnx
	{
		for(i=0;i<4;i++)
		{
			DIO_pindirection(port,i,1);
		}
	}
	
	else
	{
		for(i=0;i<4;i++) //  high nibbles=last 4 pnx
		{
			DIO_pindirection(port,i+4,1);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BCDSEVENSEGMENT_write(unsigned char port , unsigned char val, unsigned char nibble)
{
	if (nibble==0)
	{
		DIO_lownibblewrite(port,val);
	}		
	
	else
	{
			DIO_highnibblewrite(port,val);
	}
}

