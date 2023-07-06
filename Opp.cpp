#include "Opp.h"


Opp::Opp() {
	name = "Bob";

}

Opp::Opp(string in_name) {
	name = in_name;
}

string Opp::show_name() {

	return name;

}