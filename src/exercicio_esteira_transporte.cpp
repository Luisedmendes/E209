#include <avr/io.h>
#include <util/delay.h>
#define MOTOR1 (1 << PD2)
#define SENSOR1 (1 << PB3)
#define LIGA (1 << PB0)
#define DESLIGA (1 << PB1)
#define ALARME (1 << PD6)

int main() {
    // ENTRADAS
    DDRB &= ~(LIGA + DESLIGA);
    DDRB &= ~(SENSOR1);

    // SAÍDAS
    DDRD |= MOTOR1;
    DDRB |= ALARME;

    // PULL UP
    PORTD |= SENSOR1;

    PORTB |= (LIGA + DESLIGA);

    for (;;) {
        short int liga, desliga, sensor;
        liga = PINB & LIGA;
        desliga = PINB & DESLIGA;
        sensor = PINB & SENSOR1;
    

        if((liga == LIGA) && (sensor != SENSOR1)){
          PORTD &= ~ALARME;
          PORTD |= MOTOR1;
          _delay_ms(100);
        }

        if(desliga == DESLIGA){
          PORTD &= ~MOTOR1;
          _delay_ms(100);
        }

        if(sensor == SENSOR1){
          PORTD &= ~MOTOR1;
          PORTD |= ALARME;
          _delay_ms(100);
        }
    }
}
