#include <avr/interrupt.h>
#include<avr/io.h>
#include <util/delay.h>
#define LED1 (1 << PD5)
#define LED2 (1 << PD4)
int main(){

  DDRD = LED1 + LED2;



  EICRA = (1 << ISC11);
  EIMSK = (1 << INT0);
  sei();

  for(;;){
    PORTD ^= LED1;
    _delay_ms(500);
    PORTD ^= LED1;
  }
}

ISR(INT0_vect){
  PORTD ^= LED2;
  _delay_ms(1000);
  PORTD ^= LED2;
}
