#include "List.hh"

template<typename T> list::SinglyLinkedListNode<T>::SinglyLinkedListNode(T* element,SinglyLinkedListNode* next){
	this->element = element;
	this->next = next;
}

template<typename T> T* list::SinglyLinkedListNode<T>::getElement(){
	return this->element;
}

template<typename T> list::SinglyLinkedListNode<T>* list::SinglyLinkedListNode<T>::getNext(){
	return this->next;
}

template<typename T> void list::SinglyLinkedListNode<T>::setNext(SinglyLinkedListNode* next){
	this->next=next;
}

template<typename T> list::SinglyLinkedListNode<T>::~SinglyLinkedListNode(){
	delete this->element;
	this->next = nullptr;
}

template<typename T> int list::SinglyLinkedList<T>::size(){
	return this->_size;
}

template<class T> bool list::SinglyLinkedList<T>::isEmpty(){
	return this->_size==0;
}

template<typename T> T* list::SinglyLinkedList<T>::first(){
	if(isEmpty()){
		return nullptr;
	}
	return this->head->element;
}

template<typename T> T* list::SinglyLinkedList<T>::last(){
	if(isEmpty()){
		return nullptr;
	}
	return this->tail->element;
}

template<typename T> void list::SinglyLinkedList<T>::addFirst(T* e){
	head = new SinglyLinkedListNode<T>(e,head);
	if(isEmpty()){
		this->tail = head;
	}
	this->_size++;
}

template<typename T> void list::SinglyLinkedList<T>::addLast(T* e){
	SinglyLinkedListNode<T> *temp = new SinglyLinkedListNode<T>(e,nullptr);
	if(isEmpty()){
		this->head = temp;
	}else{
		this->tail->next=temp;
	}
	tail = temp;
	this->_size++;
}

template<typename T> T* list::SinglyLinkedList<T>::removeFirst(){
	if(isEmpty()){
		return nullptr;
	}
	SinglyLinkedListNode<T>* temp = head;
	head = head->next;
	this->_size--;
	if(isEmpty()){
		tail = head;
	}
	T* ret = temp->element;
	temp->element = nullptr;
	delete temp;
	return ret;
}

template<typename T> list::SinglyLinkedList<T>::~SinglyLinkedList(){
	SinglyLinkedListNode<T>* cursor = head;
	while(cursor!=nullptr){
		SinglyLinkedListNode<T>* temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
}

template<typename T> std::string list::SinglyLinkedList<T>::toString(){
	std::stringstream stream;
	stream<<"[ ";
	SinglyLinkedListNode<T> *cursor = head;
	while(cursor!=nullptr){
		stream<<*(cursor->element);
		cursor = cursor->next;
		if(cursor!=nullptr){
			stream<<"->";
		}
	}
	stream<<" ]";
	return stream.str();
}
/**
 * template initialization declared here
 **/
template class list::SinglyLinkedListNode<int>;
template class list::SinglyLinkedList<int>;
