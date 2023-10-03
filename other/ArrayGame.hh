#include <string>
#include <sstream>
#include <iostream>
#include <cstddef>

namespace other{
	class GameEntry{
		private:
			std::string *name;
			int score;
		public:
			GameEntry(std::string *name,int score):name(name),score(score){}
			std::string* getName();
			int getScore();
			std::string toString();
			~GameEntry();
	};

	class ScoreBoard{
	private:
		int numEntries;
		int capacity;
		GameEntry **board;
	public:
		ScoreBoard(int capacity);
		~ScoreBoard();
		std::string toString();
		void add(GameEntry*);
		GameEntry* remove(int);
	};
}