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
	const float dx = 7.0f;

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
		ey = float(WINDOW_HEIGHT);
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
		ey = float(WINDOW_HEIGHT);
		dy = 5;
	}
};
class Enemy2 : public Movement
{
public:
	Enemy2()
	{
		ey = float(WINDOW_HEIGHT);
	}
	void MoveDown()
	{
		ey -= 10;
	}
};
int main()
{
	Car s;
	Enemy1 en1[PLATES_AMOUNT];
	Enemy2 en2[PLATES_AMOUNT];

	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Long Road Deluxe");
	app.setFramerateLimit(60);

	Texture tBackground, tPlayer, tPlatform, tPlatform2, tPowerup1, tPowerup5;
	tBackground.loadFromFile("Resources/road.png");
	tPlayer.loadFromFile("Resources/car.png");
	tPlatform.loadFromFile("Resources/encar.png");
	tPlatform2.loadFromFile("Resources/encar2.png");
	tPowerup1.loadFromFile("Resources/points100.png");
	tPowerup5.loadFromFile("Resources/points500.png");

	sf::Font font;
	font.loadFromFile("Resources/arialbd.ttf");

	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/Undertale Ost - 098 - Battle Against a True Hero.wav");

	Sprite sprBackground(tBackground);
	Sprite sprPlayer(tPlayer);
	Sprite sprEnemy(tPlatform);
	Sprite sprEnemy2(tPlatform2);
	Sprite sprPowerup100(tPowerup1);
	Sprite sprPowerup500(tPowerup5);

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



		sprPlayer.setPosition(s.GetX(), s.GetY());
		app.draw(sprPlayer);

		app.display();
	}

	return 0;
}