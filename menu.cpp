#include "menu.h"

// ���캯��
// ����:
//   backgroundTexture - ������������
//   playerTexture - �����������
//   font - ��������
//   windowSize - ���ڴ�С
Menu::Menu(const sf::Texture& backgroundTexture,
            const sf::Texture& playerTexture, 
            const sf::Texture& bossTexture,
            const sf::Font& font, sf::Vector2u windowSize)
        : background(backgroundTexture), 
        player({ (float)windowSize.x, (float)windowSize.y }, playerTexture),
        boss({ (float)windowSize.x, (float)windowSize.y }, bossTexture),
        gameTitleText(font, "DZ vs MAMBA", 100), playCont(font, "Press Space to Continue Last Game"),  modeCont(font, "Mode", 50), helpCont(font, "Help", 50), exitCont(font, "Exit", 50),//�����ı�����ʾ�ı�
        easyText(font, "Easy", 50), normalText(font, "Normal", 50), hardText(font, "Hard", 50),
        rulescontextText(font, "Use WASD to move DinZheng\nPress the Mouse'left to defeat the\nMamba and hajimi\nTry to hide from the hajimis", 50)
    {
        //���ñ�����ȫ��
        background.setPosition({ 0,0.0 });
        background.setScale({
            (float)windowSize.x / background.getTextureRect().size.x,
            (float)windowSize.y / background.getTextureRect().size.y
            });

        //�������
        player.setPosition({ (float)windowSize.x / 4, (float)windowSize.y / 2 });//��Ļ�м�
        player.setScale({ 0.5f, 0.5f }); // ���ű���
        player.setOrigin({ player.getGlobalBounds().size.x / 1.0f, player.getGlobalBounds().size.y / 2 });//������ҽ�ɫ����

        //����boss
        boss.setPosition({ (float)windowSize.x / 4 * 3, (float)windowSize.y / 2 });
        boss.setScale({ 0.5f,0.5f });
        boss.setOrigin({ boss.getGlobalBounds().size.x / 1.0f, boss.getGlobalBounds().size.y / 2 });


        //set up the "Game Over" text  ��Ϸ����
        gameTitleText.setFillColor(sf::Color::Black);
        gameTitleText.setOrigin({ gameTitleText.getGlobalBounds().size.x / 2, gameTitleText.getGlobalBounds().size.y / 2 });
        gameTitleText.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 5.5f });

        //set up escape text           ��ʾ�ı�
        playCont.setFillColor(sf::Color::Black);
        playCont.setOrigin({ playCont.getGlobalBounds().size.x / 2, playCont.getGlobalBounds().size.y / 2 });
        playCont.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 3.45f });

        //                              ��Ϸ����
        rulescontextText.setFillColor(sf::Color::Black);
        rulescontextText.setOrigin({ rulescontextText.getGlobalBounds().size.x / 2, rulescontextText.getGlobalBounds().size.y / 2 });
        rulescontextText.setPosition({ (float)windowSize.x / 2, (float)windowSize.y / 3.45f });

        //set up go-to-menu option text ģʽ��ť
        modeCont.setFillColor(sf::Color::Black);
        modeCont.setOrigin({ (float)modeCont.getGlobalBounds().size.x / 2, (float)modeCont.getGlobalBounds().size.y / 2 });
        modeCont.setPosition({ (float)windowSize.x / 2, 900 });

        //                              ������ť
        helpCont.setFillColor(sf::Color::Black);
        helpCont.setOrigin({ (float)helpCont.getGlobalBounds().size.x / 2, (float)helpCont.getGlobalBounds().size.y / 2 });
        helpCont.setPosition({ (float)windowSize.x / 2, 1050 });

        
        //                              �˳���ť
        exitCont.setFillColor(sf::Color::Black);
        exitCont.setOrigin({ (float)exitCont.getGlobalBounds().size.x / 2, (float)exitCont.getGlobalBounds().size.y / 2 });
        exitCont.setPosition({ (float)windowSize.x / 2, 1200 });

        //set up go-to-menu option text ���װ�ť
        easyText.setFillColor(sf::Color::Black);
        easyText.setOrigin({ (float)easyText.getGlobalBounds().size.x / 2, (float)easyText.getGlobalBounds().size.y / 2 });
        easyText.setPosition({ (float)windowSize.x / 2, 750 });

        //                              ������ť
        normalText.setFillColor(sf::Color::Black);
        normalText.setOrigin({ (float)normalText.getGlobalBounds().size.x / 2, (float)normalText.getGlobalBounds().size.y / 2 });
        normalText.setPosition({ (float)windowSize.x / 2, 900 });

        //                              ���Ѱ�ť
        hardText.setFillColor(sf::Color::Black);
        hardText.setOrigin({ (float)hardText.getGlobalBounds().size.x / 2, (float)hardText.getGlobalBounds().size.y / 2 });
        hardText.setPosition({ (float)windowSize.x / 2, 1050 });

        int selectedOptionMainMenu = 0; // mainMenu = 0, mode = 1, help = 2, exit = 3
        const int totalOptionsMainMenu = 3;
        gameStateClass gameState = gameStateClass::mainMenu;

        int selectedOptionLevelsMenu = 0;
        const int totalOptionsLevelsMenu = 3;
        levelsClass level = levelsClass::Default;
    }


    //function to run the game over screen
int Menu::startMenu(sf::RenderWindow& window) {
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
                window.close();
            }

            // Switching between options in the menu
            if (gameState == gameStateClass::mainMenu) {

                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scan::Up) {
                        if (selectedOptionMainMenu == 0) {
                            selectedOptionMainMenu = 1;
                        }
                        else if (selectedOptionMainMenu == 1) {
                            selectedOptionMainMenu = totalOptionsMainMenu;
                        }
                        else {
                            selectedOptionMainMenu -= 1;
                        }
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scan::Down) {
                        if (selectedOptionMainMenu == 0) {
                            selectedOptionMainMenu = 1;
                        }
                        else {
                            selectedOptionMainMenu = (selectedOptionMainMenu % totalOptionsMainMenu) + 1;
                        }
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scan::Enter) {
                        if (selectedOptionMainMenu == 1) {
                            gameState = gameStateClass::Mode;
                        }
                        else if (selectedOptionMainMenu == 2) {
                            gameState = gameStateClass::Help;
                        }
                        else if (selectedOptionMainMenu == 3) {
                            gameState = gameStateClass::Exit;
                        }
                    }
                }
            }
            else if (gameState == gameStateClass::Mode) {

                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scan::Up) {
                        if (selectedOptionLevelsMenu == 0) {
                            selectedOptionLevelsMenu = totalOptionsLevelsMenu;
                        }
                        else if (selectedOptionLevelsMenu == 1) {
                            selectedOptionLevelsMenu = 0;
                        }
                        else if (selectedOptionLevelsMenu == 2) {
                            selectedOptionLevelsMenu = 1;
                        }
                        else if (selectedOptionLevelsMenu == 3) {
                            selectedOptionLevelsMenu = 2;
                        }
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scan::Down) {
                        if (selectedOptionLevelsMenu == 0) {
                            selectedOptionLevelsMenu = 1;
                        }
                        else if (selectedOptionLevelsMenu == 1) {
                            selectedOptionLevelsMenu = 2;
                        }
                        else if (selectedOptionLevelsMenu == 2) {
                            selectedOptionLevelsMenu = 3;
                        }
                        else if (selectedOptionLevelsMenu == 3) {
                            selectedOptionLevelsMenu = 0;
                        }
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scan::Enter) {
                        if (selectedOptionLevelsMenu == 1) {
                            level = levelsClass::Easy;
                            return 1;
                        }
                        else if (selectedOptionLevelsMenu == 2) {
                            level = levelsClass::Normal;
                            return 2;
                        }
                        else if (selectedOptionLevelsMenu == 3) {
                            level = levelsClass::Hard;
                            return 3;
                        }
                        else if (selectedOptionLevelsMenu == 0) {
                            level = levelsClass::Exit;
                        }
                    }
                }
            }
            else if (gameState == gameStateClass::Help)
            {
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scan::Enter) {
                        exit_help = 1;
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                return readLastLevel();
            }
        }
        if (gameState == gameStateClass::mainMenu) {
            if (selectedOptionMainMenu == 1) {
                modeCont.setFillColor(sf::Color::Red);
            }
            else
            {
                modeCont.setFillColor(sf::Color::Black);
            }

            if (selectedOptionMainMenu == 2) {
                helpCont.setFillColor(sf::Color::Red);
            }
            else
            {
                helpCont.setFillColor(sf::Color::Black);
            }

            if (selectedOptionMainMenu == 3) {
                exitCont.setFillColor(sf::Color::Red);
            }
            else
            {
                exitCont.setFillColor(sf::Color::Black);
            }
            window.clear();
            window.draw(background);
            window.draw(player);
            window.draw(boss);
            window.draw(gameTitleText);
            window.draw(playCont);
            window.draw(modeCont);
            window.draw(helpCont);
            window.draw(exitCont);
            window.display();

        }
        else if (gameState == gameStateClass::Mode) {

            // std::cout << "Levels state activated." << std::endl;

            // Level menu buttons coloring
            if (selectedOptionLevelsMenu == 1) {
                easyText.setFillColor(sf::Color::Red);
            }
            else
            {
                easyText.setFillColor(sf::Color::Black);
            }

            if (selectedOptionLevelsMenu == 2) {
                normalText.setFillColor(sf::Color::Red);
            }
            else
            {
                normalText.setFillColor(sf::Color::Black);
            }

            if (selectedOptionLevelsMenu == 3) {
                hardText.setFillColor(sf::Color::Red);
            }
            else
            {
                hardText.setFillColor(sf::Color::Black);
            }

            if (selectedOptionLevelsMenu == 0) {
                exitCont.setFillColor(sf::Color::Red);
            }
            else
            {
                exitCont.setFillColor(sf::Color::Black);
            }

            if (level == levelsClass::Exit) {

                // std::cout << "Levels exit activated." << std::endl;

                gameState = gameStateClass::mainMenu;
                level = levelsClass::Default;
            }

            window.clear();
            window.draw(background);
            window.draw(easyText);
            window.draw(normalText);
            window.draw(hardText);
            window.draw(exitCont);
            window.display();
        }
        else if (gameState == gameStateClass::Help)
        {
            exitCont.setFillColor(sf::Color::Red);
            if (exit_help == 1) {
                exit_help = 0;
                exitCont.setFillColor(sf::Color::Black);
                gameState = gameStateClass::mainMenu;
                level = levelsClass::Default;
            }
            window.clear();
            window.draw(background);
            window.draw(rulescontextText);
            window.draw(exitCont);
            window.display();
        }
        else if (gameState == gameStateClass::Exit) {
            window.close();
        }

    }
    return 0;
}