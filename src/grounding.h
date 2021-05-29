#include "celectric.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct groundingResistance
	{
		int resistance;
		struct groundingResistance *next;
	}groundingResistance;