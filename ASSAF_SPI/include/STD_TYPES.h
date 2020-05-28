#ifndef STD_TYPES_H
#define STD_TYPES_H

/*
#define u8 unsigned char
#define u16 unsigned short int
#define u32 unsigned long int

#define s8 signed char
#define s16 signed short int
#define s32 signed long int

#define f32 float
#define f64 double
#define f96 long double
*/

typedef unsigned char      u8
typedef unsigned short int u16
typedef unsigned long int  u32

typedef signed char        s8
typedef signed short int   s16
typedef signed long int    s32

typedef float              f32
typedef double             f64
typedef long double        f96

typedef unsigned char      ErrorStatus
#define OK                 1
#define NOK                0
/*
typedef enum Error{
	OK,
	NOK,
	NULLPOINTER
}ErrorStatus;
*/

#define NULL    ((void*)0)

#endif