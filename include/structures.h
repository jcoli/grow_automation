/**
Version: 0a
Tecnocoli - 10/2021
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Digital ECU Simulator
**/

#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

/* structures internal */

#include <Arduino.h>

typedef struct _out_ana out_ana;
struct _out_ana
{
    int addpot;
    int cs_pin;
    int val_pot;
    float value;
    float value_temp = 50;    
    bool chval;
    bool internal = true;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
};

#define MAX_OUT_ANA 2



typedef struct _inp_dig inp_dig;
struct _inp_dig
{
    int addinp;
    String addinp_desc;
    bool value;
    bool chval;
    bool oldvalue;
    bool internal = true;
    bool active_input;
    bool pullup_active;
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
    int addout;
    String addout_desc;
    bool value;
    bool chval;
    bool oldvalue;
    bool internal = true;
    String pin_con;
    String cable;
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
    int addinp;
    String addinp_desc;
    float value;
    bool chval;
    bool internal = true;
    String pin_con;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
    
    
};

#define MAX_INP_ANA 10


#endif
