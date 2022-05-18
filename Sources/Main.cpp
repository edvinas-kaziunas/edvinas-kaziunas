#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>
#include <vector>
#include <map>

#include "Objects.h"
#include "Utils.h"

using namespace sf;
using namespace std;

class Decrease
{
public:
	float Minus(float s)
	{
		float t;
		t = 0.;
		if (s < 101) throw t;
		else return s - 100;
	}
};
int main()
{
	Car s;
	Enemy1 en1[PLATES_AMOUNT];
	Powerup pu;
	Powerdown pd;
	Decrease d;
	map<int, float> p;
	pair<string, float> pup;
	pair<string, float> pdown;
	p[1];
	p[2];

	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Long Road Deluxe");
	app.setFramerateLimit(60);

	Texture tBackground, tPlayer, tPlatform, tPlatform2, tPowerup, tPowerdown;
	tBackground.loadFromFile("Resources/road.png");
	tPlayer.loadFromFile("Resources/car.png");
	tPlatform.loadFromFile("Resources/encar4.png");
	tPlatform2.loadFromFile("Resources/encar2.png");
	tPowerup.loadFromFile("Resources/points100.png");
	tPowerdown.loadFromFile("Resources/negativepoints100.png");

	sf::Font font;
	font.loadFromFile("Resources/arialbd.ttf");

	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/Undertale Ost - 098 - Battle Against a True Hero.wav");

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
	text4.setPosition(WINDOW_WIDTH / 2.0f - 250.f, WINDOW_HEIGHT-450.f);

	sf::Text text5;
	text5.setFont(font);
	text5.setCharacterSize(20);
	text5.setFillColor(Color::Yellow);
	text5.setOutlineThickness(2);
	text5.setOutlineColor(Color::Black);
	text5.setPosition(WINDOW_WIDTH / 2.0f - 250.f, WINDOW_HEIGHT - 400.f);

	Sprite sprBackground(tBackground);
	Sprite sprPlayer(tPlayer);
	Sprite sprEnemy(tPlatform);
	Sprite sprEnemy2(tPlatform2);
	Sprite sprPowerup100(tPowerup);
	Sprite sprPowerdown(tPowerdown);

	float score = 0;
	float high = 0;
	float fail = 0;

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

		app.draw(sprBackground);
		if(fail==0)
		{
			for (int i = 0; i < PLATES_AMOUNT; ++i)
			{
				Movement* move1 = &en1[i];
				move1->MoveDown();
				if (move1->GetY() < 0)
					move1->cmore();
				sprEnemy.setPosition(en1[i].GetX(), en1[i].GetY());
				app.draw(sprEnemy);
			}

			Movement* move3 = &pu;
			move3->MoveDown();
			if (move3->GetY() < 0)
				move3->cmore();
			sprPowerup100.setPosition(pu.GetX(), pu.GetY());
			app.draw(sprPowerup100);

			Movement* move4 = &pd;
			move4->MoveDown();
			if (move4->GetY() < 0)
				move4->cmore();
			sprPowerdown.setPosition(pd.GetX(), pd.GetY());
			app.draw(sprPowerdown);

			for (int i = 0; i < PLATES_AMOUNT; ++i)
			{
				if (nmUtils::InOnPlate(s, en1[i]))
				{
					fail++;
				}
			}

			score += 0.1;

			sprPlayer.setPosition(s.GetX(), s.GetY());
			app.draw(sprPlayer);

		}
		else
		{
			if (score > high) high = score;
			score = 0;
			text3.setString("Game Over");
			app.draw(text3);
			auto c1 = p.find(1);
			auto c2 = p.find(2);
			text4.setString(std::format("Powerups collected: {:.0f}", c1->second));
			text5.setString(std::format("Powerdowns collected: {:.0f}", c2->second));
			app.draw(text4);
			app.draw(text5);

		}

		if (nmUtils::InOnPlate(s, pu))
		{
			score = score + 100;
			++p[1];
		}

		if (nmUtils::InOnPlate(s, pd))
		{
			try
			{
				score=d.Minus(score);
				++p[2];
			}
			catch (float n) // jeigu prie throw parasomas skaicius
			{
				score = 0;
			}
		}
		
		
		
		text.setString(std::format("{:.0f}", score));
		app.draw(text);

		text2.setString(std::format("{:.0f}", high));
		app.draw(text2);

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			fail++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			fail = 0;
		}

		app.display();
	}

	return 0;
}