#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GlobalHeader.h"
namespace Characters
{
	class Character
	{
	protected:
		//Имя персонажа
		std::wstring nameCharacter;

		//Массив текстур для спрайтов персонажа на карте
		sf::Texture* arrTextureMap = nullptr;
		//Размер массива текстур персонажа на карте
		DWORD countTextureMap = 0;

		//Массив текстур для спрайтов персонажа в бою
		sf::Texture* arrTextureBattle = nullptr;
		//Размер массива текстур персонажа в бою
		DWORD countTextureBattle = 0;

		//Массив текстур для спрайтов атак
		sf::Texture* arrTextureAttacks = nullptr;
		//Размер массива текстур атак
		DWORD countTextureAttacks = 0;

		//Музыка боя
		sf::SoundBuffer musicBatle;
		

		//Живой ли персонаж
		BOOL isAlive = TRUE;
		//Текущий спрайт на карте
		DWORD currMapSprite = 0;
		//Текущий спрайт в бою
		DWORD currBattleSprite = 0;

		//Текущая локация в которой находиться персонаж
		DWORD currLocation = 0;
		//Позиция персонажа по оси X
		DWORD currPosX = 0;
		//Позиция персонажа по оси Y
		DWORD currPosY = 0;
	public:
		Character(VOID) = delete;
		virtual ~Character(VOID);

		
	};
}