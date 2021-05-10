#ifndef CELECTRIC_H
#define CELECTRIC_H

#define RAIZ3 1.73
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
	float load; //in Watts
	float powerFactor;  
}electricInfo;

float singlephase_current(electricInfo *info);
float twophase_current(electricInfo *info);
float threephase_current(electricInfo *info);
#endif