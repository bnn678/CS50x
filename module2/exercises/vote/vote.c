#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many people want to vote: ");
    int voters = GetInt();
    int ages[voters];
    
    for(int i = 0; i < voters; i++)
    {
        printf("Age of person %i: ", i + 1);
        ages[i] = GetInt();
    }
    
    for(int i = 0; i < voters; i++)
    {
        if(ages[i] < 18)
        {
            printf("Person %i cannot vote :( \n", i+1);
        }
        else
        {
            printf("Person %i can vote! \n", i+1);
        }
    }
}