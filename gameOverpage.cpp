#include "gameOverpage.h"


/**
 * @class GameOverScreen
 * @brief ��Ϸ���������࣬�̳���Menu����
 *
 * ��ʾ��Ϸ�������棬�ṩ���¿�ʼ���˳���Ϸѡ��
 */

    /**
     * @brief ���캯��
     * @param backgroundTexture ������������
     * @param playerTexture �����������
     * @param font ��������
     * @param windowSize ���ڳߴ�
     */
GameOverScreen::GameOverScreen(const sf::Texture& backgroundTexture, const sf::Texture& playerTexture, const sf::Texture& bossTexture, const sf::Font& font, sf::Vector2u windowSize)
        : Menu(backgroundTexture, playerTexture, bossTexture, font, windowSize), // Initialize the base class (Menu) ��ʼ������
        background(backgroundTexture),
        player({ (float)windowSize.x, (float)windowSize.y }, playerTexture),
        gameOverText(font, "GAME OVER", 100),// ��Ϸ��������
        escapeCont(font, "Press E To Play Again", 50),//ESC�ٴο�ʼ
        menuCont(font, "Or Press ESCAPE to Exit", 50),//E�˳���Ϸ
        credits(font, "Credits: \nDylan Hale \nIsaiah Foster \nAaron Sanchez \nJustin Scofield", 20)//����������
    {
        // Set up the background
        background.setPosition({ 0, 0 });
        background.setScale({
            (float)windowSize.x / background.getTextureRect().size.x,
            (float)windowSize.y / background.getTextureRect().size.y
            });

        // Set up the player
        player.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 2 });
        player.setScale({ 0.5f, 0.5f }); // Adjust scale as needed
        player.setOrigin({ player.getGlobalBounds().size.x / 1, player.getGlobalBounds().size.y / 2 });

        // Set up the "Game Over" text
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setOrigin({ gameOverText.getGlobalBounds().size.x / 2, gameOverText.getGlobalBounds().size.y / 2 });
        gameOverText.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 5.5f });

        // Set up escape text
        escapeCont.setFillColor(sf::Color::Red);
        escapeCont.setOrigin({ escapeCont.getGlobalBounds().size.x / 2, escapeCont.getGlobalBounds().size.y / 2 });
        escapeCont.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 3.45f });

        // Set up go-to-menu option text
        menuCont.setFillColor(sf::Color::Red);
        menuCont.setOrigin({ escapeCont.getGlobalBounds().size.x / 2, escapeCont.getGlobalBounds().size.y / 2 });
        menuCont.setPosition({ (float)windowSize.x / 1.7f, (float)windowSize.y / 2.8f });

        // Set up credits
        credits.setFillColor(sf::Color::Red);
        credits.setOrigin({ credits.getGlobalBounds().size.x / 2, credits.getGlobalBounds().size.y / 2 });
        credits.setPosition({ (float)windowSize.x / 4.0f, (float)windowSize.y / 2.0f });
    }

    /**
    * @brief ������Ϸ����������ѭ��
    * @param window ��Ⱦ��������
    */
    void GameOverScreen::run(sf::RenderWindow& window,Boss1& boss) {
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            // E����һ��
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                boss.setHealth(100);
                return;
            }
            // Escape�˳�
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                exit(0);
            }

            // Draw the game over screen
            window.clear();
            window.draw(background);
            window.draw(player);
            window.draw(gameOverText);
            window.draw(escapeCont);
            window.draw(menuCont);
            window.draw(credits);
            window.display();
        }
        return; // If the window is closed, do not restart
    }
