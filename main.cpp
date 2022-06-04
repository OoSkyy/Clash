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

    // vectors
    Vector2 mapPos { 0.0f, 0.0f };

    float speed { 4.0f };

    while (!WindowShouldClose())
    {
        // drawing start
        BeginDrawing();
        ClearBackground(WHITE);

        // movement
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0f ;
        if (IsKeyDown(KEY_D)) direction.x += 1.0f ;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0f ;
        if (IsKeyDown(KEY_S)) direction.y += 1.0f ;

        if (Vector2Length(direction) != 0.0f)
        {
            // set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // draw background
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