
#ifndef STD_TYPES_H
#define STD_TYPES_H

#define u8 unsigned char
#define u16 unsigned short int
#define u32 unsigned long int

#define s8 signed char
#define s16 signed short int
#define s32 signed long int

#define f32 float
#define f64 double
#define f96 long double


typedef enum Error{
	OK,
	NOK,
	NULLPOINTER
}ErrorStatus;

#define NULL    ((void*)0)

#endif
