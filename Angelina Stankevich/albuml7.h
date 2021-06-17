#pragma once

#include "composition.h"
#include <vector>

class Album 
{
private:
    string name;
    string artistName;
    int price = 0;
    vector<Composition> compositions;

public:
    Album(string name, vector<Composition> compositions);
    int getPrice();
    string getName();
	vector<Composition> getCompositions();
};