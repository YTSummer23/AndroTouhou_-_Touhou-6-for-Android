#ifndef SFML_GRAPH_HPP
#define SFML_GRAPH_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <mutex>

sf::RenderWindow window;
std::string pathsOfT[(AofT - 1)] = { "data/player00_rgba.png" };

bool createWindow()
{
	window.create(sf::VideoMode(800, 600), "Touhou 6");
	window.setVerticalSyncEnabled(1);
	return window.isOpen();
}

void setTextures(sf::Texture* textures[])
{
	for(int k = 0; textures[k] != NULL; ++k)//I don't know what i made here NULL for  \/(0-0)\/
	{
		textures[k] = new sf::Texture;
		(textures[k])->loadFromFile(pathsOfT[k]);
	}
}

sf::Sprite* setSprites(sf::Texture* texture, int k1)
{
	int AofS;//amount of sprites
	switch (k1)
	{
		case 0://reimu texture and sprites
			AofS=(23 + 1);//1 stands for NULL :) NULL IS MY LIFE!!! NUUULL!!! (Like minecraft, but NULL)
			break;
	}
	sf::Sprite* sprite = new sf::Sprite [AofS];
	for(int k=0; k < (AofS-1); ++k)
	{
		sprite[k].setTexture((*texture));
	}
	//sprite[AofS - 1] = NULL;
	return sprite;
}

void windowDisplay(sf::Sprite* sprites[]/* *coordNeededToDisplay*/)
{
        window.clear(sf::Color::Blue);
	/*for(int k = 0; sprites[k] != NULL; ++k)
	{
		for(int j = 0; sprites[k][j] != NULL; ++j)
		{
			window.draw(sprites[k][j]);
		}
	}*/
	window.draw(sprites[0][0]);
        window.display();
}

unsigned char getKeys()
{
	unsigned char input = 0;
	input += sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) << 1);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) << 2);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) << 3);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) << 4);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) << 5);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::X) << 6);
	input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) << 7);
	return input;
}

void windowLoop(sf::Sprite* sprites[]/* void (Game::*exit)() *coordNeededToDisplay*/)
{
	sf::Clock clock;
	while (window.isOpen())
	{
		*gameTime = (clock.restart()).asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
        		if (event.type == sf::Event::Closed)
			{
				isExit = true;
				while(isExit)
				{ }
				window.close();
			}
		}
		inputMutex.lock();
		input = getKeys();
		inputMutex.unlock();
		aMutex.lock();
		sprites[0][0].setPosition(xyP[0], xyP[1]);
		aMutex.unlock();
		windowDisplay(sprites);
	}
}

#endif