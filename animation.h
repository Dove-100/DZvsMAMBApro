#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <SFML/Graphics.hpp>  // SFMLͼ�ο�
#include <time.h>            // ʱ�亯��
#include <list>              // ��������
#include<iostream>           // ���������
#include<string>             // �ַ�������
#include <format>            // ��ʽ����


class Animation
{
public:
    Animation(const sf::Texture& t, int x, int y, int w, int h, int count, float Speed);

    // ���¶���֡
    void update();

    // ��鶯���Ƿ����
    bool isEnd();

	float Frame, speed;      // ��ǰ֡�Ͷ����ٶ�
	sf::Sprite sprite;       // �������
	std::vector<sf::IntRect> frames;  // ����֡���μ���
};


#endif // !_ANIMATION_H_
