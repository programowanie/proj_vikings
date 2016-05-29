#pragma once

#include <string>
#include <vector>

using namespace std;

struct parameter
{
	double chance, power;
};


class Lands 
{	
	static void init();

public:
	Lands();

	static vector <string> lands;
	string _name;
	double _hp;
	parameter _offence, _defence;

	double hp() { return _hp; }
	string name() { return _name; }
	parameter offence() { return _offence; }
	parameter defence() { return _defence; }

	double beastRatio();
	string description();
};
