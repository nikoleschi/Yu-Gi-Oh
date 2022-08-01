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

#include "Duelist.hpp"

Duelist::Duelist(const string& name) : duelistName(name)
{
}

Duelist::Duelist(const string& name, const Deck& deck) : duelistName(name), d(deck)
{
}

Deck& Duelist::getDeck()
{
	return d;
}

void Duelist::setDeck(const Deck& newDeck)
{
	d = newDeck;
}

bool Duelist::saveDeck(const char* filename)
{
	ofstream file;
	file.open(filename);
	if (!file.is_open()) return false;
	d.sortDeck();
	file << d;
	file.close();
	return true;
}

bool Duelist::loadDeck(const char* filename)
{
	ifstream file;
	file.open(filename);
	if (!file.is_open()) return false;
	d.clearDeck();
	file >> d;
	file.close();
	return true;
}

void Duelist::setName(const string& newName)
{
	duelistName = newName;
}

string Duelist::getName() const
{
	return duelistName;
}

void Duelist::duel(Duelist& second)
{
	srand(time(0));
	if (d.countAll() != second.d.countAll())
	{
		cout << "The duelists havent got the same number of cards! The duel cannot be held!\n";
		return;
	}
	d.shuffleDeck();
	second.d.shuffleDeck();
	int result = 0;
	for (unsigned int i = 0;i < d.countAll();++i)
	{
		if (*d[i] > *second.d[i]) ++result;
		else if (*d[i] < *second.d[i]) --result;
	}
	if (result == 0) cout << "Draw!\n";
	else if (result > 0) cout << getName() << " (first duelist) wins!\n";
	else cout << second.getName() <<" (second duelist) wins!\n";
}
