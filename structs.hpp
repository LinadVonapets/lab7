#ifndef __STRUCTS_LAB7
#define __STRUCTS_LAB7

struct Date
{
    int day;
    char* month;
    int year;
};


struct Fio
{
    char* name;
    char* surname;
};


struct Car
{
    char* mark;
    Fio fio;
    int power;
    int mileage;
    Date date;
};


enum state_t
{
    ADD,
    PRINT, 
    FIND_MARK,
    FIND_OWNER,
    FIND_CAR,
    QUIT,
    MAX_AMOUNT_CMD
};

#endif