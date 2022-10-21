#include "CherryTree.h"
#include <stdlib.h>

CherryTree::CherryTree() {
	fruitNumber = 0;
	fruitWeight = 5;
	startGrowing = April;
	endGrowing = Mai;
}

void CherryTree::StartHarvest(Month currentMonth) {
	if (currentMonth == startGrowing) {
		if (canHarvest) {
			fruitNumber = RandomHarvest(45000, 60000);
		}
	}
}

