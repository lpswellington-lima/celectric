#ifndef CELECTRIC_H
#define CELECTRIC_H

#define RAIZ3 1.73
#define PI 3.141592

typedef enum { 
	false, true 
} bool;

typedef enum currentType
{
	DIRECT,
	SINGLE_PHASE,
	TWO_PHASE,
	THREE_PHASE
} currentType;

typedef struct electricInfo{
	currentType type;
	int voltage; //voltage RMS
	float loadActivePower; //in Watts
	float loadApparentPower; //in VAr
	float loadReactivePower; //in VAr
	float powerFactor;  
}electricInfo;

typedef struct signal{
	float timeBetweenZeros;
	float peak;
} signal;

typedef struct groundingRods{
	float length; //that's the length of the rod
	float distance; //distance between rods
	float diameter; //diameter of each rod in mm
	int amount; //the amount of rods used in the system
	float soilResistivity; //the soil resistivity in ohms*m;
} groundingRods;

typedef struct gndHorizontalConductor{
	float length; //that's the length of the conductor
	float diameter; //diameter of each rod in mm
	float depth; // how deep is the conductor buried
	float soilResistivity; //the soil resistivity in ohms*m;
	float resistance;
}gndHorizontalConductor;

typedef struct gndMeshGrounging{
	float resistance;
	float totalLength;
	float length1;
	float length2;
	float e1;
	float e2;
	float depth;
	float area;
	float resistivity;
}gndMeshGrounging;

float singlephase_current(electricInfo *info);
float twophase_current(electricInfo *info);
float threephase_current(electricInfo *info);
bool apparent_power(electricInfo *info);
bool reactive_power(electricInfo *info);
double resistance_of_grounding_rod_sequence(groundingRods rods);
void resistance_of_grounding_horizontal_conductor(gndHorizontalConductor *gnd);
void lenght_of_grounding_horizontal_conductor(gndHorizontalConductor *gnd);
void resistance_of_mesh_grounding(gndMeshGrounging *gnd);
#endif