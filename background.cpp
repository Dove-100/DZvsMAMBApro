#include "background.h"
using std::string;            // ʹ�ñ�׼���е�string


// ���캯��ʵ��
Background::Background(const sf::Texture& texture, sf::Vector2f position)
    : sf::Sprite(texture),   // ��ʼ������Sprite
    texture(texture)       // ��ʼ����Աtexture
    {
        // ���þ���ʹ�õ�����
        setTexture(this->texture);

        // ���þ���λ��
        setPosition(position);

        // ��ȡ��ǰ����ֱ���
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

        // ���㲢�������ű�����ʹ��������������Ļ
        // ���㷽������Ļ���/�����ȣ���Ļ�߶�/����߶�
        setScale({
            (float)desktop.size.x / texture.getSize().x,  // ˮƽ���ű���
            (float)desktop.size.y / texture.getSize().y   // ��ֱ���ű���
            });
    }