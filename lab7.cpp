#include <stdio.h>
#include <string.h>

#include "structs.hpp"
#include "dynmem.hpp"
#include "utils.hpp"
#include "algorithm.hpp"
#include "db_handler.hpp"

void run_db()
{
    size_t arr_size = 2;
    Car* arr = new Car[arr_size];
    
    size_t actual_size = 0;
    
    read_from_file(arr, actual_size, arr_size);

    printf("0 - Add new element\n");
    printf("1 - Print the car's base\n");
    printf("2 - Search for car by mark\n");
    printf("3 - Find owner, which have mileage greater than N\n");
    printf("4 - Find car with TO date greater then 18 month\n");
    printf("5 - Exit and save\n");
    
    bool quit = false;
    while(!quit)
    {
        switch(handle_event())
        {
        case PRINT:
            print_info(arr, actual_size);
            break;
        case FIND_MARK:
            find_mark(arr, actual_size);
            break;

        case FIND_OWNER:
            find_owner(arr, actual_size);
            break;

        case ADD:
            add_car(arr, actual_size, arr_size);
            break;
            
        case QUIT:
            quit = true;
            break;

        }
    }
    free_car_array(arr, arr_size);
}

int main()
{   
    run_db();
}