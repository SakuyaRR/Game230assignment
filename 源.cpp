#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
float BrushRadius = 64.f;
sf::Color BrushColor = sf::Color::Green;


int main()
{
	bool tWo = false;


	sf::RenderWindow window(sf::VideoMode(1500, 1600), "SFML works!");

	sf::CircleShape shape(BrushRadius);
	sf::CircleShape shape2(BrushRadius);


	shape.setFillColor(BrushColor);
	shape2.setFillColor(BrushColor);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::R)
					BrushColor = sf::Color::Red;

				if (event.key.code == sf::Keyboard::B)
					BrushColor = sf::Color::Blue;

				if (event.key.code == sf::Keyboard::G)
					BrushColor = sf::Color::Green;

				if (event.key.code == sf::Keyboard::Up)
					BrushRadius += 4;

				if (event.key.code == sf::Keyboard::Down)
					BrushRadius -= 4;

				if (event.key.code == sf::Keyboard::D)
				{

					tWo = !tWo;

				}

				if (event.key.code == sf::Keyboard::Space) {
					sf::Texture texture;
					texture.create(window.getSize().x, window.getSize().y);
					texture.update(window);
					if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
					{
						std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
					}
				}

			}


		}

		if (tWo)
		{
			shape2.setPosition(sf::Mouse::getPosition(window).x - 20 - BrushRadius,
				sf::Mouse::getPosition(window).y - 20 - BrushRadius);
			shape2.setFillColor(BrushColor);
			shape2.setRadius(BrushRadius);
			window.draw(shape2);
			
		}


		shape.setPosition(sf::Mouse::getPosition(window).x - BrushRadius,
			sf::Mouse::getPosition(window).y - BrushRadius);

		shape.setFillColor(BrushColor);
		shape.setRadius(BrushRadius);
		
		window.draw(shape);

		window.display();





	}

	return 0;
}