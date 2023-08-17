/*
 * Comunicacion_microapp.c
 *
 * Created: 2/02/2022 4:18:29 p. m.
 * Author : luis Martinez
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "UART.h"
#include <stdlib.h>
#include <stdio.h>
#include "sip_switch.h"
#include <util/delay.h>

int main(void)
{	
	//configuracion de puertos
	DDRD=0x00;
	PORTD=0xFF;
	DDRC=0xF; //BIT 2 3 4 OUTPUT
	PORTC=0x00;
	//iniciando comunicacion serial
	UART_init();
	UART_write_txt("Atmega328p Saluda..\n\r");
	//variables
	uint8_t dato=0;
	char* Sensor1;char* Sensor2;char* Sensor3;char* Sensor4;
	char* Sensor5;char* Sensor6;char* Sensor7;
	char* guion;
	char mensaje[84];
	int s11;int s21;int s31;int s41;
	int s12;int s22;int s32;int s42;
	int s13;int s23;int s33;int s43;
	int s14;int s24;int s34;int s44;
	int s15;int s25;int s35;int s45;
	int s16;int s26;int s36;int s46;
	int s17;int s27;int s37;int s47;
    /* Replace with your application code */
    while (1) 
    {
		dato = UART_read();
		if(dato != 0){
			guion="/";
			switch(dato){
				case '1':
				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s11=dp_init(2);s21=dp_init(3);s31=dp_init(4);s41=dp_init(5);
				Sensor1=dp_read(s11,s21,s31,s41);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);

				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s12=dp_init(2);s22=dp_init(3);s32=dp_init(4);s42=dp_init(5);
				Sensor2=dp_read(s12,s22,s32,s42);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);

				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s13=dp_init(2);s23=dp_init(3);s33=dp_init(4);s43=dp_init(5);
				Sensor3=dp_read(s13,s23,s33,s43);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);
				
				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s14=dp_init(2);s24=dp_init(3);s34=dp_init(4);s44=dp_init(5);
				Sensor4=dp_read(s14,s24,s34,s44);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);
				
				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s15=dp_init(2);s25=dp_init(3);s35=dp_init(4);s45=dp_init(5);
				Sensor5=dp_read(s15,s25,s35,s45);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);
				
				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s16=dp_init(2);s26=dp_init(3);s36=dp_init(4);s46=dp_init(5);
				Sensor6=dp_read(s16,s26,s36,s46);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				_delay_ms(30000);
				
				PORTC |= (1<<PORTC0);PORTC |= (1<<PORTC1);PORTC |= (1<<PORTC2);PORTC |= (1<<PORTC3);
				_delay_ms(250);
				s17=dp_init(2);s27=dp_init(3);s37=dp_init(4);s47=dp_init(5);
				Sensor7=dp_read(s17,s27,s37,s47);
				PORTC &= ~(1<<PORTC0);PORTC &= ~(1<<PORTC1);PORTC &= ~(1<<PORTC2);PORTC &= ~(1<<PORTC3);
				//_delay_ms(10000);
				
				sprintf(mensaje,"%s%s%s%s%s%s%s%s%s%s%s%s%s%",Sensor1,guion,Sensor2,guion,Sensor3,guion,Sensor4,guion,Sensor5,guion,Sensor6,guion,Sensor7);
				UART_write_txt(mensaje);
			}
		}
    }
}

