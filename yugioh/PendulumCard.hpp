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
#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard
{
	unsigned int pendulumScale;

public:
	PendulumCard(const string = "", const string = "", unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 1, CardType = CardType::DEFAULT);
	~PendulumCard();
	PendulumCard& operator=(const PendulumCard&);

	unsigned int getScale() const;

	string getClassName() const override;

	Card* clone() const override;
	string info() const;

	friend ostream& operator<<(ostream&, const PendulumCard&);
	friend istream& operator>>(istream&, PendulumCard&);
};