#include"headers/bird.hpp"


Bird::Bird()
{
	m_Pos = {Bird_XPos, Height/2};
	m_Velocity = 0;
	rotation = 0;
}


void Bird::initTexture()
{
	Image bird = LoadImage("src/assets/sprites/redbird-upflap.png");
	ImageResize(&bird, Bird_Width, Bird_Height);

	animation.push_back(LoadTextureFromImage(bird));


	Image bird2 = LoadImage("src/assets/sprites/redbird-downflap.png");
	ImageResize(&bird2, Bird_Width, Bird_Height);
	
	animation.push_back(LoadTextureFromImage(bird2));
	Image bird3 = LoadImage("src/assets/sprites/redbird-midflap.png");
	ImageResize(&bird3, Bird_Width, Bird_Height);

	animation.push_back(LoadTextureFromImage(bird3));

	UnloadImage(bird);
	UnloadImage(bird2);
	UnloadImage(bird3);

}


void Bird::jump()
{
	if(!isJumping)
	{
		m_Velocity = -Jump_Power;
		isJumping = true;
	}
}

void Bird::update()
{
	if(m_Velocity < Max_Velocity)
		m_Velocity += Gravity;
	m_Pos.y += m_Velocity;

	rotation = std::atan(m_Velocity/Speed) * 180 / 3.1415 / 10;

	if(m_Pos.y < 0)
	{
		m_Pos.y = 0;
		m_Velocity = 0;
	}
	Frame = (Frame + 1)%75;
}

void Bird::deathUpdate()
{
	if(m_Pos.y + Bird_Height  > Height - Base_Height)
		return;
	
	update();
}


void Bird::draw()
{
	DrawTextureEx(animation[Frame / 25],m_Pos, rotation, 1, WHITE);

}

Vector2 Bird::getPos()
{
	return m_Pos;
}
