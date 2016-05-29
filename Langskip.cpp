#include "Langskip.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <string>

vector <Langskip> Langskip::langskip;

		
int randomValueLangskip()
{
	return 20 + rand() % 20;
}

//Constructor
Langskip::Langskip() 
{
	_langskipType = double( rand() % 3 + 1 );   //1=snekkar,2=skeid,3=drakkar
	_hp = randomValueLangskip() * _langskipType;

	_offence = { (double)randomValueLangskip()*_langskipType,
			 (double)randomValueLangskip()*_langskipType};

	_defence = { (double)randomValueLangskip()*_langskipType,
			 (double)randomValueLangskip()*_langskipType};
}

//Langskip description
string Langskip::description()
{
	string _type;

	if(_langskipType == 1)
		_type = " snekkar ";
	else if(_langskipType == 2)
		_type = " skeid ";
	else if (_langskipType == 3)
		_type = " drakkar ";
	else
		_type = " mixture ";


	return "Type: " + to_string(_langskipType) + _type + 
		"\n\tHP: " + to_string(_hp) + " BR: " +
		 to_string(beastRatio()) + "\n\t" +
		"offence chance:power " + to_string(_offence.chance) + 
		":" + to_string(_offence.power) + 
		"\n\tdefence chance:power " + to_string(_defence.chance) + 
		":" + to_string(_defence.power);
}

//Langskip beastRatio
double Langskip::beastRatio()
{
	double parametersRatio = 
		(_offence.chance * _defence.chance * _offence.power * _defence.power) / 100000000.;
	return _hp * parametersRatio;
}
