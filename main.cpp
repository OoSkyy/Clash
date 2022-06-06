#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"
#include "enemy.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    const char *windowTitle{"Clash"};
    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("clash_textures/WorldMap.png");
    Texture2D statueTex = LoadTexture("clash_textures/knight_statue.png");
    Texture2D logTex = LoadTexture("clash_textures/log.png");
    Texture2D blobIdle = LoadTexture("clash_textures/blob_idle.png");
    Texture2D blobRun = LoadTexture("clash_textures/blob_run.png");

    Vector2 mapPos{0.0f, 0.0f};
    const float mapScale{4.0f};
    Vector2 mapCenter{
        (static_cast<float>(map.width) * mapScale) / 2.0f,
        (static_cast<float>(map.height) * mapScale) / 2.0f};

    Vector2 initialSteveWorldPos{
        mapCenter.x - 140.0f,
        mapCenter.y};
    Character steve(windowWidth, windowHeight, initialSteveWorldPos);

    Prop props[]{
        Prop(statueTex, {mapCenter.x, mapCenter.y - (statueTex.height * mapScale)}),
        Prop(logTex, {mapCenter.x - 600.0f, mapCenter.y - 600.0f})};

    Enemy blob({mapCenter.x + 600.0f, mapCenter.y + 600.f}, blobIdle, blobRun, 5);
    blob.setTarget(&steve);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // drawing start
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(steve.getWorldPos(), -1.0f);
        DrawTextureEx(map, mapPos, 0.0f, mapScale, WHITE);

        for (Prop p : props)
        {
            p.Render(steve.getWorldPos());
        }

        // check map bounds
        steve.tick(GetFrameTime());
        if (steve.getWorldPos().x < 60.0f ||
            steve.getWorldPos().y < 0.0f ||
            steve.getWorldPos().x + windowWidth > (map.width * mapScale) - 60.0f ||
            steve.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            steve.undoMovement();
        }

        for (Prop p : props)
        {
            if (CheckCollisionRecs(p.getCollisionRec(steve.getWorldPos()), steve.getCollisionRec()))
            {
                steve.undoMovement();
            }
        }

        blob.tick(GetFrameTime());

        // drawing ends
        EndDrawing();
    }
}