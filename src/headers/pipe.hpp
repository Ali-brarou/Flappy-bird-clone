#pragma once

#include<raylib.h>
#include<random>
#include<vector> 
#include"global.hpp"

class Pipe {
	
	public :
	Pipe(const float &xPos);
	
	void initTexture();
	void draw();
	void update(unsigned int &score);

	Vector2 getPos();
		
	private : 
	Vector2 m_Pos;
	std::vector<Texture2D> textures;



	

};
