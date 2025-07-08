#include "enemy.h"

    // ���캯��
    // ����: tex - �鼮����
Enemy::Enemy(const sf::Texture& tex) : sf::Sprite(tex), velocity(sf::Vector2f{ -BASE_SPEED, -BASE_SPEED })
    {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();//��ȡ��Ļ�ֱ���
        setOrigin(sf::Vector2f{ static_cast<float>(tex.getSize().x / 2) , static_cast<float>(tex.getSize().y) / 2.f });//����Book��ԭ��λ��
        setPosition(sf::Vector2f{ static_cast<float> (std::rand() % desktop.size.x) , -getGlobalBounds().size.y });//���ó���λ��  x�������
        scale = (float)desktop.size.x / 1920;//����ϵ��
        float scales[2] = { scale, -scale };
        velocity.x *= (float)scales[rand() % 30]; // random x axis direction at start ����ٶȷ��򣨶�x�������
        velocity.y *= scale;
        setScale({ scale, scale });//���þ�������
        originalHealth = health = rand() % 10 + 5;//�������ֵ
    }

void Enemy::setTexture(const sf::Texture& tex) { texture = tex; }//��������

void Enemy::setHealth(int newHealth) { health = newHealth; }//��������ֵ

int Enemy::getHealth() const { return health; }//��ȡ��ǰ����ֵ

int Enemy::getOriginalHealth() const { return originalHealth; }//��ȡ��ʼ����ֵ

void Enemy::update(sf::Vector2u windowSize) 
{
    moderateSpeed(); // ��������ٶ�
    move(velocity); // �ƶ�
    bounce(windowSize); // check for bounces
}

void Enemy::moderateSpeed()
{
    if (velocity.x > MAX_SPEED * scale)
        velocity.x = MAX_SPEED * scale;
    else if (velocity.x < -MAX_SPEED * scale)
        velocity.x = MAX_SPEED * scale;
    if (velocity.y > MAX_SPEED * scale)
        velocity.y = MAX_SPEED * scale;
    else if (velocity.y < -MAX_SPEED * scale)
        velocity.y = MAX_SPEED * scale;
}

void Enemy::bounce(sf::Vector2u& windowSize)
{
    sf::Vector2f pos = getPosition();
    float radius = getGlobalBounds().size.x / 2.f;

    //bottom bounce
    if (pos.y + radius >= static_cast<float>(windowSize.y) * (float).88) {
        setPosition({ pos.x, static_cast<float>(windowSize.y) * (float).88 - radius });
        velocity.y = -velocity.y; //bounce the ball
        velocity.x -= BOUNCE_RNDM; //slow down the ball slightly on bounce
    }

    //top bounce
    if (pos.y - radius <= 0.f) {
        setPosition({ pos.x, radius });
        velocity.y = -velocity.y;
        velocity.x -= BOUNCE_RNDM;
    }

    //left bounce
    if (pos.x - radius <= 0.f) {
        setPosition({ radius, pos.y });
        velocity.x = -velocity.x;
        velocity.y -= BOUNCE_RNDM;
    }

    //right bounce
    if (pos.x + radius >= static_cast<float>(windowSize.x)) {
        setPosition({ static_cast<float>(windowSize.x) - radius, pos.y });
        velocity.x = -velocity.x;
        velocity.y -= BOUNCE_RNDM;
    }
}
