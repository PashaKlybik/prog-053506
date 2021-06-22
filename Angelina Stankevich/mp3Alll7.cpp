#include "mp3All.h"

Mp3All::Mp3All()
{
	fin.open("data.txt");
}

void Mp3All::addCompositions() 
{
	string str;
	getline(fin, str);
	while (str != "#") 
	{
		int i, tempPrice;
		string tempName, tempArtistName, tempText, strPrice;
		for (i = 0; str[i] != ' '; i++) 
		{
			tempName += str[i];
		}
		for (i += 1; str[i] != ' '; i++) 
		{
			tempArtistName += str[i];
		}
		for (i += 1; i < (int) str.size(); i++) 
		{
			strPrice += str[i];
		}
		tempPrice = stoi(strPrice);
		getline(fin, str, '!');
		tempText = str;
		Composition tempComposition(tempName, tempArtistName, tempPrice, tempText);
		allCompositions.push_back(tempComposition);
		countCompositions++;
		getline(fin, str);
		getline(fin, str);
	}
}

void Mp3All::addAlbums() 
{
	string str;
	getline(fin, str);
	while (str != "#") 
	{
		string tempName, strComposition;
		vector<Composition> tempCompositions;
		tempName = str;
		getline(fin, str);
		int i = 0;
		while (str[i] != '\0') 
		{
			for (i; str[i] != ' ' && str[i] != '\0'; i++) 
			{
				strComposition += str[i];
			}
			if (str[i] == ' ') 
			{
				i++;
			}
			for (Composition tempComposition : allCompositions) 
			{
				if (tempComposition.getName() == strComposition) 
				{
					tempCompositions.push_back(tempComposition);
				}
			}
		}
		Album tempAlbum(tempName, tempCompositions);
		allAlbums.push_back(tempAlbum);
		getline(fin, str);
	}
}

void Mp3All::addArtists() 
{
	string str;
	getline(fin, str, '#');
	while (str != "#") 
	{
		string strComposition, strAlbum, tempInfo;
		vector<Composition> tempCompositions;
		vector<Album> tempAlbums;
		int i = 0;
		while (str[i] != '\n') 
		{
			for (i; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++) 
			{
				strComposition += str[i];
			}
			for (Composition tempComposition : allCompositions) 
			{
				if (tempComposition.getName() == strComposition) 
				{
					tempCompositions.push_back(tempComposition);
				}
			}
			if (str[i] == ' ') 
			{
				i++;
			}
			else if (str[i] == '\0') 
			{
				break;
			}
		}
		if (str[i] != '\0') 
		{
			i++;
		}
		while (str[i] != '\0') 
		{
			for (i; str[i] != ' ' && str[i] != '\0'; i++) 
			{
				strAlbum += str[i];
			}
			if (str[i] == ' ') 
			{
				i++;
			}
			for (Album tempAlbum : allAlbums) 
			{
				if (tempAlbum.getName() == strAlbum) 
				{
					tempAlbums.push_back(tempAlbum);
				}
			}
		}
		getline(fin, str);
		getline(fin, str, '!');
		tempInfo = str;
		Artist tempArtist(tempCompositions, tempAlbums, tempInfo);
		allArtists.push_back(tempArtist);
		getline(fin, str);
		getline(fin, str);
		if (str != "#") 
		{
			string temp;
			getline(fin, temp, '#');
			str = str + '\n' + temp;
		}
	}
}

void Mp3All::addMusicalDirections() 
{
	string str;
	getline(fin, str);
	while (str != "#")
	{
		string tempName, strArtist, tempInfo;
		vector<Artist> tempArtists;
		tempName = str;
		getline(fin, str);
		int i = 0;
		while (str[i] != '\0') {
			for (i; str[i] != ' ' && str[i] != '\0'; i++) 
			{
				strArtist += str[i];
			}
			if (str[i] == ' ') 
			{
				i++;
			}
			for (Artist tempArtist : allArtists) 
			{
				if (tempArtist.getName() == strArtist) 
				{
					tempArtists.push_back(tempArtist);
				}
			}
		}
		getline(fin, str, '!');
		tempInfo = str;
		MusicalDirection tempMusicalDirection(tempName, tempArtists, tempInfo);
		allMusicalDirections.push_back(tempMusicalDirection);
		getline(fin, str);
		getline(fin, str);
	}
}

vector<MusicalDirection> Mp3All::getAllMusicalDirections() 
{
	return allMusicalDirections;
}

vector<Artist> Mp3All::getAllArtists() 
{
	return allArtists;
}

vector<Composition> Mp3All::getAllCompositions() 
{
	return allCompositions;
}


vector<Album> Mp3All::getAllAlbums() 
{
	return allAlbums;
}

Cart * Mp3All::getShopCart() 
{
	return &shopCart;
}

int * Mp3All::getCountCompositionsSold() 
{
	return &countCompositionsSold;
}

int * Mp3All::getRevenue() 
{
	return &revenue;
}

int Mp3All::getCountCompositions() 
{
	return countCompositions;
}