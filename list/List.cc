#include "List.hh"

/**
 * definition of SinglyLinkedListNode
 **/
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

/**
 * definition of SinglyLinkedList
 **/
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
 * definition of CircularlyLinkedList
 **/
template<typename T> int list::CircularlyLinkedList<T>::size(){
	return this->_size;
}

template<typename T> bool list::CircularlyLinkedList<T>::isEmpty(){
	return this->_size<=0;
}

template<typename T> T* list::CircularlyLinkedList<T>::first(){
	if(isEmpty()){
		return nullptr;
	}
	return this->tail->next->element;
}

template<typename T> T* list::CircularlyLinkedList<T>::last(){
	if(isEmpty()){
		return nullptr;
	}
	return this->tail->element;
}

template<typename T> void list::CircularlyLinkedList<T>::rotate(){
	if(!isEmpty()){
		this->tail = this->tail->next;
	}
}

template<typename T> void list::CircularlyLinkedList<T>::addFirst(T* e){
	SinglyLinkedListNode<T> *node = new SinglyLinkedListNode<T>(e,nullptr);
	if(isEmpty()){
		tail = node;
		tail->next = tail;
	}else{
		node->next = tail->next;
		tail->next = node;
	}
	this->_size++;
}

template<typename T> void list::CircularlyLinkedList<T>::addLast(T* e){
	this->addFirst(e);
	rotate();
}

template<typename T> T* list::CircularlyLinkedList<T>::removeFirst(){
	if(isEmpty()){
		return nullptr;
	}
	SinglyLinkedListNode<T>* node = this->tail->next;
	this->_size--;
	if(isEmpty()){
		this->tail = nullptr;
	}else{
		this->tail->next = node->next;
	}
	T* element = node->element;
	node->element = nullptr;
	delete node;
	return element;
}

template<typename T> std::string list::CircularlyLinkedList<T>::toString(){
	if(this->isEmpty()){
		return "[]";
	}
	std::stringstream stream;
	stream<<"[";
	for(const SinglyLinkedListNode<T> *cursor=this->tail->next;cursor!=this->tail;cursor=cursor->next){
		stream<<*(cursor->element)<<"->";
	}
	stream<<*(tail->element)<<"->"<<"]";
	return stream.str();
}

template<typename T> list::CircularlyLinkedList<T>::~CircularlyLinkedList(){
	if(isEmpty())
		return;
	SinglyLinkedListNode<T>* cursor = this->tail->next;
	this->tail->next = nullptr;
	while(cursor!=nullptr){
		SinglyLinkedListNode<T>* temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
}
/**
 * template initialization declared here
 **/
template class list::SinglyLinkedListNode<int>;
template class list::SinglyLinkedList<int>;
template class list::CircularlyLinkedList<int>;

