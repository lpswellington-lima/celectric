#include <stdio.h>
#include <stdlib.h>
#include "celectric.h"

int main(){
	electricInfo *info; //info é um ponteiro para electricInfo
	float resposta = 0;

	info = (electricInfo *) malloc(sizeof(electricInfo));

	info->type = SINGLE_PHASE;
	info->voltage = 220;
	info->load = 3800;
	info->powerFactor = 0.92;

	resposta = singlephase_current(info);
	printf("Corrente monofásica: %f \n", resposta);
	resposta = twophase_current(info);
	printf("Corrente bifasica: %f \n", resposta);
	resposta = threephase_current(info);
	printf("corrente trifasica: %f \n", resposta);
	
	free(info);
}

