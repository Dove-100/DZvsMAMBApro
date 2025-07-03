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

//���û���״̬
void BossBullet::setIsHit()
{
	isHit = true;
}
//��ȡ�Ƿ����״̬
const bool BossBullet::getIsHit()const
{
	return isHit;
}