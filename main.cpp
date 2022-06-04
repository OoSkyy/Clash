#include "raylib.h"
#include "raymath.h"

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("clash_textures/player_idle.png")};
    Texture2D idle{LoadTexture("clash_textures/player_idle.png")};
    Texture2D run{LoadTexture("clash_textures/player_run.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f / 12.f};
    const float speed{4.0f};
};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime)
{
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0f;

    if (Vector2Length(direction) != 0.0f)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        // check if character is moving left or right
        direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    // update animation frame by delta time
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrames)
            frame = 0;
    }

    // draw character
    Rectangle source{frame * (float)texture.width / 6.0f, 0.0f, rightLeft * (float)texture.width / 6.0f, (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    const char *windowTitle{"Clash"};
    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("clash_textures/WorldMap.png");
    Vector2 mapPos{0.0f, 0.0f};

    Character steve;
    steve.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // drawing start
        BeginDrawing();
        ClearBackground(WHITE);
  
        mapPos = Vector2Scale(steve.getWorldPos(), -1.0f);
        DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);

        steve.tick(GetFrameTime());

        // drawing ends
        EndDrawing();
    }
}