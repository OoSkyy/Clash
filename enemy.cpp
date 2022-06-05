#include "enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) :
    texture(idle_tex),
    idle(idle_tex),
    run(run_tex),
    worldPos(pos)
{
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
}

Vector2 Enemy::getWorldPos()
{
    return worldPos;
}

void Enemy::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

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
    Rectangle source{frame * width, 0.0f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Enemy::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Enemy::getCollisionRec()
{
        return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}