#include "boss_1.h"

// ���캯��
// ����: tex - �鼮����
Boss1::Boss1(const sf::Texture& tex) : sf::Sprite(tex)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();//��ȡ��Ļ�ֱ���
    setOrigin(sf::Vector2f{ tex.getSize().x / 2.0f , tex.getSize().y / 2.f });//����Book��ԭ��λ��
    setPosition({getGlobalBounds().size.x , getGlobalBounds().size.y / 2 });//���ó���λ��  x�������
    originalHealth = health = 100;//�������ֵ
}

void Boss1::setTexture(const sf::Texture& tex) { texture = tex; }//��������

void Boss1::setHealth(int newHealth) { health = newHealth; }//��������ֵ

int Boss1::getHealth() const { return health; }//��ȡ��ǰ����ֵ

int Boss1::getOriginalHealth() const { return originalHealth; }//��ȡ��ʼ����ֵ

void Boss1::update(sf::Vector2u windowSize) {

    move({vx,0}); // move the ball

    bounce(windowSize); // check for bounces

}

void Boss1::bounce(sf::Vector2u& windowSize)
{
    sf::Vector2f pos = getPosition();
    float radius = getGlobalBounds().size.x / 2.f;

    //left bounce
    if (pos.x - radius <= 0.f) {
        setPosition({ radius, pos.y });
        vx = -vx;
    }

    //right bounce
    if (pos.x + radius >= static_cast<float>(windowSize.x)) {
        setPosition({ static_cast<float>(windowSize.x) - radius, pos.y });
        vx = -vx;
    }
}

void Boss1::attack()
{

}