#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>
#include <vector>

#include "Objects.h"
#include "Utils.h"

using namespace sf;
using namespace std;

class Car
{
private:
	Player player;
	double px = WINDOW_WIDTH / 2, py = 100;
	const float dx = 10.0f;

public:
	void operator ++()
	{
		px += dx;
	}
	void operator --()
	{
		px -= dx;
	}
	double GetX()
	{
		return px;
	}
	double GetY()
	{
		return py;
	}
};

class Movement
{
protected:
	float ey, ex, dy;

public:
	virtual void MoveDown() // padaryk grynai virtualiu metodu
	{
		ey -= dy;
	}
	virtual void cmore()
	{
		ey = (float)WINDOW_HEIGHT - 20 * (rand() % 3);
		ex = float(rand() % (WINDOW_WIDTH - PLATES_WIDTH));
	}
	float GetX()
	{
		return ex;
	}
	float GetY()
	{
		return ey;
	}
};
class Enemy1 : public Movement
{
public:
	Enemy1()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
		dy = 5;
	}
};
class Enemy2 : public Movement
{
public:
	Enemy2()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand()%20); 
	}
	void MoveDown()
	{
		ey -= 8;
	}
};
class Powerup : public Movement
{
public:
	Powerup()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
		dy = 4;
	}

};
class Powerdown : public Movement
{
public:
	Powerdown()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
	}
	void MoveDown()
	{
		ey -= 6;
	}

};
int main()
{
	Car s;
	Enemy1 en1[PLATES_AMOUNT];
	Enemy2 en2[PLATES_AMOUNT];
	Powerup pu;
	Powerdown pd;

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

		for (int i = 0; i < PLATES_AMOUNT; ++i)
		{
			Movement* move1 = &en1[i];
			move1->MoveDown();
			if (move1->GetY() < 0)
				move1->cmore();
			sprEnemy.setPosition(en1[i].GetX(), en1[i].GetY());
			app.draw(sprEnemy);
		}

		for (int i = 0; i < PLATES_AMOUNT; ++i)
		{
			Movement* move2 = &en2[i];
			move2->MoveDown();
			if (move2->GetY() < 0)
				move2->cmore();
			sprEnemy2.setPosition(en2[i].GetX(), en2[i].GetY());
			app.draw(sprEnemy2);
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

		score += 0.1;
		text.setString(std::format("{:.0f}", score));
		app.draw(text);

		sprPlayer.setPosition(s.GetX(), s.GetY());
		app.draw(sprPlayer);

		app.display();
	}

	return 0;
}