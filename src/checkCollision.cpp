#include"headers/checkCollision.hpp"

bool checkCollision(Bird &bird, Pipe *pipe)
{
	const Vector2 &birdPos = bird.getPos();
	const Vector2 &pipePos = pipe->getPos();
	
//check collision with the upper pipe

	const float &r1x = birdPos.x;
	const float &r1y = birdPos.y;
	
	const float &r2x = pipePos.x;
	float r2y = 0;

	if (r1x + Bird_Width >= r2x &&     
		r1x <= r2x + Pipe_Width &&       
  		r1y + Bird_Height >= r2y &&       
  		r1y <= r2y + pipePos.y)  return true; 	

	
	r2y = pipePos.y + Pipes_Gap;

	if (r1x + Bird_Width  >= r2x &&     
  		r1x <= r2x + Pipe_Width &&       
  		r1y + Bird_Height >= r2y &&       
 		r1y <= r2y + Height - r2y) return true;



	return false;
}
