#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celectric.h"

int main(){
	electricInfo *info; //info é um ponteiro para electricInfo
	groundingRods rods;
	gndHorizontalConductor *wire;
	gndMeshGrounging *mesh;
	float resposta = 0;

	info = (electricInfo *) malloc(sizeof(electricInfo));

	info->type = SINGLE_PHASE;
	info->voltage = 220;
	info->loadActivePower = 3800;
	info->powerFactor = 0.92;

	if(apparent_power(info)){
		resposta = singlephase_current(info);
		printf("Corrente monofásica: %f \n", resposta);
		resposta = twophase_current(info);
		printf("Corrente bifasica: %f \n", resposta);
		resposta = threephase_current(info);
		printf("corrente trifasica: %f \n", resposta);
		reactive_power(info);
		printf("Potencia reativa %f\n", info->loadReactivePower);
		free(info);
		//return 0;
	}else{
		printf("deu errado\n");	
		free(info);
	}	


	rods.length=2; rods.distance=3; rods.amount=4; rods.soilResistivity=130; rods.diameter=12.7;
	printf("\n\n**************************************************\n");
	printf("*****Grounding Test for a grounding system *******\n");
	printf("**************************************************\n");
	printf("*****Data: \n");
	printf("*******Length: %fm\n",rods.length);
	printf("*******Distance: %fm\n",rods.distance);
	printf("*******Amount: %drods\n",rods.amount);
	printf("*******Diameter: %fmm\n",rods.diameter);
	printf("**************************************************\n");	
	resposta = resistance_of_grounding_rod_sequence(rods);
	printf("%f\n", resposta);

	wire = malloc(sizeof(gndHorizontalConductor));
	wire->length=10; wire->diameter=6.18; wire->depth=0.5; wire->soilResistivity=130;
	printf("\n\n**************************************************\n");
	printf("*****Grounding Test for a grounding system *******\n");
	printf("**************************************************\n");
	printf("*****Data: \n");
	printf("*******Length: %fm\n",wire->length);
	printf("*******depth: %fm\n",wire->depth);
	printf("*******soil resistivity: %f\n",wire->soilResistivity);
	printf("*******Diameter: %fmm\n",wire->diameter);
	printf("**************************************************\n");
	resistance_of_grounding_horizontal_conductor(wire);
	printf("%f\n", wire->resistance);
	free(wire);

	mesh = malloc(sizeof(gndMeshGrounging));
	mesh->length1 = 3;	mesh->length2 = 3;	mesh->e1 = 1;	mesh->e2 = 1;	mesh->depth = 0.5; mesh->resistivity = 130;
	printf("\n\n**************************************************\n");
	printf("*****Grounding Test for a grounding system *******\n");
	printf("**************************************************\n");
	printf("*****Data: \n");
	printf("*******Length1: %fm\n",mesh->length1);
	printf("*******length2: %fm\n",mesh->length2);
	printf("*******e1: %fm\n",mesh->e1);
	printf("*******e2: %fm\n",mesh->e2);
	printf("*******depth: %fm\n",mesh->depth);
	printf("*******resistivity: %fm\n",mesh->resistivity);
	resistance_of_mesh_grounding(mesh);
	free(mesh);
}

