#include <iostream>
#include <vector>
#include "CharacterFactory.h"

int main() 
{
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	system("PAUSE");
}
