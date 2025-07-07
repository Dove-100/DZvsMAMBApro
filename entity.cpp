#include "entity.h"

Entity::Entity() : anim(*(new sf::Texture()), 0, 0, 0, 0, 1, 0.0f) // 占位初始化
{
    life = 1;
}

// 设置实体属性
void Entity::settings(Animation& a, int X, int Y, float Angle, int radius)
{
    Angle = 0;
	radius = 1;  // 默认值
    anim = a;  // 设置动画
    x = X; y = Y;
    angle = Angle;
    R = radius;
}

// 绘制实体
void Entity::draw(sf::RenderWindow& app)
{
    anim.sprite.setPosition({ x, y });
    anim.sprite.setRotation(sf::degrees(angle + 90));  // 设置旋转角度
    app.draw(anim.sprite);

	sf::CircleShape circle(R);
    circle.setFillColor(sf::Color(255, 0, 0, 170));
    circle.setPosition({ x, y });
    circle.setOrigin({ R, R });
}