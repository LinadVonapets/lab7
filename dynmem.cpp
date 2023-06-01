#include "dynmem.hpp"

void datecpy(Date* dest, Date* src)
{
    dest->day = src->day;

    dest->month = new char[255];
    strcpy(dest->month, src->month);

    dest->year = src->year;
}



void fiocpy(Fio* dest, Fio* src)
{
    dest->name = new char[255];
    strcpy(dest->name, src->name);

    dest->surname = new char[255];
    strcpy(dest->surname, src->surname);
}



// Короче, копирует все данные из одного car другой car
// Гарантирует шо скопированные объекты уникальные(самостоятельные)
void carcpy(Car* dest,  Car* src)
{
    dest->mark = new char[255];
    strcpy(dest->mark, src->mark);

    fiocpy(&dest->fio, &src->fio);
    
    dest->power = src->power;

    dest->mileage = src->mileage;

    datecpy(&dest->date, &src->date);


}


void free_date(Date* object)
{
    object->day = 0;
    delete[] object->month;
    object->year = 0;
}



void free_fio(Fio* object)
{
    delete[] object->name;
    delete[] object->surname;
}



void free_car(Car* object)
{
    delete[] object->mark;
    object->mileage = 0;
    object->power = 0;
    free_date(&object->date);
    free_fio(&object->fio);
}



// Освобождение бедолаг фром ГУЛАГ :( 
void free_car_array(Car* object, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        free_car(&object[i]);
    }
    delete[] object;
}
