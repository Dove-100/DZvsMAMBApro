#pragma once
#ifndef _GAMEOVERPAGE_H_
#define _GAMEOVERPAGE_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "menu.h"
#include "player.h"
#include "boss.h"
#include "boss_1.h"
#include "background.h"
/**
 * @class GameOverScreen
 * @brief ��Ϸ���������࣬�̳���Menu����
 *
 * ��ʾ��Ϸ�������棬�ṩ���¿�ʼ���˳���Ϸѡ��
 */
class GameOverScreen : public Menu {
public:
    /**
     * @brief ���캯��
     * @param backgroundTexture ������������
     * @param playerTexture �����������
     * @param font ��������
     * @param windowSize ���ڳߴ�
     */
    GameOverScreen(const sf::Texture& backgroundTexture, const sf::Texture& playerTexture, const sf::Texture& bossTexture, const sf::Font& font, sf::Vector2u windowSize, int playerhealth);

    /**
    * @brief ������Ϸ����������ѭ��
    * @param window ��Ⱦ��������
    */
    void run(sf::RenderWindow& window, Boss1& boss);

private:
    Background background;
    Player player;
    sf::Text gameOverText;
    sf::Text escapeCont;
    sf::Text menuCont;
    sf::Text credits;
};
#endif