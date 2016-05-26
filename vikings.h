#pragma once

#include <string>
#include <vector>

using namespace std;


struct parameter
{
	double chance, power;
};

		//Langskip
class Langskip
{
public:
	Langskip();

	double _langskipType;
	double _hp, _beastRatio;
	parameter _offence, _defence;

	static vector <Langskip> langskip;

	double langskipType() { return _langskipType; }
	double hp() { return _hp; }
	parameter offence() { return _offence; }
	parameter defence() { return _defence; }

	double beastRatio();
	string description();
};

		//Lands
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