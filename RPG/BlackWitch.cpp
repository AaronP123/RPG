#include "BlackWitch.h"

BlackWitch::BlackWitch() {
	magicProficiency_ = 0;
	darkPower_ = 0;
}

BlackWitch::BlackWitch(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int magic, int power) :
	GameCharacter(name, health, weightLimit, weapon, armour, food, state), magicProficiency_(magic), darkPower_{ power } {

}

void BlackWitch::SetMagicProficiency(int magic) {
	magicProficiency_ = magic;
}

int BlackWitch::GetMagicProficiency() const {
	return magicProficiency_;
}

void BlackWitch::SetDarkPower(int power) {
	darkPower_ = power;
}

int BlackWitch::GetDarkPower() const {
	return darkPower_;
}

bool BlackWitch::Attack(GameCharacter& character) {
	if (GameCharacter::Attack(character)) {
		return true;
	}
	return false;
}

void BlackWitch::Bewitch(GameCharacter& character) {
	std::cout << "Black witch" << GetCharacterName() << " is attempting to bewitch " << character.GetCharacterName() << std::endl;
}

void BlackWitch::Sleep() {
	float tmp{ GetCharacterHealth() };
	tmp = tmp + (tmp * 0.15);
	SetCharacterHealth(tmp);
	GameCharacter::Sleep();
}

