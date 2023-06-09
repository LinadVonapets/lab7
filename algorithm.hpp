#ifndef __ALGORITHM_LAB7
#define __ALGORITHM_LAB7

#include <stdio.h>
#include <string.h>

#include "structs.hpp"
#include "dynmem.hpp"
#include "utils.hpp"

void add(Car*& cars, size_t& size, size_t& arr_size,
        char* mark, char* name, char* surname,
        int power, int mileage,
        int day, char* month, int year);
void add_car(Car*& cars, size_t& size, size_t& arr_size);
void print_info(const Car* cars, const size_t size);
void find_mark(Car* cars, const size_t size);
void filter_owner_by_mileage(Car* cars, const size_t size);
void filter_car_by_to_date(Car* cars, const size_t size);

#endif