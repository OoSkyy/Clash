#include "raylib.h"

class Prop
{
public:
    Prop(Texture2D tex, Vector2 pos);

private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale{4.0f};
};