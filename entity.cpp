#include "entity.h"

Entity::Entity() : anim(*(new sf::Texture()), 0, 0, 0, 0, 1, 0.0f) // ռλ��ʼ��
{
    life = 1;
}

// ����ʵ������
void Entity::settings(Animation& a, int X, int Y, float Angle, int radius)
{
    Angle = 0;
	radius = 1;  // Ĭ��ֵ
    anim = a;  // ���ö���
    x = X; y = Y;
    angle = Angle;
    R = radius;
}

// ����ʵ��
void Entity::draw(sf::RenderWindow& app)
{
    anim.sprite.setPosition({ x, y });
    anim.sprite.setRotation(sf::degrees(angle + 90));  // ������ת�Ƕ�
    app.draw(anim.sprite);

	sf::CircleShape circle(R);
    circle.setFillColor(sf::Color(255, 0, 0, 170));
    circle.setPosition({ x, y });
    circle.setOrigin({ R, R });
}