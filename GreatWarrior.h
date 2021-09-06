#ifndef GREATWARRIOR_H_
#define GREATWARRIOR_H_
#include <iostream>
using namespace std;

class Land{
		string holding;
		string name;
	public:
		Land(const Land &);
		Land(string=" ", string=" ");
		string getName(){
		return name;
		};
		string getHolding(){
			return holding;
		};
		Land *next;
};

class Character{
		int gold;
		int manpower;
		string name;
		int numofLands;
		Land *lands;		
	public:
		~Character();
		Character(const Character &);
		Character(string, int, int, int);
		Land * getLands();
		string getName();
		void setName(string);
		int getNumofLands();
		void setNumofLands(int);
		int getGold();
		void setGold(int);
		int getManpower();
		void setManpower(int);
		void getTaxes();
		string getGen() const;
		void addLand(Land *);
		void removeLand(Land *);
		void randomRemove();
};

class CharacterList{
		int size;
		Character *characters;
	public:
		~CharacterList();
		Character & getPlayer();
		Character & getLandOwner(string);
		friend void listCharacters(CharacterList &);
		friend void listLands(CharacterList &);
		int getSize();
		CharacterList();
		void addCharacter(Character &);
		void delCharacter(string);
		Land * findLand(string);
};
#endif
