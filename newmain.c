/*
 * File:   newmain.c
 * Author: peri
 *
 * Created on December 3, 2019, 10:40 PM
 */


// PIC18F4431 Configuration Bit Settings

// 'C' source line config statements

// PIC18F4431 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (clock frequency = 4 x FOSC1))
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = ON        // Internal External Oscillator Switchover bit (Internal External Switchover mode enabled)

// CONFIG2L
#pragma config PWRTEN = ON      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bits (Brown-out Reset enabled)
// BORV = No Setting

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDPS = 32768     // Watchdog Timer Postscale Select bits (1:32768)
#pragma config WINEN = OFF      // Watchdog Timer Window Enable bit (WDT window disabled)

// CONFIG3L
#pragma config PWMPIN = OFF     // PWM output pins Reset state control (PWM outputs disabled upon Reset (default))
#pragma config LPOL = HIGH      // Low-Side Transistors Polarity (PWM0, 2, 4 and 6 are active-high)
#pragma config HPOL = HIGH      // High-Side Transistors Polarity (PWM1, 3, 5 and 7 are active-high)
#pragma config T1OSCMX = ON     // Timer1 Oscillator MUX (Low-power Timer1 operation when microcontroller is in Sleep mode)

// CONFIG3H
#pragma config FLTAMX = RC1     // FLTA MUX bit (FLTA input is multiplexed with RC1)
#pragma config SSPMX = RC7      // SSP I/O MUX bit (SCK/SCL clocks and SDA/SDI data are multiplexed with RC5 and RC4, respectively. SDO output is multiplexed with RC7.)
#pragma config PWM4MX = RB5     // PWM4 MUX bit (PWM4 output is multiplexed with RB5)
#pragma config EXCLKMX = RC3    // TMR0/T5CKI External clock MUX bit (TMR0/T5CKI external clock input is multiplexed with RC3)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (Enabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF         // Low-Voltage ICSP Enable bit (Low-voltage ICSP enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-000FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (001000-001FFF) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (002000-002FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (003000-003FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-000FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (001000-001FFF) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (002000-002FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (003000-003FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-000FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (001000-001FFF) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (002000-002FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (003000-003FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "pic18f4431.h"

void configurePWM() {
    LATB = 0;
    TRISB = 0;
    PORTB = 0;
    
    /*PTCON0: PWM TIMER CONTROL REGISTER 0*/
    /*
        PTMOD1:PTMOD0: PWM Time Base Mode Select bits
        11 =PWM time base operates in a Continuous Up/Down mode with interrupts for double PWM updates.
        10 =PWM time base operates in a Continuous Up/Down Counting mode.
        01 =PWM time base configured for Single-shot mode.
        00 =PWM time base operates in a Free Running mode.
     */
    PTCON0bits.PTMOD0 = 0;
    PTCON0bits.PTMOD1 = 0;

    /*PTCON1: PWM TIMER CONTROL REGISTER 1*/
    /*
        PTEN: PWM Time Base Timer Enable bit
        1 = PWM time base is ON
        0 = PWM time base is OFF
      
        PTDIR: PWM Time Base Count Direction Status bit
        1 = PWM time base counts down.
        0 = PWM time base counts up.
     */

    PTCON1bits.PTEN = 0;
    PTCON1bits.PTDIR = 0;


    /*PWMCON0: PWM CONTROL REGISTER 0*/
    /*
        PWMEN2:PWMEN0: PWM Module Enable bits(1)
        111 =All odd PWM I/O pins enabled for PWM output(2).
        110 =PWM1, PWM3 pins enabled for PWM output.
        101 =All PWM I/O pins enabled for PWM output(2) .
        100 =PWM0, PWM1, PWM2, PWM3, PWM4 and PWM5 pins enabled for PWM output.
        011 =PWM0, PWM1, PWM2 and PWM3 I/O pins enabled for PWM output.
        010 =PWM0 and PWM1 pins enabled for PWM output.
        001 =PWM1 pin is enabled for PWM output.
        000 =PWM module disabled. All PWM I/O pins are general purpose I/O.
      
      
        PMOD3:PMOD0: PWM Output Pair Mode bits
        For PMOD0:
        1 = PWM I/O pin pair (PWM0, PWM1) is in the Independent mode.
        0 = PWM I/O pin pair (PWM0, PWM1) is in the Complementary mode.
        For PMOD1:
        1 = PWM I/O pin pair (PWM2, PWM3) is in the Independent mode.
        0 = PWM I/O pin pair (PWM2, PWM3) is in the Complementary mode.
        For PMOD2:
        1 = PWM I/O pin pair (PWM4, PWM5) is in the Independent mode.
        0 = PWM I/O pin pair (PWM4, PWM5) is in the Complementary mode.
     */
    PWMCON0bits.PWMEN2 = 1;
    PWMCON0bits.PWMEN1 = 0;
    PWMCON0bits.PWMEN0 = 0;

    PWMCON0bits.PMOD0 = 0;
    PWMCON0bits.PMOD1 = 0;
    PWMCON0bits.PMOD2 = 0;

    /*PWMCON1: PWM CONTROL REGISTER 1*/
    /*
     UDIS: PWM Update Disable bit
     1 = Updates from duty cycle and period buffer registers are disabled.
     0 = Updates from duty cycle and period buffer registers are enabled.
     */
    PWMCON1bits.UDIS = 0;
    PWMCON1bits.OSYNC = 1;

    /*PWM Period PTPER register*/
    /*20 kHz*/
    /*PTPER = 0x01FF*/
    PTPERH = 0x01;
    PTPERL = 0xF3;


    //PTMRH = 0x00;
    //PTMRL = 0xFF;
    
    PDC0H = 0x00;
    PDC0L = 0xC1;
    
    /*
     * OVDCOND: OUTPUT OVERRIDE CONTROL REGISTER
     * POVD7:POVD0: PWM Output Override bits(1)
       1 = Output on PWM I/O pin is controlled by the value in the Duty Cycle register and the PWM
       time base.
       0 = Output on PWM I/O pin is controlled by the value in the corresponding POUT bit.
     */
    OVDCOND = 0xff;
    /*OVDCONS: OUTPUT STATE REGISTER
     
     POUT7:POUT0: PWM Manual Output bits(1)
     1 = Output on PWM I/O pin is ACTIVE when the corresponding PWM output override bit is
     cleared.
     0 = Output on PWM I/O pin is INACTIVE when the corresponding PWM output override bit is
     cleared
     
     */
    OVDCONS = 0;
}

void startPWM() {
    PTCON1bits.PTEN = 1;
}

void stopPWM() {
    PTCON1bits.PTEN = 0;
}

void configureInterrupts() {
    /*INTCON REGISTER*/
    /*
    GIE/GIEH: Global Interrupt Enable bit
    When IPEN = 0:
    1 = Enables all unmasked interrupts
    0 = Disables all interrupts
    When IPEN = 1:
    1 = Enables all high priority interrupts
    0 = Disables all high priority interrupts
     
     
    PEIE/GIEL: Peripheral Interrupt Enable bit
    When IPEN = 0:
    1 = Enables all unmasked peripheral interrupts
    0 = Disables all peripheral interrupts
    When IPEN = 1:
    1 = Enables all low priority peripheral interrupts
    0 = Disables all low priority peripheral interrupts
     */
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    /*PIE3:*/
    /*
     PTIE: PWM Time Base Interrupt Enable bit
        1 = PTIF enabled
        0 = PTIF disabled
     */
    PIE3bits.PTIE = 1;
}

void configureADC() {
    //continous
    ADCON0bits.ACONV = 1;
    ADCON1 = 0;
    //The A/D acquisition time is set to 12Tad
    ADCON2bits.ACQT2 = 1;
    ADCON2bits.ACQT1 = 1;
    
    // Fosc / 32
    ADCON2bits.ADCS1 = 1;
    
    //An interrupt is generated on every 2nd and 4th write to the FIFO buffer.
    ADCON3bits.ADRS0 = 1;
            
    ANSEL0bits.ANS0 = 1;
    TRISAbits.TRISA0 = 1;
    
    ADCON0bits.ACMOD0 = 1;
    PIE1bits.ADIE = 1;
    ADCON0bits.ADON = 0;
    PIR1bits.ADIF = 0;
    
}

void main(void) {

    configureInterrupts();
    configurePWM();
   // configureADC();
    startPWM();
    //stopPWM();

    while (1) {

    }

    return;
}

void __interrupt(low_priority) tcInt(void) {
    if (PIR3bits.PTIF) {
        PIR3bits.PTIF = 0;
    }
}
