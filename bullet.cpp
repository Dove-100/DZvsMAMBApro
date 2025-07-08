#include "bullet.h"
    //constructor creates a pencil
    // ���캯��������һ��Ǧ�ʶ���
    // ������
    //   texture - Ǧ�ʵ�����
    //   position - ��ʼλ��
Bullet::Bullet(const sf::Texture& texture, sf::Vector2f position) :
        sf::Sprite(texture)
    {
        setPosition(position);//����Ǧ�ʳ�ʼλ��
        setScale(sf::Vector2f(0.1f, 0.1f));//�������Ŵ�С
        velocity_bullet = { 0,0 };
        hadShooted = false;
        isShooting = false;//��ʼ״̬��δ���
        isHit = false;//��ʼ״̬��δ����
        speed = 50;//�ٶȣ�30
    }
    //����Ǧ��״̬
    // ������
     //   window - ��Ϸ��������
     //   laserSound - ������Ч����
     //   player - ��Ҷ���
    void Bullet::update(const sf::RenderWindow& window, sf::Music& laserSound, Player player)
    {
        sf::Vector2u windowSize = window.getSize(); //��ȡ����ֱ���
        if (!isShooting)
        {
            setPosition({ player.getPosition().x, player.getPosition().y });
        }
        //�����Ǧ���ƶ�
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
        //������
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && bulletClock.getElapsedTime().asSeconds() >= bulletShootRate)
        {
            isShooting = true;
            laserSound.play();
			bulletClock.restart(); // ���ü�ʱ��
        }
    }


    float Bullet::bulletShootRate = 0.1f; // �ӵ�������ʱ�䣨�룩

    //��ȡ���״̬
    bool Bullet::getIsShooting()const//get value of isShooting
    {
        return isShooting;
    }
    //�������״̬
    void Bullet::setIsShooting(bool isShootingNewValue)
    {
        isShooting = isShootingNewValue;
    }
    //���û���״̬
    void Bullet::setIsHit()
    {
        isHit = true;
    }
    //��ȡ�Ƿ����״̬
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
		return bulletShootRate;  // ���ص�ǰ�������
	}