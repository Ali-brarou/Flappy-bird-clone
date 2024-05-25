#include<raylib.h>
#include<iostream>
#include<vector>
#include"global.hpp"
#include"bird.hpp"
#include"pipe.hpp"
#include"checkCollision.hpp"


class Game{

	public :
	Game();
	
	void run();

	private :
	void update();
	void render();
	Bird bird;
	std::vector<Pipe*> pipes;
	
	void initTextures();	
	Texture2D backgroundTexture; 
	Texture2D baseTexture;
	
	
	bool isGameStarted = false;
	
	bool checkGameOver();
	bool isGameOver = false;
	unsigned int score = 0;
	void drawBackground();
	void drawBase();
	void drawScore();

};
