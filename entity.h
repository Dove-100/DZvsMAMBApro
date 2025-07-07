#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <SFML/Graphics.hpp>  // SFML图形库
#include <SFML/Window/Window.hpp>  // SFML窗口
#include "animation.h"  // 动画类头文件


class Entity
{
public:
    Entity();

    // 设置实体属性
    void settings(Animation& a, int X, int Y, float Angle, int radius);

    virtual void update() {};  // 虚函数，子类实现更新逻辑

    // 绘制实体
    void draw(sf::RenderWindow& app);

	float x, y, dx, dy, R, angle;  // 位置、速度、半径、角度
	bool life;                      // 是否存活
	std::string name;               // 实体名称
	Animation anim;                 // 动画对象
};


#endif // !_ENTITY_H_
