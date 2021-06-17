#pragma once

#include "musicalDirection.h"
#include "cart.h"
#include <fstream>

class Mp3All 
{
private:
	vector<Artist> allArtists;
	vector<Composition> allCompositions;
	vector<Album> allAlbums;
	vector<MusicalDirection> allMusicalDirections;
	Cart shopCart;
	ifstream fin;
	int countCompositions = 0;
	int countCompositionsSold = 0;
	int revenue = 0;

public:
	Mp3All();

	void addCompositions();
	void addAlbums();
	void addArtists();
	void addMusicalDirections();

	vector<MusicalDirection> getAllMusicalDirections();
	vector<Artist> getAllArtists();
	vector<Composition> getAllCompositions();
	vector<Album> getAllAlbums();

	Cart *getShopCart();

	int *getCountCompositionsSold();
	int *getRevenue();
	int getCountCompositions();
};