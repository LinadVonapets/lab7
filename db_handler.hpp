#ifndef __DB_HANDLER_LAB7
#define __DB_HANDLER_LAB7

#include <stdio.h>
#include "unistd.h"
#include "algorithm.hpp"

bool is_exist();
void read_from_file(Car*& arr, size_t& size, size_t& arr_size);
void save_to_file(const Car* arr, size_t& size);

#endif