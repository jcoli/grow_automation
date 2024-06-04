/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

/* structures internal */

#include <Arduino.h>

typedef struct _out_ana out_ana;
struct _out_ana
{
    int disp;
    int subDisp;
    int function;
    int subFunction;
    float value;
    float oldvalue;
    bool chval;
    int address;
    int lenght;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
};

#define MAX_OUT_ANA 10



typedef struct _inp_dig inp_dig;
struct _inp_dig
{
    int disp;
    int subDisp;
    int function;
    int subFunction;
    bool value;
    bool chval;
    bool oldvalue;
    bool pullup_active;
    int address;
    int lenght;
    String pin_con;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};
#define MAX_INP_DIG 20

// #define String fields_inp_dig[]= {"addinp", "value", "chval", "oldvalue", "active_input", "pullup_active", "connector",  "pin_con", "cable", "wire", "descr", "type", "sensor", "desc_por", "desc_eng", "desc_esp"};




typedef struct _out_dig out_dig;
struct _out_dig
{
    int disp;
    int subDisp;
    int function;
    int subFunction;
    bool value;
    bool chval;
    bool oldvalue;
    int address;
    int lenght;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};

#define MAX_OUT_DIG 20


typedef struct _inp_ana inp_ana;
struct _inp_ana
{
    int disp;
    int subDisp;
    int function;
    int subFunction;
    String value1;
    String value2;
    float oldValue;
    bool chval;
    int address;
    int lenght;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
    
    
};

#define MAX_INP_ANA 20

typedef struct _credentials credentials ;
struct _inp_ana
{
    int disp;
    int subDisp;
    int function;
    int subFunction;
    int address;
    int lenght;
    String value1;
    String value2;
    String descr;
    String desc_por;
    String desc_eng;
    String desc_esp;
    
    
};

#define MAX_CREDENTIALS 10



#endif
