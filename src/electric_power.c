#include "electric_power.h"
#include <stdio.h>


float singlephase_current(electricInfo *info){
	return info->load/info->voltage;
}

float twophase_current(electricInfo *info){
	return info->load/(info->voltage*RAIZ3);
}

float threephase_current(electricInfo *info){
	return info->load/(info->voltage*RAIZ3*RAIZ3);
}