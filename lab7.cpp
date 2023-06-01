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
    printf("5 - Save\n");
    printf("6 - Exit\n");
    
    bool quit = false;
    while(!quit)
    {
        switch(handle_event())
        {
        case ADD:
            add_car(arr, actual_size, arr_size);
            break;

        case PRINT:
            print_info(arr, actual_size);
            break;

        case FIND_MARK:
            find_mark(arr, actual_size);
            break;

        case FILTER_OWNER_BY_MILEAGE:
            filter_owner_by_mileage(arr, actual_size);
            break;

        case FILTER_CAR_BY_TO_DATE:
            filter_car_by_to_date(arr, actual_size);        
            break;

        case QUIT:
            quit = true;
            break;

        case SAVE:
            save_to_file(arr, actual_size);
            break;
        }
    }
    free_car_array(arr, arr_size);
}

int main()
{   
    run_db();
}