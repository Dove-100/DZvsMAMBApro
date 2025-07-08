#include "bullet.h"
    //constructor creates a pencil
    // 构造函数：创建一个铅笔对象
    // 参数：
    //   texture - 铅笔的纹理
    //   position - 初始位置
Bullet::Bullet(const sf::Texture& texture, sf::Vector2f position) :
        sf::Sprite(texture)
    {
        setPosition(position);//设置铅笔初始位置
        setScale(sf::Vector2f(0.1f, 0.1f));//设置缩放大小
        velocity_bullet = { 0,0 };
        hadShooted = false;
        isShooting = false;//初始状态：未射击
        isHit = false;//初始状态：未射中
        speed = 50;//速度：30
    }
    //更新铅笔状态
    // 参数：
     //   window - 游戏窗口引用
     //   laserSound - 激光音效引用
     //   player - 玩家对象
    void Bullet::update(const sf::RenderWindow& window, sf::Music& laserSound, Player player)
    {
        sf::Vector2u windowSize = window.getSize(); //获取桌面分辨率
        if (!isShooting)
        {
            setPosition({ player.getPosition().x, player.getPosition().y });
        }
        //射击，铅笔移动
        if (isShooting && !hadShooted)
        {
            float x = sf::Mouse::getPosition().x;
            float y = sf::Mouse::getPosition().y;

            float xy = sqrt((x - player.getPosition().x) * (x - player.getPosition().x) + (y - player.getPosition().y) * (y - player.getPosition().y));
            velocity_bullet = { (x - player.getPosition().x) / xy * speed, (y - player.getPosition().y) / xy * speed };
            hadShooted = true;
            return;
        }
        if (hadShooted) {
            move(velocity_bullet);
        }
        //左键射击
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && bulletClock.getElapsedTime().asSeconds() >= bulletShootRate)
        {
            isShooting = true;
            laserSound.play();
			bulletClock.restart(); // 重置计时器
        }
    }


    float Bullet::bulletShootRate = 0.1f; // 子弹发射间隔时间（秒）

    //获取射击状态
    bool Bullet::getIsShooting()const//get value of isShooting
    {
        return isShooting;
    }
    //设置射击状态
    void Bullet::setIsShooting(bool isShootingNewValue)
    {
        isShooting = isShootingNewValue;
    }
    //设置击中状态
    void Bullet::setIsHit()
    {
        isHit = true;
    }
    //获取是否击中状态
    const bool Bullet::getIsHit() const
    {
        return isHit;
    }

	void Bullet::setshootRate(float rate)
	{
		bulletShootRate = rate;
	}
	float Bullet::getshootRate()
	{
		return bulletShootRate;  // 返回当前射击速率
	}