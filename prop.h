#include "raylib.h"

class Prop
{
public:
    Prop(Texture2D tex, Vector2 pos);
    void Render(Vector2 stevePos);
    Rectangle getCollisionRec(Vector2 stevePos);

private:
    Texture2D texture{};
    Vector2 worldPos{};
    Vector2 screenPos{};
    float scale{4.0f};
};