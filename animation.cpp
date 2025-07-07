#include "animation.h"

Animation::Animation(const sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
    : sprite(t),         // ��ʼ������
    Frame(0),
    speed(Speed)
{
    // ��������֡����
    for (int i = 0; i < count; i++)
        frames.push_back(sf::IntRect({ x + i * w, y }, { w, h }));

    sprite.setOrigin({ w / 2.0f, h / 2.0f });  // ���þ���ԭ��Ϊ����
    sprite.setTextureRect(frames[0]);           // ���ó�ʼ�������
}

// ���¶���֡
void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n) Frame -= n;  // ѭ������
    if (n > 0) sprite.setTextureRect(frames[int(Frame)]);
}

// ��鶯���Ƿ����
bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}