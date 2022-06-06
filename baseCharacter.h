#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() const;
    Rectangle getCollisionRec();
    void undoMovement();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() const;
    void setAlive(bool isAlive);

protected:
    Texture2D texture{LoadTexture("clash_textures/player_idle.png")};
    Texture2D idle{LoadTexture("clash_textures/player_idle.png")};
    Texture2D run{LoadTexture("clash_textures/player_run.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float width{};
    float height{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.0f};
    float scale{4.0f};
    Vector2 velocity{};

private:
    bool alive{true};
};

#endif