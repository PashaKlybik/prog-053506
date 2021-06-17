#include "album.h"

Album::Album(string name, vector<Composition> compositions) 
{
	this->name = name;
	this->artistName = compositions[0].getArtistName();

	for (int i = 0; i < (int) compositions.size(); i++)
	{
		this->price += compositions[i].getPrice();
	}
	this->compositions = compositions;
}

int Album::getPrice() 
{
	return price;
}

string Album::getName() 
{
	return name;
}

vector<Composition> Album::getCompositions() 
{
	return compositions;
}