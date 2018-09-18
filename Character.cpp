#include "Character.h"

namespace Characters
{
	Character::~Character(VOID)
	{
		this->nameCharacter.clear();
		if (this->arrTextureMap != nullptr)
		{
			for (DWORD i = 0; i < this->countTextureMap; ++i)
				this->arrTextureMap[i].loadFromMemory(nullptr, NULL);
			delete[] this->arrTextureMap;
			this->arrTextureMap = nullptr;
			this->countTextureMap = 0;
		}
		if (this->arrTextureBattle != nullptr)
		{
			for (DWORD i = 0; i < this->countTextureBattle; ++i)
				this->arrTextureBattle[i].loadFromMemory(nullptr, NULL);
			delete[] this->arrTextureBattle;
			this->arrTextureBattle = nullptr;
			this->countTextureBattle = 0;
		}
		if (this->arrTextureAttacks != nullptr)
		{
			for (DWORD i = 0; i < this->countTextureAttacks; ++i)
				this->arrTextureAttacks[i].loadFromMemory(nullptr, NULL);
			delete[] this->arrTextureAttacks;
			this->arrTextureAttacks = nullptr;
			this->countTextureAttacks = 0;
		}
		this->musicBatle.loadFromMemory(nullptr, NULL);
	}

}