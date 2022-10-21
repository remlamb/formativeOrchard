#pragma once
#include <iostream>

enum Month
{
	January = 1,
	February,
	March,
	April,
	Mai,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
};

class Tree
{
public:
	int fruitNumber;
	int fruitWeight;
	Month startGrowing;
	Month endGrowing;
	bool canHarvest;

	Tree();

	virtual void StartHarvest(Month);	//vitual void that give random fruit number after bloom // rand variable change according to the trees
	void LoosingHarvest(Month);	//5% chance to loose all 
	void GrowingLoose(Month);	//parasite or bird attack 
	void Rotting(Month);	//reduce by 25% each month
	void Sleeping(Month);	//no more fruit during winter

	int RandomHarvest(int, int);	//rand int between a given min and max, use in stratHarvest()

};

