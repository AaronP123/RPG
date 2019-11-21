#include "Orc.h"

Orc::Orc() {
	ferociousness_ = 0;
	strength_ = 0;
}

Orc::Orc(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int ferocious, int strength) :
	GameCharacter(name, health, weightLimit, weapon, armour, food, state), ferociousness_{ ferocious }, strength_{ strength }{

}

void Orc::SetFerociousness(int ferocious) {
	ferociousness_ = ferocious;
}

int Orc::GetFerociousness() const {
	return ferociousness_;
}

void Orc::SetStrength(int strength) {
	strength_ = strength;
}

int Orc::GetStrength() const {
	return strength_;
}

bool Orc::Attack(GameCharacter& character) {
	if (GameCharacter::Attack(character)) {
		return true;
	}
	return false;
}

void Orc::Scream(GameCharacter& character) {
	std::cout << "Orc " << GetCharacterName() << " is screaming at " << character.GetCharacterName() << std::endl;
}

void Orc::Sleep() {
	float tmp{ GetCharacterHealth() };
	tmp = tmp + (tmp * 0.15);
	SetCharacterHealth(tmp);
	GameCharacter::Sleep();
}

