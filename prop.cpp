#include "prop.h"
#include "raymath.h"

Prop::Prop(Texture2D tex, Vector2 pos) : texture(tex), worldPos(pos)
{
}

void Prop::Render(Vector2 stevePos)
{
    screenPos = Vector2Subtract(worldPos, stevePos);
    DrawTextureEx(texture, screenPos, 0.0f, scale, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 stevePos)
{
    screenPos = Vector2Subtract(worldPos, stevePos);
    return Rectangle {
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale
    };
}