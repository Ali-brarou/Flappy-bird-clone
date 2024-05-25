#include"headers/pipe.hpp"


int rand(int min, int max)
{
	return (random() % (max - min)) + min;
}

Pipe::Pipe(const float &xPos)
{
	m_Pos = {xPos, (float) rand(0,Height - Base_Height - Pipes_Gap)};
}

void Pipe::initTexture()
{
	Image Green_Pipe = LoadImage("src/assets/sprites/pipe-green.png");

	ImageResize(&Green_Pipe, Pipe_Width, Height);
	ImageFlipVertical(&Green_Pipe);

	textures.push_back(LoadTextureFromImage(Green_Pipe));

	ImageFlipVertical(&Green_Pipe);

	textures.push_back(LoadTextureFromImage(Green_Pipe));

	UnloadImage(Green_Pipe);
	
}


void Pipe::draw()
{
//drawing the upper pipe

	DrawTexture(textures[0], m_Pos.x,  m_Pos.y - Height,WHITE);

//drawing the lower pipe

	DrawTexture(textures[1],m_Pos.x, m_Pos.y + Pipes_Gap ,WHITE);
}

void Pipe::update(unsigned int &score)
{
	m_Pos.x -= Speed;
	if(m_Pos.x + Pipe_Width < 0)
	{
		m_Pos = {Width, (float) rand(0, Height - Base_Height - Pipes_Gap)};
		score++;
	}


}

Vector2 Pipe::getPos()
{
	return m_Pos;
}
