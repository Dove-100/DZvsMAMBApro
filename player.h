#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <SFML/Audio.hpp>
#include <SFML/graphics.hpp>
#include <string>

using std::string;
#define PLAYER_SCALE 0.15f
#define PLAYER_SPEED 7.f

class Player : public sf::Sprite
{
public:
    Player(sf::Vector2f position = { 0.f, 0.f }, const sf::Texture& playerTexture = sf::Texture());//��ʼ������ҵ�λ�ú�ͼƬ

    void movePlayer(sf::Vector2u windowSize);//�ƶ�

    void decrementPlayerHealth();//���ٽ���ֵ

    int getHealth() const { return health; }//��ȡ����ֵ

    void setHealth(int newHealth) { health = newHealth; }//���ý���ֵ

private:
    sf::Texture texture;//ͼƬ
    float speed;//�ٶ�
    int health;//����ֵ
};

#endif