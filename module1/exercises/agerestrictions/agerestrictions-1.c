#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How old are you: ");
    int age = GetInt();
    switch(age)
    {
        case(21):
            printf("You can drink!\n");
        
        case 18:
            printf("You can vote!\n");
            
        case 16:
            printf("You can drive!\n");
            break;
            
        default:
            printf("Nothing to do!\n");
    }
    
}