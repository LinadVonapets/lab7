#include "utils.hpp"


void flush()
{
    char empty;
    while((empty = getchar()) != '\n' && empty != EOF);
}

state_t handle_event()
{
    int cmd;
    while(true)
    {
        printf(">> ");
        scanf("%d", &cmd);
        if(cmd >= 0 && cmd < MAX_AMOUNT_CMD)
            return (state_t)cmd;        
        printf("Invalid command.\n");
    }
}


int month_str2int(char* month)
{
    char* months[12] = {(char*)"january", (char*)"february", (char*)"march", (char*)"april", (char*)"may", (char*)"june", (char*)"july", (char*)"august",
                        (char*)"september", (char*)"october", (char*)"november", (char*)"december"};
    
    for(int i = 0; i < 12; i++)
        if(!strcmp(month, months[i]))
            return i;
    return -1;
}


int diff_crnt_date(Date* date)
{  
    time_t k = time(NULL);
    tm crnt_date = *localtime(&k);

    int month = abs(crnt_date.tm_mon - month_str2int(date->month));
    int year = (crnt_date.tm_year+1900) - date->year;

    return month + year * 12;
}
