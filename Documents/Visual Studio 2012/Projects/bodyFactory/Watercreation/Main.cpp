#include "SDL.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <ctime>
#include "BodyFactory.h"


//Screen dimension constants 
//The window we'll be rendering to 
SDL_Window* window = NULL; 
//Event handler 
SDL_Event eHandler;
//The window renderer 
SDL_Renderer* renderer = NULL; 
//Current displayed texture 
bool createdWorld = false;
SDL_Rect stretchRect; 



//Starts up SDL and creates window 


SDL_Event e;

using namespace std;







void close() 
{ 
	//Free loaded image 
	//Destroy window 
	SDL_DestroyRenderer( renderer ); 
	SDL_DestroyWindow( window ); 
	window = NULL; 
	renderer = NULL; 
	//Quit SDL subsystems 
	IMG_Quit(); 
	SDL_Quit();
}



int main( int argc, char* args[] ) 
{ 
	bool QUIT = false;
	

			b2Vec2 gravity =  b2Vec2(0.0f,0.50f);
			//b2Vec2 gravity =  b2Vec2(0.0f,0.0f);
			bool doSleep = true;
			b2World* world = new b2World(gravity);
			b2Body* bodyDemo = BodyFactory::createBody(world,b2Vec2(0,0),b2Vec2(50,50),1,1,true,false,true,0x1,0x1);

	
			
			std::clock_t mClock;
			mClock = std::clock();
			while(!QUIT)
			{
				if(((std::clock()-mClock)/(double)CLOCKS_PER_SEC) >= 1.0/480.0)
				{
					mClock = std::clock();
				}
			}

	
	close();
	return 0;
}