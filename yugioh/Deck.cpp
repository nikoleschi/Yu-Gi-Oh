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

#include "Deck.hpp"

void Deck::clean_clones()
{
	for (auto x : deck) delete x;
}

void Deck::copy_clones(const vector<Card*> other)
{
	for (auto x : other) deck.push_back(x->clone());
}

Deck::Deck(const string& name) : deckName(name)
{
}

Deck::Deck(const Deck& copy)
{
	copy_clones(copy.deck);
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		clean_clones();
		copy_clones(other.deck);
	}
	return *this;
}

Deck::~Deck()
{
	clean_clones();
}

Card* Deck::operator[](int index)
{
	return deck[index];
}

unsigned int Deck::countMonsters() const
{
	unsigned int counter = 0;
	for (auto x : deck)
		if (x->getClassName() == "MonsterCard") ++counter;
	return counter;
}

unsigned int Deck::countMagics() const
{
	unsigned int counter = 0;
	for (auto x : deck)
		if (x->getClassName() == "MagicCard") ++counter;
	return counter;
}

unsigned int Deck::countPendulums() const
{
	unsigned int counter = 0;
	for (auto x : deck)
		if (x->getClassName() == "PendulumCard") ++counter;
	return counter;
}

unsigned int Deck::countAll() const
{
	return deck.size();
}

void Deck::addCard(Card* newCard)
{
	deck.push_back(newCard->clone());
}

void Deck::setCard(unsigned int index, Card* newCard)
{
	if (newCard->getClassName() == deck[index]->getClassName())
	{
		delete deck[index];
		deck[index] = newCard->clone();
		return;
	}
	cout << "The type of the new card is not the same as the type of the card with index " << index << "\n";
}

void Deck::clearDeck()
{
	clean_clones();
	deck.clear();
}

void Deck::sortDeck()
{
	vector<Card*> newDeck;
	unsigned countMon = 0, countMag = 0, countPend = 0;
	for (unsigned int i = 0;i < countAll();++i) newDeck.push_back(nullptr);
	for (unsigned int i = 0;i < countAll();++i)
	{
		if (deck[i]->getClassName() == "MonsterCard")
		{
			newDeck[countMon] = deck[i];
			++countMon;
		}
		else if (deck[i]->getClassName() == "MagicCard")
		{
			newDeck[countMonsters() + countMag] = deck[i];
			++countMag;
		}
		else
		{
			newDeck[countMonsters() + countMagics() + countPend] = deck[i];
			++countPend;
		}
	}
	deck = newDeck;
}

void Deck::shuffleDeck()
{
	random_shuffle(deck.begin(), deck.end());
}

string Deck::info()
{
	string info;
	info.append("Deck name: " + deckName + '\n');
	for (auto x : deck) info.append(x->info() + '\n');
	return info;
}

void Deck::setDeckname(const string& newName)
{
	deckName = newName;
}

string Deck::getDeckname() const
{
	return deckName;
}

ostream& operator<<(ostream& o, const Deck& obj)
{
	o << obj.deckName << '|' << obj.countAll() << '|' << obj.countMonsters() << '|' << obj.countMagics() << '|' << obj.countPendulums() << "\n";
	for (unsigned int i = 0;i < obj.countMonsters();++i)
	{
		auto monsterPtr = dynamic_cast<MonsterCard*>(obj.deck[i]);
		o << *monsterPtr;
	}
	for (unsigned int i = obj.countMonsters();i < obj.countMagics() + obj.countMonsters();++i)
	{
		auto magicPtr = dynamic_cast<MagicCard*>(obj.deck[i]);
		o << *magicPtr;
	}
	for (unsigned int i = obj.countMagics() + obj.countMonsters();i < obj.countAll();++i)
	{
		auto pendulumPtr = dynamic_cast<PendulumCard*>(obj.deck[i]);
		o << *pendulumPtr;
	}
	return o;
}

istream& operator>>(istream& in, Deck& obj)
{
	string countMon, countMag, countPend;
	getline(in, obj.deckName, '|');
	getline(in, countMon, '|');
	getline(in, countMon, '|');
	getline(in, countMag, '|');
	getline(in, countPend);
	for (int i = 0;i < stoi(countMon);++i)
	{
		MonsterCard newMonster;
		in >> newMonster;
		obj.addCard(&newMonster);
	}
	for (int i = 0;i < stoi(countMag);++i)
	{
		MagicCard newMagic;
		in >> newMagic;
		obj.addCard(&newMagic);
	}
	for (int i = 0;i < stoi(countPend);++i)
	{
		PendulumCard newPendulum;
		in >> newPendulum;
		obj.addCard(&newPendulum);
	}
	return in;
}