/*
 * INTERRUPT_private.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_



//INTERRUPT REGISTERS

/**********************************************/

// Microcontroller Control Register
#define MCUCR_REG           (*((volatile u8*)0x55))

//General Interrupt Flag Register GICR
#define GIFR_REG            (*((volatile u8*)0x5A))

//General Interrupt Control Register GICR
#define GICR_REG            (*((volatile u8*)0x5B))

//Status Register
#define SREG_REG            (*((volatile u8*)0x5F))

/**********************************************/





// INTERRUPT VECTOR IN ATMEGA32

/***********************************************/

/* External Pin, Power-on Reset, Brown-out
 * Reset, Watchdog Reset, and JTAG AVR Reset*/
#define RESET           (*((volatile u8*)0x000))
/***********************************************/

// External Interrupt Request 0
#define   INT0_VECT          (*((volatile u8*)0x002))

// External Interrupt Request 1
#define INT1_VECT            (*((volatile u8*)0x004))

// External Interrupt Request 2
#define INT2_VECT            (*((volatile u8*)0x006))

/***********************************************/

//Timer/Counter2 Compare Match
#define TIMER2_COMP     (*((volatile u8*)0x008))

// Timer/Counter2 Overflow
#define TIMER2_OVF      (*((volatile u8*)0x00A))

/***********************************************/

// Timer/Counter1 Capture Event
#define TIMER1_CAPT     (*((volatile u8*)0x00C))

// Timer/Counter1 Compare Match A
#define TIMER1_COMP_A   (*((volatile u8*)0x00E))

// Timer/Counter1 Compare Match B
#define TIMER1_COMP_B   (*((volatile u8*)0x010))

// Timer/Counter1 Overflow
#define TIMER1_OVF      (*((volatile u8*)0x012))

/***********************************************/

// Timer/Counter0 Compare Match
#define TOMER0_COMP     (*((volatile u8*)0x014))

// Timer/Counter0 Overflow
#define TIMER0_OVF      (*((volatile u8*)0x016))

/***********************************************/

// Serial Transfer Complete (SPI , STC )
#define SPI_STC         (*((volatile u8*)0x018))

// USART, Rx Complete
#define USART_RX        (*((volatile u8*)0x01A))


// USART Data Register Empty
#define USART_UDRE      (*((volatile u8*)0x01C))

//USART, Tx Complete
#define USART_TXC       (*((volatile u8*)0x01E))

//ADC Conversion Complete
#define ADC_VECT             (*((volatile u8*)0x020))

//EEPROM Ready
#define EEPROM_RDY      (*((volatile u8*)0x022))

//Analog Comparator
#define ANALOG_COMP     (*((volatile u8*)0x024))

// Two-wire Serial Interface
#define TWI             (*((volatile u8*)0x026))

//Store Program Memory Ready
#define SPM_RDY         (*((volatile u8*)0x028))




#endif /* INTERRUPT_PRIVATE_H_ */
