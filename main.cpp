#include "Langskip.h"
#include "Lands.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iterator>
#include <unistd.h>
#include <string>

#define N 12					//[4,12] lands
#define INTERVAL 90000			//interval between fights
#define PARAM 15				//offence,defence
#define MONEY_RANGE 15			//money = beastRatio * MONEY_RANGE

using namespace std;

void showLangskips();


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	printf("\n\tGoal: \n\tconquest all the lands vikings did from VIII to XI century\n\n");

	Lands lands[N];

//all lands
	for (int i = 0; i < N; ++i)
		printf("%d.\t%s\n\n", 
			i+1, lands[i].description().c_str());

//money for Norway, Sweden and Denmark which are initially "won"
	double money = 100 + (lands[0].beastRatio() +
				lands[1].beastRatio() +
				lands[2].beastRatio())*MONEY_RANGE;

	printf("\tVikings have already conquered Norway, Sweden and Denmark\n");
	printf("\tInitial amount of money: %f\n", money);

		while( money >= 100){
		Langskip::langskip.push_back(Langskip());
		money-=100;
		}

	showLangskips();


	Langskip tempLangskip;

		//fight
	for (int i = 3; i < N; ++i)
	{
		double gold = lands[i].beastRatio() * MONEY_RANGE;
		int isBrutal_counter = 0;
		//tempLangskip - averaging

/////////////////////////////////////////
double t_langskipType = 0,
			t_hp = 0,
			t_offenceChance = 0,
			t_offencePower = 0,
			t_defenceChance = 0,
			t_defencePower = 0;

		int amount = Langskip::langskip.size();


		for (int i = 0; i < amount; i++)
		{
			t_langskipType += Langskip::langskip[i].langskipType();
			t_hp += Langskip::langskip[i].hp();
			t_offenceChance += Langskip::langskip[i].offence().chance;
			t_offencePower += Langskip::langskip[i].offence().power;
			t_defenceChance += Langskip::langskip[i].defence().chance;
			t_defencePower += Langskip::langskip[i].defence().power;
		}

		tempLangskip._langskipType = t_langskipType /= amount;
		tempLangskip._hp = t_langskipType*(t_hp /= amount);
		tempLangskip._offence.chance = t_langskipType*(t_offenceChance /= amount);
		tempLangskip._offence.power = t_langskipType*(t_offencePower /= amount);
		tempLangskip._defence.chance = t_langskipType*(t_defenceChance /= amount);
		tempLangskip._defence.power = t_langskipType*(t_defencePower /= amount);

		tempLangskip._beastRatio = t_hp * (t_offenceChance*t_offencePower*t_defencePower*t_defenceChance);

///////////////////////////////////////

		printf("\n\n\n\n##################### fight %d.", i+1);
		printf("\n--------Average Langskip:\t%s\n\n", 
			tempLangskip.description().c_str() );


		while(1)
		{
			isBrutal_counter++;

			usleep(INTERVAL);


			if  (( (rand() % 100) * tempLangskip.offence().chance)
				>
				( (rand() % 100) * lands[i].offence().chance) )

				lands[i]._hp -= ( (1 - lands[i].defence().chance)
					* (1 - lands[i].defence().power) * 0.0001
					* ((PARAM + rand() % PARAM)*0.01*
					tempLangskip.offence().power) );
			else
				tempLangskip._hp -= ( (1 - tempLangskip.defence().chance)
					* (1 - tempLangskip.defence().power) * 0.0001
					* ((PARAM + rand() % PARAM)*0.01*
					lands[i].offence().power) );

			printf("[ %d ]  HP:\tVikings %s\tvs\t%s\t%s\n",
				isBrutal_counter, 
				(to_string(tempLangskip.hp())).c_str(), 
				lands[i].name().c_str(), 
				(to_string(lands[i].hp())).c_str() );

			if ( (tempLangskip.hp() < 0)  || (lands[i].hp() < 0) )
				break;
		}

		//if Land loses
		if( lands[i].hp() < 0)
		{
			money += gold;

			if (isBrutal_counter < 10)
			{
				printf("\n+++Extra money for brutality");
				money += (rand() % 50)*0.01*gold;
			}
		}

		//if vikings loose
		if( tempLangskip.hp() < 0)
		{
			int choose = rand() % 3;
			switch(choose)
			{
				case 0:	printf("\n###Odin saves vikings! They loose nothing");
						printf("\nVikings have to repeat this level");

						break;
				case 1: printf("\n###Vikings loose one langskip ;_;");
						Langskip::langskip.pop_back();
						break;
				case 2: printf("\n###All vikings die. The end\n\n\n");
						return 0;
						break;
				default: printf("KILL ME fatal error");
							return 0;
							break;
			}
		}

		//if 0 Langskips
		if(Langskip::langskip.size() == 0)
		{
			printf("\n\nAll vikings are dead, because they have lost their langskips\n###END###\n\n");
			return 0;
		}

		printf("\n\tMoney to spend: %f", money);

		//buying Langskips
		while( money >= 100){
			Langskip::langskip.push_back(Langskip());
			money-=100;
			}
		
		showLangskips();
	}

	printf("\n\n\tVICTORY OF VIKINGS!!!\n\n");
}

void showLangskips()
{
		printf("\n\tLangskips:\n\n");

		for (unsigned int i = 0; i < Langskip::langskip.size(); i++)
			printf("%d.\t%s\n\n", 
				i+1, Langskip::langskip[i].description().c_str());	
}
