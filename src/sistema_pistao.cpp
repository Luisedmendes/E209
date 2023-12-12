#include <avr/io.h>
#include <avr/interrupt.h>
#define LIGA (1 << PC0)
#define DESLIGA (1 << PC1)
#define S1 (1 << PB0)
#define S2 (1 << PB1)
#define AVANCO (1 << PD1)
#define RECUO (1 << PD2)
#define M1 (1 << PD3)

int main (){
  // ENTRADAS
  DDRC &= ~(LIGA + DESLIGA);

  PORTC = (LIGA + DESLIGA);
  

  // SAIDAS
  DDRD |= (AVANCO + RECUO + M1);

  PCICR = (1 << PCIE0);
  PCMSK0 = (S1 + S2);
	sei();
  for (;;) {
    short int liga, desliga;
    liga = PINC & LIGA;
    desliga = PINC & DESLIGA;

    if (liga == LIGA){
      PORTD |= M1;
      PORTD |= AVANCO;
      PORTD &= ~(RECUO);
    }

    if (desliga == DESLIGA){
      PORTD &=~(M1);
      PORTD &=~(AVANCO);
      PORTD |= RECUO;
    }

  }
}

ISR(PCINT0_vect){
  if(PINB & S1){
    PORTD |= AVANCO;
    PORTD &= ~RECUO;
  } else if (PINB & S2){
    PORTD &= ~(M1);
    PORTD &= ~(AVANCO);
    PORTD |= RECUO;
  } else{
    PORTD &= ~(AVANCO + RECUO);
  }

}