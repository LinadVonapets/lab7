#include "db_handler.hpp"



bool is_exist()
{
    return access("db.txt", F_OK) == 0;
}


void read_from_file(Car*& cars, size_t& size, size_t& arr_size)
{
    printf("Reading from file...\n");
    if(!is_exist())
        printf("<WARN: database file doesn't exist!\n>");
    else
    {
        FILE* fp = fopen("db.txt", "r");

        int flag = 1;
        while(1)
        {
            char mark[255] = "";

            char name[255] = "";
            char surname[255] = "";

            int power = 0;
            int mileage = 0;

            int day = 0;
            char month[255] = ""; 
            int year = 0;

            flag = fscanf(fp, "%s %s %s %d %d %d %s %d", mark, name, surname, &power, &mileage, &day, month, &year);
            if(flag == -1)
                break;
            add(cars, size, arr_size, mark, name, surname, power, mileage, day, month, year);
        }
        
        fclose(fp);
        printf("Reading is done!\n");
    }

}


void save_to_file(const Car* arr, size_t& size)
{
    printf("Saving...\n");
    if(!is_exist())
        printf("<WARN: Creating new save file!\n>");
    
    FILE* fp = fopen("db_saved.txt", "w");
    
    
    for(size_t i = 0; i < size; i++)
    {
        fprintf(fp, "%s %s %s %d %d %d %s %d\n", arr[i].mark,     arr[i].fio.name,   arr[i].fio.surname,
                                               arr[i].power,    arr[i].mileage, 
                                               arr[i].date.day, arr[i].date.month, arr[i].date.year);
    }
        
    fclose(fp);
    printf("Saved\n");
}