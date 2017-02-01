#include "mathhelper.h"
#include <math.h>

int numberOfContainers(int numberOfUnits, int unitsPerContainer)
{
    // calculate number of containers to order using ceil from math.h
    float numberToOrder = ceil(((float)numberOfUnits)/unitsPerContainer);
    return (int)numberToOrder;
}