#pragma once
#include <vector>
#include <string>

enum States
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};
class Automata
{
	private:
		int cash;
		std::vector<std::string> menu{"Latte","Cappuccino","Espresso","Americano"};
		std::vector<int> prices {100,90,120,200};
		States state;
		bool check(int choise);
		void cook();
public:
	Automata();
	void on();
	void off();
	void coin(int numb);
	std::vector<std::string> etMenu();
	States getState();
	void choice(int ch);
	int cancel();
	int finish();
	~Automata();
};

