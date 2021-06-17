#pragma once

#include "album.h"

class Artist 
{
private:
	string name;
	string info;
	vector<Composition> compositions;
	vector<Album> albums;

public:
	Artist(vector<Composition> compositions, vector<Album> albums, string  info);
	string getName();
	string getInfo();
	vector<Album> getAlbums();
	vector<Composition> getCompositions();
};