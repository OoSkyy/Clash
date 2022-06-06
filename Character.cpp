#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight, Vector2 initWorldPos) : windowWidth(winWidth),
                                                                          windowHeight(winHeight)
{
    // set character size
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);

    // set initial character world position
    worldPos = initWorldPos;
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0f;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0f;
    BaseCharacter::tick(deltaTime);
}