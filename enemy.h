#include "raylib.h"

class Enemy
{
public:
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
    Vector2 getWorldPos();
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();

private:
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float width{};
    float height{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{4};
    float updateTime{1.f / 12.f};
    float speed{4.0f};
    float scale{4.0f};
};