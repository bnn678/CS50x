#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    char* array[3];
    char* array1 = argv[1];
    char* array2 = argv[2];
    char* array3 = argv[3];
    
    array[0] = array1; array[1] = array2; array[2] = array3;
    
    for( int i = 0; i < 3; i++)
    {
        for( int j = 0; j < 3; j++)
        {
            printf("%c", array[j][i]);
        }
        printf("\n");
    }
};