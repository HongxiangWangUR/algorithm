#include "other/ArrayGame.hh"
#include "sort/Sorting.hh"
#include "list/List.hh"

void GameEntryTest();
void testInsertSort();
void testSinglyLinkedList();
extern template void sorting::insertSort(char (&arr)[5]);
extern template class list::SinglyLinkedListNode<int>;
extern template class list::SinglyLinkedList<int>;
int main(){
	testSinglyLinkedList();
	return 0;
}

void GameEntryTest(){
	
	other::ScoreBoard board(10);
	std::cout<<"before add: "<<board.toString()<<std::endl;
	other::GameEntry* entry1=new other::GameEntry(new std::string("hello"),1);
	other::GameEntry* entry2=new other::GameEntry(new std::string("world"),2);
	other::GameEntry* entry3 = new other::GameEntry(new std::string("cpp"),3);
	board.add(entry1);
	board.add(entry2);
	board.add(entry3);
	std::cout<<"after add: "<<board.toString()<<std::endl;
	other::GameEntry* ret = board.remove(0);
	std::cout<<"after remove: "<<board.toString()<<std::endl;
	std::cout<<"the removed element is: "<<ret->toString()<<std::endl;
	delete ret;
}

void testInsertSort(){
	char a[] = {'x','e','d','c','b'};
	sorting::insertSort(a);
	std::cout<<"after sorting: "<<std::endl;
	for(char &c:a){
		std::cout<<c<<", ";
	}
	std::cout<<std::endl;
}

void testSinglyLinkedList(){
	list::SinglyLinkedList<int> list;
	std::cout<<"before add: "<<list.toString()<<std::endl;
	list.addFirst(new int(1));
	list.addLast(new int(10));
	list.addFirst(new int(-10));
	list.addLast(new int(20));
	std::cout<<"after add: "<<list.toString()<<std::endl;
	int* ret = list.removeFirst();
	std::cout<<"after removefirst: "<<list.toString()<<std::endl;
	delete ret;
}
