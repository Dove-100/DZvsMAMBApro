#include "bossBullet.h"

BossBullet::BossBullet(const sf::Texture& texture, sf::Vector2f position)
	:sf::Sprite(texture)
{
	setOrigin(sf::Vector2f{ texture.getSize().x / 2.0f , texture.getSize().y / 2.f });
	setPosition(position);
	isHit = false;
}

void BossBullet::update()
{
	move({ 0, 10 });
}

//设置击中状态
void BossBullet::setIsHit()
{
	isHit = true;
}
//获取是否击中状态
const bool BossBullet::getIsHit()const
{
	return isHit;
}