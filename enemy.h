#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <SFML/graphics.hpp>  
#include <cmath>

#define MAX_SPEED 4
#define BOUNCE_RNDM .1
#define BASE_SPEED 2

class Enemy : public sf::Sprite {
public:
    // ���캯��
    // ����: tex - ��������
    Enemy(const sf::Texture& tex);

    sf::Vector2f getVelocity() const { return velocity; }//��ȡ�ٶ�ʸ��

    void update(sf::Vector2u windowSize);  //���µ���λ�á��ٶȡ��߽���

    void moderateSpeed();//�����ٶȲ���������ٶ�

    void bounce(sf::Vector2u& windowSize);//�߽���

    void setTexture(const sf::Texture& tex);//��������

    void setHealth(int newHealth);//��������ֵ

    int getHealth() const;//��ȡ��ǰ����ֵ

    int getOriginalHealth() const;//��ȡ��ʼ����ֵ

private:
    sf::Vector2f velocity;  //�ٶ�ʸ��
    float scale; //����ϵ��
    sf::Texture texture;//����
    int health;//����ֵ
    int originalHealth;//��ʼ����ֵ
};

#endif