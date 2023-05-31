#ifndef __DYNMEM_LAB7
#define __DYNMEM_LAB7

#include "structs.hpp"
#include <string.h>

void datecpy(Date* dest, Date* src);
void fiocpy(Fio* dest, Fio* src);
void carcpy(Car* dest,  Car* src);


void free_date(Date* object);
void free_fio(Fio* object);
void free_car(Car* object);
void free_car_array(Car* object, size_t size);

#endif