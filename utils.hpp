#ifndef __UTILS_LAB7
#define __UTILS_LAB7

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "structs.hpp"

void flush();
state_t handle_event();
int month_str2int(char* month);
int diff_crnt_date(Date* date);


#endif