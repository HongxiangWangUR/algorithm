#include "ArrayGame.hh"
#include "Sorting.hh"
#include "List.hh"
#include "recurse.hh"

void GameEntryTest();
void testInsertSort();
void testSinglyLinkedList();
void testCircularLinkedList();
void testDoublyLinkedList();
void testFactorial();
void testDrawRuler();
void binarySearchTest();
void testLinerSum();
void testReverseArray();
void testPower();
void testMorePower();
void testBinarySum();
void testBinarySum();
void testUnique3();
void testFibonacciBad();
void testFibonacciGood();
void testBinarySearchIterative();
void testReverseIterative();
extern template void sorting::insertSort(char (&arr)[5]);
extern template class list::SinglyLinkedListNode<int>;
extern template class list::SinglyLinkedList<int>;
extern template class list::CircularlyLinkedList<int>;
extern template class list::DoublyLinkedList<int>;

int main(){
	testReverseIterative();
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

void testCircularLinkedList(){
	list::CircularlyLinkedList<int> list;
	std::cout<<"before add: "<<list.toString()<<std::endl;
	list.addFirst(new int(1));
	list.addFirst(new int(2));
	list.addFirst(new int(-1));
	list.addFirst(new int(3));
	std::cout<<"after add: "<<list.toString()<<std::endl;
	int* ret=list.removeFirst();
	std::cout<<"after remove first"<<list.toString()<<std::endl;
	delete ret;
}

void testDoublyLinkedList(){
	list::DoublyLinkedList<int> list;
	std::cout<<"before operating: "<<list.toString()<<std::endl;
	list.addFirst(new int(10));
	list.addLast(new int(20));
	list.addFirst(new int(5));
	list.addLast(new int(30));
	std::cout<<"after operating: "<<list.toString()<<std::endl;
	int* first = list.removeFirst();
	int* last = list.removeLast();
	std::cout<<"after remove: "<<list.toString()<<std::endl;
	delete first;
	delete last;
}

void testFactorial(){
	int result = recurse::factorial(4);
	std::cout<<"factorial(4)="<<result<<std::endl;
}

void testDrawRuler(){
	recurse::drawRuler(4,2);
}

void binarySearchTest(){
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	bool result = recurse::binarySearch(data,6,0,9);
	if(result){
		std::cout<<"find result 6"<<std::endl;
	}else{
		std::cout<<"can't find target"<<std::endl;
	}
}

void testLinerSum(){
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	int result = recurse::linearSum(data,10);
	std::cout<<"the result is: "<<result<<std::endl;
}

void testReverseArray(){
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	recurse::reverseArray(data,0,9);
	std::cout<<"after reverse:";
	for(auto &e:data){
		std::cout<<e<<" ";
	}
	std::cout<<std::endl;
}

void testPower(){
	int x=4,n=3;
	std::cout<<"4^3="<<recurse::power(x,n)<<std::endl;
}

void testMorePower(){
	int x=4,n=3;
	std::cout<<"morepower(4^3)="<<recurse::morePower(x,n)<<std::endl;
}

void testBinarySum(){
	int data[]={1,2,3,4,5,6,7,8,9,10};
	int result = recurse::binarySum(data,0,9);
	std::cout<<"the result of binary sum is: "<<result<<std::endl;
}

void testUnique3(){
	int data[]={1,2,3,4,5,6,7,8,9,10};
	bool result = recurse::unique3(data,0,9);
	std::cout<<"test result of unique3: "<<result<<std::endl;
}

void testFibonacciBad(){
	int result = recurse::fibonacciBad(10);
	std::cout<<"the result of fibonacciBad(): "<<result<<std::endl;
}

void testFibonacciGood(){
	int* ret=recurse::fibonacciGood(10);
	std::cout<<"result of fibonacciGood(): "<<ret[0]<<std::endl;
	delete [] ret;
}

void testBinarySearchIterative(){
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	bool result = recurse::binarySearchIterative(data,6);
	std::cout<<"result of binarySearchIterative() is: "<<result<<std::endl;
}

void testReverseIterative(){
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	recurse::reverseIterative(data);
	std::cout<<"after reverse:";
	for(auto &e:data){
		std::cout<<e<<" ";
	}
	std::cout<<std::endl;
}
