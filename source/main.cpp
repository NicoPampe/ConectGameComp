// A simple program that computes the square root of a number
#include <iostream>
#include <string>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

//#include 

//class RectangleChar
//{
//public:
//	RectangleChar();
//	~RectangleChar();
//
//private:
//	int x, y;
//	sf::RectangleShape rectangle;
//	//sf::ve
//	void position(int x, int y) {rectangle.};
//
//};




int main() {
	

	//sf::Window window(sf::VideoMode(800, 600), "My window");
	sf::RenderWindow window(sf::VideoMode(800, 600), "My rendered window");
	window.setVerticalSyncEnabled(true);
	sf::Style::Close;

	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// creat an event, check all of the windows events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close ruquest" we want to close the window and program
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			// "close ruquest" we want to close the window and program
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			/*else if (event.KeyPressed)
			{
			std::cout << "key" << std::endl;
			break;
			}*/
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 120)
					std::cout << "ASCII character typed is: " << static_cast<char>(event.text.unicode) << std::endl;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::L)
				{
					std::cout << "the escape key was pressed" << std::endl;
					std::cout << "control:" << event.key.control << std::endl;
					std::cout << "alt:" << event.key.alt << std::endl;
					std::cout << "shift:" << event.key.shift << std::endl;
					std::cout << "system:" << event.key.system << std::endl;
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				//std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				//std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				std::cout << "Left key was pressed" << std::endl;
			else
				break;
		}

		window.clear(sf::Color::Black);

		sf::CircleShape shape(50);

		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));
		window.draw(shape);

		rectangle.setFillColor(sf::Color(100, 50, 50));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			rectangle.move(5, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			rectangle.move(-5, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			rectangle.move(0, 5);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			rectangle.move(0, -5);
		if (event.key.code == sf::Keyboard::Space)
		{
			window.setKeyRepeatEnabled(false);
			rectangle.rotate(90);
		}
		window.draw(rectangle);

		window.display();

	}

	return 0;
}