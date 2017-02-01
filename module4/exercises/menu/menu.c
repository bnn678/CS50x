#include <stdio.h>

int main(void)
{
    printf("Welcome to Better Burger, way better than Good Burger!\n");
    printf("TITLE: \n");
    
    FILE* ptr = fopen("exampleMenu.txt", "r");
    if( ptr == NULL)
    {
        printf("Fail\n");
        return 1;
    }
    
    char line[256];
    for( int i = 1; fgets(line, sizeof(line), ptr) != NULL; i++ )
    {
        printf("%i) %s", i, line);
    }
    
    printf("\n");
    fclose(ptr);
}