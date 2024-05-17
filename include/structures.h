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
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
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
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};
#define MAX_INP_DIG 3

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
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};

#define MAX_OUT_DIG 8


typedef struct _inp_ana inp_ana;
struct _inp_ana
{
    int addinp;
    String addinp_desc;
    float value;
    bool chval;
    bool internal = true;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
    
    
};

#define MAX_INP_ANA 5


typedef struct _inp_inj inp_inj;
struct _inp_inj
{
    int addinp;
    String addinp_desc;
    float value;
    bool chval;
    bool internal = true;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
   
    
};

#define MAX_INP_INJ 4
// String mem_inp_anj[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

typedef struct _inp_coil inp_coil;
struct _inp_coil
{
    int addinp;
    String addinp_desc;
    float value;
    bool chval;
    bool internal = true;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
    
    
};

#define MAX_INP_COIL 4
// String mem_inp_coil[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};



/* structures external */

typedef struct _inp_dig_ext inp_dig_ext;
struct _inp_dig_ext
{
    int addinp;
    String addinp_desc;
    bool value;
    bool chval;
    bool oldvalue;
    bool internal = false;
    bool active_input;
    bool pullup_active;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};
#define MAX_INP_DIG_EXT 16

typedef struct _out_dig_ext out_dig_ext;
struct _out_dig_ext
{
    int addinp;
    String addinp_desc;
    bool value;
    bool chval;
    bool oldvalue;
    bool internal = false;
    bool active_input;
    bool pullup_active;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String desc_por;
    String desc_eng;
    String desc_esp;
};
#define MAX_OUT_DIG_EXT 8

typedef struct _inp_ana_ext inp_ana_ext;
struct _inp_ana_ext
{
    int addinp;
    String addinp_desc;
    float value;
    bool chval;
    bool internal = false;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
 
};

#define MAX_INP_ANA_EXT 8



typedef struct _out_ana_ext out_ana_ext;
struct _out_ana_ext
{
    int addout;
    int slider;
    int val_pot;
    float value;
    float value_temp = 50;
    bool internal = false;
    bool chval;
    String desc_map;
    String conector;
    String pin_con;
    String cable;
    String wire;
    String descr;
    String type;
    String sensor;
    String unity;
    String desc_por;
    String desc_eng;
    String desc_esp;
   
};

#define MAX_OUT_ANA_EXT 12



#endif
