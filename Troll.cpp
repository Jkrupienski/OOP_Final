#include "Troll.h"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


Troll::Troll(int in_health) {
	health = in_health;

}


void Troll::set_name(string in_name) {
	name = in_name;

}

string Troll::boss_name() {
	return "Boss " + Opp::show_name();

}

string Troll::show_name() {
	return "Troll " + Opp::show_name();

}


int Troll::show_health() {
	return health;
}

int Troll::show_attack() {
	return attack;
}

int Troll::show_defense() {
	return defense;
}

int Troll::show_power() {
	return power;
}

void Troll::set_power(int in) {

	power = power + in;
}

void Troll::sub_power(int in) {

	power = power - in;
}



void Troll::set_health(int in) {
	health = health - in;

}