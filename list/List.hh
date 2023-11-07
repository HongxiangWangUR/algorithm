#include <iostream>
#include <string>
#include <sstream>
#ifndef LIST
#define LIST
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

	template<typename T> class DoublyLinkedList{
		public:
			class Node{
				public:
					Node(T* e,Node* prev,Node* next):element(e),prev(prev),next(next){};
					T* getElement();
					void setElement(T*);
					Node* getPrev();
					void setPrev(Node* prev);
					Node* getNext();
					void setNext(Node* next);
					std::string toString();
					~Node();
				private:
					T* element;
					Node* prev;
					Node* next;
			};
			DoublyLinkedList():_size(0){
				this->head = new Node(nullptr,nullptr,nullptr);
				this->tail = new Node(nullptr,head,nullptr);
				this->head->setNext(this->tail);
			}
			int size(){
				return this->_size;
			}
			bool isEmpty(){
				return this->_size == 0;
			}
			Node* first(){
				if(isEmpty())
					return nullptr;
				return head->getNext();
			}
			Node* last(){
				if(isEmpty()){
					return nullptr;
				}
				return tail->getPrev();
			}
			void addFirst(T* e){
				this->addBetween(e,this->head,this->head->getNext());
			}
			void addLast(T* e){
				this->addBetween(e,this->tail->getPrev(),this->tail);
			}
			T* removeFirst(){
				if(isEmpty()){
					return nullptr;
				}
				return remove(this->head->getNext());
			}
			T* removeLast(){
				if(isEmpty()){
					return nullptr;
				}
				return remove(this->tail->getPrev());
			}
			std::string toString();
			~DoublyLinkedList();
		private:
			Node* head;
			Node* tail;
			int _size;
			void addBetween(T* element,Node* prev,Node* next);
			T* remove(Node* node);
	};
}
#endif