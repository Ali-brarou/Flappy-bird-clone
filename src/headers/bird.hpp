#pragma once

#include <raylib.h>
#include "global.hpp"
#include <vector> 
#include <iostream>
#include <cmath>

class Bird {
	
	public :
	Bird();
	
	void jump();

	void initTexture();
	void draw();
	void update();
	void deathUpdate();	

	Vector2 getPos();
	bool isJumping = false;

	private :
	Vector2 m_Pos;
	float m_Velocity;	

	int Frame = 0;	
	std::vector<Texture2D> animation;

	int rotation;

};
