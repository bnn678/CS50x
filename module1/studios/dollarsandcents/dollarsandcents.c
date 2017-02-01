#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("Gimme a dollar amount: ");
    float decimal = GetFloat();
    
    decimal *= 100;
    decimal = round(decimal);
    decimal /= 100;
    
    printf("Oh, I think you mean $%f\n", decimal);
}