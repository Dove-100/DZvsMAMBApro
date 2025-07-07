#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <SFML/Graphics.hpp>  // SFML图形库
#include <time.h>            // 时间函数
#include <list>              // 链表容器
#include<iostream>           // 输入输出流
#include<string>             // 字符串处理
#include <format>            // 格式化库


class Animation
{
public:
    Animation(const sf::Texture& t, int x, int y, int w, int h, int count, float Speed);

    // 更新动画帧
    void update();

    // 检查动画是否结束
    bool isEnd();

	float Frame, speed;      // 当前帧和动画速度
	sf::Sprite sprite;       // 精灵对象
	std::vector<sf::IntRect> frames;  // 动画帧矩形集合
};


#endif // !_ANIMATION_H_
