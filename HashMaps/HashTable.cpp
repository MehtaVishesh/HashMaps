#include "HashTable.h"


int HashMap::_hash(const std::string &key) const{

	int hash = 0;

	for (int i = 0; i < key.size(); i++) {
		hash = (hash + (int(key[i]) * i)) % data.size();
	}

	return hash;
}

pair* HashMap::makeNewPair(std::string &key, int &value) const{

	pair* newPair = new pair(key, value);

	return newPair;
}

void HashMap::set(std::string key, int value){

	if (!checkCollision(key)) {
		data[_hash(key)] = makeNewPair(key, value);
	}
}


int HashMap::get(std::string key) const{

	int keyHash = _hash(key);

	for (int i = 0; i < data.size(); i++) {
		if (data[i] != nullptr) {
			if (data[keyHash]->key == data[i]->key) {
				return data[keyHash]->value;
			}
		}
	}

	return -1;
}


void HashMap::remove(std::string key) {

	deleteDataElement(key);
	deleteDataKeyElement(key);
}


void HashMap::setVectorSize(const int &size) {
	data.reserve(size);

	for (int i = 0; i < size; i++) {
		data.push_back(nullptr);
	}
}


bool HashMap::checkCollision(const std::string &key) const {

	for (int i = 0; i < data.size(); i++) {
		if (data[i] != nullptr){
			if (data[i]->key == key) {
				return true;
			}
		}
	}

	return false;
}


void HashMap::keys() {

	dataKeys.clear();
	for (int i = 0; i < data.size(); i++) {
		if (data[i] != nullptr) {
			dataKeys.push_back(data[i]->key);
		}
	}
}


void HashMap::displayKeys(){

	keys();
	for (int i = 0; i < dataKeys.size(); i++) {
		std::cout << dataKeys[i] << std::endl;
	}
}

void HashMap::deleteDataElement(const std::string &key) {
	for (int i = 0; i < data.size(); i++) {

		if (data[i] != nullptr) {

			if (key == data[i]->key) {
				pair* temp = data[i];
				data[i] = nullptr;
				delete temp;
			}
		}
	}
}

void HashMap::deleteDataKeyElement(const std::string &key) {

	for (int i = 0; i < dataKeys.size(); i++) {
		if (key == dataKeys[i]) {
			dataKeys.erase(dataKeys.begin() + i);
		}
	}
}