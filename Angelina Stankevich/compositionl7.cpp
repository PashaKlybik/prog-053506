#include "composition.h"

Composition::Composition(string name, string artistName, int price, string text) 
{
	this->name = name;
	this->artistName = artistName;
	this->price = price;
	this->text = text;
}

string Composition::getName()
{
	return name;
}

int Composition::getPrice() 
{
	return price;
}

string Composition::getArtistName() 
{
	return artistName;
}

string Composition::getText() 
{
	return text;
}