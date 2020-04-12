
#include "Player.h"


int main(void)
{
	Player* mPlayer = new Player();
	mPlayer->Initialize();
	while (1)
	{
		mPlayer->State_Check();
		mPlayer->State_Run();
		Sleep(1000);
	}
	delete mPlayer;
	return 0;
}