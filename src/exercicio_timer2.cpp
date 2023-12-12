#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#define LED_VERMELHO (1 << PB0)
#define LED_VERDE (1 << PB1)

int cont_segundos = 0;
int cont_minutos = 0;

void ConfigTimer(void){
  TCCR0B |= (1 << CS02) + (1 << CS00);
  TCCR0A |= (1 << WGM01);
  OCR0A = 200;
  TIMSK0 |= (1 << OCIE0A);

}

int main(){

  DDRB |= (LED_VERMELHO + LED_VERDE);

  ConfigTimer();
  sei();
  
  for(;;){

  }
}

ISR(TIMER0_COMPA_vect){
  cont_segundos++;
  if ( cont_segundos > 78){
    PORTD ^= LED_VERMELHO;
    _delay_ms(500);
    cont_segundos = 0;
    cont_minutos++;
  }
  if ( cont_minutos = 60){
    PORTD ^= LED_VERDE;
    _delay_ms(500);
    cont_minutos = 0;
  }
}