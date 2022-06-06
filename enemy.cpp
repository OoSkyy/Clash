#include "enemy.h"
#include "raymath.h"
#include "Character.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex, int frames)
{
    worldPos = pos;
    texture = idle_tex;
    idle = idle_tex;
    run = run_tex;
    maxFrames = frames;
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
    speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{
    // get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    //BaseCharacter::tick(deltaTime);
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}

void Enemy::setTarget(Character *character)
{
    target = character;
}