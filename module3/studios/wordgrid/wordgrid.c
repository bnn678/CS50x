#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    for( int i = 0; i < 3; i++)
    {
        for( int j = 1; j < 4; j++)
        {
            printf("%c", argv[j][i]);
        }
        printf("\n");
    }
    
    //char* array[3] = { argv[1][0], argv[2][0], argv[3][0] };
};