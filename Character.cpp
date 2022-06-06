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

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.0f)
    {
        origin = {0.0f, weapon.height * (scale / 2)};
        offset = {45.0f, 70.0f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * (scale / 2),
            weapon.width * (scale / 2),
            weapon.height * (scale / 2)
        };
        rotation = 35.0f;
    }
    else
    {
        origin = {weapon.width * (scale / 2), weapon.height * (scale / 2)};
        offset = {15.0f, 70.0f};
            weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * (scale / 2),
            getScreenPos().y + offset.y - weapon.height * (scale / 2),
            weapon.width * (scale / 2),
            weapon.height * (scale / 2)

        };
        rotation = -35.0f;
    }

    // draw the "sword"
    Rectangle source{0.0f, 0.0f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * (scale / 2), weapon.height * (scale / 2)};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x, weaponCollisionRec.y, weaponCollisionRec.width, weaponCollisionRec.height, RED);

    BaseCharacter::tick(deltaTime);
}