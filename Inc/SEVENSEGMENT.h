
#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_
void SEVENSEGMENT_initialize(unsigned char port);
void SEVENSEGMENT_write(unsigned char port , unsigned char val);
void BCDSEVENSEGMENT_initialize(unsigned char port , unsigned char nibble);
void BCDSEVENSEGMENT_write(unsigned char port , unsigned char val, unsigned char nibble);

#endif /* 7SEGMENT_H_ */