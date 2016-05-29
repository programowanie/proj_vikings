#pragma once

#include <string>
#include <vector>

using namespace std;

struct parameter2
{
	double chance, power;
};

class Langskip 
{
public:
	Langskip();

	double _langskipType;
	double _hp, _beastRatio;
	parameter2 _offence, _defence;

	static vector <Langskip> langskip;

	double langskipType() { return _langskipType; }
	double hp() { return _hp; }
	parameter2 offence() { return _offence; }
	parameter2 defence() { return _defence; }

	double beastRatio();
	string description();
};
