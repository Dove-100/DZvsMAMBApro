// animation.h
#pragma once
#include <SFML/Graphics.hpp>

class Animation : public sf::Sprite {
public:
    Animation(const sf::Texture& texture, int frameCount, float frameTime, sf::Vector2f position);
    void update(float deltaTime);
    bool isFinished() const;
private:
    int frameCount;
    float frameTime;
    float elapsedTime;
    int currentFrame;
    bool finished;
};
