#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Count down from: ");
    int x = GetInt();
    
    if(x >= 0)
    {
        for(int i = x; i > 0; i--)
        {
            printf("%d...\n",i);
        }
    }
    else
    {
        for(int i = x; i < 0; i++)
        {
            printf("%d...\n",i);
        }
    }
    
    printf("BLAST OFF!\n");
}