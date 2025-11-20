#ifndef QHEADER_H
#define QHEADER_H
#include <iostream>
template<typename T>

class Node{
	public:
		T data;
		Node* next;
		
		Node(T new_data){
			data = new_data;
			next = nullptr;
			
		}

};

template<typename T>
class Queue{
	private:
		Node<T> *front;
		Node<T> *rear;
			
	public:
		// Create an empty queue
		Queue(){
			front = rear = nullptr;
			std::cout << "A Queue has been created.."<<std::endl;
		}
		

		//isEmpty
		bool isEmpty(){
			return front == nullptr;
		}
				
		//enqueue
		void enqueue(T new_data){
			Node<T> *new_node  = new Node<T> (new_data);
			
			if (isEmpty()){
				front = rear = new_node;
				std::cout<< "Enqueue to an empty queue"<<std::endl;
				
				return;
			}
			rear->next = new_node;
			rear = new_node;
			std::cout<< "Successfully Enqueued. "<<std::endl;
			
		}
		
		//dequeue
		void dequeue(){
			if (isEmpty()){
				std::cout<<"The Queue is Empty"<<std::endl;
				return;
			}
			
			//storing the front to a temporary pointer
			Node<T>* temp = front;
			
			//check if after the dequeue, the queue is empty
			if (front == nullptr){
				rear == nullptr;
			}
			else{
				//reassign the front to the next node
				front = front->next;
			}
			
			delete temp;
			
		}
		
		//getfront
		void getFront(){
			if (isEmpty()){
				std::cout<<"The Queue is Empty"<<std::endl;
				return;
			}
			
			std::cout<<"Current Front: "<< front -> data << std::endl;
			
		}
		
		//getrear
		void getRear(){
			if (isEmpty()){
				std::cout<<"The Queue is Empty"<<std::endl;
				return;
			}
			
			std::cout<<"Current Rear: "<< rear -> data << std::endl;
		}

		//display
		void Display(){
			if (isEmpty()){
				std::cout<<"The Queue is Empty"<<std::endl;
				return;
			}
			
			Node<T> *temp = front;
			while (temp !=nullptr){
				std::cout<< temp -> data << " ";
				temp = temp -> next;
			}
			std::cout<<std::endl;
		}
		
		//to deallocate memory
		~Queue(){
			while(!isEmpty()){
				dequeue();
			}
		}
};






#endif
