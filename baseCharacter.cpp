#include "baseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

Vector2 BaseCharacter::getWorldPos()
{
    return worldPos;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}
