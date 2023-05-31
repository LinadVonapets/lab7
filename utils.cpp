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
        printf("Invalid command.");
    }
}