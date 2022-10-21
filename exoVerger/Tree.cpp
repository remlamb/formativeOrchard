#include "Tree.h"
#include <stdlib.h>

Tree::Tree() {

}

void Tree::LoosingHarvest(Month currentMonth) {	//do once in March
	if (currentMonth == Month::March) {	
		int pourcentage = rand() % 101;   
		if (pourcentage <= 5) {	
			canHarvest = false;
		}
		else {
			canHarvest = true;
		}
	}
}

void Tree::StartHarvest(Month currentMonth) {


}

void Tree::GrowingLoose(Month currentMonth) {
	if (currentMonth == endGrowing) {
		float lost = 0.03 + (rand() / (RAND_MAX / (0.07 - 0.03)));
		fruitNumber -= fruitNumber * lost;
	}

}

void Tree::Rotting(Month currentMonth) {
	if (currentMonth > endGrowing) {
		fruitNumber *= 0.25;
	}
}

void Tree::Sleeping(Month currentMonth) {
	if (currentMonth == Month::January) {
		fruitNumber = 0;
	}
}

int Tree::RandomHarvest(int harvestMin, int harvestMax) {
	return rand() % harvestMax + harvestMin;
}


