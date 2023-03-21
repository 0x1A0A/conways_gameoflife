#include "raylib.h"
#include "raygui.h"
#include "raymath.h"
#include <time.h>

// default screen size
const int screenWidth = 640;
const int screenHeight = 480;

int world = 0;

static float timePass = 0.f;
static float updateTime = 1.0f;
static bool process = false;

double all_fps = 0;

void randomcell(RenderTexture2D &texture) {
	BeginTextureMode(texture);
	ClearBackground(BLACK);
	for (int i{0}; i<screenWidth; ++i)
		for (int j{0}; j<screenHeight; ++j)
			if (!GetRandomValue(0,1)) DrawPixel(i,j, WHITE);
	EndTextureMode();
}

void clearcell(RenderTexture2D &texture) {
	BeginTextureMode(texture);
	ClearBackground(BLACK);
	EndTextureMode();
}

void automaton(RenderTexture2D &src, RenderTexture2D &target, Shader &gameoflife) {
	BeginTextureMode(target);
	ClearBackground(BLACK);
	{
		BeginShaderMode(gameoflife);
		DrawTextureRec(src.texture,{0,0,screenWidth,-screenHeight},{0,0},WHITE);
		EndShaderMode();
	}
	EndTextureMode();
}

int main(int argc, char **argv) {
	InitWindow(screenWidth, screenHeight, "raylib game of life");
	SetTraceLogLevel(LOG_ALL);
	SetRandomSeed(time(NULL));

	RenderTexture2D target[2] = {
		LoadRenderTexture(screenWidth,screenHeight),
		LoadRenderTexture(screenWidth,screenHeight),
	};

	Camera2D camera = {0};
	Shader gameoflife = LoadShader("shaders/gameoflife.vert", "shaders/gameoflife.frag");

	int uf = GetShaderLocation(gameoflife, "resolution");
	Vector2 resolution{screenWidth, screenHeight};
	SetShaderValue(gameoflife, uf, &resolution, SHADER_UNIFORM_VEC2);

	camera.target.x = 640/2;
	camera.target.y = 480/2;
	camera.offset = { 640/2, 480/2 };
	camera.zoom = 2.f;

	float zoom = 2.f;
	float moveSpeed = 200.f;

	Vector2 look = camera.target;

	Rectangle source{0,0,(float)screenWidth, -(float)screenHeight};

	int time_uniform = GetShaderLocation(gameoflife, "TIME");
	float running_time;
	while(!WindowShouldClose()) {
		running_time = GetTime();
		SetShaderValue(gameoflife, time_uniform, &running_time, SHADER_UNIFORM_FLOAT);
		if (process && timePass >= updateTime) {
			automaton(target[world],target[!world],gameoflife);
			world = !world;
			timePass = 0;
		}
		if (IsKeyPressed(KEY_R)) randomcell(target[world]);
		if (IsKeyPressed(KEY_C)) clearcell(target[world]);
		Vector2 mwheel = GetMouseWheelMoveV();
		zoom += (mwheel.y != 0 ? mwheel.y > 0 ? .1 : -.1 : 0) * !IsKeyDown(KEY_LEFT_CONTROL);

		camera.zoom += (zoom-camera.zoom)/6;

		camera.zoom = Clamp(camera.zoom, 0.1, 20);

		process = IsKeyPressed(KEY_SPACE) ? !process: process;

		float movex = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
		float movey = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

		if(movex || movey) {
			look.x += moveSpeed	* movex * GetFrameTime();
			look.y += moveSpeed	* movey * GetFrameTime();
		}

		camera.target.x += (look.x - camera.target.x)/4;
		camera.target.y += (look.y - camera.target.y)/4;

		Vector2 mouse = GetScreenToWorld2D(GetMousePosition(), camera);
		int i = mouse.x, j = mouse.y;
		
		if (CheckCollisionPointRec(mouse, {0,0,screenWidth,screenHeight})) {
			BeginTextureMode(target[world]);
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
				DrawPixel(i,j, WHITE);	
			}
			if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
				DrawPixel(i,j, BLACK);	
			}
			EndTextureMode();
		}

		updateTime = IsKeyPressed(KEY_ONE) ? 1.f : updateTime;
		updateTime = IsKeyPressed(KEY_TWO) ? 0.5f : updateTime;
		updateTime = IsKeyPressed(KEY_THREE) ? 0.2f : updateTime;
		updateTime = IsKeyPressed(KEY_FOUR) ? 0.1f : updateTime;

		if (IsKeyDown(KEY_LEFT_CONTROL)) {
			float t = 1.0/updateTime+
				((IsKeyPressed(KEY_EQUAL)||mwheel.y > 0)-(IsKeyPressed(KEY_MINUS)||mwheel.y<0));
			t = t <= 0 ? 1 : t;
			updateTime = 1.0/t;
		}
		
		updateTime = Clamp(updateTime, 0, 120);

		BeginDrawing();
		ClearBackground(BLACK);
		{
			BeginMode2D(camera);
			DrawRectangleLines(-1,-1,screenWidth+2,screenHeight+2, Fade(GRAY, 0.2));
			DrawTextureRec(target[world].texture, source, {0,0}, WHITE);
			EndMode2D();
		}

		DrawRectangle(5,5,180,35, Fade(BLACK, 0.8));
		DrawText(TextFormat("FPS - %d, X[%d] Y[%d]", GetFPS(), i, j), 10,10,10, BLUE);
		DrawText(TextFormat("SPEED - %4.f/s", 1.f/updateTime), 10,25,10, BLUE);
		DrawText(TextFormat("Since Run - %4.2f/s", GetTime()), 10,40,10, BLUE);
		DrawText(TextFormat("[[%s]]",process ? "RUNNING":"PAUSE"), 100,25,10, process ? RAYWHITE:GRAY);
		EndDrawing();

		timePass += GetFrameTime();
		all_fps += 1;
	}

	UnloadRenderTexture(target[0]);
	UnloadRenderTexture(target[1]);
	UnloadShader(gameoflife);
	CloseWindow();

	TraceLog(LOG_INFO, TextFormat("Average FPS >> %f", all_fps/running_time));

	return 0;
}
