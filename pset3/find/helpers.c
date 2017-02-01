/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first = 0;
    int last = n - 1;
    bool found = false;
    int midpoint;
    
    while( first <= last && found == false)
    {
        midpoint = (first + last) / 2;
        if( values[midpoint] == value )
        {
            found = true;
        }
        else
        {
            if( value < values[midpoint])
            {
                last = midpoint - 1;
            }
            else
            {
                first = midpoint + 1;
            }
        }
    }
    
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int current_num = 1;
    int num1; int num2;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 1; j < n - current_num; j++ )
        {
            num1 = values[i+1];
            num2 = values[i];
            
            if( num2 > num1 )
            {
                values[i] = num1;
                values[i+1] = num2;
            }
        }
        current_num += 1;
    }
    return;
}