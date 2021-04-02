#include "Automata.h"
#include <iostream>

Automata::Automata()
{
	cash = 0;
	state = OFF;

}
States Automata::getState()
{
	return state;
}
void Automata::on()
{
	if (getState() == OFF) {
		state = WAIT;
		std::vector<std::string> fullMenu = etMenu();

	}
}
void Automata::off()
{
	if (getState() == WAIT)
		state = OFF;
	cash = 0;
}
void Automata::coin(int numb)
{
	if (getState() == ACCEPT || getState() == WAIT)
	{
		if (getState() == WAIT)
			state = ACCEPT;
		cash += numb;
	}
}
std::vector<std::string>Automata::etMenu()
{
	std::vector<std::string> fullMenu;

	for (int i = 0; i < menu.size(); i++) 
		fullMenu.push_back(menu[i] + std::to_string(prices[i]));		
	
	return fullMenu;
}
bool Automata::check(int choise)
{
	if (state == CHECK) {
		if (cash - prices[choise] >= 0)
			return true;
	}
	return false;
}
void Automata::choice(int ch)
{
	if (getState() == ACCEPT)
	{
		state = CHECK;
		if (ch < menu.size() && ch >= 0 && check(ch))
		{
			cash -= prices[ch];
			cook();
		}
		else
		{
			cancel();
		}
	}
	
}
int Automata::cancel()
{
	if (getState() == ACCEPT || getState() == WAIT)
	{
		state = WAIT;
		int tmp = cash;
		cash = 0;
		return tmp;
	}
	return 0;
}
void Automata::cook()
{
	if (getState() == CHECK)
	{
		state = COOK;
		if (cash == 0)
			finish();
	}
}
int  Automata::finish()
{
	if (getState() == COOK)
	{
		state = WAIT;
		int tmp = cash;
		cash = 0;
		return tmp;
	}
	return 0;
}
Automata::~Automata()
{}