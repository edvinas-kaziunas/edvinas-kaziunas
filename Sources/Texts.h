#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>
using namespace sf;
using namespace std;

sf::Font font;
font.loadFromFile("Resources/arialbd.ttf");

sf::Text text;
text.setFont(font);
text.setString("0");
text.setCharacterSize(55);
text.setFillColor(Color::Green);
text.setOutlineThickness(3);
text.setOutlineColor(Color::Black);
text.setPosition(WINDOW_WIDTH / 2.0f - 25.f, WINDOW_HEIGHT - 100.f);

sf::Text text2;
text2.setFont(font);
text2.setString("0");
text2.setCharacterSize(60);
text2.setFillColor(Color::Magenta);
text2.setOutlineThickness(5);
text2.setOutlineColor(Color::Black);
text2.setPosition(WINDOW_WIDTH / 2.0f - 30.f, WINDOW_HEIGHT - 600.f);

sf::Text text3;
text3.setFont(font);
text3.setString("0");
text3.setCharacterSize(70);
text3.setFillColor(Color::Red);
text3.setOutlineThickness(7);
text3.setOutlineColor(Color::Black);
text3.setPosition(WINDOW_WIDTH / 2.0f - 170.f, WINDOW_HEIGHT / 2);

sf::Text text4;
text4.setFont(font);
text4.setCharacterSize(20);
text4.setFillColor(Color::Blue);
text4.setOutlineThickness(2);
text4.setOutlineColor(Color::Black);
text4.setPosition(WINDOW_WIDTH / 2.0f - 250.f, WINDOW_HEIGHT - 450.f);

sf::Text text5;
text5.setFont(font);
text5.setCharacterSize(20);
text5.setFillColor(Color::Yellow);
text5.setOutlineThickness(2);
text5.setOutlineColor(Color::Black);
text5.setPosition(WINDOW_WIDTH / 2.0f - 250.f, WINDOW_HEIGHT - 400.f);

