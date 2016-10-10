#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "BaseEntity.h"
#include "UtilRandom.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AI Framework");
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Green);

	std::cout << "Constructed SFML Window" << std::endl;

	for (int i = 0; i < 5; i++) 
	{
		BaseEntity *boid = new BaseEntity();
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window.close();
		}

		window.clear();
		
		for ( auto entity : BaseEntity::Renderables )
		{
			entity->Think();
		}

		for (auto entity : BaseEntity::Renderables)
		{
			window.draw(entity->GetSprite(), entity->getTransform());
		}

		window.display();
	}

	return 0;
}
