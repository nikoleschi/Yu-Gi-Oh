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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const string name, const string effect, unsigned int rare, unsigned int atk, unsigned int def)
	: Card(name, effect, rare), attackPoints(atk), defencePoints(def)
{
}

MonsterCard::MonsterCard(unsigned int atk, unsigned int def) : attackPoints(atk), defencePoints(def)
{
}

MonsterCard::~MonsterCard()
{
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
	if (this != &other)
	{
		name = other.name;
		effect = other.effect;
		attackPoints = other.attackPoints;
		defencePoints = other.defencePoints;
		rarity = other.rarity;
	}
	return *this;
}

unsigned int MonsterCard::getAtkPoints() const
{
	return attackPoints;
}

unsigned int MonsterCard::getDefPoints() const
{
	return defencePoints;
}

string MonsterCard::getClassName() const
{
	return "MonsterCard";
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

string MonsterCard::info() const
{
	string info;
	info.append(Card::info() + "Attack points: " + to_string(attackPoints) + '\n' + "Defence points: " + to_string(defencePoints) + '\n');
	return info;
}

ostream& operator<<(ostream& o, const MonsterCard& obj)
{
	return o << obj.name << '|' << obj.effect << '|' << obj.rarity << '|' << obj.attackPoints << '|' << obj.defencePoints << '\n';
}

istream& operator>>(istream& i, MonsterCard& obj)
{
	string rarity, atk, def;
	getline(i, obj.name, '|');
	getline(i, obj.effect, '|');
	getline(i, rarity, '|');
	getline(i, atk, '|');
	getline(i, def);
	obj.rarity = stoi(rarity);
	obj.attackPoints = stoi(atk);
	obj.defencePoints = stoi(def);
	return i;
}