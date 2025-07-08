#pragma once
#ifndef _DROP_H_
#define _DROP_H_
#include <SFML/Graphics.hpp>
#include <string>
#include "enemy.h"


class Drop : public sf::Sprite
{
public:
	Drop(const sf::Texture& texture, Enemy& enemy);

	void setName(const std::string& dropName);

	std::string getName() const { return name; }  // 获取掉落物名称

private:
	std::string name;  // 掉落物名称
};


#endif // !_DROP_H_
