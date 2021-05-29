#include "electric_power.h"


bool apparent_power(electricInfo *info){
	if (info->loadActivePower && info->powerFactor){
		info->loadApparentPower = info->loadActivePower/info->powerFactor;
		return true;
	}
	return false;
}

bool reactive_power(electricInfo *info){
	if (info->loadActivePower && info->loadApparentPower){
		info->loadReactivePower = sqrt(
			(pow(info->loadApparentPower,2)-pow(info->loadActivePower,2))
			);
		return true;
	}
	return false;
}

float singlephase_current(electricInfo *info){
	return info->loadApparentPower/info->voltage;
}

float twophase_current(electricInfo *info){
	return info->loadApparentPower/(info->voltage*RAIZ3);
}

float threephase_current(electricInfo *info){
	return info->loadApparentPower/(info->voltage*RAIZ3*RAIZ3);
}