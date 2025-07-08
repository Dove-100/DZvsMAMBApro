// animation.cpp
#include "animation.h"

Animation::Animation(const sf::Texture& texture, int frameCount, float frameTime, sf::Vector2f position)
    : sf::Sprite(texture), frameCount(frameCount), frameTime(frameTime), elapsedTime(0), currentFrame(0), finished(false)
{
    setTexture(texture);
    setPosition(position);
    setTextureRect(sf::IntRect({ 0, 0 }, { 256,256 }));
    //setOrigin({ texture.getSize().x / 2.0f, texture.getSize().y / 2.0f });
}

void Animation::update(float deltaTime) {
    if (finished) return;
    elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        elapsedTime = 0;
        currentFrame++;
        if (currentFrame >= frameCount) {
            finished = true;
            return;
        }
        setTextureRect(sf::IntRect({ currentFrame * 256, 0 },
            { 256, 256 }));
    }
}

bool Animation::isFinished() const {
    return finished;
}

