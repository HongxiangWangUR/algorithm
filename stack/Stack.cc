#include "Stack.h"

namespace stack{
	template<class T> void ArrayStack<T>::push(T* e){
		if(top_index >= capacity-1){
			throw std::runtime_error("stack is full");
		}
		data[++top_index]=e;
	}

	template<class T> T* ArrayStack<T>::top(){
		if(isEmpty()){
			std::cout<<"the stack is empty, can't top()"<<std::endl;
			return nullptr;
		}
		return data[top_index];
	}

	template<class T> T* ArrayStack<T>::pop(){
		if(isEmpty()){
			std::cout<<"the stack is empty, can't pop()"<<std::endl;
			return nullptr;
		}
		T* ret = data[top_index];
		data[top_index]=nullptr;
		top_index--;
		return ret;
	}

	template<class T> ArrayStack<T>::~ArrayStack(){
		for(int i=0;i<=top_index;i++){
			delete data[i];
		}
		delete [] data;
	}

	template<class T> std::string ArrayStack<T>::toString(){
		std::stringstream stream;
		stream<<"[";
		for(unsigned i=0;i<=top_index;i++){
			stream<<*data[i]<<",";
		}
		return stream.str();
	}
}

template class stack::ArrayStack<int>;