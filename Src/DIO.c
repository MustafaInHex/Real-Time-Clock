#include <avr/io.h>
#include "std_macros.h"


void DIO_pindirection(unsigned char port, unsigned char pin ,unsigned char dir )
{

	switch (port){
		
		case 'A':
		case 'a':
		if(dir==1)
		{
			SET_BIT(DDRA,pin);
		}
		else{
			CLR_BIT(DDRA,pin);
		}
		
		break;
		
		case 'B':
		case 'b':
		if(dir==1)
		{
			SET_BIT(DDRB,pin);
		}
		else{
			CLR_BIT(DDRB,pin);
		}
		
		break;
		
		case 'C':
		case 'c':
		if(dir==1)
		{
			SET_BIT(DDRC,pin);
		}
		else{
			CLR_BIT(DDRC,pin);
		}
		
		break;
		
		case 'D':
		case 'd':
		if(dir==1)
		{
			SET_BIT(DDRD,pin);
		}
		else{
			CLR_BIT(DDRD,pin);
		}
		
		break;
		
		default:
		break;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DIO_writepin(unsigned char port, unsigned char pin ,unsigned char val )
{
	
	switch (port){
		
		case 'A':
		case 'a':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else{
			CLR_BIT(PORTA,pin);
		}
		
		break;
		
		
		case 'B':
		case 'b':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else{
			CLR_BIT(PORTB,pin);
		}
		
		break;
		
		
		case 'C':
		case 'c':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else{
			CLR_BIT(PORTC,pin);
		}
		
		break;
		
		case 'D':
		case 'd':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else{
			CLR_BIT(PORTD,pin);
		}
		
		break;
		
		default:
		break;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DIO_togglepin(unsigned char port, unsigned char pin)
{
	switch(port){
		
		case 'A':
		case'a':
		TOG_BIT(PORTA,pin);
		break;
		
		case 'B':
		case'b':
		TOG_BIT(PORTB,pin);
		break;
		
		
		case 'C':
		case'c':
		TOG_BIT(PORTC,pin);
		break;
		
		case 'D':
		case'd':
		TOG_BIT(PORTD,pin);
		break;
		
		default:
		break;
		
		
	}

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char DIO_readpin(unsigned char port , unsigned char pin)
{
	unsigned char x;
	switch (port){
		
		case 'A':
		case 'a':
		
		x=READ_BIT(PINA,pin);
		break;
		
		case 'B':
		case 'b':
		
		x=READ_BIT(PINB,pin);
		break;
		
		
		case 'C':
		case 'c':
		
		x=READ_BIT(PINC,pin);
		break;
		
		case 'D':
		case 'd':
		
		x=READ_BIT(PIND,pin);
		break;
		
		default:
		break;
	}
	return x;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DIO_portdirection(unsigned char port,unsigned char dir)
{
	switch (port){
		
		case 'A':
		case 'a':
		DDRA=dir;
		break;
		
		case 'B':
		case 'b':
		DDRB=dir;
		break;
		
		case 'C':
		case 'c':
		DDRC=dir;
		break;
		
		case 'D':
		case 'd':
		DDRD=dir;
		break;
		
		default:
		break;
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_writeport(unsigned char port, unsigned val)
{
	
	switch (port){
		
		case 'A':
		case 'a':
		PORTA=val;
		break;
		
		case 'B':
		case 'b':
		PORTB=val;
		break;
		
		case 'C':
		case 'c':
		PORTC=val;
		break;
		
		case 'D':
		case 'd':
		PORTD=val;
		break;
		
		default:
		break;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char DIO_readport(unsigned char port)
{
	unsigned char x;
	switch(port)
	{
		case 'A':
		case 'a':
		x=PINA;
		break;
		
		case 'B':
		case 'b':
		x=PINB;
		break;
		
		case 'C':
		case 'c':
		x=PINC;
		break;
		
		case 'D':
		case 'd':
		x=PIND;
		break;
		default:
		break;
	}
	return x;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void DIO_toggleport(unsigned char port)
{
	
	
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;
		break;
		
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;
		
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		
		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
		
		default:
		break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_pullup(unsigned char port , unsigned char pin )
{
	
	DIO_pindirection(port,pin,0);
	

	
	DIO_writepin(port,pin,1);   //turn on pull up

	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_lownibblewrite(unsigned char port , unsigned char val) // shows the first four bits of a number on the first 4 bits of the port
{
	int i;
	for(i=0;i<4;i++)
	{
		DIO_writepin(port,i,READ_BIT(val,i));
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_highnibblewrite(unsigned char port , unsigned char val) // shows the first four bits of a number on the last 4 bits of the port
{

	int i;
	for(i=0;i<4;i++)
	{
		DIO_writepin(port,i+4,READ_BIT(val,i));
	}
}




























































