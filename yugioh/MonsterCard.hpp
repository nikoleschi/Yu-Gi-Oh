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
#include "Card.hpp"

class MonsterCard : virtual public Card
{
protected:
	unsigned int attackPoints;
	unsigned int defencePoints;
public:
	MonsterCard(const string = "", const string = "", unsigned int = 0, unsigned int = 0, unsigned int = 0);
	MonsterCard(unsigned int, unsigned int);
	~MonsterCard();

	MonsterCard& operator=(const MonsterCard&);

	unsigned int getAtkPoints() const;
	unsigned int getDefPoints() const;
	string getClassName() const override;

	Card* clone() const override;

	string info() const;

	friend ostream& operator<<(ostream&, const MonsterCard&);
	friend istream& operator>>(istream&, MonsterCard&);
};