#include <avr/io.h>

#define LIGA (1 << PC0)
#define DESLIGA (1 << PC1)
#define BAIXO (1 << PD4)
#define ALTO (1 << PD5)
#define BOMBA (1 << PB0)
#define CHAVE (1 << PD3)

int main(){
  // quem é entrada e quem é saída
  DDRC &= ~(LIGA + DESLIGA);
  DDRD &= ~(BAIXO + ALTO + CHAVE);

  // pull up interno
  PORTC |= (LIGA+ DESLIGA);

  DDRB |= BOMBA;

  // LÓGICA
  for(;;) {
    short int chave;

    chave = PIND & CHAVE;
    if (chave == CHAVE)
    {
      short int baixo;
      short int alto;
      baixo = PIND & BAIXO;
      alto = PIND & ALTO;
      if((baixo != BAIXO) && (alto != ALTO))
      {
        PORTB |= BOMBA;
      }

      if(alto == ALTO)
      {
        PORTB &= ~BOMBA;
      }

    } else {
      short int liga;
      short int desliga;
      liga = PINC & LIGA;
      desliga = PINC & DESLIGA;
      if(liga == LIGA){
        PORTB |= BOMBA;
      }

      if(desliga == DESLIGA){
        PORTB &= ~BOMBA;
      }

    }

  }
}