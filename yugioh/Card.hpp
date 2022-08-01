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
#include <string>
#include <iostream>
using namespace std;

class Card
{
protected:
	string name;
	string effect;
	unsigned int rarity;
public:
	Card(const string& name = "", const string & = "", const unsigned int = 0);
	virtual ~Card() = 0;
	virtual Card* clone() const = 0;
	virtual string getClassName() const = 0;

	string getName() const;
	string getEffect() const;
	unsigned int getRarity() const;

	string info() const;
	bool operator<(const Card&) const;
	bool operator>(const Card&) const;

};