// TO DO: #include needed standard libraries and your own libraries here
#include <chrono>
#include <string>
#include <iostream>
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"
#include "User.h"

using namespace std;
// TO DO: function implementations

User::User(string username, string password, string email, string bio, string profilePic  ) : posts(new LinkedBag<Post*>()), username(username), password(password), email(email), bio(bio), profilePic(profilePic){}
User::~User(){
	Node<Post*>* curr = posts->getHead(); 

	while(curr != nullptr){
		Post* post = curr->getItem();
		delete post;

		
        curr = curr->getNext();  
        

	}

	
	delete posts;




	

	
}

void User::setPassword(string newPassword){
	password = newPassword;


}
void User::display(){
	cout << "Username: " << username << endl;
	cout << "Email: " << email << endl;
	cout << "Bio: " << bio << endl;
	cout << "Photo: " << profilePic << endl;


}
void User::createPost(std::string postType, std::string title, std::string URL, int durationInSeconds){
	if(postType == "Reel"){
		Reel* newReel = new Reel(title,URL,durationInSeconds);
		posts->add(newReel);




	}
	else if(postType == "Story"){
		Story* newStory = new Story(title,URL,durationInSeconds);
		posts->add(newStory);

	}
	else{
		cout << "This type of post doesn't exist, no post added to account" << endl;
	}

}
string User::getUsername() const{
	return username;
}

void User::displayPosts(){
	Node<Post*>* curr = posts->getHead();
	int count = 0;

	while(curr!=nullptr){
		Post* currPost = curr->getItem();
		currPost->display();
		cout << endl;
		curr = curr->getNext();
	}

}

void User:: displayKthPost(int k){
	Node<Post*>* kthPostNode= posts->findKthItem(k);
	Post* kthPost = kthPostNode->getItem();
	kthPost->display();
}
void User::modifyKthPost(int k,string newTitle){
	if(k> posts->getCurrentSize()){
		cout<< "K out of bounds";
	}
	Node<Post*>* kthPostNode= posts->findKthItem(k);
	Post* kthPost = kthPostNode->getItem();
	kthPost->modify(newTitle);


}
int User::getSize(){
	return posts->getCurrentSize();
}

void User::deletePost(int k){

	if(k >= posts->getCurrentSize()){
		cout << "Removed Nothing" << endl;
		return;
	}

	int count = 0; //traverse to find k , cant use the function i made because i need prev to remove node
	Node<Post*>* curr = posts->getHead(); //m
	Node<Post*>* prev = nullptr;
	while(curr!=nullptr && count < k){
		prev = curr;
		curr = curr->getNext();
		count++;


	}

	if(curr!=nullptr){
		Post* postToDelete = curr->getItem(); //delet post
		delete postToDelete;

		if(prev == nullptr){ //deleted front
			posts->setHead(curr->getNext());
			
		}
		else {  // deletes either middle or last node
			prev->setNext(curr->getNext());
		}

		delete curr; // delete current node

	}

}

void User::editPost(int k){
	Node<Post*>* kthPostNode = posts->findKthItem(k);
	Post* kthPost = kthPostNode->getItem();
	kthPost->edit();
}



bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}








