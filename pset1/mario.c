#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("height: ");
    int height = GetInt();
    
    if(height < 0 || height > 23)
    {
        do
        {
            printf("Height must be between 1 and 23. Try again: ");
            height = GetInt();
        }
        while(height < 0 || height > 23);
    }
    
    if(height != 0)
    {
        int total_width = height + 1;
        int hashtags = 2;
        int spaces = total_width - hashtags;
        
        for(int i = height; i > 0; i--)
        {
            for(int a = spaces; a > 0; a--)
            {
                printf(" ");
            }
            for(int a = hashtags; a > 0; a--)
            {
                printf("#");
            }
            printf("\n");
            hashtags += 1;
            spaces -= 1;
        }
    }
    else
    {
        return 0;
    }
}