#include "Orchard.h"
#include <iostream>


std::string Orchard::MonthToString() {
	switch (currentMonth) {
	case Month::January:
		return "January";

	case Month::February:
		return "February";

	case Month::March:
		return "March";

	case Month::April:
		return "April";

	case Month::Mai:
		return "Mai";

	case Month::June:
		return "June";

	case Month::July:
		return "July";

	case Month::August:
		return "August";

	case Month::September:
		return "September";

	case Month::October:
		return "October";

	case Month::November:
		return "November";

	case Month::December:
		return "December";

	default:
		break;
	}
};

void Orchard::Season() {
	ClearConsole();
	std::cout << "---  OBJECTIVE 2 000KG  ---" << std::endl;
	std::cout << "Current month is : ";
	std::cout << MonthToString() << "\n";

	for (auto& plant : planting) {
		plant->LoosingHarvest(currentMonth);
		plant->StartHarvest(currentMonth);
		plant->GrowingLoose(currentMonth);
		plant->Rotting(currentMonth);
		plant->Sleeping(currentMonth);
	}
	PrintInfo();

	varMonth++;
	if (varMonth > 12) {
		varMonth = 1;
	}
	currentMonth = Month(varMonth);


	int input;
	std::cout << "Press 1 to continue, Press 2 to harvest, Press 3 to exit : " << std::endl;
	std::cin >> input;

	if (input == 1) {
		Season();
	}
	if (input == 2) {
		GetHarvest();
	}
	if (input == 3) {
		return;
	}
}

void Orchard::ChooseOurPlanting() {
	int totalTree = 0;
	int nbrCherryTree;
	int nbrAppleTree;
	int nbrPearTree;
	std::cout << "--- ORCHARD SIMULATOR ---" << std::endl;
	std::cout << "You can plant to 15 trees : You can choose between Cherry Tree, Pear Tree or Apple tree" << std::endl ;
	std::cout << "Enter the number of Cherry Tree (Max 8) :" << std::endl;
	std::cin >> nbrCherryTree;

	OutOfRangeTypeTree(nbrCherryTree, 8);
	totalTree += nbrCherryTree;

	std::cout << "Enter the number of Apple Tree (Max 15) :" << std::endl;
	std::cin >> nbrAppleTree;
	OutOfRangeTypeTree(nbrAppleTree, 15);
	totalTree += nbrAppleTree;
	OutOfRangeTreeInPlantation(nbrAppleTree, totalTree, nbrCherryTree);

	std::cout << "Enter the number of Pear Tree (Max 10) :" << std::endl;
	std::cin >> nbrPearTree;
	OutOfRangeTypeTree(nbrPearTree, 10);
	totalTree += nbrPearTree;
	OutOfRangeTreeInPlantation(nbrPearTree, totalTree, (nbrCherryTree + nbrAppleTree));

	for (int i = 0; i < nbrCherryTree; i++) {
		AddCherryTree();
	}

	for (int i = 0; i < nbrAppleTree; i++) {
		AddAppleTree();
	}

	for (int i = 0; i < nbrPearTree; i++) {
		AddPearTree();
	}

	Season();

}

void Orchard::AddCherryTree() {
	planting.emplace_back(new CherryTree());
}

void Orchard::AddAppleTree() {
	planting.emplace_back(new AppleTree());
}

void Orchard::AddPearTree() {
	planting.emplace_back(new PearTree());
}

void Orchard::GetHarvest() {
	harvest = 0;
	for (auto& plant : planting) {
		harvest += plant->fruitNumber* plant->fruitWeight;
	}
	std::cout << "You get " << harvest << " g" << std::endl;

	CheckIfWinning();
}

void Orchard::CheckIfWinning() {
	if (harvest / 1000 >= 2000) {
		std::cout << "You Win" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
}

bool Orchard::IsACherryTree(Tree* plant) {
	CherryTree* cherrytree = dynamic_cast<CherryTree*>(plant);
	if (cherrytree != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Orchard::IsAAppleTree(Tree* plant) {
	AppleTree* appletree = dynamic_cast<AppleTree*>(plant);
	if (appletree != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Orchard::IsAPearTree(Tree* plant) {
	PearTree* peartree = dynamic_cast<PearTree*>(plant);
	if (peartree != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Orchard::PrintInfo() {
	int nbrCherryFruit = 0;
	int nbrAppleFruit = 0;
	int nbrPearFruit = 0;
	for (auto& plant : planting) {
		if (IsACherryTree(plant)) {
			nbrCherryFruit += plant->fruitNumber;
		}
		if (IsAAppleTree(plant)) {
			nbrAppleFruit += plant->fruitNumber;
		}
		if (IsAPearTree(plant)) {
			nbrPearFruit += plant->fruitNumber;
		}
	}
	std::cout << "CherryTree fruits : " << nbrCherryFruit << " | " << "AppleTree fruits : " << nbrAppleFruit << " | " << "PearTree fruits : " << nbrPearFruit << std::endl;
}

void Orchard::OutOfRangeTypeTree(int& input, int maxTree) {
	if (input > maxTree) {
		input = maxTree;
	}
}

void Orchard::OutOfRangeTreeInPlantation(int& numberTypeTree, int& totalTree, int currentTree) {
	if (totalTree > 15) {
		numberTypeTree = 15 - currentTree;
		totalTree = 15;
	}
}

void Orchard::ClearConsole() {
	std::cout << "\x1B[2J\x1B[H";
}

