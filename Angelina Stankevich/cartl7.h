#pragma once

#include "album.h"

class Cart 
{
private:
	vector<Composition> compositions;
	vector<Album> albums;
	int price = 0;
public:
	vector<Composition> *getCompositions();
	vector<Album> *getAlbums();
	int *getPrice();
};