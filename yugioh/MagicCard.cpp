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


#include "MagicCard.hpp"

MagicCard::MagicCard(const string name, const string effect, unsigned int rare, CardType type) : Card(name, effect, rare), type(type)
{
}

MagicCard::MagicCard(CardType type) : type(type)
{
}

MagicCard::~MagicCard()
{
}

MagicCard& MagicCard::operator=(const MagicCard& other)
{
	if (this != &other)
	{
		name = other.name;
		effect = other.effect;
		type = other.type;
		rarity = other.rarity;
	}
	return *this;
}

CardType MagicCard::getType() const
{
	return type;
}

string MagicCard::getClassName() const
{
	return "MagicCard";
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

string MagicCard::info() const
{
	string info, typeString;
	switch (type)
	{
	case CardType::buff: typeString = "buff"; break;
	case CardType::spell: typeString = "spell"; break;
	case CardType::trap: typeString = "trap"; break;
	}
	info.append(Card::info() + "Type: " + typeString + '\n');
	return info;
}

ostream& operator<<(ostream& o, const MagicCard& obj)
{
	string typeString;
	switch (obj.type)
	{
	case CardType::buff: typeString = "buff"; break;
	case CardType::spell: typeString = "spell"; break;
	case CardType::trap: typeString = "trap"; break;
	}
	return o << obj.name << "|" << obj.effect << '|' << obj.rarity << '|' << typeString << '\n';
}

istream& operator>>(istream& i, MagicCard& obj)
{
	string rarity, type;
	getline(i, obj.name, '|');
	getline(i, obj.effect, '|');
	getline(i, rarity, '|');
	getline(i, type);
	obj.rarity = stoi(rarity);
	if (type == "spell") obj.type = CardType::spell;
	else if (type == "trap") obj.type = CardType::trap;
	else obj.type = CardType::buff;
	return i;
}