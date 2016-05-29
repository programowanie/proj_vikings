#include "Lands.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <string>

vector <string> Lands::lands;

int lvl = 0;

int randomValue()
{
	return 30 + rand() % 20 + lvl*4;	
}

//initialization - data from .dat file
void Lands::init()
{
	ifstream file("lands.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(lands));
	file.close();
}

//Constructor
Lands::Lands()
{
	init();

	_hp = randomValue();
	_offence = { (double)randomValue(), (double)randomValue()};
	_defence = { (double)randomValue(), (double)randomValue()};

	_name = lands[ lvl++ ];
}

//Lands description
string Lands::description()
{
	return _name + "\n\tHP: " + to_string(_hp) + " BR: " 
		+ to_string(beastRatio()) + "\n\t" +
		"gold: " + to_string(beastRatio()*100) + "\n\t" +
		"offence chance:power " + to_string(_offence.chance) + 
		":" + to_string(_offence.power) + 
		"\n\tdefence chance:power " + to_string(_defence.chance) + 
		":" + to_string(_defence.power);
}

//Lands beastRatio
double Lands::beastRatio()
{
	double parametersRatio = 
		(_offence.chance * _defence.chance * _offence.power * _defence.power) / 100000000.;
	return _hp * parametersRatio;
}
