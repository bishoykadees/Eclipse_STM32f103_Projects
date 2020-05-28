
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT_NO)    (VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)    (VAR&=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)    ((VAR>>BIT_NO)&0X01)

#endif