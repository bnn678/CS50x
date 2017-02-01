#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("WELCOME to the store!\n");
    printf("Today's special is %s!\n", "Rhubarb");
    printf("How many donuts would you like: ");
    float donuts = GetFloat();

    printf("How much would you like to pay for each donut: \n");
    float price = GetFloat();
    
    price *= 1.05;
    price *= donuts;

    printf("Okay! After tax your order will be %.2f for %.0f donuts. Thank you!\n", price, donuts);
    printf("Come back soon!\n");
}