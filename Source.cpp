
#include "Define.h"
#include "Controls.h"
#include "Cloud.h"

int main()
{
	sf::Font font;

	if (!font.loadFromFile("Code Files/Resource Files/sansation.ttf")) {
		std::cout << "sansation.ttf Load Error" << std::endl;
		return EXIT_FAILURE;
	}

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Particle Cloud 2D");

	sf::Event event;

	Controls controls;

	Clock clock;
	Physics physics;
	Cloud cloud(window);
	//Screen screen(1920, 1080);
	
	while (window.isOpen()) {

		window.clear();

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		controls.mousePosX = mousePos.x;
		controls.mousePosY = mousePos.y;

		clock.Update(font);

		while (window.pollEvent(event))
		{
			controls.Update(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//screen.Draw(&cloud, window);

		cloud.Draw(&clock, &controls, window);

		clock.Draw(font, window);

		window.display();

	}
}