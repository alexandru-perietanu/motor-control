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
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = OFF        // Internal External Oscillator Switchover bit (Internal External Switchover mode enabled)

// CONFIG2L
#pragma config PWRTEN = OFF      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bits (Brown-out Reset enabled)
// BORV = No Setting

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDPS = 32768     // Watchdog Timer Postscale Select bits (1:32768)
#pragma config WINEN = OFF      // Watchdog Timer Window Enable bit (WDT window disabled)

// CONFIG3L
#pragma config PWMPIN = ON     // PWM output pins Reset state control (PWM outputs disabled upon Reset (default))
#pragma config LPOL = HIGH      // Low-Side Transistors Polarity (PWM0, 2, 4 and 6 are active-high)
#pragma config HPOL = HIGH      // High-Side Transistors Polarity (PWM1, 3, 5 and 7 are active-high)
#pragma config T1OSCMX = ON     // Timer1 Oscillator MUX (Low-power Timer1 operation when microcontroller is in Sleep mode)

// CONFIG3H
#pragma config FLTAMX = RC1     // FLTA MUX bit (FLTA input is multiplexed with RC1)
#pragma config SSPMX = RC7      // SSP I/O MUX bit (SCK/SCL clocks and SDA/SDI data are multiplexed with RC5 and RC4, respectively. SDO output is multiplexed with RC7.)
#pragma config PWM4MX = RB5     // PWM4 MUX bit (PWM4 output is multiplexed with RB5)
#pragma config EXCLKMX = RC3    // TMR0/T5CKI External clock MUX bit (TMR0/T5CKI external clock input is multiplexed with RC3)
#pragma config MCLRE = OFF       // MCLR Pin Enable bit (Enabled)

// CONFIG4L
#pragma config STVREN = OFF      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
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
#include "lcd.h"
#include "stdint.h"
#include "stdio.h"

#define _XTAL_FREQ 40000000
//4.9khz
const unsigned int sinusValues[256] = {4111, 4207, 4304, 4400, 4497, 4593, 4689, 4786, 4882, 4978, 5075, 5203, 5300, 5364, 5460, 5557, 5653, 5749, 5846, 5942, 6038, 6103, 6199, 6295, 6360, 6456, 6520, 6617, 6681, 6777, 6841, 6906, 7002, 7066, 7130, 7195, 7259, 7323, 7387, 7452, 7484, 7548, 7612, 7644, 7709, 7741, 7805, 7837, 7869, 7901, 7934, 7966, 7998, 8030, 8062, 8094, 8094, 8126, 8126, 8158, 8158, 8158, 8158, 8158, 8158, 8158, 8158, 8158, 8158, 8126, 8126, 8094, 8094, 8062, 8030, 8030, 7998, 7966, 7934, 7901, 7837, 7805, 7773, 7709, 7677, 7612, 7580, 7516, 7452, 7420, 7355, 7291, 7227, 7163, 7098, 7034, 6938, 6874, 6809, 6745, 6649, 6584, 6488, 6424, 6327, 6231, 6167, 6070, 5974, 5878, 5814, 5717, 5621, 5524, 5428, 5332, 5235, 5139, 5043, 4946, 4850, 4753, 4657, 4561, 4432, 4336, 4240, 4143, 4047, 3950, 3854, 3758, 3629, 3533, 3437, 3340, 3244, 3147, 3051, 2955, 2858, 2762, 2666, 2569, 2473, 2376, 2312, 2216, 2120, 2023, 1959, 1863, 1766, 1702, 1606, 1541, 1445, 1381, 1316, 1252, 1156, 1092, 1027, 963, 899, 835, 770, 738, 674, 610, 578, 513, 481, 417, 385, 353, 289, 256, 224, 192, 160, 160, 128, 96, 96, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 64, 64, 96, 96, 128, 160, 192, 224, 256, 289, 321, 353, 385, 449, 481, 546, 578, 642, 706, 738, 803, 867, 931, 995, 1060, 1124, 1188, 1284, 1349, 1413, 1509, 1573, 1670, 1734, 1830, 1895, 1991, 2087, 2152, 2248, 2344, 2441, 2537, 2633, 2730, 2826, 2890, 2987, 3115, 3212, 3308, 3404, 3501, 3597, 3693, 3790, 3886, 3983, 4079};
//20KHZconst unsigned int sinusValues[256] = {1028, 1052, 1076, 1100, 1124, 1148, 1172, 1196, 1220, 1244, 1268, 1301, 1325, 1341, 1365, 1389, 1413, 1437, 1461, 1485, 1509, 1525, 1550, 1574, 1590, 1614, 1630, 1654, 1670, 1694, 1710, 1726, 1750, 1766, 1782, 1799, 1815, 1831, 1847, 1863, 1871, 1887, 1903, 1911, 1927, 1935, 1951, 1959, 1967, 1975, 1983, 1991, 1999, 2007, 2015, 2023, 2023, 2031, 2031, 2039, 2039, 2039, 2039, 2039, 2039, 2039, 2039, 2039, 2039, 2031, 2031, 2023, 2023, 2015, 2007, 2007, 1999, 1991, 1983, 1975, 1959, 1951, 1943, 1927, 1919, 1903, 1895, 1879, 1863, 1855, 1839, 1823, 1807, 1790, 1774, 1758, 1734, 1718, 1702, 1686, 1662, 1646, 1622, 1606, 1582, 1558, 1542, 1517, 1493, 1469, 1453, 1429, 1405, 1381, 1357, 1333, 1309, 1285, 1260, 1236, 1212, 1188, 1164, 1140, 1108, 1084, 1060, 1036, 1011, 987, 963, 939, 907, 883, 859, 835, 811, 787, 762, 738, 714, 690, 666, 642, 618, 594, 578, 554, 530, 505, 489, 465, 441, 425, 401, 385, 361, 345, 329, 313, 289, 273, 257, 240, 224, 208, 192, 184, 168, 152, 144, 128, 120, 104, 96, 88, 72, 64, 56, 48, 40, 40, 32, 24, 24, 16, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 16, 24, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 112, 120, 136, 144, 160, 176, 184, 200, 216, 232, 248, 265, 281, 297, 321, 337, 353, 377, 393, 417, 433, 457, 473, 497, 522, 538, 562, 586, 610, 634, 658, 682, 706, 722, 746, 779, 803, 827, 851, 875, 899, 923, 947, 971, 995, 1019};
const unsigned int scaleFactor[50] = {64, 63, 62, 61, 60, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 14, 13, 12, 11, 10};

volatile unsigned char skipValue = 1;
const unsigned int timer0PreloadValues[100] = {55769, 60652, 62280, 63094, 63582, 63907, 64140, 64314, 64450, 64558, 64647, 64721, 64784, 64837, 64884, 64925, 64961, 64992, 65021, 65047, 65070, 65091, 65110, 65128, 65144, 65159, 65173, 65186, 65198, 65209, 65220, 65230, 65239, 65248, 65256, 65264, 65271, 65278, 65285, 65291, 65297, 65302, 65308, 65313, 65318, 65323, 65327, 65332, 65336, 65340, 65344, 65347, 65351, 65354, 65357, 65361, 65364, 65367, 65369, 65372, 65375, 65377, 65380, 65382, 65385, 65387, 65389, 65391, 65393, 65395, 65397, 65399, 65401, 65403, 65405, 65407, 65408, 65410, 65411, 65413, 65414, 65416, 65417, 65419, 65420, 65421, 65423, 65424, 65425, 65426, 65428, 65429, 65430, 65431, 65432, 65436, 65437, 65438, 65439, 65440};
const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

volatile unsigned int adcPercent = 65;
volatile unsigned int prevAdcPercent = 101;
unsigned int maxADCVal = 0xFF;
volatile unsigned long dutyCycle = 0;
volatile unsigned char sinusIndex1 = 0;
volatile unsigned char sinusIndex2 = 85;
volatile unsigned char sinusIndex3 = 170;
volatile unsigned int sinusValue1 = 0;
volatile unsigned int sinusValue2 = 85;
volatile unsigned int sinusValue3 = 170;
volatile char d1 = 1;
//char sinusVales[256] = {128, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173, 176, 179, 182, 185, 188, 190, 193, 196, 198, 201, 203, 206, 208, 211, 213, 215, 218, 220, 222, 224, 226, 228, 230, 232, 233, 235, 237, 238, 240, 241, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 252, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 252, 252, 251, 250, 250, 249, 248, 247, 246, 244, 243, 242, 240, 239, 237, 236, 234, 232, 231, 229, 227, 225, 223, 221, 219, 216, 214, 212, 210, 207, 205, 202, 200, 197, 194, 192, 189, 186, 183, 181, 178, 175, 172, 169, 166, 163, 160, 157, 154, 151, 148, 145, 142, 138, 135, 132, 129, 126, 123, 120, 117, 113, 110, 107, 104, 101, 98, 95, 92, 89, 86, 83, 80, 77, 74, 72, 69, 66, 63, 61, 58, 55, 53, 50, 48, 45, 43, 41, 39, 36, 34, 32, 30, 28, 26, 24, 23, 21, 19, 18, 16, 15, 13, 12, 11, 9, 8, 7, 6, 5, 5, 4, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 17, 18, 20, 22, 23, 25, 27, 29, 31, 33, 35, 37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76, 79, 82, 85, 88, 90, 93, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 127};

unsigned int timer5ReloadValue = 3035;
volatile char timer5OverflowCount = 0;
volatile unsigned int timer0ReloadValue = 60652;
volatile unsigned int prevTimer0ReloadValue = 60535;
volatile unsigned char PrevADRESH = 65;
volatile char refreshTime = 0;
volatile char currentPreloadIndex = 0;
volatile char shouldUpdateDutyCycle = 0;
volatile char shouldDisplay = 0;
volatile char shouldUpdateTimer0Preload = 0;


volatile unsigned char counter = 0;

void display(void);
void readADC(void);
void updateTMR0PreloadValue(void);
void updateSinusIndexes(void);

void configurePWM() {
    LATB = 0;
    TRISB = 0;
    PORTB = 0;


    PTCON0bits.PTMOD0 = 0;
    PTCON0bits.PTMOD1 = 0;
    PTCON0bits.PTCKPS1 = 0;
    PTCON0bits.PTCKPS0 = 0;
    PTCON0bits.PTOPS0 = 0;
    PTCON0bits.PTOPS1 = 0;
    PTCON0bits.PTOPS2 = 0;
    PTCON0bits.PTOPS3 = 0;

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
    //    PTPERH = 0x01;
    //    PTPERL = 0xF3;

    /*4.9 kHz*/
    /*PTPER = 0x07FF*/
    PTPERH = 0x07;
    PTPERL = 0xFF;

    //PIE3bits.PTIE = 1;

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

    //Dead time configuration
    DTCONbits.DTPS1 = 0;
    DTCONbits.DTPS0 = 1;
    DTCON |= 50; // pentru 2us

}

void startPWM() {
    PTCON1bits.PTEN = 1;
}

void stopPWM() {
    PTCON1bits.PTEN = 0;
}

void configureInterrupts() {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

void configureADC() {
    //continous
    ADCON0bits.ACONV = 1;
    ADCON0bits.ACSCH = 0;
    ADCON0bits.ACMOD1 = 0;
    ADCON0bits.ACMOD0 = 0;

    ADCON1 = 0;
    //The A/D acquisition time is set to 12Tad
    ADCON2bits.ACQT2 = 1;
    ADCON2bits.ACQT1 = 1;

    // Fosc / 64
    ADCON2bits.ADCS2 = 1;
    ADCON2bits.ADCS1 = 1;
    ADCON2bits.ADFM = 0;

    //An interrupt is generated on every 2nd and 4th write to the FIFO buffer.
    ADCON3bits.ADRS1 = 1;

    ADCHSbits.GASEL1 = 0;
    ADCHSbits.GASEL0 = 0;

    ANSEL0bits.ANS0 = 1;
    TRISAbits.TRISA0 = 1;

    // ADC __interrupt enable/disable
    PIE1bits.ADIE = 0;

    ADCON0bits.ADON = 1;
    //PIR1bits.ADIF = 0;
    ADCON0bits.GODONE = 1;
}

void configureTimer0() {
    //    TMR0L = 0x0B;
    //    TMR0H = 0x74;

    T0CONbits.PSA = 0;
    T0CONbits.T0SE = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.T016BIT = 0;
    T0CONbits.TMR0ON = 1;
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 0;
    INTCONbits.TMR0IE = 1;
    INTCON2bits.TMR0IP = 0;
    //TMR0 = timer0ReloadValue;
    //TRISDbits.RD1 = 0;
}

void configureTimer1() {
    //prescale = 8
    T1CONbits.T1CKPS1 = 1;
    T1CONbits.T1CKPS0 = 1;

    T1CONbits.TMR1CS = 0;
    T1CONbits.TMR1ON = 1;
    PIE1bits.TMR1IE = 1;
    TMR1 = 0;
}

void configureTimer5() {
    T5CONbits.T5PS1 = 1;
    T5CONbits.T5PS0 = 1;
    T5CONbits.T5MOD = 0;
    T5CONbits.TMR5ON = 1;
    PIE3bits.TMR5IE = 1;
    TMR5 = timer5ReloadValue;
}

void configureInputs() {
    TRISAbits.TRISA1 = 1;
    ANSEL0bits.ANS1 = 0;

    TRISAbits.TRISA3 = 1;
    ANSEL0bits.ANS3 = 0;
}

void configureTimer2() {
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.T2CKPS1 = 1;

    T2CONbits.TMR2ON = 1;
    PIE1bits.TMR2IE = 1;
    TMR2 = 230;

}

void main(void) {
    LCD_Initialize();
    configureInterrupts();
    configurePWM();
    configureADC();
    configureTimer0();
    configureTimer1();
    configureTimer2();
    configureTimer5();
    configureInputs();
    startPWM();

    TRISAbits.TRISA2 = 0;
    TRISAbits.RA2 = 0;
    ANSEL0bits.ANS2 = 0;
    PORTAbits.RA2 = 0;

    //stopPWM();
    NOP();
    while (1) {
        NOP();
        //        PORTAbits.RA2 = d1;
        //        d1 = !d1;
        //updateSinusIndexes();
        //        PORTAbits.RA2 = d1;
        //        d1 = !d1;

        display();
        updateTMR0PreloadValue();
        readADC();

        //        if (PORTAbits.RA1 == 1) {
        //            PORTAbits.RA2 = 1;
        //            //d1 = !d1;
        //        } else {
        //            PORTAbits.RA2 = 0;
        //        }

        if (PORTAbits.RA3 == 1) {
            //PORTAbits.RA2 = 1;
            //d1 = !d1;
        } else {
            //ORTAbits.RA2 = 0;
        }



    }

    return;
}

void __interrupt(low_priority) tcInt(void) {

    //    if (PIR3bits.PTIF) {
    //        PIR3bits.PTIF = 0;
    //        updateSinusIndexes();
    //    }

    if (INTCONbits.TMR0IF) {

        //        counter++;
        //        if (counter >= 255) {
        //            PORTAbits.RA2 = d1;
        //            d1 = !d1;
        //        }
        //        if (sinusIndex1 >= 254) {
        //            PORTAbits.RA2 = d1;
        //            d1 = !d1;
        //        }
        INTCONbits.TMR0IF = 0;

        PWMCON1bits.UDIS = 1;
        unsigned char duty = (sinusValue1 >> 8);
        PDC0H = duty;
        PDC0L = sinusValue1;

        duty = (sinusValue2 >> 8);
        PDC1H = duty;
        PDC1L = sinusValue2;

        duty = (sinusValue3 >> 8);
        PDC2H = duty;
        PDC2L = sinusValue3;
        PWMCON1bits.UDIS = 0;

        sinusIndex1 += 4;
        sinusIndex2 += 4;
        sinusIndex3 += 4;

        TMR0 = timer0ReloadValue;
        //PORTAbits.RA2 = d1;
        //d1 = !d1;
    }

    if (PIR1bits.TMR1IF) {

        PIR1bits.TMR1IF = 0;
        TMR1 = 0;
        //refreshTime++;
        shouldDisplay = 1;
        //        PORTAbits.RA2 = d1;
        //        d1 = !d1;

    }

    if (PIR3bits.TMR5IF) {
        PIR3bits.TMR5IF = 0;
        TMR5 = timer5ReloadValue;
        shouldUpdateTimer0Preload = 1;
        //        PORTAbits.RA2 = d1;
        //        d1 = !d1;
    }

    if (PIR1bits.TMR2IF) {
        PORTAbits.RA2 = d1;
        d1 = !d1;
        updateSinusIndexes();
        PIR1bits.TMR2IF = 0;
        TMR2 = 230;
    }

    //        PORTAbits.RA2 = d1;
    //        d1 = !d1;


}

void display() {
    if (shouldDisplay) {
        if (refreshTime == 10) {
            if (currentPreloadIndex != adcPercent || prevTimer0ReloadValue != timer0ReloadValue || prevAdcPercent != adcPercent) {

                char str1[16];
                char str2[16];
                char str3[16];

                DisplayClr();
                sprintf(str3, "%d", currentPreloadIndex);
                LCDPutStr(str3);
                LCDPutChar(' ');
                sprintf(str1, "%d", adcPercent);
                LCDPutStr(str1);
                LCDPutChar(' ');

                unsigned int timer0ReloadValueCopy = timer0ReloadValue;
                char noDigits = 0;
                while (timer0ReloadValueCopy > 0) {
                    str2[noDigits] = timer0ReloadValueCopy % 10;
                    timer0ReloadValueCopy /= 10;
                    noDigits++;
                }
                for (int i = noDigits - 1; i >= 0; i--) {
                    LCDPutChar(digits[str2[i]]);
                }
                //shouldDisplay = 0;
            }
            refreshTime = 0;
            prevAdcPercent = adcPercent;
            prevTimer0ReloadValue = timer0ReloadValue;
        }
        refreshTime++;

        shouldDisplay = 0;
    }
}

void updateTMR0PreloadValue() {
    if (shouldUpdateTimer0Preload) {
        if (timer5OverflowCount == 1) {
            timer5OverflowCount = 0;
            if (currentPreloadIndex < adcPercent) {
                currentPreloadIndex++;
            } else if (currentPreloadIndex > adcPercent) {
                currentPreloadIndex--;
            }
            timer0ReloadValue = timer0PreloadValues[currentPreloadIndex];
        }
        timer5OverflowCount++;
        shouldUpdateTimer0Preload = 0;
    }
}

void readADC() {
    if (PIR1bits.ADIF == 1) {
        if (PrevADRESH != ADRESH) {
            adcPercent = (255 - ADRESH) * 99 / maxADCVal; //
            //timer0ReloadValue = timer0PreloadValues[adcPercent];
        }
        PrevADRESH = ADRESH;
        PIR1bits.ADIF = 0;
    }
}

void updateSinusIndexes() {
    int currentScalefactor = scaleFactor[currentPreloadIndex];
    unsigned int lowerLimit = 32;
    unsigned int upperLimit = 8158;

    //unsigned int lowerLimit = 8;
    //unsigned int upperLimit = 2039;
    if (currentPreloadIndex < 50) {
        sinusValue1 = (sinusValues[sinusIndex1] << 3) / currentScalefactor;
        sinusValue2 = (sinusValues[sinusIndex2] << 3) / currentScalefactor;
        sinusValue3 = (sinusValues[sinusIndex3] << 3) / currentScalefactor;

    } else {
        sinusValue1 = sinusValues[sinusIndex1];
        sinusValue2 = sinusValues[sinusIndex2];
        sinusValue3 = sinusValues[sinusIndex3];
    }

    sinusValue1 = sinusValue1 < lowerLimit ? lowerLimit : sinusValue1;
    sinusValue2 = sinusValue2 < lowerLimit ? lowerLimit : sinusValue2;
    sinusValue3 = sinusValue3 < lowerLimit ? lowerLimit : sinusValue3;
    sinusValue1 = sinusValue1 > upperLimit ? upperLimit : sinusValue1;
    sinusValue2 = sinusValue2 > upperLimit ? upperLimit : sinusValue2;
    sinusValue3 = sinusValue3 > upperLimit ? upperLimit : sinusValue3;
}