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

#include <iostream>
#include "Duelist.hpp"
using namespace std;

int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::spell);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::trap);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::spell);
	MagicCard box("Mystic Box", "Destroy one monster.", 2, CardType::spell);
	
	Deck magician_deck;
	magician_deck.addCard(&dragon);
	magician_deck.addCard(&magician);
	magician_deck.addCard(&swords);
	magician_deck.addCard(&cylinder);
	magician_deck.addCard(&timegazer);

	Duelist firstDuelist("Nikola Mihaylov", magician_deck);
	firstDuelist.getDeck().setDeckname("Magician Deck");

	/*
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&timegazer);
	*/

	cout << firstDuelist.getDeck().info() << endl;
	firstDuelist.saveDeck("magician_deck.txt");
	
	cout << "------------------------------------\n";
	cout << firstDuelist.getDeck()[2]->info()<<endl;
	firstDuelist.getDeck().setCard(2, &box);
	cout << firstDuelist.getDeck()[2]->info();
	cout << "------------------------------------\n\n";

	firstDuelist.getDeck().setCard(2, &swords);

	firstDuelist.loadDeck("new_deck.txt");
	cout << firstDuelist.getDeck() << endl;
	
	firstDuelist.loadDeck("magician_deck.txt");
	
	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck().setDeckname("Gosho's deck");
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);
	cout << "First duel result: ";
	firstDuelist.duel(secondDuelist);
	cout << "\nCleared deck:\n";

	secondDuelist.getDeck().clearDeck();
	cout << secondDuelist.getDeck() << endl << endl;

	secondDuelist.loadDeck("new_deck.txt");
	MonsterCard exodia("Exodia the Forbidden One", "Automatically win the duel", 6969, INT_MAX - 1, INT_MAX - 1);
	firstDuelist.getDeck().addCard(&box);
	firstDuelist.getDeck().addCard(&exodia);
	
	cout << "Second duel result: ";
	firstDuelist.duel(secondDuelist);
}