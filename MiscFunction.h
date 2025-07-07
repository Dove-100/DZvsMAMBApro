#pragma once
#ifndef _MISCFUNCTION_H_
#define _MISCFUNCTION_H_
#include <SFML/Graphics.hpp>
#include "background.h"
#include "player.h"
#include "boss.h"
#include "boss_1.h"
#include <cstdlib>
#include <ctime>
#include "bossBullet.h"
#include "bullet.h"
#include "enemy.h"
#include <iostream>
#include <fstream>
/**
 * ��ʼ����Ϸ����
 * @return ȫ��ģʽ����Ⱦ���ںʹ��ڳߴ�
 */
sf::RenderWindow initWindow();

/**
*����ģ��
* @param window ��Ϸ�������ã����ڻ�ȡ���ڳߴ磩
* @return ��ʼ����Ķ���
* */
Player loadPlayer(sf::RenderWindow& window);
Boss loadBoss(sf::RenderWindow& window);
Background loadBackground();

 /**
  * ����ӵ��Ƿ���е���
  * @param bullet ����
  * @param enemy ���˶���
  * @return �Ƿ����
  */
extern bool checkShotHit(Bullet& bullet, Enemy& enemy);
extern bool checkShotHitBoss(Bullet& bullet, Boss1& boss);
extern bool checkBossHit(BossBullet& bossbullet, Player& player);
extern bool checkIfPlayerIsHit(Player& player, const Enemy& ball);

/**
 * ��鲢������߷�
 * @param cur ��ǰ����
 * @return �µ���߷�
 */
int checkHighScore(int cur);

int readLastLevel();

void writeLevel(int curlevel);

int readLastScore();

void writeScore(int curScore);

int readlasthealth();

void writeHealth(int curHealth);
/**
 * ���ز���ʼ����Ϸ�ı���ǩ
 * @param window ��Ϸ����
 * @param font �������
 * @param scoreLabel ������ǩ
 * @param healthLabel ����ֵ��ǩ
 * @param highScoreLable ��߷ֱ�ǩ
 */
void loadTexts(sf::RenderWindow& window, sf::Font& font, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable, bool iscontinue);

void DrawGameState(sf::RenderWindow& window, sf::Font& font, Background& background, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable,
std::vector<Enemy> balls,
std::vector<Bullet> bullets,
std::vector<BossBullet> bossbullets,
Player& player, Boss1& boss,
bool isPause);


#endif // !_MISCFUNCTION_H_