#include <stdio.h>

void CountUp(int limit, int* cap);

int main(void)
{
    int limit = 0;
    int* cap = &limit;
    CountUp(10, cap);
    printf("Counted up to %i!\n", *cap);
}

void CountUp(int limit, int* cap)
{
    for( int i = 0; i < limit; i++ )
    {
        printf("%i\n", i);
    }
    
    *cap = limit;
}