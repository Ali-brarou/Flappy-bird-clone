#include"headers/game.hpp"

Game::Game()
{
	for(int i = 0; i < 2; i++)
	{

		Pipe *pipe = new Pipe(Width + i*Distance_Between_Pipes);

		pipes.push_back(pipe);
	}
}	

void Game::run()
{
	InitWindow(Width, Height, "flappy bird");
	
	initTextures();
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		update();
		render();
	}
}

void Game::update()
{
	if(isGameOver)
	{
		bird.deathUpdate();
		return;
	}



	if(IsKeyDown(KEY_SPACE)) 
	{	
		bird.jump();
		if(!isGameStarted)
			isGameStarted = true;
	}
	else bird.isJumping = false;

	if(!isGameStarted)
		return;

	bird.update();
	for(auto pipe : pipes)
	{
		pipe->update(score);
	}
	
		
	isGameOver = checkGameOver();

}


void Game::render()
{
	BeginDrawing();
		
		ClearBackground(RAYWHITE);
		drawBackground();
		
		
		for(auto pipe : pipes)
			pipe->draw();
			
		bird.draw();

		drawBase();	
		
		drawScore();

		DrawFPS(0,0);
	EndDrawing();
}



void Game::initTextures()
{
	Image BackgroundImage = LoadImage("src/assets/sprites/background-day.png");

	ImageResize(&BackgroundImage, Width, Height);
	backgroundTexture = LoadTextureFromImage(BackgroundImage);
	UnloadImage(BackgroundImage);


	Image BaseImage = LoadImage("src/assets/sprites/base.png");

	ImageResize(&BaseImage, Width, Base_Height);

	baseTexture = LoadTextureFromImage(BaseImage);

	UnloadImage(BaseImage);


	bird.initTexture();
	
		
	for(auto pipe : pipes)
	{
		pipe->initTexture();
	}

}


void Game::drawBackground()
{
	DrawTexture(backgroundTexture, 0, 0, WHITE);
}

void Game::drawBase()
{
	DrawTexture(baseTexture, 0, Height - Base_Height, WHITE);
}

bool Game::checkGameOver()
{
	if(bird.getPos().y + Bird_Height > Height - Base_Height)
		return true;

	for(auto pipe : pipes)
	{
		if(checkCollision(bird, pipe))
			return true;
	}

	return false;
}

void Game::drawScore()
{
	DrawText(TextFormat("Score: %08i", score), Width/2, 80, 20, ORANGE);
}
