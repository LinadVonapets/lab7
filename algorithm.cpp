#include "algorithm.hpp"


void add(Car*& cars, size_t& size, size_t& arr_size,
        char* mark, char* name, char* surname,
        int power, int mileage,
        int day, char* month, int year)
{
    if(size == arr_size)
    {
        arr_size += 2;
        Car* temp = new Car[arr_size];

        for(size_t i = 0; i < size; i++)
        {
            temp[i].fio.name    = cars[i].fio.name;
            temp[i].fio.surname = cars[i].fio.surname;
            temp[i].date.day    = cars[i].date.day;
            temp[i].date.month  = cars[i].date.month;
            temp[i].date.year   = cars[i].date.year;  
            temp[i].mark        = cars[i].mark;
            temp[i].mileage     = cars[i].mileage;
            temp[i].power       = cars[i].power;
        }

        delete[] cars;
        cars = temp;
    }

    cars[size].mark = new char[255];
    strcpy(cars[size].mark, mark);
    cars[size].power = power;
    cars[size].mileage = mileage;


    cars[size].fio.name = new char[255];
    strcpy(cars[size].fio.name, name);
    cars[size].fio.surname = new char[255];
    strcpy(cars[size].fio.surname, surname);


    cars[size].date.month = new char[255];
    strcpy(cars[size].date.month, month);
    cars[size].date.day = day;
    cars[size].date.year = year;


    size++;
}

// Добавление бедолаг :)
void add_car(Car*& cars, size_t& size, size_t& arr_size)
{  
    //main section
    char mark[255];
    int power;
    int mileage;

    //fio section
    char name[255];
    char surname[255];

    //date section
    int day;
    char month[255];
    int year;

    printf("Enter element data\nMark Name Surname Power Milage Day Month Year\n");
    scanf("%s %s %s %d %d %d %s %d", &mark, &name, &surname, &power, &mileage, &day, &month, &year);
    
    add(cars, size, arr_size, mark, name, surname, power, mileage, day, month, year);
}


// Вывод бедолаг в консоль 0_0
void print_info(const Car* cars, const size_t size)
{
    printf("=================================================\n");
    printf("Mark\tName\tSurname\tPower\tMileage\tDate\n");

    for(size_t i = 0; i < size; i++)
    {
        printf("%s\t%s\t%s\t%d\t%d\t%d_%s_%d\n", cars[i].mark, cars[i].fio.name,
               cars[i].fio.surname, cars[i].power, cars[i].mileage, 
               cars[i].date.day, cars[i].date.month, cars[i].date.year);
    }
    printf("=================================================\n");
}



void find_mark(Car* cars, const size_t size)
{  
    Car* founded = new Car[size];
    size_t found_size = 0;

    char mark[255] = "";
    printf("Enter mark: ");
    scanf("%s", &mark);

    
    for(size_t i = 0; i < size; i++)
        if(!strcmp(cars[i].mark, mark))
            carcpy(&founded[found_size++], &cars[i]);

    print_info(founded, found_size);
    free_car_array(founded, size);

}



void filter_owner_by_mileage(Car* cars, const size_t size)
{   
    Car* founded = new Car[size];
    size_t found_size = 0;
    int gt_mileage=0;
    printf("Enter milage: ");
    scanf("%d", &gt_mileage);


    for(size_t i = 0; i < size; i++)
        if(cars[i].mileage > gt_mileage)
            carcpy(&founded[found_size++], &cars[i]);

    for(size_t i = 0; i < found_size; i++)
        for(size_t j = i+1; j < found_size; j++)
            if(strcmp(founded[j].fio.surname, founded[i].fio.surname)<0)
            {
                Car temp;
                carcpy(&temp, &founded[i]);
                free_car(&founded[i]);
                carcpy(&founded[i], &founded[j]);
                free_car(&founded[j]);
                carcpy(&founded[j], &temp);
            }

    print_info(founded, found_size);
    free_car_array(founded, size);
}



void filter_car_by_to_date(Car* cars, const size_t size)
{
    Car* founded = new Car[size];
    size_t found_size = 0;

    for(size_t i = 0; i < size; i++)
    {
        int abs_month = diff_crnt_date(&cars[i].date);
        if(abs_month > 18)
            carcpy(&founded[found_size++], &cars[i]);
    }

    print_info(founded, found_size);
    free_car_array(founded, size); 
}