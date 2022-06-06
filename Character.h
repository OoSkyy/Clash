#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "baseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight, Vector2 initWorldPos);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("clash_textures/weapon.png")};
};

#endif