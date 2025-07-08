#include "drop.h"

Drop::Drop(const sf::Texture& texture, Enemy& enemy)
	: sf::Sprite(texture)
{
	setOrigin(sf::Vector2f{ texture.getSize().x / 2.0f, texture.getSize().y / 2.f });
	setPosition(enemy.getPosition());
}


void Drop::setName(const std::string& dropName)
{
	name = dropName;
}

