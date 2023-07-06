#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "Human.h"
#include <time.h>
#include "Troll.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

string hero_Name;

string boss;
int cpuRoll = 0;
int attribute_Points = 3;
int cpuIn = 0;
int in = 0;
int b1 = 0;
int b2 = 0;
int roll = 0;
int shack = 0;
int user_choice = 0;
int hero_roll = 0;
int hut = 0;
int cave = 0;

string final_name;
string enter;


int roll_Dice();


int main() {

	cout << "-----------------------------------------------------" << endl
		<< "              Welcome to Bandersnatch" << endl
		<< "-----------------------------------------------------" << endl << endl << endl;




	cout << "Welcome to the character creator, please assign your name and attribute points" << endl;
	cout << "Name:";
	cin >> hero_Name;
	cout << endl;


	Human Hero(hero_Name, 100); // Creates your character

	while (attribute_Points > 0) { // Assigning attribute
		cout << "1: Defense" << endl;
		cout << "2: Power" << endl;
		cout << "3: Attack" << endl;
		cout << "Attribute points:" << attribute_Points << endl;

		cin >> in;
		switch (in) {
		case 1:
			Hero.change_defense(10);
			attribute_Points -= 1;
			break;

		case 2:
			Hero.change_power(10);
			attribute_Points -= 1;
			break;

		case 3:
			Hero.change_attack(10);
			attribute_Points -= 1;
			break;

		}


	}
	// shows point distribution to player
	cout << endl;
	cout << "Your attribute point distribution: " << endl;
	cout << "Power: " << Hero.show_power() << endl;
	cout << "Attack: " << Hero.show_attack() << endl;
	cout << "Defense: " << Hero.show_defense() << endl;


	cout << "What would you like to name a potential opponent?" << endl; // input first boss name
	cin >> final_name;

	cout << "And your final opponent?" << endl; // input final boss name
	cin >> boss;


	cout << "~Your adventure begins now~ echoes a booming voice" << endl; // dialogue starts


	cout << "Narrator: You wakeup to a dark figure standing above you" << endl;
	system("pause");
	cout << endl;


	cout << "Unknown Person: You really took a hard fall under there didn't ya!" << endl;
	cout << Hero.show_name() << ": under where?" << endl;
	cout << "Person: HAHAHA you said underwear, but seriously looks like you took quite the spill!" << endl << "Whats your name?" << endl;

	system("pause");
	cout << endl;
	cout << Hero.show_name() << ": My name is " << Hero.show_name() << " i'm a gunslinger out looking for adventure, I guess I must have hit fell and hit my head on this rock." << endl << " Who are you though?" << endl;;

	system("pause");
	cout << endl;

	cout << "Xlevi: The names Xlevi! I was out foraging when I came across you all sprawled out on the ground. If it's adventure you seek I may just have the thing for you however." << endl;
	cout << "Xlevi: A pesky couple of trolls have been bothering the nearbye townfolk, I am sure that if you helped defeat it the townspeople would reward you handsomely for your actions." << endl;

	system("pause");
	cout << endl;

	cout << Hero.show_name() << ": That's exactly the type of thing I am looking for!" << endl;
	cout << "Do you have any information on the whereabouts of this these trolls Xlevi ? " << endl;

	system("pause");
	cout << endl;

	cout << "Xlevi: Rumors are going around that it resides at the top of that mountain" << endl;
	cout << "~~Xlevi motions to a tall moutain in the distance~~" << endl;
	cout << "I do warn you though, there are many viscious creatures you may run into on this journey, which is why I am gifting you with these three health potions" << endl;
	Hero.potions = Hero.potions + 3; // 3 potions added to inventory
	cout << "~You obtained three health potions!~~" << endl;
	cout << "Potion Inventory: " << Hero.potions << endl;

	system("pause");
	cout << endl;

	cout << "Xlevi: I wish you the best on this adventure, I hope to see you come back victorious" << endl;

	system("pause");
	cout << endl;


	cout << "~You set out on your adventure up the mountainside, however your travels are quickly cut short by a Troll, much smaller than they usually are, blocking the bridge you are attempting to cross" << endl;

	system("pause");

	Troll Beast(110); // first opponent created
	Beast.set_name(final_name); // sets their name from earlier inputs

	cout << Beast.show_name() << ": RAAAAAAAHHHHHHHHHHHHHHH " << endl;

	cout << "~You Enter Battle with the Troll" << endl;
	system("pause");

	

	while (Hero.show_health() > 0 && Beast.show_health() > 0) { // First Troll battle

		cout << "Select your move: " << endl;
		cout << "1: Fan the hammer" << endl;
		cout << "2: Pistol Whip" << endl;
		cout << "3: Precision Shot" << endl;
		cout << "4: Healing potion" << endl;



		cin >> user_choice;
		hero_roll = roll_Dice(); // assigns the random number 1-20 to hero's dice roll



		if (Hero.show_power() > 0) { // checks to make sure you have some power
			switch (user_choice)
			{
			case 1:
				if (Hero.show_power() >= 40) // need a minimum of 40 power to use attack
				{
					cout << "You roll a " << hero_roll << endl;
					system("pause");
					Hero.fan(hero_roll, Hero); // hero roll impacting amount of power taken from hero

					if (hero_roll <= 5) { // hero roll impacting damage done to Troll
						Beast.set_health(5);

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Beast.set_health(10);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Beast.set_health(15);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Beast.set_health(25);

					}
					else if (hero_roll == 20) {
						Beast.set_health(35);

					}

					system("pause");
				}
				else { // if you don't have enoough power you're given more power but your turn is skipped
					cout << "You don't have enough power to Fan the Hammer!" << endl;
					Hero.change_power(40);
					system("pause");
				}
				break;

			case 2:


				if (Hero.show_power() >= 15) {
					cout << "You roll a " << hero_roll << endl;
					Hero.pistol_whip(hero_roll, Hero);
					system("pause");

					if (hero_roll <= 5) {
						Beast.set_health(5);

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Beast.set_health(10);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Beast.set_health(10);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Beast.set_health(10);

					}
					else if (hero_roll == 20) {
						Beast.set_health(15);

					}

				}
				else {
					cout << "You don't have enough power to pistol whip!" << endl;
					Hero.change_power(40);
					system("pause");
				}


				break;
			case 3:
				cout << "You roll a " << hero_roll << endl;
				if (Hero.show_power() >= 35) {
					Hero.precision_shot(hero_roll, Hero);

					system("pause");

					if (hero_roll <= 5) {
						Beast.set_health(10);

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Beast.set_health(15);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Beast.set_health(25);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Beast.set_health(35);

					}
					else if (hero_roll == 20) {
						Beast.set_health(40);

					}


				}
				else {
					cout << "You don't have enough power to take a precision shot!!" << endl;
					Hero.change_power(40);
					system("pause");
				}


				break;

			case 4:
				cout << "You roll a " << hero_roll << endl;
				Hero.healing_pot(Hero, hero_roll);

				system("pause");

				break;
			}
		}
		else {
			cout << "You Don't have enough power to attack! Your turn is skipped!" << endl;
			Hero.change_power(50);
			system("pause");

		}


		cpuIn = (rand() % 3) + 1; // Troll has 3 potential rolls 
		cpuRoll = roll_Dice();

		if (Beast.show_power() > 0) {
			switch (cpuIn)
			{
			default:
			case 1:
				cout << "The Troll rolls a " << cpuRoll << endl; // outputs Troll roll


				if (cpuRoll <= 10) {
					Hero.change_health(15);
					cout << "The Troll picks up a chunk of earth, throwing it at you" << endl;

				}
				else if (cpuRoll > 10 && cpuRoll < 20) {
					Hero.change_health(25);
					cout << "The Troll picks up a large boulder, hucking it at you" << endl;

				}
				else if (cpuRoll == 20) {
					Hero.change_health(45);
					cout << "The Troll picks up a large mass of the ground and hurls it at you landing a critical hit" << endl;
				}

				
				system("pause");

				break;
			case 2:
				cout << "The Troll rolls a " << cpuRoll << endl;

				if (cpuRoll <= 10) {
					Hero.change_health(20);
					cout << "The troll slashes at you with its claws" << endl;
				}
				else if (cpuRoll > 10 && cpuRoll < 20) {
					Hero.change_health(40);
					cout << "The troll lunges at you and swipes at you with its large hands" << endl;
				}
				else if (cpuRoll == 20) {
					Hero.change_health(15);
					cout << "The troll bolts at you, swiping with its large sharp hands dealing a critical hit" << endl;
				}


				system("pause");
				break;
			case 3:
				cout << "The Troll stands and does nothing, trolls aren't the smartest afterall" << endl;
				break;

			}

		}
		else {
			cout << "The Troll didn't have enough power to attack!, their turn is skipped!" << endl;
			Beast.set_power(50);
			system("pause");

		}

		// check if hero dies and end game
		if (Hero.show_health() <= 0) {
			cout << Hero.show_name() << " Health: " << Hero.show_health() << endl;
			cout << "~Your quest has come to an end~" << endl;
			cout << "----------GAME OVER----------" << endl;
			return 0;
		}

		// Both you and opponent gain 10 more power after each round
		Hero.change_power(10); 
		Beast.set_power(10);


		// shows both objects health
		cout << Beast.show_name() << " Health: " << Beast.show_health() << endl;
		cout << endl;
		cout << Hero.show_name() << " Health: " << Hero.show_health() << endl;
		cout << Hero.show_name() << " Power: " << Hero.show_power() << endl;


		//check if Troll is dead
		if (Beast.show_health() <= 0) {
			cout << "As you land your last blow, the Troll drops to the ground" << endl;
			cout << "You have defeated the Troll, and may continue on across the bridge" << endl;
			Hero.set_power(100);

			system("pause");
		}

	}

	// dialogue 
	cout << "You cross the bridge, off in the distance you see a small hut, you have reason to believe it is occupied from the smoke coming from its chimney" << endl;


	cout << "Do you knock on the door of the small hut or continue onward up the mountainside?" << endl;
	// given the decision to choose hut path or walking path

	while ((hut != 1) && (hut != 2)) {

		cout << "1: Knock on the door" << endl;
		cout << "2: Continue onward" << endl;
		cin >> hut;

		// makes sure only 1 and 2 work for inputs
		if ((hut != 1) && (hut != 2)) {
			cout << "Not an option, try again" << endl;
		}

	}

	// start of the 1 selected path
	if (hut == 1) {

		cout << "~You approach the hut and knock on the door~" << endl;
		cout << "Unknown: COMING" << endl;

		system("pause");
		cout << "~The door flies open and you are met with a short older woman~" << endl;
		system("pause");

		cout << "Unknown: Oh Dear you do look exhausted please do come in and rest!" << endl;
		cout << "~You follow the woman inside the small hut" << endl;
		system("pause");

		cout << "Rachel: The names Rachel, you can stay and rest in my hut for the night" << endl;
		cout << hero_Name << ": Your generosity is appreciated" << endl;

		system("pause");
		cout << "~You rest for the night regaining your health~" << endl;
		// sets the hero back to their full health
		Hero.set_health(100);
		system("pause");

		cout << "~Morning comes and you thank Rachel for the place to rest~" << endl;



	}
	// start of the two selected path
	else if (hut == 2) {
		cout << "~Tired and in very much still in need of rest you push onward up the mountainside~" << endl;



	}

	cout << "As you continue onward on your journey you notice a shiny object out of the corner of your eye..." << endl;

	// another player decision 
	while ((b2 != 1) && (b2 != 2)) {
		cout << "1: Investigate the shiny object" << endl;
		cout << "2: Continue walking on" << endl;
		cin >> b2;

		if ((b2 != 1) && (b2 != 2)) {
			cout << "Not an option, try again" << endl;
		}

	}
	// player inputs 1 path
	if (b2 == 1) {

		cout << "You walk over to where you saw the shiny object." << endl;

		cout << "Sticking out of the ground is a power bonus" << endl;

		Hero.change_power(10);

		cout << "Your current power is now: " << Hero.show_power() << endl;
		system("pause");

	}
	// player inputs 2 path
	else if (b2 == 2) {
		cout << "~You decide the shiny object is not worth your time~" << endl;
		system("pause");
	}



	cout << "You finally reach the entrance to the cave, you notice that it splits down to tunnels though" << endl;

	// cave optinos
	while ((cave != 1) && (cave != 2)) {
		cout << "As you begin to enter the cave you notice it branches two ways" << endl;
		cout << "1: Go to the left tunnel" << endl;
		cout << "2: Go to the right tunnel" << endl;
		cin >> cave;

		if ((cave != 1) && (cave != 2)) {
			cout << "Not an option, try again" << endl;
		}

	}
	// Troll boss is created
	Troll Boss(185);
	Boss.set_name(boss); // sets the name of boss to whatever was input in the beginning for the final boss name

	if (cave == 1) {

		cout << "You wander down the left tunnel" << endl;





	}
	else if (cave == 2) {
		cout << "You wander down the right tunnel and feel a great aura surrounding you" << endl;
		cout << "~Xlevi's presence grants you additional power to use in battle" << endl;

		system("pause");
		Hero.change_power(30); // gives you 30 more power going into the final boss

		cout << "Your current power is now: " << Hero.show_power() << endl;

		system("pause");
	}

	cout << "As you walk further you the walls widen and you begin to enter a large room, standing in the middle is the Troll Boss" << endl;

	cout << "~You Enter Battle with the Troll Boss~" << endl;

	// start of final battle

	while (Hero.show_health() > 0 && Boss.show_health() > 0) {

		cout << "Select your move: " << endl;
		cout << "1: Fan the hammer" << endl;
		cout << "2: Pistol Whip" << endl;
		cout << "3: Precision Shot" << endl;
		cout << "4: Healing potion" << endl;



		cin >> user_choice;
		hero_roll = roll_Dice();



		if (Hero.show_power() > 0) { // checks if you have any power
			switch (user_choice)
			{
			case 1:
				if (Hero.show_power() >= 40) // checks if you have more than the max required power
				{
					cout << "You roll a " << hero_roll << endl;
					system("pause");
					Hero.fan(hero_roll, Hero);

					if (hero_roll <= 5) { // damage to troll is dependent on the dice rolls
						Boss.set_health(5); 

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Boss.set_health(10);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Boss.set_health(15);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Boss.set_health(25);

					}
					else if (hero_roll == 20) {
						Boss.set_health(35);

					}

					system("pause");
				}
				else {
					cout << "You don't have enough power to Fan the Hammer!" << endl;
					Hero.change_power(40);
					system("pause");
				}
				break;

			case 2:


				if (Hero.show_power() >= 15) {
					cout << "You roll a " << hero_roll << endl;
					Hero.pistol_whip(hero_roll, Hero);
					system("pause");

					if (hero_roll <= 5) {
						Boss.set_health(5);

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Boss.set_health(10);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Boss.set_health(10);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Boss.set_health(10);

					}
					else if (hero_roll == 20) {
						Boss.set_health(15);

					}

				}
				else {
					cout << "You don't have enough power to pistol whip!" << endl;
					Hero.change_power(40);
					system("pause");
				}


				break;
			case 3:
				cout << "You roll a " << hero_roll << endl;
				if (Hero.show_power() >= 35) {
					Hero.precision_shot(hero_roll, Hero);

					system("pause");

					if (hero_roll <= 5) {
						Boss.set_health(10);

					}
					else if (hero_roll > 5 && hero_roll <= 10) {
						Boss.set_health(15);
					}
					else if (hero_roll > 10 && hero_roll <= 15) {
						Boss.set_health(25);

					}
					else if (hero_roll > 15 && hero_roll <= 19) {
						Boss.set_health(35);

					}
					else if (hero_roll == 20) {
						Boss.set_health(40);

					}


				}
				else {
					cout << "You don't have enough power to take a precision shot!!" << endl;
					Hero.change_power(40);
					system("pause");
				}


				break;

			case 4:
				cout << "You roll a " << hero_roll << endl;
				Hero.healing_pot(Hero, hero_roll);

				system("pause");

				break;
			}
		}
		else {
			cout << "You Don't have enough power to attack! Your turn is skipped!" << endl;
			Hero.change_power(50);
			system("pause");

		}


		cpuIn = (rand() % 4) + 1; // give a random number between 1 and 4 for the trolls attack
		cpuRoll = roll_Dice();

		if (Beast.show_power() > 0) {
			switch (cpuIn)
			{
			default:
			case 1:
				cout << "The Troll rolls a " << cpuRoll << endl;

				if (cpuRoll <= 10) {
					Hero.change_health(15);
					cout << "The Troll picks up a chunk of earth, throwing it at you" << endl;

				}
				else if (cpuRoll > 10 && cpuRoll < 20) {
					Hero.change_health(25);
					cout << "The Troll picks up a large boulder, hucking it at you" << endl;

				}
				else if (cpuRoll == 20) {
					Hero.change_health(45);
					cout << "The Troll picks up a large mass of the ground and hurls it at you landing a critical hit" << endl;
				}

				system("pause");

				break;
			case 2:
				cout << "The Troll rolls a " << cpuRoll << endl;

				if (cpuRoll <= 10) {
					Hero.change_health(20);
					cout << "The troll slashes at you with its claws" << endl;
				}
				else if (cpuRoll > 10 && cpuRoll < 20) {
					Hero.change_health(40);
					cout << "The troll lunges at you and swipes at you with its large hands" << endl;
				}
				else if (cpuRoll == 20) {
					Hero.change_health(15);
					cout << "The troll bolts at you, swiping with its large sharp hands dealing a critical hit" << endl;
				}


				system("pause");
				break;
			case 3:
				cout << "The Troll stands and does nothing, trolls aren't the smartest afterall" << endl;
				break;


			case 4:
				cout << "The Troll rolls a " << cpuRoll << endl;

				if (cpuRoll <= 10) {
					Hero.change_health(10);
					cout << "The troll slams the ground causing you to fall!" << endl;
				}

				else if (cpuRoll > 10 && cpuRoll < 20) {

					cout << "The Troll smashes the ground in front of it sending rocks flying at you, and sending you stumbling!" << endl;
					Hero.change_health(20);
				}
				else if (cpuRoll == 20) {
					cout << "The Troll pounds the ground with extreme mite, causing the room to shake, rocks go flying and you slam into the ground dealing critical damage!" << endl;
					Hero.change_health(30);

				}
				break;

			}


		}
		else {
			cout << "The Troll didn't have enough power to attack!, their turn is skipped!" << endl;
			Beast.set_power(50);
			system("pause");

		}


		// each player gets 10 more power at end of turn
		Hero.change_power(10);
		Beast.set_power(10);



		cout << Boss.boss_name() << " Health: " <<  Boss.show_health() << endl;

		cout << endl;
		cout << Hero.show_name() << " Health: " << Hero.show_health() << endl;
		cout << Hero.show_name() << " Power: " << Hero.show_power() << endl;



		if (Hero.show_health() <= 0) { // checks if hero is dead and game ends
			cout << Hero.show_name() << " Health: " << Hero.show_health() << endl;
			cout << "~Your quest has come to an end~" << endl;
			cout << "----------GAME OVER----------" << endl;

		}
		else if (Boss.show_health() <= 0) { // if the boss dies it gives the end of game dialogue 

			cout << "You land your final blow on " << Boss.boss_name() << endl;
			system("pause");


			cout << "~You turn around and see a dark figure approaching you from the way you came~" << endl;;
			cout << "Xlevi: You did it " << Hero.show_name() << " you defeated the Trolls, the village people can now live in peace!" << endl;

			system("pause");


			cout << "Xlevi: This isn't the only village that's affected by these kinds of troubles however, I think this might be just the beginning of your work" << endl;


			cout << "The end?" << endl;



			return 0;
		}


	}


	return 0;



}
// function for dice roll (D20)
int roll_Dice() { 

	srand((time(0)));

	int num = rand();

	num = (num % 20) + 1;

	return num;

}