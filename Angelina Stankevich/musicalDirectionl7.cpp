#include "musicalDirection.h"

MusicalDirection::MusicalDirection(string name, vector<Artist> artists, string  info) 
{
	this->name = name;
	this->info = info;
	this->artists = artists;
}

string MusicalDirection::getName() 
{
	return name;
}

string MusicalDirection::getInfo() 
{
	return info;
}

vector<Artist> MusicalDirection::getArtists() {
	return artists;
}