#include "raylib.h"
#include "baseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex, int frames);
    virtual void tick(float deltaTime) override;
    void setTarget(Character *character);
    virtual Vector2 getScreenPos() override;

private:
    Character *target;
    float damagePerSec {10.0f};
    float radius{25.0f};
};