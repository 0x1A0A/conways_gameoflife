#include "raylib.h"
#include "raygui.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <atomic>

#define SIZE 2

const int screenWidth = 640;
const int screenHeight = 480;
const int cw = screenWidth/SIZE;
const int ch = screenHeight/SIZE;

int cell[cw][ch][2] = {0};
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
			count += cell[_x][_y][world] & 1 ? 1 : 0;
	}
	return count;
}

void add_neightbor(int x, int y, int w, int value) {
	int test_case[] = {0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
	for (int i{0}; i<8; ++i) {
		int _x = test_case[i*2] + x;
		int _y = test_case[i*2 + 1] + y;

		if ( _x >= 0 && _x < cw && _y >= 0 && _y <ch) {
			//int count = cell[_x][_y][w] >> 1;
			//count += value;
			//count = count < 0 ? 0 : count > 8 ? 8 : count;
			cell[_x][_y][w] += 2 * value;
		}
	}
}

void thread_cell_life() {
	while (!done) {
		if (process && timePass > updateTime) {
			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					cell[i][j][!world] = cell[i][j][world];
				}
			}

			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					int count_neightbor = cell[i][j][world] >> 1;
					if (cell[i][j][world] & 1) {
						if (!(count_neightbor == 2 || count_neightbor == 3)) {
							cell[i][j][!world] &= 0xfe;
							add_neightbor(i,j,!world,-1);
						}
					} else if(count_neightbor == 3) {
						cell[i][j][!world] |= 1;
						add_neightbor(i,j,!world,1);
					}
				}
			}

			world = !world;
			timePass = 0.f;
		}
	}
}

int main(int argc, char **argv) {
	Camera2D camera = {0};
	InitWindow(screenWidth, screenHeight, "raylib game of life");

	SetTraceLogLevel(LOG_ALL);
	srand(time(NULL));

	// random start cell
	for (int i{0}; i<cw; ++i)
		for (int j{0}; j<ch; ++j)
			cell[i][j][world] = cell[i][j][!world] = rand()%2;

	for (int i{0}; i<cw; ++i)
		for (int j{0}; j<ch; ++j) {
			int count_neightbor = neightbors(i,j);
			cell[i][j][world] = cell[i][j][!world] |= count_neightbor << 1;
		}

	camera.target.x = 640/2;
	camera.target.y = 480/2;

	camera.offset = { 640/2, 480/2 };

	camera.zoom = 2.f;

	float zoom = 2.f;
	float moveSpeed = 200.f;

	Vector2 look = camera.target;

	std::thread worker1{ thread_cell_life };

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


		BeginDrawing();
		BeginMode2D(camera);
		{
			ClearBackground(BLACK);
			// draw_grid_2d();
			for (int i{0}; i<cw; ++i) {
				for (int j{0}; j<ch; ++j) {
					if (cell[i][j][world] & 1)
						DrawRectangle(i*SIZE, j*SIZE, SIZE, SIZE, RAYWHITE);
				}
			}

		}
		EndMode2D();

		// mouse debugger
		Vector2 cm_mouse = GetScreenToWorld2D(GetMousePosition(), camera);
		int i = (int)cm_mouse.x/SIZE, j = (int)cm_mouse.y/SIZE;
			
		char t[100];
		sprintf(t, "x %d, y %d",i,j);

		DrawText( t, 10, 10, 10, BLUE);
		
		if ( i >= 0 && i<cw && j>=0 && j<ch ) {
			sprintf(t, "neightbor %d, state now %s -- next %s",
					cell[i][j][world] >> 1, cell[i][j][world] & 1 ? "alive" : "empty", "?");
			DrawText( t, 10, 20, 10, BLUE);
			BeginMode2D(camera);
			DrawRectangleLines(i*SIZE, j*SIZE, SIZE, SIZE, RAYWHITE);
			EndMode2D();
			if ( IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
				cell[i][j][world] ^= 1;
				add_neightbor(i,j,world,cell[i][j][world] & 1 ? 1:-1);
			}
		}
		EndDrawing();

		timePass = timePass + GetFrameTime();
	}

	CloseWindow();
	done = true;
	worker1.join();

	return 0;
}
