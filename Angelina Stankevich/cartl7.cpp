#include "cart.h"

vector<Composition> * Cart::getCompositions() 
{
	return &compositions;
}

vector<Album> * Cart::getAlbums() 
{
	return &albums;
}

int * Cart::getPrice() 
{
	return &price;
}