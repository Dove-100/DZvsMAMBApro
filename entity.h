#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <SFML/Graphics.hpp>  // SFMLͼ�ο�
#include <SFML/Window/Window.hpp>  // SFML����
#include "animation.h"  // ������ͷ�ļ�


class Entity
{
public:
    Entity();

    // ����ʵ������
    void settings(Animation& a, int X, int Y, float Angle, int radius);

    virtual void update() {};  // �麯��������ʵ�ָ����߼�

    // ����ʵ��
    void draw(sf::RenderWindow& app);

	float x, y, dx, dy, R, angle;  // λ�á��ٶȡ��뾶���Ƕ�
	bool life;                      // �Ƿ���
	std::string name;               // ʵ������
	Animation anim;                 // ��������
};


#endif // !_ENTITY_H_
