#pragma once
#ifndef _BOSS_1_H_
#define _BOSS_1_H_
#include <SFML/graphics.hpp>  
#include <cmath>  

class Boss1 : public sf::Sprite {
public:
    // ���캯��
    // ����: tex - Boss1����
    Boss1(const sf::Texture& tex);

    void update(sf::Vector2u windowSize);  //����Boss1λ�á��ٶȡ��߽���

    void bounce(sf::Vector2u& windowSize);//�߽���

    void setTexture(const sf::Texture& tex);//��������

    void setHealth(int newHealth);//��������ֵ

    int getHealth() const;//��ȡ��ǰ����ֵ

    int getOriginalHealth() const;//��ȡ��ʼ����ֵ

    void attack();

private:
    float vx = 5;  //�ٶ�
    float vy = 0;
    sf::Texture texture;//����
    int health;//����ֵ
    int originalHealth;//��ʼ����ֵ
};

#endif