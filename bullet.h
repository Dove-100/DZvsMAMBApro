#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

class Bullet : public sf::Sprite
{
public:
    // ���캯��������һ���ӵ�����
    // ������
    //   texture - �ӵ�������
    //   position - ��ʼλ��
    Bullet(const sf::Texture& texture, sf::Vector2f position);

    //����Ǧ��״̬
    // ������
     //   window - ��Ϸ��������
     //   laserSound - ������Ч����
     //   player - ��Ҷ���
    void update(const sf::RenderWindow& window, sf::Music& laserSound, Player player);
    //��ȡ���״̬
    bool getIsShooting()const;
    //�������״̬
    void setIsShooting(bool isShootingNewValue);
    //���û���״̬
    void setIsHit();
    //��ȡ�Ƿ����״̬
    const bool getIsHit()const;

private:
    float speed;//ģ�ٶ�
    bool isShooting;//�Ƿ���
    bool isHit;//�Ƿ����
    bool hadShooted;//�Ƿ��Ѿ�����
    sf::Vector2f velocity_bullet;  //�ٶ�ʸ��
};
#endif // !_BULLET_H_