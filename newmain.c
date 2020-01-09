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
#pragma config PWMPIN = OFF     // PWM output pins Reset state control (PWM outputs disabled upon Reset (default))
#pragma config LPOL = LOW      // Low-Side Transistors Polarity (PWM0, 2, 4 and 6 are active-high)
#pragma config HPOL = LOW      // High-Side Transistors Polarity (PWM1, 3, 5 and 7 are active-high)
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


const int sinusValues[256] = {960, 982, 1004, 1026, 1049, 1071, 1093, 1115, 1137, 1160, 1182, 1211, 1234, 1248, 1271, 1293, 1315, 1337, 1359, 1382, 1404, 1419, 1441, 1463, 1478, 1500, 1515, 1537, 1552, 1574, 1589, 1604, 1626, 1641, 1655, 1670, 1685, 1700, 1715, 1729, 1737, 1752, 1766, 1774, 1789, 1796, 1811, 1818, 1826, 1833, 1840, 1848, 1855, 1863, 1870, 1877, 1877, 1885, 1885, 1892, 1892, 1892, 1892, 1892, 1892, 1892, 1892, 1892, 1892, 1885, 1885, 1877, 1877, 1870, 1863, 1863, 1855, 1848, 1840, 1833, 1818, 1811, 1803, 1789, 1781, 1766, 1759, 1744, 1729, 1722, 1707, 1692, 1678, 1663, 1648, 1633, 1611, 1596, 1581, 1567, 1544, 1530, 1507, 1493, 1470, 1448, 1433, 1411, 1389, 1367, 1352, 1330, 1308, 1285, 1263, 1241, 1219, 1197, 1174, 1152, 1130, 1108, 1086, 1063, 1034, 1012, 989, 967, 945, 923, 901, 878, 849, 827, 804, 782, 760, 738, 716, 693, 671, 649, 627, 605, 582, 560, 545, 523, 501, 479, 464, 442, 420, 405, 383, 368, 346, 331, 316, 301, 279, 264, 249, 235, 220, 205, 190, 183, 168, 153, 146, 131, 124, 109, 101, 94, 79, 72, 64, 57, 50, 50, 42, 35, 35, 27, 27, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 27, 27, 35, 35, 42, 50, 57, 64, 72, 79, 87, 94, 101, 116, 124, 138, 146, 161, 175, 183, 198, 212, 227, 242, 257, 272, 286, 309, 323, 338, 360, 375, 397, 412, 434, 449, 471, 494, 508, 531, 553, 575, 597, 619, 642, 664, 679, 701, 730, 753, 775, 797, 819, 841, 864, 886, 908, 930, 952};
/*const unsigned int timer0PreloadValues[101] = 
{60652, 60701, 60750, 60799, 60848, 60897, 60946, 60995, 61044, 61093,
61142, 61191, 61240, 61289, 61338, 61387, 61436, 61485, 61534, 61583,
61633, 61682, 61731, 61780, 61829, 61878, 61927, 61976, 62025, 62074,
62123, 62172, 62221, 62270, 62319, 62368, 62417, 62466, 62515, 62564, 
62614, 62663, 62712, 62761, 62810, 62859, 62908, 62957, 63006, 63055,
63104, 63153, 63202, 63251, 63300, 63349, 63398, 63447, 63496, 63545,
63595, 63644, 63693, 63742, 63791, 63840, 63889, 63938, 63987, 64036,
64085, 64134, 64183, 64232, 64281, 64330, 64379, 64428, 64477, 64526, 
64576, 64625, 64674, 64723, 64772, 64821, 64870, 64919, 64968, 65017,
65066, 65115, 65164, 65213, 65262, 65311, 65360, 65409, 65458, 65508, 65508};
 */
const unsigned int timer0PreloadValues[100] = {
    60652, 63093, 63907, 64314, 64558, 64721, 64837, 64924, 64992, 65046, 65091,
    65128, 65159, 65186, 65209, 65229, 65247, 65263, 65278, 65290, 65302, 65313,
    65322, 65331, 65339, 65347, 65354, 65360, 65366, 65372, 65377, 65382, 65387,
    65391, 65395, 65399, 65403, 65406, 65409, 65412, 65415, 65418, 65421, 65424,
    65426, 65428, 65431, 65433, 65435, 65437, 65439, 65441, 65442, 65444, 65446,
    65447, 65449, 65450, 65452, 65453, 65454, 65456, 65457, 65458, 65459, 65461,
    65462, 65463, 65464, 65465, 65466, 65467, 65468, 65469, 65469, 65470, 65471,
    65472, 65473, 65473, 65474, 65475, 65476, 65476, 65477, 65478, 65478, 65479,
    65480, 65480, 65481, 65481, 65482, 65483, 65483, 65484, 65484, 65485, 65485, 65486
};

const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

volatile unsigned int adcPercent = 65;
volatile unsigned int prevAdcPercent = 101;
unsigned int maxADCVal = 0xFF;
volatile unsigned long dutyCycle = 0;
volatile unsigned char sinusIndex1 = 0;
volatile unsigned char sinusIndex2 = 85;
volatile unsigned char sinusIndex3 = 170;
volatile char d1 = 1;
//char sinusVales[256] = {128, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173, 176, 179, 182, 185, 188, 190, 193, 196, 198, 201, 203, 206, 208, 211, 213, 215, 218, 220, 222, 224, 226, 228, 230, 232, 233, 235, 237, 238, 240, 241, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 252, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 252, 252, 251, 250, 250, 249, 248, 247, 246, 244, 243, 242, 240, 239, 237, 236, 234, 232, 231, 229, 227, 225, 223, 221, 219, 216, 214, 212, 210, 207, 205, 202, 200, 197, 194, 192, 189, 186, 183, 181, 178, 175, 172, 169, 166, 163, 160, 157, 154, 151, 148, 145, 142, 138, 135, 132, 129, 126, 123, 120, 117, 113, 110, 107, 104, 101, 98, 95, 92, 89, 86, 83, 80, 77, 74, 72, 69, 66, 63, 61, 58, 55, 53, 50, 48, 45, 43, 41, 39, 36, 34, 32, 30, 28, 26, 24, 23, 21, 19, 18, 16, 15, 13, 12, 11, 9, 8, 7, 6, 5, 5, 4, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 17, 18, 20, 22, 23, 25, 27, 29, 31, 33, 35, 37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76, 79, 82, 85, 88, 90, 93, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 127};

//unsigned int timer0ReloadMin = 60652; // pt 1Hz
//unsigned int timer0ReloadMax = 65508; // pt 100Hz
unsigned int timer5ReloadValue = 3035;
volatile char timer5OverflowCount = 0;
volatile unsigned int timer0ReloadValue = 60535;
volatile unsigned int prevTimer0ReloadValue = 60535;
volatile unsigned char PrevADRESH = 65;
volatile char refreshTime = 0;
volatile char currentPreloadIndex = 0;
volatile char shouldUpdateDutyCycle = 0;
volatile char shouldDisplay = 0;
volatile char shouldUpdateTimer0Preload = 0;


//void handleDisplay(void);
//void handlePWMDutyCycle(void);
//void handleTimer0Preload(void);
//void display(void);

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
    PDC0L = 0x13;
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
}

void startPWM() {
    PTCON1bits.PTEN = 1;
}

void stopPWM() {
    PTCON1bits.PTEN = 0;
}

//unsigned int map(unsigned int x, unsigned int in_min, unsigned int in_max, unsigned int out_min, unsigned int out_max) {
//    return (x - in_min) * ((out_max - out_min) / (in_max - in_min)) + out_min;
//}

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
    T0CONbits.T0PS0 = 0;
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

void main(void) {
    LCD_Initialize();
    configureInterrupts();
    configurePWM();
    configureADC();
    configureTimer0();
    configureTimer1();
    configureTimer5();
    startPWM();

    //DisplayClr();
    ///LCDPutStr("aaaa");



    TRISAbits.TRISA2 = 0;
    TRISAbits.RA2 = 0;
    ANSEL0bits.ANS2 = 0;
    PORTAbits.RA2 = 0;
    //timer0ReloadValue = timer0PreloadValues[50];

    //stopPWM();
    NOP();
    //LCDPutChar('a');
    while (1) {
        NOP();
        //shouldUpdateDutyCycle = 0;
        if (shouldUpdateDutyCycle) {
            if (sinusIndex1 == 255) {
                sinusIndex1 = 0;
            }
            if (sinusIndex2 == 255) {
                sinusIndex2 = 0;
            }
            if (sinusIndex3 == 255) {
                sinusIndex3 = 0;
            }

            //dutyCycle = sinusVales[sinusIndex] * (1900 - 13) / 255 + 13;
            unsigned char duty = (sinusValues[sinusIndex1] >> 8);
            PDC0H = duty;
            PDC0L = sinusValues[sinusIndex1];

            duty = (sinusValues[sinusIndex2] >> 8);
            PDC1H = duty;
            PDC1L = sinusValues[sinusIndex2];

            duty = (sinusValues[sinusIndex3] >> 8);
            PDC2H = duty;
            PDC2L = sinusValues[sinusIndex3];


            //TMR0 = timer0ReloadValue;

            //        PORTDbits.RD1 = d1;
            //        d1 = !d1;

            sinusIndex1++;
            sinusIndex2++;
            sinusIndex3++;
            shouldUpdateDutyCycle = 0;
        }
        //shouldDisplay = 0;
        if (shouldDisplay) {
            if (refreshTime == 5) {
                if (prevAdcPercent != adcPercent || prevTimer0ReloadValue != timer0ReloadValue) {

                    char str1[16];
                    char str2[16];

                    DisplayClr();
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
            } 
            refreshTime++;
            prevAdcPercent = adcPercent;
            prevTimer0ReloadValue = timer0ReloadValue;
            shouldDisplay = 0;
        }

        if (shouldUpdateTimer0Preload) {
            if (timer5OverflowCount == 2) {
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

        if (PIR1bits.ADIF == 1) {
            if (PrevADRESH != ADRESH) {
                adcPercent = (255 - ADRESH) * 99 / maxADCVal; //
                //timer0ReloadValue = timer0PreloadValues[adcPercent];
            }
            PrevADRESH = ADRESH;
            PIR1bits.ADIF = 0;
        }
    }

    return;
}

void __interrupt(low_priority) tcInt(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        shouldUpdateDutyCycle = 1;
        //PORTAbits.RA4 = 1;
        //PORTAbits.RA2 = d1;
        //d1 = !d1;
        TMR0 = timer0ReloadValue;
    }

    if (PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;
        TMR1 = 0;
        //refreshTime++;
        shouldDisplay = 1;

    }

    if (PIR3bits.TMR5IF) {
        PIR3bits.TMR5IF = 0;
        TMR5 = timer5ReloadValue;
        shouldUpdateTimer0Preload = 1;
        //        PORTAbits.RA2 = d1;
        //        d1 = !d1;
    }

}
