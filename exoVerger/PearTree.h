#include "Tree.h"

class PearTree : public Tree
{
public:
	PearTree() {
		fruitNumber = 0;
		fruitWeight = 90;
		startGrowing = October;
		endGrowing = November;
	};
	void StartHarvest(Month currentMonth) override {
		if (currentMonth == startGrowing) {
			if (canHarvest) {
				fruitNumber = RandomHarvest(250, 350);
			}
		}
	};
};
