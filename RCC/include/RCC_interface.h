
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* RCC_CR */
#define PLLRDY                          25
#define PLLON                           24
#define CSSON                           19
#define HSEBYP                          18
#define HSERDY                          17
#define HSEON                           16
//#define HSICAL
//#define HSITRIM
#define HSIRDY                          1
#define HSION                           0

/* RCC_CFGR */
#define MCO                             24
#define MCO_SYSCLOCKSELECTED            0b00000100
#define MCO_HSICLOCKSELECTED            0b00000101
#define MCO_HSECLOCKSELECTED            0b00000110
#define MCO_PLLCLOCKSELECTED            0b80111
#define USBPRE                          22
#define PLLMUL                          18
#define PLLXTPRE                        17
#define PLLSRC                          16
#define ADCPRE                          14
#define PPRE2                           11
#define PPRE1                           8
#define HPRE                            4
#define SWS                             2
#define SW                              0

/* RCC_CIR */                           
#define CSSC                            23
#define PLLRDYC                         20
#define HSERDYC                         19
#define HSIRDYC                         18
#define LSERDYC                         17
#define LSIRDYC                         16
#define PLLRDYIE                        12
#define HSERDYIE                        11
#define HSIRDYIE                        10
#define LSERDYIE                        9
#define LSIRDYIE                        8
#define CSSF                            7
#define PLLRDYF                         4
#define HSERDYF                         3
#define HSIRDYF                         2
#define LSERDYF                         1
#define LSIRDYF                         0

/* RCC_APB2RSTR */

/* RCC_APB1RSTR */

/* RCC_AHBENR */

/* RCC_APB2ENR */

/* RCC_APB1ENR */

/* RCC_BDCR */

/* RCC_CSR */

#define HSI_PLL                         0
#define HSE_PLL                         1

#define HSE_DIVIDED_BY_TWO_ENABLED      1
#define HSE_DIVIDED_BY_TWO_DISABLED     0

#define PLLx2                           0b0000
#define PLLx3                           0b0001
#define PLLx4                           0b0010
#define PLLx5                           0b0011
#define PLLx6                           0b0100
#define PLLx7                           0b0101
#define PLLx8                           0b0110
#define PLLx9                           0b0111
#define PLLx10                          0b1000
#define PLLx11                          0b1001
#define PLLx12                          0b1010
#define PLLx13                          0b1011
#define PLLx14                          0b1100
#define PLLx15                          0b1101
#define PLLx16                          0b1110

#define MCO_SYSCLK_SELECTED             0b100
#define MCO_HSI_SELECTED                0b101
#define MCO_HSE_SELECTED                0b110
#define MCO_PLL_DIVIDED_BY_TWO_SELECTED 0b111

#define IOPA                            2
#define IOPB                            3
#define IOPC                            4

#define HSI_SYSCLK                      0b00
#define HSE_SYSCLK                      0b01
#define PLL_SYSCLK                      0b10

#define SW_CLEAR                        0xFFFFFFFC


extern ErrorStatus RCC_EnablePLL(u8 Copy_u8PLLClockSelected, u8 Copy_u8HSEDivision, u8 Copy_u8PLLMUL);
extern ErrorStatus RCC_EnableHSE(void);
extern ErrorStatus RCC_EnableHSI(void);
extern ErrorStatus RCC_MCOConfiguration(u8 Copy_u8MCOCLockSelected);
extern ErrorStatus RCC_DisablePLL(void);
extern ErrorStatus RCC_DisableHSE(void);
extern ErrorStatus RCC_DisableHSI(void);
extern ErrorStatus RCC_EnablePeripheralClock(u8 Copy_u8PeripheralName);
extern ErrorStatus RCC_DisablePeripheralClock(u8 Copy_u8PeripheralName);
extern ErrorStatus RCC_SelectSystemClock(u8 Copy_u8SelectSystemClock);

#endif
