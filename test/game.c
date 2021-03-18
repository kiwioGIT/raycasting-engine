#include <stdio.h>
#include "../src/engine.h"

int main()
{
        int screenWidth = 185;
        int screenHeight = 50;
        int map[MAP_HEIGHT][MAP_WIDTH] = {
                {1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,1,0,0,0,0,1},
                {1,0,0,0,0,0,1,0,0,1},
                {1,0,1,0,0,0,1,0,0,1},
                {1,1,1,1,1,1,1,1,1,1}
        };
        struct Camera camera;
        camera.position.x = 2;
        camera.position.y = 2;
        camera.angle = 0;
        camera.FOV = 90;
        camera.renderDistance = 6;
        char input;
	short running = 1;
	float raySpeedModifier = 0.001;
        while (running){
                renderFrame(camera, map, screenWidth, screenHeight, raySpeedModifier);
                scanf("%c", &input);
                if (input == 'k') camera.angle += 10;
                else if (input == 'j') camera.angle -= 10;
                else if (input == 'w') camera.position.x += 0.5;
                else if (input == 's') camera.position.x -= 0.5;
                else if (input == 'a') camera.position.y -= 0.5;
                else if (input == 'd') camera.position.y += 0.5;
        	else if (input == 'x') running = 0;
	}
        return 0;
}

