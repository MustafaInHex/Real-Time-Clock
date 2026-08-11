

#ifndef DIO_H_
#define DIO_H_
void DIO_pindirection(unsigned char port, unsigned char pin ,unsigned char dir );
void DIO_writepin(unsigned char port, unsigned char pin ,unsigned char val );
void DIO_togglepin(unsigned char port, unsigned char pin);
unsigned char DIO_readpin(unsigned char port , unsigned char pin);
void DIO_portdirection(unsigned char port,unsigned char dir);
void DIO_writeport(unsigned char port, unsigned val);
unsigned char DIO_readport(unsigned char port);
void DIO_toggleport(unsigned char port);
void DIO_pullup(unsigned char port , unsigned char pin );
void DIO_lownibblewrite(unsigned char port , unsigned char val);
void DIO_highnibblewrite(unsigned char port , unsigned char val);

#endif /* DIO_H_ */