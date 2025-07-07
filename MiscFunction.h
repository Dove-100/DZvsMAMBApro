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
 * 初始化游戏窗口
 * @return 全屏模式的渲染窗口和窗口尺寸
 */
sf::RenderWindow initWindow();

/**
*加载模块
* @param window 游戏窗口引用（用于获取窗口尺寸）
* @return 初始化后的对象
* */
Player loadPlayer(sf::RenderWindow& window);
Boss loadBoss(sf::RenderWindow& window);
Background loadBackground();

 /**
  * 检测子弹是否击中敌人
  * @param bullet 对象
  * @param enemy 敌人对象
  * @return 是否击中
  */
extern bool checkShotHit(Bullet& bullet, Enemy& enemy);
extern bool checkShotHitBoss(Bullet& bullet, Boss1& boss);
extern bool checkBossHit(BossBullet& bossbullet, Player& player);
extern bool checkIfPlayerIsHit(Player& player, const Enemy& ball);

/**
 * 检查并更新最高分
 * @param cur 当前分数
 * @return 新的最高分
 */
int checkHighScore(int cur);

int readLastLevel();

void writeLevel(int curlevel);

int readLastScore();

void writeScore(int curScore);

int readlasthealth();

void writeHealth(int curHealth);
/**
 * 加载并初始化游戏文本标签
 * @param window 游戏窗口
 * @param font 字体对象
 * @param scoreLabel 分数标签
 * @param healthLabel 生命值标签
 * @param highScoreLable 最高分标签
 */
void loadTexts(sf::RenderWindow& window, sf::Font& font, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable, bool iscontinue);

void DrawGameState(sf::RenderWindow& window, sf::Font& font, Background& background, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable,
std::vector<Enemy> balls,
std::vector<Bullet> bullets,
std::vector<BossBullet> bossbullets,
Player& player, Boss1& boss,
bool isPause);


#endif // !_MISCFUNCTION_H_