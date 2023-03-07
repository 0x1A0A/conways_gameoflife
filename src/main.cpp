#include "raylib.h"
#include "raygui.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 16

const int screenWidth = 640;
const int screenHeight = 480;
const int cw = screenWidth/SIZE;
const int ch = screenHeight/SIZE;

int cell[cw][ch][2] = {0};
int world = 0;

void draw_grid_2d() {
	// draw vertical line
	for (int i{0}; i<cw; ++i)
		DrawLine(i*SIZE, 0, i*SIZE, screenHeight, GRAY);
	// draw horizontal line 
	for (int i{0}; i<ch; ++i)
		DrawLine(0, i*SIZE, screenWidth, i*SIZE, GRAY);
}

int neightbors(int x, int y, int world) {
	int count = 0;
	int test_case[] = {0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
	for (int i{0}; i<=8; ++i) {
		int _x = test_case[i*2] + x;
		int _y = test_case[i*2 + 1] + y;

		if ( _x >= 0 && _x < cw && _y >=0 && _y <ch)
		count += cell[_x][_y][world];
	}
	return count;
}

int main(int argc, char **argv) {
	InitWindow(screenWidth, screenHeight, "raylib game of life");
	SetTargetFPS(12);

	SetTraceLogLevel(LOG_ALL);
	srand(time(NULL));

	// random start cell
	for (int i{0}; i<cw; ++i) {
		for (int j{0}; j<ch; ++j) {
			cell[i][j][world] = cell[i][j][!world] = rand()%2;
		}
	}

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		draw_grid_2d();
		for (int i{0}; i<cw; ++i) {
			for (int j{0}; j<ch; ++j) {
				int count_neightbor = neightbors(i,j,world); 
				if (cell[i][j][world]) {
					DrawRectangle(i*SIZE, j*SIZE, SIZE, SIZE, BLACK);
					cell[i][j][!world] = (count_neightbor == 2 || count_neightbor == 3) ? 1:0;
				} else {
					cell[i][j][!world] = (count_neightbor == 3) ? 1:0;
				}
			}
		}
		world = !world;
		DrawFPS(10,10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
