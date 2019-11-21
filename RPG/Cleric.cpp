#include "Cleric.h"

Cleric::Cleric() {
	pietyLevel_ = 0;

}

Cleric::Cleric(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int level) :
	GameCharacter( name, health, weightLimit, weapon, armour, food, state ), pietyLevel_{ level } {

}

void Cleric::SetPietyLevel(int level) {
	pietyLevel_ = level;
}

int Cleric::GetPietyLevel() const {
	return pietyLevel_;
}

bool Cleric::Attack(GameCharacter& character) {
	if (GameCharacter::Attack(character) ){
		return true;
	}
	return false;
}

void Cleric::PrayFor(GameCharacter& character) {
	std::cout << GetCharacterName() << " is praying for " << character.GetCharacterName() << std::endl;
}


void Cleric::Sleep() {
	float tmp{ GetCharacterHealth() };
	tmp = tmp + (tmp * 0.15);
	SetCharacterHealth(tmp);
	GameCharacter::Sleep();
}
