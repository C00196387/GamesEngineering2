#include <iostream>
#include "Player.h"
#include "DrawImpl.h"

using namespace std;

int main(void)
{
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	cin.get();

	system("PAUSE");
}
