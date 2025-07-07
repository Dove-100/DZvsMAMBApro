#include "animation.h"

Animation::Animation(const sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
    : sprite(t),         // 初始化精灵
    Frame(0),
    speed(Speed)
{
    // 创建动画帧矩形
    for (int i = 0; i < count; i++)
        frames.push_back(sf::IntRect({ x + i * w, y }, { w, h }));

    sprite.setOrigin({ w / 2.0f, h / 2.0f });  // 设置精灵原点为中心
    sprite.setTextureRect(frames[0]);           // 设置初始纹理矩形
}

// 更新动画帧
void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n) Frame -= n;  // 循环播放
    if (n > 0) sprite.setTextureRect(frames[int(Frame)]);
}

// 检查动画是否结束
bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}