#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 683), "Testing");
	window.setVerticalSyncEnabled(true);

	/*sf::Texture texture;
	sf::Texture ortonTexture;
	sf::Texture heartTexture;
	if (!texture.loadFromFile("TestCena2.png"))
	{
		std::cout << "Failed to load image\n";
	}
	if (!ortonTexture.loadFromFile("TestOrton.png"))
	{
		std::cout << "Failed to load image\n";
	}
	if (!heartTexture.loadFromFile("TestHeart.png"))
	{
		std::cout << "Failed to load image\n";
	}*/

	sf::Texture background;
	background.loadFromFile("ForestBackground.jpg");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	sf::Image foxSpriteSheet;
	foxSpriteSheet.loadFromFile("FoxSprites.png");
	int foxSpriteLength = 48;
	int currentFoxSprite = 6;
	sf::Texture foxTexture;
	sf::IntRect spriteBox(((currentFoxSprite % 3))*foxSpriteLength, ((currentFoxSprite % 4))*foxSpriteLength, foxSpriteLength, foxSpriteLength);
	foxTexture.loadFromImage(foxSpriteSheet, spriteBox);
	sf::Sprite foxSprite;
	foxSprite.setTexture(foxTexture);
	//window.draw(foxSprite);
	foxSprite.setPosition(0, 500);
	sf::FloatRect foxBox = foxSprite.getGlobalBounds();

	sf::RectangleShape rectangle(sf::Vector2f(60, 60));
	rectangle.setFillColor(sf::Color(255, 0, 0));
	rectangle.setPosition(400, 500);
	sf::RectangleShape rectangle2(sf::Vector2f(60, 120));
	rectangle2.setFillColor(sf::Color(255, 0, 0));
	rectangle2.setPosition(800, 440);
	sf::FloatRect rectBox = rectangle.getGlobalBounds();
	sf::FloatRect rect2Box = rectangle2.getGlobalBounds();

	int animationCounter = 0;
	int jumpCounter = 0;
	int jumpVelo = -6;
	int jumpTime = 0;
	bool jumping = false;
	int jumpAccel = 1;

	/*sf::Sprite shape;
	shape.setTexture(texture);
	shape.setPosition(0, 0);
	sf::Sprite orton;
	orton.setTexture(ortonTexture);
	orton.setPosition(750,0);
	sf::Sprite heart;
	heart.setTexture(heartTexture);
	sf::Sprite heart2;
	heart2.setTexture(heartTexture);

	sf::FloatRect cenaBox = shape.getGlobalBounds();
	sf::FloatRect ortonBox = orton.getGlobalBounds();

	int kissCount = 0;*/

	//shape.setScale(100.0f, 100.0f);
	//shape.setPosition(0, 0);

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//sf::Vector2f position = shape.getPosition;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			shape.move(5, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			shape.move(-5, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			shape.move(0, -5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			shape.move(0, 5);
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			foxBox = foxSprite.getGlobalBounds();

			/*if (foxBox.intersects(rectBox) && foxBox.left<(rectBox.width + rectBox.left) || (foxBox.left+foxBox.width)>(rectBox.left))
			{
				jumping = false;
			}*/

			if (foxBox.intersects(rectBox))
			{
				std::cout << "Testing\n";
			}

			if (foxBox.intersects(rectBox) && (foxBox.top + foxBox.height) > (rectBox.top) && ((foxBox.left) + (foxBox.width)) >= (rectBox.left))
			{
				// && ((foxBox.left) + (foxBox.width)) >= (rectBox.left)
			}
			else
			{
				foxSprite.move(3, 0);

				if (currentFoxSprite != 6 && currentFoxSprite != 7)
				{
					currentFoxSprite = 6;
				}
				else if (animationCounter % 10 != 9)
				{
					animationCounter++;
				}
				else
				{
					animationCounter = 0;
					currentFoxSprite++;
				}

				sf::IntRect newSpriteBox(((currentFoxSprite % 3))*foxSpriteLength, ((currentFoxSprite / 3))*foxSpriteLength, foxSpriteLength, foxSpriteLength);
				foxTexture.loadFromImage(foxSpriteSheet, newSpriteBox);
				foxSprite.setTexture(foxTexture);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			foxBox = foxSprite.getGlobalBounds();

			/*if (foxBox.intersects(rectBox) && foxBox.left<(rectBox.width + rectBox.left) || (foxBox.left + foxBox.width)>(rectBox.left))
			{
				jumping = false;
			}*/

			
			if (foxBox.intersects(rectBox) && (foxBox.top + foxBox.height) > (rectBox.top) && foxBox.left <= (rectBox.width + rectBox.left))
			{
				// && foxBox.left<=(rectBox.width + rectBox.left)
			}
			else
			{
				foxSprite.move(-3, 0);

				if (currentFoxSprite != 3 && currentFoxSprite != 4)
				{
					currentFoxSprite = 3;
				}
				else if (animationCounter % 10 != 9)
				{
					animationCounter++;
				}
				else
				{
					animationCounter = 0;
					currentFoxSprite++;
				}

				sf::IntRect newSpriteBox(((currentFoxSprite % 3))*foxSpriteLength, ((currentFoxSprite / 3))*foxSpriteLength, foxSpriteLength, foxSpriteLength);
				foxTexture.loadFromImage(foxSpriteSheet, newSpriteBox);
				foxSprite.setTexture(foxTexture);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!jumping)
			{
				jumping = true;
				//jumpVelo = 50;
				jumpTime = 0;
			}
		}

		if (jumping)
		{
			
			jumpTime++;
			int calcedMove = jumpVelo*jumpTime + 0.5*jumpAccel*jumpTime*jumpTime;
			foxSprite.move(0, calcedMove);

			if (foxSprite.getPosition().y > 500)
			{
				foxSprite.setPosition(foxSprite.getPosition().x, 500);
				jumping = false;
			}

			foxBox = foxSprite.getGlobalBounds();

			if (foxBox.intersects(rectBox) && (foxBox.top + foxBox.height) >= (rectBox.top))
			{
				jumping = false;
			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			foxSprite.move(0, -2);

			if (currentFoxSprite != 9 && currentFoxSprite != 10)
			{
				currentFoxSprite = 9;
			}
			else if (animationCounter % 10 != 9)
			{
				animationCounter++;
			}
			else
			{
				animationCounter = 0;
				currentFoxSprite++;
			}

			sf::IntRect newSpriteBox(((currentFoxSprite % 3))*foxSpriteLength, ((currentFoxSprite /3))*foxSpriteLength, foxSpriteLength, foxSpriteLength);
			foxTexture.loadFromImage(foxSpriteSheet, newSpriteBox);
			foxSprite.setTexture(foxTexture);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			foxSprite.move(0, 2);

			if (currentFoxSprite != 0 && currentFoxSprite != 1)
			{
				currentFoxSprite = 0;
			}
			else if (animationCounter % 10 != 9)
			{
				animationCounter++;
			}
			else
			{
				animationCounter = 0;
				currentFoxSprite++;
			}

			sf::IntRect newSpriteBox(((currentFoxSprite % 3))*foxSpriteLength, ((currentFoxSprite /3))*foxSpriteLength, foxSpriteLength, foxSpriteLength);
			foxTexture.loadFromImage(foxSpriteSheet, newSpriteBox);
			foxSprite.setTexture(foxTexture);
		}*/

		//cenaBox = shape.getGlobalBounds();
		//ortonBox = orton.getGlobalBounds();
		
		window.clear();
		//window.draw(shape);
		//window.draw(orton);
		window.draw(backgroundSprite);
		window.draw(foxSprite);
		window.draw(rectangle);
		window.draw(rectangle2);
		
		/*if (cenaBox.intersects(ortonBox))
		{
			heart.setPosition(ortonBox.left, ortonBox.top);
			heart2.setPosition(cenaBox.left + cenaBox.width, cenaBox.top);
			window.draw(heart);
			window.draw(heart2);
		}*/
		/*if ((ortonBox.left + ortonBox.width) > cenaBox.left)
		{
			window.draw(heart);
			std::cout << "Kiss " << ++kissCount << "\n";
		}*/
		
		
		window.display();
	}

	return 0;
}