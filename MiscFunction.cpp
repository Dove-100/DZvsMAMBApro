#include "MiscFunction.h"

using sf::Text;

/**
 * ��ʼ����Ϸ����
 * @return ȫ��ģʽ����Ⱦ���ںʹ��ڳߴ�
 */
sf::RenderWindow initWindow()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();// ��ȡ����ֱ���
	sf::RenderWindow window(desktop, "Book Blaster", sf::Style::None);//�����ޱ߿򴰿�
	window.setFramerateLimit(120);//����֡��
	sf::Vector2u windowSize = window.getSize();//��ȡ���ڴ�С
	return window;
}

/**
*������ҽ�ɫ
* @param window ��Ϸ�������ã����ڻ�ȡ���ڳߴ磩
* @return ��ʼ�������Ҷ���
* */
Player loadPlayer(sf::RenderWindow& window)
{
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Player.png");//�����������
	Player playerSprite({ (float)window.getSize().x, (float)window.getSize().y }, playerTexture);//������Ҷ���
	return playerSprite;
}

Boss loadBoss(sf::RenderWindow& window)
{
	sf::Texture BossTexture;
	BossTexture.loadFromFile("boss/boss.png");//�����������
	Boss bossSprite({ (float)window.getSize().x, (float)window.getSize().y }, BossTexture);//������Ҷ���
	return bossSprite;
}

/**
 * ������Ϸ����
 * @return ��ʼ����ı�������
 */
Background loadBackground()
{
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("PNG/background(1.png");//���ر�������
	Background backgroundSprite(backgroundTexture, { 0.f, 0.f });
	return backgroundSprite;
}

 /**
  * ���Ǧ�ʣ��ӵ����Ƿ�����鼮
  * @param bullet Ǧ�ʶ���
  * @param enemy �鼮����
  * @return �Ƿ����
  */
extern bool checkShotHit(Bullet& bullet, Enemy& enemy)
{
	// ��ȡ���ߵ�ȫ�ֱ߽��
	sf::FloatRect bulletBounds = bullet.getGlobalBounds();
	sf::FloatRect ballBounds = enemy.getGlobalBounds();
	// ʹ��SFML���õ���ײ���
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		enemy.setHealth(enemy.getHealth() - 1); // �����鼮����ֵ
		bullet.setIsHit(); // �ӵ��ѻ���
		return true;
	}
	return false;
}

extern bool checkShotHitBoss(Bullet& bullet, Boss1& boss)
{
	// ��ȡ���ߵ�ȫ�ֱ߽��
	sf::FloatRect bulletBounds = bullet.getGlobalBounds();
	sf::FloatRect ballBounds = boss.getGlobalBounds();
	// ʹ��SFML���õ���ײ���
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		boss.setHealth(boss.getHealth() - 1); // �����鼮����ֵ
		bullet.setIsHit(); // �ӵ��ѻ���
		return true;
	}
	return false;
}

extern bool checkBossHit(BossBullet& bossbullet, Player& player)
{
	// ��ȡ���ߵ�ȫ�ֱ߽��
	sf::FloatRect bulletBounds = bossbullet.getGlobalBounds();
	sf::FloatRect ballBounds = player.getGlobalBounds();
	// ʹ��SFML���õ���ײ���
	if (auto intersection = bulletBounds.findIntersection(ballBounds)) {
		return true;
	}
	return false;
}

/**
 * �������Ƿ��鼮����
 * @param player ��Ҷ���
 * @param ball �鼮����
 * @return �Ƿ�����ײ
 */
extern bool checkIfPlayerIsHit(Player& player, const Enemy& ball)
{
	// ��ȡ���ߵ�ȫ�ֱ߽��
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect ballBounds = ball.getGlobalBounds();
	// ʹ��SFML���õ���ײ���
	if (auto intersection = playerBounds.findIntersection(ballBounds)) {
		return true;
	}
	return false;
}

/**
 * ��鲢������߷�
 * @param cur ��ǰ����
 * @return �µ���߷�
 */
int checkHighScore(int cur)
{
	// ��ȡ��ʷ��߷�
	std::ifstream file("HighScore.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening high score file." << std::endl;
		return -1;
	}
	int highScore;
	file >> highScore;
	file.close();
	// �����ǰ�������ߣ����¼�¼
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
	// ��ȡ�ϴ�ѡ���ģʽ
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
	// ��ȡ�ϴ�ѡ���ģʽ
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
	// ��ȡ�ϴ�ѡ���ģʽ
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
 * ���ز���ʼ����Ϸ�ı���ǩ
 * @param window ��Ϸ����
 * @param font �������
 * @param scoreLabel ������ǩ
 * @param healthLabel ����ֵ��ǩ
 * @param highScoreLable ��߷ֱ�ǩ
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
	// ����
	window.clear();

	// ����������Ϸ���� //

	// ���Ʊ������ı�
	window.draw(background);
	window.draw(scoreLabel);
	window.draw(healthLabel);
	window.draw(highScoreLable);

	// �������е���
	for (const auto& ball : balls)
	{
		window.draw(ball);
	}

	// ���������ӵ�
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

	// �������
	window.draw(player);
	window.draw(boss);

	if (isPause)
	{
		// ������ͣ����
		sf::Text pauseText(font, "Game Paused\nPress P again to continue", 50);
		pauseText.setFillColor(sf::Color::White);
		pauseText.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });
		pauseText.setOrigin({ pauseText.getGlobalBounds().size.x / 2, pauseText.getGlobalBounds().size.y / 2 });

		// ������ͣ����
		sf::RectangleShape pauseOverlay;
		pauseOverlay.setSize(sf::Vector2f(window.getSize()));
		pauseOverlay.setFillColor(sf::Color(0, 0, 0, 150)); // ��͸����ɫ
		window.draw(pauseOverlay);
		window.draw(pauseText);

	}

	// ��ʾ��������
	window.display();
}

int srandbuff()
{
	// �������������
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	// ���������0-99
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
	// ��ȡ���ߵ�ȫ�ֱ߽��
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect dropBounds = drop.getGlobalBounds();
	// ʹ��SFML���õ���ײ���
	if (auto intersection = playerBounds.findIntersection(dropBounds)) {
		return true;
	}
	return false;
}