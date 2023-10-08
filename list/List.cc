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
 * definition of doubly linked list Node
 **/

template<typename T> T* list::DoublyLinkedList<T>::Node::getElement(){
	return this->element;
}

template<typename T> void list::DoublyLinkedList<T>::Node::setElement(T* e){
	this->element = e;
}

template<typename T> typename list::DoublyLinkedList<T>::Node* list::DoublyLinkedList<T>::Node::getPrev(){
	return this->prev;
}

template<typename T> void list::DoublyLinkedList<T>::Node::setPrev(Node* prev){
	this->prev = prev;
}

template<typename T> typename list::DoublyLinkedList<T>::Node* list::DoublyLinkedList<T>::Node::getNext(){
	return this->next;
}

template<typename T> void list::DoublyLinkedList<T>::Node::setNext(Node* next){
	this->next = next;
}

template<typename T> std::string list::DoublyLinkedList<T>::Node::toString(){
	std::stringstream stream;
	stream<<*(this->element);
	return stream.str();
}

template<typename T> list::DoublyLinkedList<T>::Node::~Node(){
	this->prev = nullptr;
	this->next = nullptr;
	delete this->element;
}

/**
 * definition of doubly linked list
 **/

template<typename T> void list::DoublyLinkedList<T>::addBetween(T* element,Node* prev,Node* next){
	Node* node = new Node(element,prev,next);
	prev->setNext(node);
	next->setPrev(node);
	this->_size++;
}

template<typename T> T* list::DoublyLinkedList<T>::remove(Node* node){
	Node* prev = node->getPrev();
	Node* next = node->getNext();
	prev->setNext(next);
	next->setPrev(prev);
	T* ret = node->getElement();
	node->setElement(nullptr);
	delete node;
	this->_size--;
	return ret;
}

template<typename T> std::string list::DoublyLinkedList<T>::toString(){
	std::stringstream stream;
	stream<<"[head<=>";
	Node* cursor = this->head->getNext();
	while(cursor != tail){
		stream<<*(cursor->getElement())<<"<=>";
		cursor=cursor->getNext();
	}
	stream<<"tail]";
	return stream.str();
}

template<typename T> list::DoublyLinkedList<T>::~DoublyLinkedList(){
	Node* cursor=head;
	while(cursor!=tail){
		Node* temp=cursor->getNext();
		delete cursor;
		cursor = temp;
	}
	head=nullptr;
	delete tail;
	tail = nullptr;
}
/**
 * template initialization declared here
 **/
template class list::SinglyLinkedListNode<int>;
template class list::SinglyLinkedList<int>;
template class list::CircularlyLinkedList<int>;
template class list::DoublyLinkedList<int>;

