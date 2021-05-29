#include "grounding.h"

double resistance_of_grounding_rod_sequence(groundingRods rods){
	int i,j;
	double resistanceTotal=0, resistance=0,resistanceaux,bhm,ehm;
	for(i=1;i<=rods.amount;i++){
		for(j=1;j<=rods.amount;j++){
			if(i==j){
				resistanceaux= (rods.soilResistivity/(2*PI*rods.length)) *log(	(	(4*rods.length) / (rods.diameter/1000)  )	);
				printf("%f %d %d\n", resistanceaux,i,j);
				resistance = resistance + resistanceaux;
				continue;
			}
			ehm = abs(i-j)*rods.distance;
			bhm = sqrt( pow(rods.length,2) + pow( ehm , 2));
			//printf("\n bhm:%f ehm:%f p1:%f p2:%f %d %d \n", bhm, ehm,(rods.soilResistivity/(4*PI*rods.length)), (	(pow((bhm + rods.length),2) - pow(ehm,2)) /  (pow(ehm,2) - pow((bhm - rods.length),2)) ), i, j);
			resistanceaux= (rods.soilResistivity/(4*PI*rods.length)) *log(	(	(pow((bhm + rods.length),2) - pow(ehm,2)) /  (pow(ehm,2) - pow((bhm - rods.length),2)) )	);
			printf("%f %d %d\n\n", resistanceaux,i,j);
			resistance = resistance + resistanceaux;
		}
		printf("R%d = %f\n",i, resistance);
		resistance = 1/resistance;
		resistanceTotal = resistanceTotal + resistance;
		resistance = 0;
	}
	resistanceTotal = 1/resistanceTotal;
	return resistanceTotal;
}

void resistance_of_grounding_horizontal_conductor(gndHorizontalConductor *gnd){
	gnd->resistance = (gnd->soilResistivity/(PI*gnd->length))*( log((2*gnd->length)/sqrt((gnd->diameter/1000)*gnd->depth)) -1);
}

void lenght_of_grounding_horizontal_conductor(gndHorizontalConductor *gnd){
	gnd->length = (gnd->soilResistivity/(PI*gnd->resistance))*( log((2*gnd->length)/sqrt((gnd->diameter/1000)*gnd->depth)) -1);
}

void resistance_of_mesh_grounding(gndMeshGrounging *gnd){
	if(!gnd->totalLength && gnd->length1 && gnd->length2 && gnd->e1 && gnd->e2){
		gnd->totalLength = (((gnd->length1/gnd->e1)+1)*gnd->length2)+(((gnd->length2/gnd->e2)+1)*gnd->length1);
		printf("total length: %f\n", gnd->totalLength);
	}
	if(!gnd->area && gnd->length1 && gnd->length2){
		gnd->area = gnd->length1 * gnd->length2;
		printf("total area: %f\n", gnd->area);
	}

	gnd->resistance = gnd->resistivity*(
		(1/gnd->totalLength) +
		(1/sqrt(20*gnd->area)) *
		(1+ (1/(1+ (gnd->depth*sqrt(20/gnd->area)) )) )
		);

	printf("grounding resistance: %f\n", gnd->resistance);
}
