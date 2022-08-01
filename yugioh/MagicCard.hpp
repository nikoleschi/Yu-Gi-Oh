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

enum class CardType
{
	trap,
	buff,
	spell,
	DEFAULT
};

class MagicCard : virtual public Card
{
protected:
	CardType type;
public:
	MagicCard(const string = "", const string = "", unsigned int = 0, CardType = CardType::DEFAULT);
	MagicCard(CardType);
	~MagicCard();
	MagicCard& operator=(const MagicCard&);

	CardType getType() const;

	string getClassName() const override;

	Card* clone() const override;
	string info() const;

	friend ostream& operator<<(ostream&, const MagicCard&);
	friend istream& operator>>(istream&, MagicCard&);
};