#pragma once
#include "GlobalHeader.h"
#include "DllProvider.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Container
{

	static Container* instance;

	std::vector<sf::Texture> ui;
	std::vector<sf::Texture> sprites;
	std::vector<sf::SoundBuffer> music;
	std::vector<sf::SoundBuffer> musicEffects;

	Container()
	{
		std::size_t iIndex = 0;
		while (GetFileById(PATH_UI, TEMPORALY_FILE_W, iIndex++))
		{
			sf::Texture img;
			img.loadFromFile(TEMPORALY_FILE_A);
			DeleteFile(TEMPORALY_FILE_W);
			this->ui.push_back(img);
		}
		iIndex = 0;
		while (GetFileById(PATH_SPRITES, TEMPORALY_FILE_W, iIndex++))
		{
			sf::Texture img;
			img.loadFromFile(TEMPORALY_FILE_A);
			DeleteFile(TEMPORALY_FILE_W);
			this->sprites.push_back(img);
		}
		iIndex = 0;
		while (GetFileById(PATH_MUSIC, TEMPORALY_FILE_W, iIndex++))
		{
			sf::SoundBuffer sb;
			sb.loadFromFile(TEMPORALY_FILE_A);
			DeleteFile(TEMPORALY_FILE_W);
			this->music.push_back(sb);
		}
		iIndex = 0;
		while (GetFileById(PATH_EFFECTS, TEMPORALY_FILE_W, iIndex++))
		{
			sf::SoundBuffer sb;
			sb.loadFromFile(TEMPORALY_FILE_A);
			DeleteFile(TEMPORALY_FILE_W);
			this->musicEffects.push_back(sb);
		}
	}
public:
	~Container()
	{
		this->ui.clear();
		this->sprites.clear();
		this->music.clear();
		this->musicEffects.clear();
	}

	static Container* getInstance(void)
	{
		if (Container::instance == nullptr)
			Container::instance = new Container();
		return Container::instance;
	}
	sf::Texture& getUIbyID(std::size_t id)
	{
		return this->ui[id];
	}
	sf::Texture& getSpritebyID(std::size_t id)
	{
		return this->sprites[id];
	}
	sf::SoundBuffer& getSoundByID(std::size_t id)
	{
		return this->music[id];
	}
	sf::SoundBuffer& getSoundEffectByID(std::size_t id)
	{
		return this->musicEffects[id];
	}
};