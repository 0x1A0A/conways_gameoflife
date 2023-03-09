#include "raylib.h"
#include "raygui.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <atomic>
#include <string.h>
#include "raymath.h"

#define SIZE 2

const int screenWidth = 640;
const int screenHeight = 480;
const int cw = screenWidth/SIZE;
const int ch = screenHeight/SIZE;

int cell[2][ch][cw] = {0};
int world = 0;

static float timePass = 0.f;
static float updateTime = 1.0f;
std::atomic_bool done={false};
static bool process = false;

void draw_grid_2d() {
	// draw vertical line
	for (int i{0}; i<=cw; ++i)
		DrawLine(i*SIZE, 0, i*SIZE, screenHeight, GRAY);
	// draw horizontal line 
	for (int i{0}; i<=ch; ++i)
		DrawLine(0, i*SIZE, screenWidth, i*SIZE, GRAY);
}

int neightbors(int x, int y) {
	int count = 0;
	int test_case[] = {0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
	for (int i{0}; i<8; ++i) {
		int _x = test_case[i*2] + x;
		int _y = test_case[i*2 + 1] + y;

		if ( _x >= 0 && _x < cw && _y >= 0 && _y <ch)
			count += cell[world][_y][_x] & 1 ? 1 : 0;
	}
	return count;
}

void add_neightbor(int x, int y, int w, int value) {
	int test_case[] = {0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
	for (int i{0}; i<8; ++i) {
		int _x = test_case[i*2] + x;
		int _y = test_case[i*2 + 1] + y;

		if ( _x >= 0 && _x < cw && _y >= 0 && _y <ch) {
			cell[w][_y][_x] += 2 * value;
		}
	}
}

void thread_cell_life() {
	while (!done) {
		if (process && timePass > updateTime) {
			
			memcpy( cell + !world, cell + world, sizeof(cell)/2);

			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					int count_neightbor = cell[world][j][i] >> 1;
					if (cell[world][j][i] & 1) {
						if (!(count_neightbor == 2 || count_neightbor == 3)) {
							cell[!world][j][i] &= 0xfe;
							add_neightbor(i,j,!world,-1);
						}
					} else if(count_neightbor == 3) {
						cell[!world][j][i] |= 1;
						add_neightbor(i,j,!world,1);
					}
				}
			}

			world = !world;
			timePass = 0.f;
		}
	}
}

void clean_cell() {
	for (int i{0}; i<cw; ++i)
		for (int j{0}; j<ch; ++j)
			cell[world][j][i] = cell[!world][j][i] = 0;
}

void random_cell() {
	for (int i{0}; i<cw; ++i)
		for (int j{0}; j<ch; ++j)
			cell[world][j][i] = cell[!world][j][i] = rand()%2;
	for (int i{0}; i<cw; ++i)
		for (int j{0}; j<ch; ++j) {
			int count_neightbor = neightbors(i,j);
			cell[world][j][i] = cell[!world][j][i] |= count_neightbor << 1;
		}
}

int main(int argc, char **argv) {
	Camera2D camera = {0};
	InitWindow(screenWidth, screenHeight, "raylib game of life");

	SetTraceLogLevel(LOG_ALL);
	srand(time(NULL));


	camera.target.x = 640/2;
	camera.target.y = 480/2;

	camera.offset = { 640/2, 480/2 };

	camera.zoom = 2.f;

	float zoom = 2.f;
	float moveSpeed = 200.f;

	Vector2 look = camera.target;

	std::thread worker1{ thread_cell_life };

	Color ghostColor = Fade(BLUE, 0.7);

	bool mouse_Lbutton_available = true;

	while(!WindowShouldClose()) {
		Vector2 mwheel = GetMouseWheelMoveV();
		zoom += mwheel.y != 0 ?
			mwheel.y > 0 ? .1 : -.1 : 0;

		camera.zoom += ( zoom - camera.zoom )/6;

		camera.zoom = Clamp(camera.zoom, 0.1, 10);

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

		if(IsKeyPressed(KEY_R)) random_cell();
		if(IsKeyPressed(KEY_C)) clean_cell();

		BeginDrawing();
		BeginMode2D(camera);
		{
			ClearBackground(BLACK);
			DrawRectangleLines(-1,-1,screenWidth+1,screenHeight+1, GRAY);
			// draw_grid_2d();
			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					if (cell[world][j][i] & 1)
						DrawRectangle(i*SIZE, j*SIZE, SIZE, SIZE, RAYWHITE);
				}
			}

			// UI


		}
		EndMode2D();
		Rectangle sliderBound{0};
		sliderBound.width = 100;
		sliderBound.height = 10;
		sliderBound.x = screenWidth - 100 - 5;
		sliderBound.y = 15;
		float updatePersec = 1.0f/updateTime;
		updatePersec = GuiSliderBar(sliderBound, "", "", updatePersec, 1, 60);
		if (1.0f/updatePersec != updateTime) {
			mouse_Lbutton_available = false;
		}
		updateTime = 1.0f/updatePersec;

		// mouse debugger
		Vector2 cm_mouse = GetScreenToWorld2D(GetMousePosition(), camera);
		int i = (int)cm_mouse.x/SIZE, j = (int)cm_mouse.y/SIZE;

		char t[100];
		sprintf(t, "fps %d -- x %d, y %d",GetFPS(),i,j);

		DrawText( t, 10, 10, 10, BLUE);

		if ( i >= 0 && i<cw && j>=0 && j<ch ) {
			sprintf(t, "neightbor %d, state now %s -- next %s",
					cell[world][j][i] >> 1, cell[world][j][i] & 1 ? "alive" : "empty", "?");
			DrawText( t, 10, 20, 10, BLUE);
			BeginMode2D(camera);
			DrawRectangleLines(i*SIZE, j*SIZE, SIZE, SIZE, ghostColor);
			EndMode2D();
			if ( mouse_Lbutton_available ) 
			if ( IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !(cell[world][j][i] & 1) ) {
				cell[world][j][i] |= 1;
				add_neightbor(i,j,world,1);
			}
			if ( IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && (cell[world][j][i] & 1) ) {
				cell[world][j][i] &= 0xfe;
				add_neightbor(i,j,world,-1);
			}
		}
		EndDrawing();

		timePass = timePass + GetFrameTime();
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) mouse_Lbutton_available = true;
	}

	CloseWindow();
	done = true;
	worker1.join();

	return 0;
}
