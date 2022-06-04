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
    Texture2D hero = LoadTexture("clash_textures/player.png");

    // vectors
    Vector2 mapPos { 0.0f, 0.0f };
    Vector2 heroPos { 
        (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)hero.width / 6.0f),
        (float)windowHeight / 2.0f - 4.0f *(0.5f * (float)hero.height / 5.0f)   
    };

    float speed { 4.0f };

    // value of 1 is facing right -1 facing left
    float rightLeft { 1.0f };
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
            //check if character is moving left or right
            direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;

        }

        // draw background
        DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);

        // draw character
        Rectangle source { // position in the spritesheet 
            0.0f, // first sprite in row
            (float)hero.height / 5.0f, // second row
            rightLeft * (float)hero.width / 6.0f, 
            (float)hero.height / 5.0f 
        };

        Rectangle dest { // position on screen
            heroPos.x, 
            heroPos.y, 
            4.0f * (float)hero.width /6.0f, 
            4.0f * (float)hero.height / 5.0f 
        };

        DrawTexturePro(hero, source, dest, Vector2{}, 0.0f, WHITE);

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