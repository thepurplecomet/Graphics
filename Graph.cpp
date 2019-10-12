#include <iostream>
#include <string>
#include <SDL.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
const int WIDTH = 600;
const int HEIGHT = 600;

void graph(SDL_Renderer* renderer, string quad[]){
	double a = stod(quad[0]);
	double b = stod(quad[1]);
	double c = stod(quad[2]);
	for (int i = -20; i < 20; i++) {
		SDL_RenderDrawLine(renderer,
			(WIDTH/2 + (i)*6),
			(HEIGHT/2 - ((((i) * (i) * a) + ((i) * b) + c)*6)),
			(WIDTH/2 + (i + 1)*6),
			(HEIGHT/2 - ((((i+1) * (i+1)* a) + ((i+1)* b) + c) * 6)));
	}
}
int start(string quad[])
{//Initializing SDL Window
	SDL_Init(SDL_INIT_VIDEO);//Initialise SDL
	SDL_Window* window;//Make Window Pointer
	window = SDL_CreateWindow(//Create Window
		"Your Graph",//Window Title
		SDL_WINDOWPOS_UNDEFINED,//Window Position X
		SDL_WINDOWPOS_UNDEFINED,//Window Position Y
		WIDTH,//Window Size X
		HEIGHT,//Window Size Y
		SDL_WINDOW_OPENGL);//Flag - Use OPENGL
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);//Create Renderer for the Window
	SDL_SetRenderDrawColor(renderer,0,0,0,255);//RGB Black
	SDL_RenderPresent(renderer);//Apply Renderer
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);//Set
	SDL_RenderDrawLine(renderer, 300, 0, 300, 600);
	SDL_RenderDrawLine(renderer, 0, 300, 600, 300);
	for (int i = 1; i < (600 / 6); i++){
		SDL_RenderDrawLine(renderer, (i * 6), (298), (i * 6), (302));
	}
	for (int i = 1; i < (600 / 6); i++){//This 'for loop' is used to draw the intervals along the y-axis
		SDL_RenderDrawLine(renderer, (298), (i * 6), (302), (i * 6));
	}
	graph(renderer, quad);
	SDL_RenderPresent(renderer);//Show Render
	SDL_RenderClear(renderer);//Clear Render
	SDL_Delay(12000);//Pause for 3000 miliseconds
	return 0;
}

int main(int argc, char* argv[]) {
	string quad[3];
	printf("Type in your quadratic in standard form!\nf(x)=:(A)");
	cin >> quad[0];
	printf("f(x)=%sx^2+(B)", quad[0].c_str());
	cin >> quad[1];
	printf("f(x)=%s^2+%sx+(C)", quad[0].c_str(), quad[1].c_str());
	cin >> quad[2];
	printf("\nf(x)=%s^2+%sx+%s", quad[0].c_str(), quad[1].c_str(), quad[2].c_str());
	start(quad);
	return 0;
}