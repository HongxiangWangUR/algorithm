#include "ArrayGame.hh"

/**
 * definition of GameEntry
 **/

std::string* other::GameEntry::getName(){
	return this->name;
}

int other::GameEntry::getScore(){
	return this->score;
}

std::string other::GameEntry::toString(){
	return "[ name:"+ *(this->name) + ", score:"+std::to_string(this->score)+" ]";
}

other::GameEntry::~GameEntry(){
	std::cout<<"releasing GameEntry: ["<<*(this->name)<<", "<<this->score<<"]"<<std::endl;
	delete this->name;
}

/**
 * definition of Scoreboard
 **/

other::ScoreBoard::ScoreBoard(int capacity):numEntries(0),capacity(capacity){
	board = new GameEntry*[capacity];
	for(GameEntry** ptr = this->board ; ptr<this->board+capacity ; ptr++){
		(*ptr)=nullptr;
	}
}

other::ScoreBoard::~ScoreBoard(){
	std::cout<<"releasing scoreboard numEntries:"<<this->numEntries<<", capacity: "<<this->capacity<<std::endl;
	for(GameEntry** ptr = this->board ; ptr<this->board+capacity ; ptr++){
		delete (*ptr);
	}
	delete [] this->board;
}

std::string other::ScoreBoard::toString(){
	std::stringstream stream;
	stream<<"[";
	for(int i=0;i<numEntries;i++){
		stream<<"{"<<"name:"<< *(board[i]->getName()) <<", score:"<<board[i]->getScore()<<"}";
		if(i != numEntries-1){
			stream<<", ";
		}
	}
	stream<<"]";
	return stream.str();
}

void other::ScoreBoard::add(GameEntry *entry){
	int newscore = entry->getScore();
	if(numEntries<capacity || newscore>board[numEntries-1]->getScore()){
		if(numEntries<capacity)
			numEntries++;
		int cursor = numEntries-1;
		while(cursor-1>=0 && board[cursor-1]->getScore()<newscore){
			board[cursor]=board[cursor-1];
			cursor--;
		}
		board[cursor]=entry;
	}
}

other::GameEntry* other::ScoreBoard::remove(int index){
	if(index<0 || index>=numEntries){
		return nullptr;
	}

	GameEntry* ret = board[index];
	for(size_t i=index;i<numEntries-1;i++){
		board[i]=board[i+1];
	}
	board[numEntries-1]=nullptr;
	numEntries--;
	return ret;
}
