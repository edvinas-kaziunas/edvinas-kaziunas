#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>
#include <vector>
#include <map>

#include "Objects.h"
#include "Utils.h"
//#include "Texts.h"

using namespace sf;
using namespace std;

float Minus(float s)
{
	if (s < 101)
		throw 0;
	return s - 100;
}

int main()
{
	Car s;
	Enemy en1[PLATES_AMOUNT];
	Powerup pu(4.0f);
	Powerup pd(6.0f);
	map<int, float> p;

	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Long Road Deluxe");
	app.setFramerateLimit(60);

	Texture tBackground,tTitleScreen, tPlayer, tPlatform, tPlatform2, tPowerup, tPowerdown;
	tBackground.loadFromFile("Resources/road.png");
	tTitleScreen.loadFromFile("Resources/Title.png");
	tPlayer.loadFromFile("Resources/car.png");
	tPlatform.loadFromFile("Resources/encar4.png");
	tPlatform2.loadFromFile("Resources/encar2.png");
	tPowerup.loadFromFile("Resources/points100.png");
	tPowerdown.loadFromFile("Resources/negativepoints100.png");

	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/Undertale Ost - 098 - Battle Against a True Hero.wav");

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

	sf::Text textTitle1;
	textTitle1.setFont(font);
	textTitle1.setString("Long Road");
	textTitle1.setCharacterSize(70);
	textTitle1.setFillColor(Color::Red);
	textTitle1.setOutlineThickness(7);
	textTitle1.setOutlineColor(Color::White);
	textTitle1.setPosition(WINDOW_WIDTH / 2.0f - 170.f, (WINDOW_HEIGHT / 2)-100.f);

	sf::Text textTitle2;
	textTitle2.setFont(font);
	textTitle2.setString("Deluxe");
	textTitle2.setCharacterSize(50);
	textTitle2.setFillColor(Color::Cyan);
	textTitle2.setOutlineThickness(4);
	textTitle2.setOutlineColor(Color::White);
	textTitle2.setPosition(WINDOW_WIDTH / 2.0f - 75.f, WINDOW_HEIGHT / 2);

	sf::Text textPressR;
	textPressR.setFont(font);
	textPressR.setString("Press R to start");
	textPressR.setCharacterSize(30);
	textPressR.setFillColor(Color::White);
	//textPressR.setOutlineThickness(7);
	//textPressR.setOutlineColor(Color::Black);
	textPressR.setPosition(WINDOW_WIDTH / 2.0f - 90.f, WINDOW_HEIGHT-100.f);

	Sprite sprBackground(tBackground);
	Sprite sprTitle(tTitleScreen);
	Sprite sprPlayer(tPlayer);
	Sprite sprEnemy(tPlatform);
	Sprite sprEnemy2(tPlatform2);
	Sprite sprPowerup100(tPowerup);
	Sprite sprPowerdown(tPowerdown);

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setLoop(true);
	sound.play();

	float score = 0;
	float high = 0;
	float fail = -1;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			--s;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			++s;
		}

		if(fail==-1)
			app.draw(sprTitle);
		else app.draw(sprBackground);
		if(fail==0)
		{
			for (int i = 0; i < PLATES_AMOUNT; ++i)
			{
				MovingObject* move1 = &en1[i];
				move1->MoveUp();
				if (move1->GetY() < 0)
					move1->Respawn();
				sprEnemy.setPosition(en1[i].GetX(), en1[i].GetY());
				app.draw(sprEnemy);
			}

			MovingObject* move3 = &pu;
			move3->MoveUp();
			if (move3->GetY() < 0)
				move3->Respawn();
			sprPowerup100.setPosition(pu.GetX(), pu.GetY());
			app.draw(sprPowerup100);

			MovingObject* move4 = &pd;
			move4->MoveUp();
			if (move4->GetY() < 0)
				move4->Respawn();
			sprPowerdown.setPosition(pd.GetX(), pd.GetY());
			app.draw(sprPowerdown);

			for (int i = 0; i < PLATES_AMOUNT; ++i)
			{
				if (nmUtils::Touching(s, en1[i]))
				{
					fail++;
				}
			}

			score += 0.1;

			sprPlayer.setPosition(s.GetX(), s.GetY());
			app.draw(sprPlayer);

			if (nmUtils::Touching(s, pu))
			{
				score = score + 100;
				++p[1];
				move3->Respawn();
			}

			if (nmUtils::Touching(s, pd))
			{
				move4->Respawn();
				try
				{
					++p[2];
					score = Minus(score);
				}
				catch (int n) // jeigu prie throw parasomas skaicius
				{
					score = 0;
				}
			}

		}
		else if(fail>0)
		{
			if (score > high) high = score;
			score = 0;
			text3.setString("Game Over");
			app.draw(text3);
			text4.setString(std::format("Powerups collected: {:.0f}", p[1]));
			text5.setString(std::format("Powerdowns collected: {:.0f}", p[2]));
			app.draw(text4);
			app.draw(text5);

		}
		
		if (fail == -1)
		{
			app.draw(textTitle1);
			app.draw(textTitle2);
			app.draw(textPressR);
		}
		else
		{
			text.setString(std::format("{:.0f}", score));
			app.draw(text);

			text2.setString(std::format("{:.0f}", high));
			app.draw(text2);
	
		}
		

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			fail++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			fail = 0;
			p[1] = 0;
			p[2] = 0;
			for (int i = 0; i < PLATES_AMOUNT; ++i)
			{
				MovingObject* move1 = &en1[i];
				move1->Respawn();
				sprEnemy.setPosition(en1[i].GetX(), en1[i].GetY());
			}
		}

		app.display();
	}

	return 0;
}