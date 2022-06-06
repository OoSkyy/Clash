#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"
#include "enemy.h"
#include <string>
using namespace std;

int main()
{
    const int windowWidth{600};
    const int windowHeight{600};
    const string windowTitle{"Clash"};
    InitWindow(windowWidth, windowHeight, windowTitle.c_str());

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

    Enemy blobOne{{mapCenter.x - 600.0f, mapCenter.y - 600.0f}, blobIdle, blobRun, 5};
    Enemy blobTwo{{mapCenter.x + 600.0f, mapCenter.y - 600.0f}, blobIdle, blobRun, 5};
    Enemy blobThree{{mapCenter.x + 600.0f, mapCenter.y + 600.f}, blobIdle, blobRun, 5};
    Enemy blobFour{{mapCenter.x + 600.0f, mapCenter.y + 600.0f}, blobIdle, blobRun, 5};
    Enemy blobFive{{mapCenter.x + 750.0f, mapCenter.y}, blobIdle, blobRun, 5};
    Enemy blobSix{{mapCenter.x - 750.0f, mapCenter.y}, blobIdle, blobRun, 5};
    Enemy blobSeven{{mapCenter.x, mapCenter.y + 800.0f}, blobIdle, blobRun, 5};
    Enemy blobEight{{mapCenter.x, mapCenter.y - 800.0f}, blobIdle, blobRun, 5};

    Enemy *enemies[]{
        &blobOne, &blobTwo, &blobThree, &blobFour, &blobFive, &blobSix, &blobSeven, &blobEight};

    for (Enemy *blob : enemies)
    {
        blob->setTarget(&steve);
    }

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

        if (!steve.getAlive())
        {
            DrawText("Game Over!", 55.0f, 45.0f, 40, RED);
            EndDrawing();
            continue;
        }
        else
        {
            string steveHealth = "Health: ";
            steveHealth.append(to_string(steve.getHealth()), 0, 5);
            steveHealth.append("/100.0");
            DrawText(steveHealth.c_str(), 55.0f, 45.0f, 30, RED);
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

        for (Enemy *blob : enemies)
        {
            blob->tick(GetFrameTime());
        }

        for (Prop p : props)
        {
            if (CheckCollisionRecs(p.getCollisionRec(steve.getWorldPos()), steve.getCollisionRec()))
            {
                steve.undoMovement();
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (Enemy *blob : enemies)
            {
                if (CheckCollisionRecs(blob->getCollisionRec(), steve.getCollisionRec()))
                {
                    blob->setAlive(false);
                }
            }
        }

        // drawing ends
        EndDrawing();
    }
}