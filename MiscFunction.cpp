#include "MiscFunction.h"

using sf::Text;

/**
 * 初始化游戏窗口
 * @return 全屏模式的渲染窗口和窗口尺寸
 */
sf::RenderWindow initWindow()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();// 获取桌面分辨率
	sf::RenderWindow window(desktop, "Book Blaster", sf::Style::None);//创建无边框窗口
	window.setFramerateLimit(120);//设置帧率
	sf::Vector2u windowSize = window.getSize();//获取窗口大小
	return window;
}

/**
*加载玩家角色
* @param window 游戏窗口引用（用于获取窗口尺寸）
* @return 初始化后的玩家对象
* */
Player loadPlayer(sf::RenderWindow& window)
{
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Player.png");//加载玩家纹理
	Player playerSprite({ (float)window.getSize().x, (float)window.getSize().y }, playerTexture);//创建玩家对象
	return playerSprite;
}

Boss loadBoss(sf::RenderWindow& window)
{
	sf::Texture BossTexture;
	BossTexture.loadFromFile("boss/boss.png");//加载玩家纹理
	Boss bossSprite({ (float)window.getSize().x, (float)window.getSize().y }, BossTexture);//创建玩家对象
	return bossSprite;
}

/**
 * 加载游戏背景
 * @return 初始化后的背景对象
 */
Background loadBackground()
{
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("PNG/background(1.png");//加载背景纹理
	Background backgroundSprite(backgroundTexture, { 0.f, 0.f });
	return backgroundSprite;
}

 /**
  * 检测铅笔（子弹）是否击中书籍
  * @param bullet 铅笔对象
  * @param enemy 书籍对象
  * @return 是否击中
  */
extern bool checkShotHit(Bullet& bullet, Enemy& enemy)
{
	// 获取两者的全局边界框
	sf::FloatRect bulletBounds = bullet.getGlobalBounds();
	sf::FloatRect ballBounds = enemy.getGlobalBounds();
	// 使用SFML内置的碰撞检测
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		enemy.setHealth(enemy.getHealth() - 1); // 减少书籍生命值
		bullet.setIsHit(); // 子弹已击中
		return true;
	}
	return false;
}

extern bool checkShotHitBoss(Bullet& bullet, Boss1& boss)
{
	// 获取两者的全局边界框
	sf::FloatRect bulletBounds = bullet.getGlobalBounds();
	sf::FloatRect ballBounds = boss.getGlobalBounds();
	// 使用SFML内置的碰撞检测
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		boss.setHealth(boss.getHealth() - 1); // 减少书籍生命值
		bullet.setIsHit(); // 子弹已击中
		return true;
	}
	return false;
}

extern bool checkBossHit(BossBullet& bossbullet, Player& player)
{
	// 获取两者的全局边界框
	sf::FloatRect bulletBounds = bossbullet.getGlobalBounds();
	sf::FloatRect ballBounds = player.getGlobalBounds();
	// 使用SFML内置的碰撞检测
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		return true;
	}
	return false;
}

/**
 * 检测玩家是否被书籍击中
 * @param player 玩家对象
 * @param ball 书籍对象
 * @return 是否发生碰撞
 */
extern bool checkIfPlayerIsHit(Player& player, const Enemy& ball)
{
	// 获取两者的全局边界框
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect ballBounds = ball.getGlobalBounds();
	// 使用SFML内置的碰撞检测
	if (auto intersection = playerBounds.findIntersection(ballBounds)) {
		return true;
	}
	return false;
}

/**
 * 检查并更新最高分
 * @param cur 当前分数
 * @return 新的最高分
 */
int checkHighScore(int cur)
{
	// 读取历史最高分
	std::ifstream file("HighScore.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening high score file." << std::endl;
		return -1;
	}
	int highScore;
	file >> highScore;
	file.close();
	// 如果当前分数更高，更新记录
	if (cur > highScore)
	{
		std::ofstream file("HighScore.txt");
		if (!file.is_open())
		{
			std::cerr << "Error opening high score file." << std::endl;
			return -1;
		}
		file << cur;
		file.close();
		return cur;
	}
	else
	{
		return highScore;
	}
}

int readLastLevel()
{
	// 读取上次选择的模式
	std::ifstream file("Lastlevel.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening last level file." << std::endl;
		return -1;
	}
	int lastlevel;
	file >> lastlevel;
	file.close();
	return lastlevel;
}

void writeLevel(int curlevel)
{
	std::ofstream file("Lastlevel.txt");
	file << curlevel;
	file.close();
}

int readLastScore()
{
	// 读取上次选择的模式
	std::ifstream file("LastScore.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening last score file." << std::endl;
		return -1;
	}
	int lastscore;
	file >> lastscore;
	file.close();
	return lastscore;
}

void writeScore(int curScore)
{
	std::ofstream file("LastScore.txt");
	file << curScore;
	file.close();
}

int readlasthealth()
{
	// 读取上次选择的模式
	std::ifstream file("Lasthealth.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening last health file." << std::endl;
		return -1;
	}
	int Lasthealth;
	file >> Lasthealth;
	file.close();
	return Lasthealth;
}

void writeHealth(int curHealth)
{
	std::ofstream file("Lasthealth.txt");
	file << curHealth;
	file.close();
}

/**
 * 加载并初始化游戏文本标签
 * @param window 游戏窗口
 * @param font 字体对象
 * @param scoreLabel 分数标签
 * @param healthLabel 生命值标签
 * @param highScoreLable 最高分标签
 */
void loadTexts(sf::RenderWindow& window, sf::Font& font, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable, bool iscontinue)
{

	//determine scale based on monitor
	sf::Vector2u windowSize = window.getSize();
	float scale = (float)windowSize.x / 1920;
	
	//set font and scale for score and health labels
	if (iscontinue)
	{
		string lastscore = std::to_string(readLastScore());
		scoreLabel.setString("Score: " + lastscore);
	}
	else
	{
		scoreLabel.setString("Score: 0");
	}
	scoreLabel.setCharacterSize(30);
	scoreLabel.setFillColor(sf::Color::Green);
	scoreLabel.setOrigin({ scoreLabel.getGlobalBounds().size.x / 2, scoreLabel.getGlobalBounds().size.y / 2 });
	scoreLabel.setPosition({ (float)windowSize.x / 2, (float)windowSize.y * .93f });

	if (iscontinue)
	{
		string lasthealth;
		lasthealth = std::to_string(readlasthealth());
		healthLabel.setString(lasthealth+" HP");
	}
	else {
		healthLabel.setString("5 HP");
	}
	healthLabel.setCharacterSize(30);
	healthLabel.setFillColor(sf::Color::Red);
	healthLabel.setOrigin({ healthLabel.getGlobalBounds().size.x / 2, healthLabel.getGlobalBounds().size.y / 2 });
	healthLabel.setPosition({ (float)windowSize.x / 4, (float)windowSize.y * .93f });

	//open highscore file to read
	std::ifstream file("HighScore.txt");
	std::string line;
	std::getline(file, line);
	file.close();

	//set font and scale for highscore label
	highScoreLable.setCharacterSize(30);
	highScoreLable.setFillColor(sf::Color::Red);
	highScoreLable.setString("High Score: " + line);
	highScoreLable.setOrigin({ (float)highScoreLable.getGlobalBounds().size.x / 2, highScoreLable.getGlobalBounds().size.y / 2 });
	highScoreLable.setPosition({ (float)windowSize.x / 1.25f , (float)windowSize.y * .93f });

}

void DrawGameState(sf::RenderWindow& window, sf::Font& font, Background& background, sf::Text& scoreLabel, sf::Text& healthLabel, sf::Text& highScoreLable,
	std::vector<Enemy> balls,
	std::vector<Bullet> bullets,
	std::vector<BossBullet> bossbullets,
	Player& player, Boss1& boss,
	std::vector<Drop> drops,
	bool isPause)
{
	// 清屏
	window.clear();

	// 绘制所有游戏对象 //

	// 绘制背景和文本
	window.draw(background);
	window.draw(scoreLabel);
	window.draw(healthLabel);
	window.draw(highScoreLable);

	// 绘制所有敌人
	for (const auto& ball : balls)
	{
		window.draw(ball);
	}

	// 绘制所有子弹
	for (const auto& bullet : bullets)
	{
		window.draw(bullet);
	}

	for (const auto& bossbullet : bossbullets)
	{
		window.draw(bossbullet);
	}

	for (const auto& drop : drops)
	{
		window.draw(drop);
	}

	// 绘制玩家
	window.draw(player);
	window.draw(boss);

	if (isPause)
	{
		// 绘制暂停界面
		sf::Text pauseText(font, "Game Paused\nPress P again to continue", 50);
		pauseText.setFillColor(sf::Color::White);
		pauseText.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });
		pauseText.setOrigin({ pauseText.getGlobalBounds().size.x / 2, pauseText.getGlobalBounds().size.y / 2 });

		// 创建暂停背景
		sf::RectangleShape pauseOverlay;
		pauseOverlay.setSize(sf::Vector2f(window.getSize()));
		pauseOverlay.setFillColor(sf::Color(0, 0, 0, 150)); // 半透明黑色
		window.draw(pauseOverlay);
		window.draw(pauseText);

	}

	// 显示绘制内容
	window.display();
}

int srandbuff()
{
	// 设置随机数种子
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	// 生成随机数0-99
	int seed = std::rand()%100;
	if (seed < 25)
	{
		return 1;
		
	}
	else if (seed >= 25 && seed < 50)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

bool checkgetdrop(Drop& drop, Player& player)
{
	// 获取两者的全局边界框
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect dropBounds = drop.getGlobalBounds();
	// 使用SFML内置的碰撞检测
	if (auto intersection = playerBounds.findIntersection(dropBounds)) {
		return true;
	}
	return false;
}