#pragma once
#include "Tree.h"

class CherryTree : public Tree {
public:
    CherryTree();
    void StartHarvest(Month) override;
};

