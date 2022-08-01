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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard(const string name, const string effect, unsigned int rare, unsigned int atk, unsigned int def, unsigned int scale, CardType type)
	: Card(name, effect, rare), MonsterCard(atk, def), MagicCard(type), pendulumScale(scale)
{
}

PendulumCard::~PendulumCard()
{
}

PendulumCard& PendulumCard::operator=(const PendulumCard& other)
{
	if (this != &other)
	{
		name = other.name;
		effect = other.effect;
		attackPoints = other.attackPoints;
		defencePoints = other.defencePoints;
		type = other.type;
		pendulumScale = other.pendulumScale;
	}
	return *this;
}

unsigned int PendulumCard::getScale() const
{
	return pendulumScale;
}

string PendulumCard::getClassName() const
{
	return "PendulumCard";
}

Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

string PendulumCard::info() const
{
	string info, typeString;
	switch (type)
	{
	case CardType::buff: typeString = "buff"; break;
	case CardType::spell: typeString = "spell"; break;
	case CardType::trap: typeString = "trap"; break;
	}
	info.append(MonsterCard::info() + "Pendulum scale: " + to_string(pendulumScale) + '\n' + "Type: " + typeString + '\n');
	return info;
}

ostream& operator<<(ostream& o, const PendulumCard& obj)
{
	string typeString;
	switch (obj.type)
	{
	case CardType::buff: typeString = "buff"; break;
	case CardType::spell: typeString = "spell"; break;
	case CardType::trap: typeString = "trap"; break;
	}
	return o << obj.name << '|' << obj.effect << '|' << obj.rarity << '|' << obj.attackPoints << '|'
		<< obj.defencePoints << '|' << obj.pendulumScale << '|' << typeString << '\n';
}

istream& operator>>(istream& i, PendulumCard& obj)
{
	string rarity, atk, def, scale, type;
	getline(i, obj.name, '|');
	getline(i, obj.effect, '|');
	getline(i, rarity, '|');
	getline(i, atk, '|'); 
	getline(i, def, '|');
	getline(i, scale, '|');
	getline(i, type);
	obj.rarity = stoi(rarity);
	obj.attackPoints = stoi(atk);
	obj.defencePoints = stoi(def);
	obj.pendulumScale = stoi(scale);
	if (type == "spell") obj.type = CardType::spell;
	else if (type == "trap") obj.type = CardType::trap;
	else obj.type = CardType::buff;
	return i;
}