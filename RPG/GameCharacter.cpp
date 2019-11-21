#include "GameCharacter.h"

GameCharacter::GameCharacter() {
	characterName_ = "";
	health_ = 0;
	weightLimit_ = 0;
	weapon_ = Weapon("", 0, 0, 0, 0);
	armour_ = Armour("", 0, 0, 0, 0, ArmourType::Cardboard);
	food_ = 0;
	state_ = CharacterState::Idle;
	std::cout << "A Game Character " << characterName_ << " has been born\n";
}

GameCharacter::GameCharacter(std::string name, float health, float weight, Weapon weapon, Armour armour, int food, CharacterState state) :
	characterName_{ name }, health_{health}, weightLimit_{weight}, weapon_{weapon}, armour_{armour},food_{food}, state_{state}{
	std::cout << "A Game Character " << characterName_ << " has been born\n";
	}


void GameCharacter::SetCharacterName(std::string name) {
	characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
	return characterName_;
}

void GameCharacter::SetCharacterHealth(float health) {
	health_ = health;
}

float GameCharacter::GetCharacterHealth() const {
	return health_;
}

void GameCharacter::SetCharacterWeightLimit(float weightLimit) {
	weightLimit_ = weightLimit;
}

float GameCharacter::GetCharacterWeightLimit() const {
	return weightLimit_;
}

void GameCharacter::SetCharacterWeapon(Weapon weapon) {
	weapon_ = weapon;
}

Weapon GameCharacter::GetCharacterWeapon() const {
	return weapon_;
}

void GameCharacter::SetCharacterArmour(Armour armour) {
	armour_ = armour;
}

Armour GameCharacter::GetCharacterArmour() const {
	return armour_;
}

void GameCharacter::SetCharacterFood(int food) {
	food_ = food;
}

int GameCharacter::GetCharacterFood() const {
	return food_;
}

void GameCharacter::SetCharacterState(CharacterState state) {
	state_ = state;
}

CharacterState GameCharacter::GetCharacterState() const {
	return state_;
}

void GameCharacter::AddFood(int amount) {
	int food = GetCharacterFood() + amount;
	SetCharacterFood(food);
}

void GameCharacter::Eat() {
	int food = GetCharacterFood();
	int health = GetCharacterHealth();
	if (food >= 4) {
		food -= 4;
		health += 1;
		SetCharacterHealth(health);
		SetCharacterFood(food);
	}
	else{
		for (int i = food; i >= 0; i--) {
			food--;
			health += 0.25;
		}
		SetCharacterFood(food);
		SetCharacterHealth(health);
	}
}

bool GameCharacter::Attack(GameCharacter& character) {
	std::cout << characterName_ << " is attacking " << character.GetCharacterName() << " with " << weapon_.GetItemName() << std::endl;
	state_ = CharacterState::Attacking;
	return true;
}

void GameCharacter::Defend() {
	std::string tmp{};
	switch (armour_.GetArmourType()) {
	case ArmourType::Cardboard: tmp = "Cardboard"; break;
	case ArmourType::Iron: tmp = "Iron"; break;
	case ArmourType::Leather: tmp = "Leather"; break;
	case ArmourType::Steel: tmp = "Steel"; break;
	case ArmourType::Wood: tmp = "Wood"; break;
	}
	std::cout << GetCharacterName() << " is defending themselves with a " << armour_.GetItemName() << " made from " << tmp << std::endl;
	state_ = CharacterState::Defending;
}

void GameCharacter::Walk() {
	std::cout << characterName_ << " is walking" << std::endl;
	state_ = CharacterState::Walking;
}

void GameCharacter::Run() {
	std::cout << characterName_ << " is running" << std::endl;
	state_ = CharacterState::Running;
}

void GameCharacter::Sleep() {
	std::cout << characterName_ << " is sleeping" << std::endl;
	state_ = CharacterState::Sleeping;
}



