#include "Tree.h"

class AppleTree : public Tree
{
public:
	AppleTree() {
		fruitNumber = 0;
		fruitWeight = 150;
		startGrowing = September;
		endGrowing = November;
	};
	void StartHarvest(Month currentMonth) override {
		if (currentMonth == startGrowing) {
			if (canHarvest) {
				fruitNumber = RandomHarvest(600, 850);
			}
		}
	};
};
