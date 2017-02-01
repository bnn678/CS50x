#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Say something: ");
    char* s = GetString();
    
    printf("Say something: ");
    char* t = GetString();
    
    if(s == t)
    {
        printf("You typed something different.\n");
    }
    else
    {
        printf("You typed something different.\n");
    }
}