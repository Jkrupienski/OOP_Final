#pragma once

#include <string>

using std::string;


class Opp
{
protected:
	string name;
	

public:
	Opp();
	Opp(string in_name);

	string show_name();

};

