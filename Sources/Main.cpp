#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>
#include <vector>

#include "Objects.h"
#include "Utils.h"

using namespace sf;
using namespace std;
class car
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
	double get_x()
	{
		return px;
	}
	double get_y()
	{
		return py;
	}

};

int main()
{
	//double positionx, positiony;
	car s;
	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Long Road Deluxe");
	app.setFramerateLimit(60);

	Texture tBackground, tPlayer, tPlatform, tPowerup1, tPowerup5;
	tBackground.loadFromFile("Resources/road.png");
	tPlayer.loadFromFile("Resources/car.png");
	tPlatform.loadFromFile("Resources/encar.png");
	tPowerup1.loadFromFile("Resources/points100.png");
	tPowerup5.loadFromFile("Resources/points500.png");

	sf::Font font;
	font.loadFromFile("Resources/arialbd.ttf");

	Sprite sprBackground(tBackground);
	Sprite sprPlayer(tPlayer);
	Sprite sprPlatform(tPlatform);
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
			//positionx = s.get_x();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			++s;
			//positionx = s.get_x();
		}

		app.draw(sprBackground);

		sprPlayer.setPosition(s.get_x(), s.get_y());
		app.draw(sprPlayer);

		app.display();
	}
	
	return 0;
}