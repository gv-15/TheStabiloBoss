#include "pch.h"
#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"


GameLogic::GameLogic(World* pWorld)
{
	m_pWorld = pWorld;
}


GameLogic::~GameLogic()
{
}

void GameLogic::ProcessInput()
{

	if (!System::IsKeyPressed())
		return; //No keyboard event to be processed


	while (System::IsKeyPressed())
	{
		char c = System::GetNextPressedKey();
		switch (c)
		{
		case 'w':
			//Move up player 1
			m_pWorld->MoveUp(0);
			break;
			
		case 's':
			//Move down player 1
			m_pWorld->MoveDown(0);
			break;

		case 'a':
			//Move left player 1
			m_pWorld->MoveLeft(0);
			break;
			
		case 'd':
			//Move right player 1
			m_pWorld->MoveRight(0);
			break;
			
		case 72:
			//Move up player 2
			m_pWorld->MoveUp1(1);
			break;

		case 80:
			//Move down player 2
			m_pWorld->MoveDown1(1);
			break;

		case 75:
			//Move left player 2
			m_pWorld->MoveLeft1(1);
			break;

		case 77:
			//Move right player 2
			m_pWorld->MoveRight1(1);
			break;
		case 27:
			//'Esc' key pressed. Exit the game
			exit(0);
		}
	}
}
float roundoff(float value, unsigned char prec)
{
	float pow_10 = pow(10.0f, (float)prec);
	return round(value * pow_10) / pow_10;
}


bool GameLogic::IsGameEnded()
{
	//When will the game end? --> The game will end when the coins in map are 0
	if (m_pWorld->GetNumCoinsLeft() == 0)
	{

		vector <Player> mplayers;
		Player* mplayer1;
		Player* mplayer2;
		mplayers = m_pWorld->GetmPlayers();

		if (mplayers[0].GetCoins() > mplayers[1].GetCoins())
		{
			System::Clear();
			m_pWorld->Draw();
			Timer t;
			m_pWorld->GetTimer().ElapsedSeconds(true);
			t = m_pWorld->GetTimer();
			auto rounded = roundoff(100.123456, 3);
			cout << "\n";
			cout << "\n\n" << "El jugador 1 ha ganado con " << mplayers[0].GetCoins() << " monedas" << " en " << roundoff(t.ElapsedSeconds(true),2) << " seg." << "\n\n";
			cout << "\n";
		}
		else {

			System::Clear();
			m_pWorld->Draw();
			Timer t;
			m_pWorld->GetTimer().ElapsedSeconds(true);
			t = m_pWorld->GetTimer();
			cout << "\n";
			cout << "\n\n" "El jugador 2 ha ganado con " << mplayers[1].GetCoins() << " monedas" << " en " << roundoff(t.ElapsedSeconds(true),2) <<  " seg."<< "\n\n";
			cout << "\n";
		}

		return true;
	}
	else
	{
		return false;
	}

}
	bool GameLogic::IsGameStarted()
	{
		char c = System::GetNextPressedKey();
		if (c == ' ')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
	
		
	