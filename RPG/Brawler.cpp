#include "Brawler.h"

Brawler::Brawler() {
	punchDamage_ = 0;
	strength_ = 0;
}

Brawler::Brawler(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int punchDamage, int strength) :
	GameCharacter(name, health, weightLimit, weapon, armour, food, state), punchDamage_{ punchDamage }, strength_{ strength }{
}

void Brawler::SetPunchDamage(int damage) {
	punchDamage_ = damage;
}

int Brawler::GetPunchDamage() const {
	return punchDamage_;
}

void Brawler::SetStrength(int strength) {
	strength_ = strength;
}

int Brawler::GetStrength() const {
	return strength_;
}

bool Brawler::Attack(GameCharacter& character) {
	if (GameCharacter::Attack(character)) {
		return true;
	}
	return false;
}

bool Brawler::Brawl(GameCharacter& character) {
	std::cout << GetCharacterName() << " is brawling with " << character.GetCharacterName() << std::endl;
	return true;
}

void Brawler::Sleep() {
	float tmp{ GetCharacterHealth() };
	tmp = tmp + (tmp * 0.15);
	SetCharacterHealth(tmp);
	GameCharacter::Sleep();
}

