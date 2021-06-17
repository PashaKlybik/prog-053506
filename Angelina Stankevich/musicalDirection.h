#pragma once

#include "artist.h"

class MusicalDirection
{
private:
	string name;
	string info;
	vector<Artist> artists;

public:
	MusicalDirection(string name, vector<Artist> artists, string  info);

	string getName();

	string getInfo();

	vector<Artist> getArtists();
};