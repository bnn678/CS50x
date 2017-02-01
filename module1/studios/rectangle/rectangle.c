#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Width: ");
    int width = GetInt();
    
    printf("Height:");
    int height = GetInt();
    
    for( int i = 0; i < height; i++ )
    {
        for( int j = 0; j < width; j++)
            printf("<3");
        printf("\n");
    }
}