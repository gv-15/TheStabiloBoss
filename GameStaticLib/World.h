#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class World
{
	string namefile;
	int m_WorldCoins = 0;
	vector <Player> m_players;
	int m_Height = 0;
	int m_Width = 0;
	Timer timer;
	vector < vector<char>> m_mundo = vector<vector<char>>(0);
public:

	World(string nameFile);

	~World();
	
	void Draw();

	void Load();

	int GetNumPlayers();

	Player* GetPlayer(int id);

	vector<Player> GetmPlayers();

	vector<vector<char>> GetmMundo();

	Timer GetTimer();


	int GetNumCoinsLeft();

	int GetHeight();

	int GetWidth();

	vector<vector<char>> getWorld();

	void MoveUp(int i);

	void MoveDown(int i);

	void MoveRight(int i);

	void MoveLeft(int i);

	void MoveUp1(int i);

	void MoveDown1(int i);

	void MoveRight1(int i);

	void MoveLeft1(int i);

	Player* GetPlayerById(int id);

	float roundoff1(float value, unsigned char prec);

	
};