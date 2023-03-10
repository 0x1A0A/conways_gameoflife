#include "raylib.h"
#include "raygui.h"
#include "raymath.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <atomic>

const int screenWidth = 640;
const int screenHeight = 480;

int world = 0;

static float timePass = 0.f;
static float updateTime = 1.0f;
static bool process = false;

void randomcell(RenderTexture2D &texture) {
	BeginTextureMode(texture);
	ClearBackground(BLACK);
	for (int i{0}; i<screenWidth; ++i) {
		for (int j{0}; j<screenHeight; ++j) {
			if ( GetRandomValue(0,1) ) DrawPixel(i,j, WHITE);	
		}
	}
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

	int uf = GetShaderLocation(gameoflife, "resolutionNormalized");
	Vector2 resNorm{1.0f/screenWidth, 1.0f/screenHeight};
	SetShaderValue(gameoflife, uf, &resNorm, SHADER_UNIFORM_VEC2);

	camera.target.x = 640/2;
	camera.target.y = 480/2;
	camera.offset = { 640/2, 480/2 };
	camera.zoom = 2.f;

	float zoom = 2.f;
	float moveSpeed = 200.f;

	Vector2 look = camera.target;

	randomcell(target[world]);

	Rectangle source{0,0,(float)screenWidth, -(float)screenHeight};
	
	while(!WindowShouldClose()) {
		if (process && timePass >= updateTime) {
			automaton(target[world],target[!world],gameoflife);
			world = !world;
			timePass = 0;
		}
		Vector2 mwheel = GetMouseWheelMoveV();
		zoom += mwheel.y != 0 ?
			mwheel.y > 0 ? .1 : -.1 : 0;

		camera.zoom += ( zoom - camera.zoom )/6;

		camera.zoom = Clamp(camera.zoom, 0.1, 20);

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
		ClearBackground(WHITE);
		{
			BeginMode2D(camera);
			DrawTextureRec(target[world].texture, source, {0,0}, WHITE);
			EndMode2D();
		}

		DrawText(TextFormat("%d", GetFPS()), 10,10,10, BLUE);
		EndDrawing();

		timePass += GetFrameTime();
	}

	UnloadRenderTexture(target[0]);
	UnloadRenderTexture(target[1]);
	UnloadShader(gameoflife);
	CloseWindow();

	return 0;
}
