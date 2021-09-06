#include "GreatWarrior.h"
#include <iostream>
using namespace std;

//constructors

Land::Land(string name, string holding){
	this->name=name;
	this->holding=holding;
	next=NULL;
}

Land::Land(const Land &landIn){
	name=landIn.name;
	holding=landIn.holding;
	next=NULL;
}


//constructors and destructors

Character::Character(string name="default", int manpower=0, int gold=0, int numofLands=0){
	this->name=name;
	this->gold=gold;
	this->manpower=manpower;
	this->numofLands=numofLands;
	lands=NULL;
}

Character::Character(const Character &objIn){
	name=objIn.name;
	gold=objIn.gold;
	manpower=objIn.manpower;
	numofLands=objIn.numofLands;
	Land *temp=objIn.lands;
	lands=NULL;
	while(temp!=NULL){
		Land *a = new Land(*temp);
		this->addLand(a);
		temp=temp->next;
	}
}

Character::~Character(){
	Land *tail=lands;
	while(tail!=NULL){
		lands=lands->next;
		delete tail;
		tail=lands;
	}
}

//get and set methods

int Character::getNumofLands(){
	return numofLands;
}

void Character::setNumofLands(int i){
	numofLands=i;
}

int Character::getGold(){
	return gold;
}

void Character::setGold(int i){
	gold=i;
}

string Character::getName(){
	return name;
}

void Character::setName(string C){
	name=C;
}

Land * Character::getLands(){
	return lands;
}

string Character::getGen() const{
	return name;
}

int Character::getManpower(){
	return manpower;
}

void Character::setManpower(int i){
	manpower=i;
}

void Character::addLand(Land *L){
	if(lands==NULL){
		lands=L;
	}
	else{
		Land *temp = lands;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=L;
	}
}

void Character::removeLand(Land *L){
	Land *temp = lands;
	Land *tail = lands;
	while(temp!=NULL){
		if(temp==L){
			if(temp==tail){
				lands=lands->next;
				temp->next=NULL;
				numofLands--;
				break;
			}
			else{
			tail->next=tail->next->next;
			temp->next=NULL;
			numofLands--;
			break;
			}
		}
		else{
			tail=temp;
			temp=temp->next;
			
		}
	}
}

void Character::randomRemove(){
	if(lands!=NULL){
	Land *temp = lands;
	lands=lands->next;
	delete temp;
	numofLands--;
	}
}

void Character::getTaxes(){
	Land *temp=lands;
	
	while(temp!=NULL){
		if(temp->getHolding()=="village"){
			gold+=5;
		}
		else if(temp->getHolding()=="castle"){
			gold+=7;
		}
		else{
			gold+=10;
		}
		temp=temp->next;
	}
}

//constructors and destructor
CharacterList::CharacterList(){
	size=0;
	characters=NULL ;
}

void CharacterList::addCharacter(Character &C){
	if(size==0){
		characters = new Character[size+1];
		characters[size].setName(C.getName());
		characters[size].setGold(C.getGold());
		characters[size].setManpower(C.getManpower());
		characters[size].setNumofLands(C.getNumofLands());
		Land *tempL = C.getLands();
		while (tempL != NULL) {
			Land* x = new Land(tempL->getName(), tempL->getHolding());
			characters[size].addLand(x);
			tempL = tempL->next;
		}

	}
	
	else{
		Character *temp =new Character[size+1];
		for(int i = 0; i<size; i++){
			temp[i].setName(characters[i].getName());
			temp[i].setGold(characters[i].getGold());
			temp[i].setManpower(characters[i].getManpower());
			temp[i].setNumofLands(characters[i].getNumofLands());;
			Land *tempL = characters[i].getLands();
			while (tempL!=NULL) {
				Land* x = new Land(tempL->getName(), tempL->getHolding());
				temp[i].addLand(x);
				tempL = tempL->next;
			}
		}
		temp[size].setName(C.getName());
		temp[size].setGold(C.getGold());
		temp[size].setManpower(C.getManpower());
		temp[size].setNumofLands(C.getNumofLands());
		Land *tempL = C.getLands();
		while (tempL != NULL) {
			Land* x = new Land(tempL->getName(), tempL->getHolding());
			temp[size].addLand(x);
			tempL = tempL->next;
			}
			
		delete [] characters;
		characters = temp;
	}
	size++;
}

CharacterList::~CharacterList(){
	delete [] characters;
}

void CharacterList::delCharacter(string C){
	Character *temp =new Character[size-1];
	int check = 0;
		for(int i = 0; i<size; i++){
			if(characters[i].getName()!=C){
			temp[check].setName(characters[i].getName());
			temp[check].setGold(characters[i].getGold());
			temp[check].setManpower(characters[i].getManpower());
			temp[check].setNumofLands(characters[i].getNumofLands());
			Land *tempL = characters[i].getLands();
			while (tempL != NULL) {
				Land* x = new Land(tempL->getName(), tempL->getHolding());
				temp[check].addLand(x);
				tempL = tempL->next;
			}
			check++;
			}
		}
		delete [] characters;
		characters = temp;
		size--;
}

int CharacterList::getSize(){
	return size;
}

Character & CharacterList::getLandOwner(string L){
	for(int i = 0; i < size; i++ ){
		Land *temp = characters[i].getLands();
		while(temp!=NULL){
			if(temp->getName()==L){
				return characters[i];
			}
			temp=temp->next;
		}
	}
}

Character & CharacterList::getPlayer(){
	return characters[size-1];
}

Land * CharacterList::findLand(string S){
	for(int i=0; i<size;i++){
	Land *temp = characters[i].getLands();
	while(temp!=NULL){
		if(temp->getName()==S){
			return temp;
		}
		temp=temp->next;
	}
	}
	return NULL;
}

