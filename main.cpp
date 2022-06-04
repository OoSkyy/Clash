#include "raylib.h"
#include "raymath.h"

int main()
{
    // window dimensions and settings
    const int windowWidth{ 384 };
    const int windowHeight{ 384 };
    SetTargetFPS( 60 );
    const char* windowTitle { "Clash" };

    InitWindow(windowWidth, windowHeight, windowTitle);
    
    // textures
    Texture2D map = LoadTexture("clash_textures/WorldMap.png");
    while (!WindowShouldClose())
    {
        // drawing start
        BeginDrawing();
        ClearBackground(WHITE);

        // draw background
        
        Vector2 mapPos { 0.0f, 0.0f};
        DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);

        ////
        //   game logic starts
        ////
        
        ////
        //   game logic ends
        ////

        //drawing ends
        EndDrawing();
    }

}