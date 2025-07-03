#pragma once
#ifndef _BOSSBULLET_H_
#define _BOSSBULLET_H_
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "boss_1.h"

class BossBullet : public sf::Sprite
{
public:
	BossBullet(const sf::Texture& texture, sf::Vector2f position);

	void update();

	//设置击中状态
	void setIsHit();
	//获取是否击中状态
	const bool getIsHit()const;

private:
	float speed = 10;
	bool isHit;
};


#endif // !_BOSSBULLET_H_
