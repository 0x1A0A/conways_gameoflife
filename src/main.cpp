#include "raylib.h"
#include "raygui.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 2

const int screenWidth = 640;
const int screenHeight = 480;
const int cw = screenWidth/SIZE;
const int ch = screenHeight/SIZE;

int cell[cw][ch][2] = {0};
int world = 0;

void draw_grid_2d() {
	// draw vertical line
	for (int i{0}; i<=cw; ++i)
		DrawLine(i*SIZE, 0, i*SIZE, screenHeight, GRAY);
	// draw horizontal line 
	for (int i{0}; i<=ch; ++i)
		DrawLine(0, i*SIZE, screenWidth, i*SIZE, GRAY);
}

int neightbors(int x, int y, int world) {
	int count = 0;
	int test_case[] = {0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
	for (int i{0}; i<8; ++i) {
		int _x = test_case[i*2] + x;
		int _y = test_case[i*2 + 1] + y;

		if ( _x >= 0 && _x < cw && _y >=0 && _y <ch)
		count += cell[_x][_y][world];
	}
	return count;
}

int main(int argc, char **argv) {
	Camera2D camera = {0};
	InitWindow(screenWidth, screenHeight, "raylib game of life");

	SetTraceLogLevel(LOG_ALL);
	srand(time(NULL));

	// random start cell
	for (int i{0}; i<cw; ++i) {
		for (int j{0}; j<ch; ++j) {
			cell[i][j][world] = cell[i][j][!world] = rand()%2;
		}
	}

	camera.target.x = 640/2;
	camera.target.y = 480/2;

	camera.offset = { 640/2, 480/2 };

	camera.zoom = 2.f;

	float zoom = 2.f;
	float moveSpeed = 100.f;

	bool process = false;

	Vector2 look = camera.target;
	float timePass = 0.f;

	float updateTime = 1.0f;

	while(!WindowShouldClose()) {
		Vector2 mwheel = GetMouseWheelMoveV();
		zoom += mwheel.y != 0 ?
			mwheel.y > 0 ? .1 : -.1 : 0;

		camera.zoom += ( zoom - camera.zoom )/6;

		process = IsKeyPressed(KEY_SPACE) ? !process: process;

		float movex = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
		float movey = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

		if(movex || movey) {
			look.x += moveSpeed	* movex * GetFrameTime();
			look.y += moveSpeed	* movey * GetFrameTime();
		}

		camera.target.x += ( look.x - camera.target.x)/4;
		camera.target.y += ( look.y - camera.target.y)/4;

		updateTime = IsKeyPressed(KEY_ONE) ? 1.f : updateTime;
		updateTime = IsKeyPressed(KEY_TWO) ? 0.5f : updateTime;
		updateTime = IsKeyPressed(KEY_THREE) ? 0.2f : updateTime;
		updateTime = IsKeyPressed(KEY_FOUR) ? 0.1f : updateTime;

		if (process && timePass > updateTime) {
			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					int count_neightbor = neightbors(i,j,world); 
					if (cell[i][j][world]) {
						cell[i][j][!world] = (count_neightbor == 2 || count_neightbor == 3) ? 1:0;
					} else {
						cell[i][j][!world] = (count_neightbor == 3) ? 1:0;
					}
				}
			}

			world = !world;
			timePass = 0.f;
		}

		BeginDrawing();
		BeginMode2D(camera);
		{
			ClearBackground(RAYWHITE);
			draw_grid_2d();
			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					if (cell[i][j][world])
						DrawRectangle(i*SIZE, j*SIZE, SIZE, SIZE, BLACK);
				}
			}

		}
		EndMode2D();
		DrawFPS(10,10);
		EndDrawing();

		timePass += GetFrameTime();
	}

	CloseWindow();

	return 0;
}
