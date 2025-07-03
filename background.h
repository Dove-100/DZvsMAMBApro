#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_
#include <SFML/graphics.hpp>  // ����SFMLͼ��ģ��
#include <string>             // �����ַ�����

// �����࣬�̳���SFML��Sprite��
class Background : public sf::Sprite
{
public:
    // ���캯��
    // ������
    //   texture - ������������
    //   position - ������ʼλ�ã�Ĭ��Ϊ(0,0)
    Background(const sf::Texture& texture, sf::Vector2f position = { 0.f, 0.f });

private:
    sf::Texture texture;  // �洢��������
    float scale;          // �������ű���
};

#endif