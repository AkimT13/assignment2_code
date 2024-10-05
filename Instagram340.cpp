// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"


Instagram340::Instagram340(): users(new LinkedBag<User*>){ 
	// TO DO: implement constructor
	
	


	
}

Instagram340::~Instagram340(){
	
	Node<User*>* curr = users->getHead(); //getHead() returns the head, I added it to LinkedBag.cpp/.h
	while(curr!=nullptr){ // iterarte through linked list and deleting users and nodes, and finally deleting the pointer to the new
		User* user = curr->getItem();
		delete user;

		Node<User*>* nodeToDelete = curr;
		curr = curr->getNext();
		delete nodeToDelete;

	}
	delete users;
	
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
					User* newUser = new User(username,password,email,bio,profilePicture);
					users->add(newUser);
	// TO DO: implement function

}

User* Instagram340::getUser(const int& indexK){

	// TO DO: implement function
	Node<User*>* userNode = users->findKthItem(indexK);
	return userNode->getItem();


}