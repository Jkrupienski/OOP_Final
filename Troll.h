#pragma once
#include <string>
#include "Human.h"
#include "Opp.h"

using std::string;

class Troll: public Opp

{

protected:
	int power = 100;
	int defense = 120;
	int attack = 55;
	int health = 0;
	

public:
	
	string boss_name(); // displays name with boss in front
	int show_attack(); // displays current attack
	int show_defense(); // displays current defense
	int show_power(); // displays current power
	Troll(int in_health);
	void set_name(string in_name); // sets name of object
	void set_health(int in); // sets health
	void set_power(int in); // sets power 
	void sub_power(int in); // subtracts power 
	string show_name(); // shows troll + whatever it is named

	int show_health(); // displays current health
	






};

