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
		//��� ���������
		std::wstring nameCharacter;

		//������ ������� ��� �������� ��������� �� �����
		sf::Texture* arrTextureMap = nullptr;
		//������ ������� ������� ��������� �� �����
		DWORD countTextureMap = 0;

		//������ ������� ��� �������� ��������� � ���
		sf::Texture* arrTextureBattle = nullptr;
		//������ ������� ������� ��������� � ���
		DWORD countTextureBattle = 0;

		//������ ������� ��� �������� ����
		sf::Texture* arrTextureAttacks = nullptr;
		//������ ������� ������� ����
		DWORD countTextureAttacks = 0;

		//������ ���
		sf::SoundBuffer musicBatle;
		

		//����� �� ��������
		BOOL isAlive = TRUE;
		//������� ������ �� �����
		DWORD currMapSprite = 0;
		//������� ������ � ���
		DWORD currBattleSprite = 0;

		//������� ������� � ������� ���������� ��������
		DWORD currLocation = 0;
		//������� ��������� �� ��� X
		DWORD currPosX = 0;
		//������� ��������� �� ��� Y
		DWORD currPosY = 0;
	public:
		Character(VOID) = delete;
		virtual ~Character(VOID);

		
	};
}