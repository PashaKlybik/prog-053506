#include "artist.h"

Artist::Artist(vector<Composition> compositions, vector<Album> albums, string  info) 
{
	this->name = compositions[0].getArtistName();
	this->info = info;
	this->compositions = compositions;
	this->albums = albums;
}

string Artist::getName() 
{
	return name;
}

string Artist::getInfo()
{
	return info;
}

vector<Album> Artist::getAlbums() 
{
	return albums;
}

vector<Composition> Artist::getCompositions() 
{
	return compositions;
}