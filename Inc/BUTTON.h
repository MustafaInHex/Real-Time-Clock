#ifndef BUTTON_H_
#define BUTTON_H_
void BUTTON_initialize(unsigned char port, unsigned char pin);
unsigned char BUTTON_status(unsigned char port, unsigned char pin);
void BUTTON_pullup(unsigned char port , unsigned char pin);

#endif /* BUTTON_H_ */


