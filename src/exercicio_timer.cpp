#include<avr/io.h>
#include<avr/interrupt.h>
#define LED (1 << PB0)

int cont = 0;

void ConfigTimer0 (void){

  TCCR0B |= (1 << CS02) + (1 << CS00); // 1024 64us
  TCCR0A |= (1 << WGM01); // CTC
  OCR0A = 200; // 200* 64us = 12.8ms
  TIMSK0 |= (1 << OCIE0A); // TIMER0
}

int main(){

  DDRB |= LED;

  ConfigTimer0();
  sei();
  for(;;){

  }

}

ISR(TIMER0_COMPA_vect){
  cont++;
  if( cont >= 12){ // 12*12.8ms ~= 150ms
    PORTB ^= LED;
    cont = 0;
  }
  
}