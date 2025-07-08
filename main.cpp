#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "menu.h"
#include "player.h"
#include "boss.h"
#include "boss_1.h"
#include "background.h"
#include "enemy.h"
#include "Windows.h"
#include "MiscFunction.h"
#include "bullet.h"
#include "bossBullet.h"
#include "gameOverpage.h"
#include "drop.h"
#include "animation.h"

bool isPause = false; // 游戏是否暂停

int main()
{
    std::vector<Animation> explosions;
    sf::Texture explosionTexture;
    explosionTexture.loadFromFile("PNG/type_C.png"); // 假设为横向帧图
    int explosionFrameCount = 48; // 帧数
    float explosionFrameTime = 0.05f; // 每帧时间

    /*-------------------------------------------- 加载模块 ---------------------------------------- */
    // 初始化随机数种子
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 初始化窗口并获取窗口尺寸
    sf::RenderWindow window = initWindow();
    sf::Vector2u windowSize = window.getSize();

    // 加载菜单背景音乐
    sf::Music menuMusic;
    menuMusic.openFromFile("danceWeapon4.mp3");  // 加载音乐文件
    menuMusic.setVolume(10);  // 设置音量
    menuMusic.play();  // 播放音乐
    menuMusic.setLooping(true);  // 设置循环播放

    // 加载游戏背景音乐
    sf::Music gameMusic;
    gameMusic.openFromFile("track1.mp3");
    gameMusic.setVolume(15);

    // 加载玩家角色
    Player player = loadPlayer(window);
    Boss boss = loadBoss(window);

    // 加载背景
    Background background = loadBackground();

    // 初始化游戏分数
    int score = 0;

    // 加载激光音效
    sf::Music laserSound;
    laserSound.openFromFile("hit_sound.mp3");

    // 加载碰撞音效
    sf::Music hitSound;
    hitSound.openFromFile("pencil_hit.mp3");

    // 加载boss攻击音效
    sf::Music bossHitSound;
    bossHitSound.openFromFile("boss/boss_hit_sound.mp3");

    // 加载boss失败音效
    sf::Music bossSound;
    bossSound.openFromFile("boss/boss_voice.mp3");

    // 加载敌人纹理
    sf::Texture enemyTextures[3];
    enemyTextures[0].loadFromFile("PNG/googly-a.png");
    enemyTextures[1].loadFromFile("PNG/googly-b.png");
    enemyTextures[2].loadFromFile("PNG/googly-c.png");

    //加载掉落物纹理
	sf::Texture dropTexture[2];
	dropTexture[0].loadFromFile("PNG/health.png");  // 加载生命值掉落物纹理
	dropTexture[1].loadFromFile("PNG/shootingRate.png");  // 加载攻速掉落物纹理

    //加载Boss纹理
    sf::Texture bossTexture;

    // 创建存储敌人和子弹的容器
    std::vector<Enemy> balls;
    std::vector<Bullet> bullets;
    std::vector<BossBullet> bossbullets;
	std::vector<Drop> drops;  // 存储掉落物

    // 创建第一个敌人对象
    Enemy firstEnemy(enemyTextures[std::rand() % 3]);  // 随机选择纹理
    float scale = 0.1f + ((float)(std::rand() % 5 + 1) / 60); // 随机缩放比例(0.1到0.15之间)
    firstEnemy.setScale({ scale, scale });
    balls.push_back(firstEnemy);

    // 加载第一个子弹对象
    sf::Texture bulletTex;
    bulletTex.loadFromFile("PNG/circle_bullet.png");
    Bullet bullet(bulletTex, player.getPosition());
    bullets.push_back(bullet);

    // 初始化计时器用于控制生成间隔
    sf::Clock ball_spawn_clock;  // 敌人生成计时器
    sf::Clock bullet_spawn_clock;  // 子弹生成计时器
    sf::Clock hitRestrictor;  // 击中限制计时器
    sf::Clock boss_hit_clock;
    sf::Clock hitbossRestrictor;
    sf::Clock clock;

    // 加载字体
    sf::Font font;
    font.openFromFile("PressStart2P-Regular.ttf");
    // 创建文本对象
    sf::Text scoreLabel(font);  // 分数显示
    sf::Text healthLabel(font);  // 生命值显示
    sf::Text highScoreLable(font);  // 最高分显示

    // 设置初始生成速率
    float enemySpawnRate = 4;  // 敌人生成速率(秒)
    float pencilSpawnRate = 0.1;  // 子弹生成速率(秒)
    float bossHitRate = 4;

    // 显示开始菜单
    Menu menu(background.getTexture(), player.getTexture(), boss.getTexture(), font, windowSize);
    int level = menu.startMenu(window);
	bool isContinuelast = menu.isContinueLast();  // 检查是否继续上次游戏
    if (level == 1) {
        bossTexture.loadFromFile("boss/green_boss.png");
    }
    else if (level == 2) {
        bossTexture.loadFromFile("boss/red_boss.png");
    }
    else if (level == 3)
    {
        bossTexture.loadFromFile("boss/blue_boss.png");
    }

    // 创建boss对象
    Boss1 firstBoss(bossTexture);

    if (level == 1) {
        writeLevel(level);
        firstBoss.setHealth(100);
    }
    else if (level == 2) {
        writeLevel(level);
        firstBoss.setHealth(200);
    }
    else if (level == 3)
    {
        writeLevel(level);
        firstBoss.setHealth(300);
    }
	// 如果是继续上次游戏，读取上次的生命值
    if (isContinuelast) 
    {
		player.setHealth(readlasthealth());  // 恢复玩家生命值
		score = readLastScore();  // 恢复分数
    }

    // 设置文本样式
    loadTexts(window, font, scoreLabel, healthLabel, highScoreLable, isContinuelast);

    //加载boss子弹纹理
    sf::Texture bossBullet;
    bossBullet.loadFromFile("PNG/basketball.png");
    BossBullet firstBullet(bossBullet, firstBoss.getPosition());
    bossbullets.push_back(firstBullet);

    // 停止菜单音乐，开始游戏音乐
    menuMusic.stop();
    gameMusic.play();
    gameMusic.setLooping(true);
    /* ------------------------------------------- 加载模块 ---------------------------------------- */
    // 主游戏循环
    while (window.isOpen())
    {
        // 事件处理循环
        while (const std::optional event = window.pollEvent())
        {
            // 按ESC键关闭窗口
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
            {
                writeHealth(player.getHealth());  // 保存玩家生命值
				writeScore(score); // 保存当前分数
                window.close();
            }
			if (auto* key = event->getIf<sf::Event::KeyPressed>())
			{
				// 按下空格键时，玩家射击
				if (key->scancode == sf::Keyboard::Scancode::P)
				{
					isPause = !isPause;  // 切换暂停状态
				}
			}
        }
        if (!isPause)
        {
            /* ------------------------------------- 实体生成模块 --------------------------------------- */
            // 敌人生成逻辑
            if (ball_spawn_clock.getElapsedTime().asSeconds() >= enemySpawnRate)
            {
                // 创建新敌人
                Enemy newBall(enemyTextures[std::rand() % 3]);
                float scale = 0.1f + ((float)(std::rand() % 5 + 1) / 60);
                newBall.setScale({ scale, scale });
                balls.push_back(newBall);
                ball_spawn_clock.restart();
                // 逐渐增加难度(减少生成间隔)
                if (enemySpawnRate > 1) enemySpawnRate -= 0.1f;
                std::cout << "Number of balls: " << balls.size() << std::endl;
            }
            // 子弹生成逻辑
            if (bullets[bullets.size() - 1].getIsShooting() == true &&
                bullet_spawn_clock.getElapsedTime().asSeconds() >= pencilSpawnRate)
            {
                Bullet newPencil(bulletTex, player.getPosition());
                bullets.push_back(newPencil);
                bullet_spawn_clock.restart();
            }
            // boss子弹生成逻辑
            if (boss_hit_clock.getElapsedTime().asSeconds() >= bossHitRate)
            {
                BossBullet newbossbullet(bossBullet, firstBoss.getPosition());
                bossbullets.push_back(newbossbullet);
                boss_hit_clock.restart();
            }
            /* ------------------------------------- 实体生成模块 --------------------------------------- */

            /* --------------------------------- 所有游戏对象更新模块 ------------------------------------ */
            //更新boss
            firstBoss.update(window.getSize());
            // 更新所有敌人
            for (auto& ball : balls)
            {
                ball.update(window.getSize());
                if (ball.getHealth() <= 0)  // 如果敌人生命值耗尽
                {
                    explosions.emplace_back(explosionTexture, explosionFrameCount, explosionFrameTime, sf::Vector2f({ ball.getPosition().x - 128,ball.getPosition().y - 128 }));
                    if (srandbuff() == 1)
                    {
                        Drop drop(dropTexture[0], ball);
                        drop.setName("health");
						drops.push_back(drop);  // 添加生命值掉落物
                    }
					else if (srandbuff() == 2)
					{
						Drop drop(dropTexture[1], ball);
                        drop.setName("shootingRate");
                        drops.push_back(drop);  // 添加攻速掉落物
                    }
                    score += ball.getOriginalHealth() * 8;  // 增加分数
                    ball.setHealth(0);
                    // 从向量中移除被摧毁的敌人
                    balls.erase(std::remove_if(balls.begin(), balls.end(),
                        [](const Enemy& b) { return b.getHealth() <= 0; }), balls.end());
                    scoreLabel.setString("Score: " + std::to_string(score));  // 更新分数显示
                }
            }
            // 更新所有子弹
            for (auto& bullet : bullets)
            {
                bullet.update(window, laserSound, player);
                // 如果子弹击中目标或飞出屏幕，且子弹数量大于2
                if ((bullet.getIsHit() || bullet.getPosition().y < 0) && bullets.size() > 2)
                {
                    // 从向量中移除子弹
                    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                        [](const Bullet& p) { return p.getIsHit() || p.getPosition().y < 0; }), bullets.end());
                }
            }
            // 更新boss子弹
            for (auto& bossbullet : bossbullets)
            {
                bossbullet.update();
                if (bullet.getIsHit() || bullet.getPosition().y < 0)
                {
                    bossbullets.erase(std::remove_if(bossbullets.begin(), bossbullets.end(),
                        [](const BossBullet& q) { return q.getIsHit() || q.getPosition().y < 0;}), bossbullets.end());
                }
            }
            /* --------------------------------- 所有游戏对象更新模块 ------------------------------------ */

            /* ------------------------------------ 碰撞检测模块 ----------------------------------------- */
            for (auto& ball : balls)
            {
                // 检测玩家是否被敌人击中
                if (checkIfPlayerIsHit(player, ball) && hitRestrictor.getElapsedTime().asSeconds() >= 1)
                {
                    player.setHealth(player.getHealth() - 1);  // 减少生命值
                    healthLabel.setString(std::to_string(player.getHealth()) + " HP");  // 更新生命值显示
                    hitRestrictor.restart();
                    player.setColor(sf::Color::Red);  // 玩家变红表示受伤
                }
                // 受伤后恢复颜色
                if (player.getColor() == sf::Color::Red && hitRestrictor.getElapsedTime().asSeconds() >= 0.5)
                {
                    player.setColor(sf::Color::White);
                }
                // 检测子弹是否击中敌人
                for (auto& bullet : bullets)
                {
                    if (checkShotHit(bullet, ball)) hitSound.play();  // 播放击中音效
                }
                // 检测子弹是否击中 Boss
                for (auto& bullet : bullets) {
                    if (checkShotHitBoss(bullet, firstBoss) && hitbossRestrictor.getElapsedTime().asSeconds() >= 0.1) {
                        hitSound.play();  // 播放 Boss 被击中的音效
                        hitbossRestrictor.restart();
                        firstBoss.setColor(sf::Color::Red);
                    }
                    if (firstBoss.getColor() == sf::Color::Red && hitbossRestrictor.getElapsedTime().asSeconds() >= 0.5)
                    {
                        firstBoss.setColor(sf::Color::White);
                    }
                }
            }
            for (auto& bossbullet : bossbullets) {
                if (checkBossHit(bossbullet, player) && hitRestrictor.getElapsedTime().asSeconds() >= 1)
                {
                    player.setHealth(player.getHealth() - 2);  // 减少生命值
                    healthLabel.setString(std::to_string(player.getHealth()) + " HP");  // 更新生命值显示
                    hitRestrictor.restart();
                    player.setColor(sf::Color::Red);  // 玩家变红表示受伤
                }
                // 受伤后恢复颜色
                if (player.getColor() == sf::Color::Red && hitRestrictor.getElapsedTime().asSeconds() >= 0.5)
                {
                    player.setColor(sf::Color::White);
                }
            }
            for (auto& drop : drops)
            {
                if (checkgetdrop(drop, player))
                {
					if (drop.getName() == "health")
					{
                        player.setHealth(player.getHealth() + 1);  // 增加生命值
                        if (player.getHealth() > 5)
                        {
                            player.setHealth(5);  // 确保生命值不超过5
                        }
                        healthLabel.setString(std::to_string(player.getHealth()) + " HP");
					}
					else if (drop.getName() == "shootingRate")
					{
						bullet.setshootRate(bullet.getshootRate() - 0.9f);  // 增加射击速率
						if (bullet.getshootRate() < 0.1f) bullet.setshootRate(0.1f);  // 确保射击速率不低于0.1秒
					}
					drops.erase(std::remove_if(drops.begin(), drops.end(),
						[](const Drop& d) { return d.getName() == "health" || d.getName() == "shootingRate"; }), drops.end());
                }
            }
            /* ------------------------------------ 碰撞检测模块 ----------------------------------------- */
            // 更新玩家位置
            player.movePlayer(window.getSize());


            // 游戏结束检测
            if (firstBoss.getHealth() <= 0 || player.getHealth() <= 0)
            {
                bossSound.play();
                std::cout << "GAME OVER!" << std::endl;

                // 重置玩家位置和状态
                player.setPosition({ (float)windowSize.x / 2.f, (float)windowSize.y / 1.5f });
                window.clear();

                // 显示游戏结束画面
                GameOverScreen gameOverScreen(background.getTexture(), player.getTexture(), boss.getTexture(), font, windowSize, player.getHealth());
                gameOverScreen.run(window, firstBoss);

                // 重置游戏状态
                enemySpawnRate = 5;
                highScoreLable.setString("High Score: " + std::to_string(checkHighScore(score)));
                score = 0;
                scoreLabel.setString("Score: 0");
                player.setHealth(5);
                healthLabel.setString("5 HP");
                balls.clear();  // 清空所有敌人
            }
        }
        float deltaTime = clock.restart().asSeconds();
        for (auto& explosion : explosions) {
            explosion.update(deltaTime);
        }
        explosions.erase(std::remove_if(explosions.begin(), explosions.end(),
            [](const Animation& anim) { return anim.isFinished(); }), explosions.end());

        DrawGameState(window, font, background, scoreLabel, healthLabel, highScoreLable,
            balls, bullets, bossbullets, player, firstBoss, drops, explosions, isPause);
        
    }
    return 0;
}