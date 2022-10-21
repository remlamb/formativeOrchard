#pragma once
#include "Tree.h"
#include "CherryTree.h"
#include "PearTree.h"
#include "AppleTree.h"
#include <vector>


class Orchard
{
public:
	Month currentMonth = January;
	int varMonth = 1;
	int harvest;
	std::vector<Tree*> planting;

	void Season();	//The function that pass the month and act on the trees

	std::string MonthToString();
	void ChooseOurPlanting();	//Tree selection to put in planting 
	void AddCherryTree();
	void AddAppleTree();
	void AddPearTree();
	void GetHarvest();	//get Harvest and get total weight 
	void CheckIfWinning();	//find if you have validated the objectives of 2000kg, use in GetHarvest()

	bool IsACherryTree(Tree*);
	bool IsAAppleTree(Tree*);
	bool IsAPearTree(Tree*);
	void PrintInfo(); //print all fruits number by type of trees

	void OutOfRangeTypeTree(int&, int); //Verified if you input to much type of tree, compare input to a max number
	void OutOfRangeTreeInPlantation(int&, int&, int); //Verified if you input to much tree, compare number type of tree to the max tree possible in plantation
	void ClearConsole();
};

