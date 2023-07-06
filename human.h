#pragma once
#include <string>

#include "Troll.h"

using std::string;



class Human
{
	string name; // name variable 

protected:
	int power = 100;
	int defense = 100;
	int attack = 100;
	int health = 100;
	int max_power = 0;


public:
	int potions = 0; // number of potions 
	Human();
	Human(string in_name, int in_health);


	string show_name();
	void set_name(string in_name);
	int show_power(); // displays current power
	int show_defense(); // displays defense info
	int show_attack(); // displays attack info
	int show_health(); // displays health
	void add_health(int in_health); // increases health



	void change_power(int in_num); // adds to power
	void change_defense(int in_num); // adds to defense
	void change_attack(int in_num); // adds to attack
	void set_health(int in_health); // sets health of object
	void change_health(int in_num); // subtracts health
	void sub_power(int in_num); // subtract power 
	void set_power(int in_power); // sets power

	// attack methods
	void fan( int roll, Human& self);
	void pistol_whip( int roll, Human& self);
	void precision_shot( int roll, Human& self);

	void healing_pot(Human& self, int roll); // healing potion method


	~Human();

};

