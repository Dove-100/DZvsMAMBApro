#include "boss.h"

Boss::Boss(sf::Vector2f position, const sf::Texture& bossTexture)
    : sf::Sprite(bossTexture), texture(bossTexture)
{
    setTexture(texture);//������ҽ�ɫͼƬ
    //setPosition({ position.x / 2, position.y / 1.5f });//����λ��
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();// ��ȡ����ֱ���
    //setScale({ PLAYER_SCALE * desktop.size.x / 1920, PLAYER_SCALE * desktop.size.x / 1920 });//���÷ֱ���
    //speed = PLAYER_SPEED * (static_cast<float>(desktop.size.x) / 1920);//�����ٶ�
    health = 100;//���ý���ֵ
};

//��Ա����
//void Boss::movePlayer(sf::Vector2u windowSize)
//{
//    float radius = getGlobalBounds().size.x / 2.f;
//    sf::Vector2u spriteSize = (getTexture().getSize());//���ô�С
//
//    sf::Vector2f position = getPosition();//λ��
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//        if (position.x > 0)//�����߽�
//            move({ -speed, 0 });
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//        if (position.x + PLAYER_SCALE * spriteSize.x < windowSize.x) //����ұ߽�
//            move({ speed, 0 });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//        if (position.y > 0)//����ϱ߽�
//            move({ 0,-speed });
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//        if (position.y + PLAYER_SCALE * spriteSize.y < windowSize.y * 0.84) //����±߽�
//            move({ 0,speed });
//
//
//
//}

//����ֵ����
//void Player::decrementPlayerHealth()
//{
//    if (health > 0)
//    {
//        health -= 1;
//
//    }
//}
//
