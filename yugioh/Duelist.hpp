/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nikola Mihaylov
* @idnumber 62579
* @task 1
* @compiler VC
*/

#pragma once
#include "Deck.hpp"
#include <fstream>

class Duelist
{
	string duelistName;
	Deck d;

public:
	Duelist(const string & = "");
	Duelist(const string &, const Deck&);
	
	Deck& getDeck();
	void setDeck(const Deck&);

	bool saveDeck(const char*);
	bool loadDeck(const char*);

	void setName(const string&);
	string getName() const;

	void duel(Duelist&);
};

