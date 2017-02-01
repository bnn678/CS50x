#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if( argc != 4 )
    {
        printf("Invalid input!\n");
        return 1;
    }
    
    printf("Your word grid currently looks liek this:\n");
    printf( "%s\n%s\n%s\n", argv[1], argv[2], argv[3] );
    printf("Now I will strech it out. How much should I strech by?\n");
    int stretch = GetInt();
    
    printf("After stretching by %i, you now have this!\n", stretch);
    
    char* array = malloc( (strlen(argv[1]) + 1) * 3 * sizeof(char) );
    
    char letter;
    int count;
    for( int current = 1; current < 4; current++ )
    {
        count = 0;
        for( int i = 0, len = strlen( argv[current] ); i < len; i++ )
        {
            letter = argv[current][i];
            
            for( int j = 0; j < stretch; j++ )
            {
                array[count] = letter;
                count++;
            }
        }
        
        for( int a = 0; a < stretch; a++ )
        {
            printf("%s\n", array);
        }
    }
}