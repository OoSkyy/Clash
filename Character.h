#include "raylib.h"
#include "baseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight, Vector2 initWorldPos);

    void tick(float deltaTime);

private:

};