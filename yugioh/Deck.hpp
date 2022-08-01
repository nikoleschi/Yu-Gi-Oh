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
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "PendulumCard.hpp"

class Deck
{
	string deckName;
	vector<Card*> deck;
	void clean_clones();
	void copy_clones(const vector<Card*>);

public:
	Deck(const string & = "");
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	~Deck();

	Card* operator[](int);

	unsigned int countMonsters() const;
	unsigned int countMagics() const;
	unsigned int countPendulums() const;
	unsigned int countAll() const;

	void addCard(Card*);
	void setCard(unsigned int, Card*);
	void clearDeck();

	void sortDeck();
	void shuffleDeck();

	friend ostream& operator<<(ostream&, const Deck&);
	friend istream& operator>>(istream&, Deck&);
	string info();

	void setDeckname(const string&);
	string getDeckname() const;
};