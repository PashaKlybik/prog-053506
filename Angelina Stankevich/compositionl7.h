#pragma once

#include <string>
using namespace std;

class Composition
{
private:
	string name;
	string artistName;
	string text;
	int price;

public:
	Composition(string name, string artistName, int price, string text);
	string getName();
	int getPrice();
	string getArtistName();
	string getText();
};