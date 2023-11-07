#include <iostream>
#include <sstream>
#include "List.hh"
namespace stack{
	template <typename T> class ArrayStack{
		public:
			static const int CAPACITY = 1000;
			ArrayStack(int cap):capacity(cap){
				data = new T*[cap];
				for(int i=0;i<capacity;i++){
					data[i]=nullptr;
				}
			}
			ArrayStack():ArrayStack(CAPACITY){}
			int size(){
				return this->top_index+1;
			}
			bool isEmpty(){
				return this->top_index<0;
			}
			~ArrayStack();
			std::string toString();
			void push(T* e);
			T* top();
			T* pop();
		private:
			T** data;
			int capacity;
			int top_index = -1;
	};

	template<typename T> class LinkedStack{
		public:
			LinkedStack(){};
			int size(){
				return list.size();
			}
			bool isEmpty(){
				return list.isEmpty();
			}
			void push(T* e){
				list.addLast(e);
			}
			T* top(){
				return list.first();
			}
			T* pop(){
				return list.removeFirst();
			}
			std::string toString(){
				std::stringstream stream;
				stream<<"["<<list.toString();
				return stream.str();
			}
		private:
			list::SinglyLinkedList<T> list;
	};
}