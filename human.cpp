#include "Human.h"
#include "Troll.h"
#include<iostream>

using std::endl;
using std::cout;

Human::Human() {

}
Human::Human(string in_name, int in_health) {

	name = in_name;


}

void Human::set_health(int in_health) {
	health = in_health;

}

void Human::set_power(int in_power) {
	power = in_power;


}


void Human::change_power(int in_num) {

	power = power + in_num;
	max_power = power;
}
void Human::change_defense(int in_num) {
	defense = defense + in_num;
}
void Human::change_attack(int in_num) {
	attack = attack + in_num;
}
void Human::change_health(int in_num) {
	health = health - in_num;
}

void Human::sub_power(int in_num) {

	power = power - in_num;
}

void Human::add_health(int in_health) {

	health = health + in_health;
}



int Human::show_health() {

	return health;
}


int Human::show_power() {

	return power;
}
int Human::show_defense() {

	return defense;
}
int Human::show_attack() {
	return attack;
}


string Human::show_name() {

	return name;
}

void Human::set_name(string in_name) {

	name = in_name;
}



// fan the hammer attack
void Human::fan( int roll, Human& self) {
	if (roll <= 5) {
		cout << "Your gun has no bullets! You fail at fanning the hammer!" << endl;
		self.sub_power(40);

	}
	else if (roll > 5 && roll <= 10) {
		cout << "You fan the hammer and one of the bullets connect with your opponent!" << endl;
		self.sub_power(35);
	}
	else if (roll > 10 && roll <= 15) {
		cout << "You fan the hammer and half the bullets connect with your opponent!" << endl;
		self.sub_power(25);
		

	}
	else if (roll > 15 && roll <= 19) {
		cout << "You fan the hammer and nearly all the bullets strike your opponent!" << endl;
		self.sub_power(15);

	}
	else if (roll == 20) {
		cout << "You fan the hammer connecting every bullet with your opponent landing a critical hit!" << endl;
		
	}

}


// pistol whip attack
void Human::pistol_whip(int roll, Human& self) {

	if (roll <= 5) {
		cout << "You whiff your pistol whip!" << endl;
		self.sub_power(15);

	}
	else if (roll > 5 && roll <= 10) {
		cout << "You swing your sidearm smacking your opponent weakly" << endl;
		self.sub_power(10);

	}
	else if (roll > 10 && roll <= 15) {
		cout << "You hit your opponent with your sidearm!" << endl;
		self.sub_power(10);
		

	}
	else if (roll > 15 && roll <= 19) {
		cout << "You pistol whip your opponent over the back of their head making them physically dazed!" << endl;
		self.sub_power(10);

	}
	else if (roll == 20) {
		cout << "You pistol whip your opponent, striking them dead on their forehead causing them to stumble away from you" << endl;
		self.sub_power(5);
	}


}

// method for the hero using the precision shot attack
void Human::precision_shot( int roll, Human& self) {

	if (roll <= 5) {
		cout << "You aim your pistol, but miss your shot at the opponent" << endl;
		self.sub_power(35); // takes away hero power

	}
	else if (roll > 5 && roll <= 10) {
		cout << "You aim your pistol and fire, your bullet graze the opponent. It appears to be but only a flesh wound" << endl;
		self.sub_power(30);

	}
	else if (roll > 10 && roll <= 15) {
		cout << "You take aim with your pistol, your shot strikes the opponent in their arm!" << endl;
		self.sub_power(25);
		

	}
	else if (roll > 15 && roll <= 19) {
		cout << "You aim your pistol and fire, you strike the opponent in their chest dealing great damage" << endl;
		self.sub_power(20);


	}
	else if (roll == 20) {
		cout << "You draw your pistol and prepare a precise shot. You fire and strike an artery on your opponent doing a critical amount of damage" << endl;
		
		self.sub_power(15);
	}

}

void Human::healing_pot(Human& self, int roll) {
	if (self.potions > 0) { // checks the dice roll to know how much health to give
		if (roll > 0 && roll <= 10) {
			self.potions = self.potions - 1;
			self.add_health(25);
			cout << "You use a health potion, it restores a small piece of your health!" << endl;
		}
		else if (roll > 10 && roll <= 19) {
			self.potions = self.potions - 1;
			self.add_health(50);
			cout << "You use a health potion, it restoring a chunk of your health!" << endl;
		}
		else if (roll == 20) {
			self.potions = self.potions - 1;
			self.add_health(100);
			cout << "You use a health potion, you receive a large amount of your health!" << endl;
		}

	}
	else { // displays if the number of potions is 0
		cout << "You do not have any healing potions!" << endl;


	}
}




Human::~Human() {


}
