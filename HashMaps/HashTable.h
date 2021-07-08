#include <string>
#include <vector>
#include <iostream>

class pair {

	public:
		std::string key;
		int value;
		
		pair(const std::string key, const int value){
			this->key = key;
			this->value = value;
		}
};

class HashMap {
	private:
		std::vector<pair*> data;
		std::vector<std::string> dataKeys;

		void keys();
		void setVectorSize(const int &);
		int _hash(const std::string &) const;
		bool checkCollision(const std::string &) const;
		void deleteDataElement(const std::string &);
		void deleteDataKeyElement(const std::string &);
		pair* makeNewPair(std::string&, int&) const;


	public:

		HashMap(const int size){
			setVectorSize(size);
		}	

		void set(std::string , int);
		int get(std::string) const;
		void remove(std::string);
		void displayKeys();
};
