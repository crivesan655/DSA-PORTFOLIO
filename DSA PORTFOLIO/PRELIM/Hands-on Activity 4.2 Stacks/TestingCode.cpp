#include <iostream>
#include "stack.h"

int main(){
	stack <int> s1;
	
	//isEmpty
	std::cout<<"Testing isEmpty: \n";
	std::cout<<s1.isEmpty()<<std::endl<<std::endl;
	
	//push
	for (int i = 1; i < 10; i++){
		s1.push(i);
	}
	
	//stack overflow
	s1.push(100);
		
	//peek
	std::cout<<std::endl;
	std::cout<<"Testing peek....\n";
	s1.peek();
	
	//pop
	std::cout<<std::endl;
	std::cout<<"Testing pop....\n";
	s1.pop();
	
	//display
	std::cout<<std::endl;
	std::cout<<"Testing display....\n";
	s1.display();
	
	
	
	return 0;
}
