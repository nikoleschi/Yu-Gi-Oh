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

#include "Card.hpp"

Card::Card(const string& name, const string& eff, const unsigned int rare) : name(name), effect(eff), rarity(rare)
{
}

Card::~Card()
{
}

string Card::getName() const
{
	return name;
}

string Card::getEffect() const
{
	return effect;
}

unsigned int Card::getRarity() const
{
	return rarity;
}

string Card::info() const
{
	string info;
	info.append("Name: " + name + '\n' +"Effect: " + effect + '\n' + "Rarity: " + to_string(rarity) + '\n');
	return info;
}

bool Card::operator<(const Card& other) const
{
	return rarity < other.rarity;
}

bool Card::operator>(const Card& other) const
{
	return rarity > other.rarity;
}
