#include "ObjectManager.h"
#include <string>

// Constructor

ObjectManager::ObjectManager() {
	m_player = Player();
	kraken_exist = false;
}

// Getter

Player& ObjectManager::GetPlayer() {
	return m_player;
}

vector<MovableObject*>& ObjectManager::GetMovable() {
	return m_vector_movable;
}

vector<GameObject*>& ObjectManager::GetImmovable() {
	return m_vector_immovable;
}

// Setter

void ObjectManager::AddMovable(MovableObject* object) {
	m_vector_movable.push_back(object); //add Movable object using push_back
}

void ObjectManager::AddImmovable(GameObject* object) {
	m_vector_immovable.push_back(object); //add Immovable object using push_back
}

void ObjectManager::ResetPlayer() {
	m_player.Stop();
	m_player.SetCenter(0, 0);
}

void ObjectManager::RemoveMovable(MovableObject* object) {
	vector <MovableObject*>::iterator it;
	for (int i = 0; i < m_vector_movable.size(); i++) {
		if (m_vector_movable[i] == object) {
			delete object;
			m_vector_movable.erase(m_vector_movable.begin() + i);
		}
	}
	//I don'know how can i use std::find_if 
}

void ObjectManager::RemoveImmovable(GameObject* object) {
	for (int i = 0; i < m_vector_immovable.size(); i++) {
		if (m_vector_immovable[i] == object) {
			delete object;
			m_vector_immovable.erase(m_vector_immovable.begin() + i);
		}
	}
}

void ObjectManager::RemoveAllMovables() {
	m_vector_movable.clear();
	kraken_exist = false;
}

void ObjectManager::RemoveAllImmovables() {
	m_vector_immovable.clear();
}

void ObjectManager::Clear() {
	m_vector_movable.clear();
	m_vector_immovable.clear();
	kraken_exist = false;
}

bool ObjectManager::GetKraken() {
	return kraken_exist;
}

void ObjectManager::SetKraken(bool boolean) {
	kraken_exist = boolean;
}