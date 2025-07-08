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

	std::string getName() const { return name; }  // ��ȡ����������

private:
	std::string name;  // ����������
};


#endif // !_DROP_H_
