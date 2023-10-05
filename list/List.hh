#include <iostream>
#include <string>
#include <sstream>
namespace list{
	template<typename T> class SinglyLinkedList;
	template<typename T> class CircularlyLinkedList;
	template<typename T> class SinglyLinkedListNode{
		friend class SinglyLinkedList<T>;
		friend class CircularlyLinkedList<T>;
		public:
			SinglyLinkedListNode(T*,SinglyLinkedListNode*);
			T* getElement();
			SinglyLinkedListNode* getNext();
			void setNext(SinglyLinkedListNode*);
			~SinglyLinkedListNode();
		private:
			T* element;
			SinglyLinkedListNode* next;
	};

	template<typename T> class SinglyLinkedList{
		private:
			SinglyLinkedListNode<T>* head;
			SinglyLinkedListNode<T>* tail;
			int _size;
		public:
			SinglyLinkedList():head(nullptr),tail(nullptr),_size(0){}
			int size();
			bool isEmpty();
			T* first();
			T* last();
			void addFirst(T*);
			void addLast(T*);
			T* removeFirst();
			~SinglyLinkedList();
			std::string toString();
	};

	template<typename T> class CircularlyLinkedList{
		public:
			CircularlyLinkedList():_size(0),tail(nullptr){};
			int size();
			bool isEmpty();
			T* first();
			T* last();
			void rotate();
			void addFirst(T*);
			void addLast(T*);
			T* removeFirst();
			std::string toString();
			~CircularlyLinkedList();
		private:
			int _size;
			SinglyLinkedListNode<T>* tail;
	};
}
