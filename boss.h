#pragma once
#ifndef _BOSS_H_
#define _BOSS_H_
#include <SFML/Audio.hpp>
#include <SFML/graphics.hpp>
class Boss : public sf::Sprite
{
public:
    Boss(sf::Vector2f position = { 0.f, 0.f }, const sf::Texture& bossTexture = sf::Texture());//��ʼ����boss��λ�ú�ͼƬ

    int getHealth() const { return health; }//��ȡ����ֵ

    void setHealth(int newHealth) { health = newHealth; }//���ý���ֵ

private:
    sf::Texture texture;//ͼƬ
    int health;//����ֵ
};


#endif // !_BOSS_H_
