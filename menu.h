#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "MiscFunction.h"
#include "boss.h"
#include "player.h"
#include "background.h"

static bool isContinue; // �Ƿ�����ϴ���Ϸ
enum class gameStateClass {
    mainMenu,
    Mode,
    Help,
    Exit,
};
enum class levelsClass {
    Default,
    Easy,
    Normal,
    Hard,
    Exit
};
class Menu
{
public:
    // ���캯��
    // ����:
    //   backgroundTexture - ������������
    //   playerTexture - �����������
    //   font - ��������
    //   windowSize - ���ڴ�С
    Menu(const sf::Texture& backgroundTexture, const sf::Texture& playerTexture, const sf::Texture& bossTexture, const sf::Font& font, sf::Vector2u windowSize);
    //�˵���ʼҳ��
    int startMenu(sf::RenderWindow& window);
    bool isContinueLast();
private:
    Background background;//����
    Player player;//���
    Boss boss;//Boss
    sf::Text gameTitleText;//��Ϸ�����ı�
    sf::Text playCont;//��ʼ��Ϸ��ʾ�ı�
    sf::Text helpCont;//���������ı�
    sf::Text modeCont;//ģʽѡ���ı�
    sf::Text exitCont;//�˳��ı�
    sf::Text easyText;//��ģʽ
    sf::Text normalText;//����ģʽ
    sf::Text hardText;//����ģʽ
    sf::Text rulescontextText;//��Ϸ�淨
    int selectedOptionMainMenu = 0; // mainMenu = 0, play = 1, levels = 2, exit = 3
    const int totalOptionsMainMenu = 3;
    gameStateClass gameState = gameStateClass::mainMenu;

    int selectedOptionLevelsMenu = 0;
    const int totalOptionsLevelsMenu = 3;
    levelsClass level = levelsClass::Default;

    int exit_help = 0;
};
#endif