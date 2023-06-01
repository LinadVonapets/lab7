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
    FILTER_OWNER_BY_MILEAGE,
    FILTER_CAR_BY_TO_DATE,
    SAVE,
    QUIT,
    MAX_AMOUNT_CMD
};

#endif