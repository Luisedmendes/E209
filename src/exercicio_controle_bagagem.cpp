#include<avr/io.h>
#include <avr/interrupt.h>
#define BUZZER (1 << PB4)
// PB2 + PC4 + PD6
int main(){
  DDRB |= BUZZER;
  EICRA = (1 << ISC00) + (1 << ISC01) + (1 << ISC10) + (1 << ISC11);
  EIMSK = (1 << INT0) + (1 << INT1);
  PCICR = (1 << PCIE1) + (1 << PCIE0) + (1 << PCIE2);
  PCMSK1 = (1 << PC4);
  PCMSK0 = (1 << PB2);
  PCMSK2 = (1 << PD6);
  sei();

  for(;;){

  }
}

ISR(INT0_vect){
  PORTB |= BUZZER;
}

ISR(INT1_vect){
  PORTB |= BUZZER;
}

ISR(PCINT0_vect){
  PORTB |= BUZZER;
}

ISR(PCINT1_vect){
  PORTB |= BUZZER;
}

ISR(PCINT2_vect){
  PORTB |= BUZZER;
}