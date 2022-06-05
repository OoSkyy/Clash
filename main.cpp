#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    const char *windowTitle{"Clash"};
    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("clash_textures/WorldMap.png");
    Vector2 mapPos{0.0f, 0.0f};
    const float mapScale{4.0f};
    Vector2 initialWorldPos{200.0f, 200.0f};

    Character steve(windowWidth, windowHeight, initialWorldPos);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // drawing start
        BeginDrawing();
        ClearBackground(WHITE);
  
        mapPos = Vector2Scale(steve.getWorldPos(), -1.0f);
        DrawTextureEx(map, mapPos, 0.0f, mapScale, WHITE);

        // check map bounds
        steve.tick(GetFrameTime());
        if (steve.getWorldPos().x < 60.0f || 
            steve.getWorldPos().y < 0.0f || 
            steve.getWorldPos().x + windowWidth > (map.width * mapScale) - 60.0f ||
            steve.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            steve.undoMovement();
        }

        // drawing ends
        EndDrawing();
    }
}