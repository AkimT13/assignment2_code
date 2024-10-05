
#ifndef USER_H
#define USER_H


// TO DO: #include all the standard libraries and your own libraries here


#include <string>
#include <iostream>
#include "Post.h"
#include "LinkedBagDS/LinkedBag.h"

// To DO: define the class User with the necessary functions and data fields
class User{
    private:
        LinkedBag<Post*>* posts; // pointer to a linked bag of post pointers
		std::string username;
		std::string password;
		std::string email;
		std::string bio;
		std::string profilePic;
        
    public:
        /**Constructor for user */
        User(std::string username, std::string password, std::string email, std::string bio, std::string profilePic);
        
        ~User();
        bool operator==(const User& otherUser) const;
        void createPost(std::string postType, std::string title, std::string URL, int durationInSeconds);
        std::string getUsername() const;
        void setPassword(std::string newPassword);
        void displayPosts();
        void displayKthPost(int k);
        void modifyKthPost(int k, std::string newTitle);
        void deletePost(int k);
        void editPost(int k);
        int  getSize();
        void display(); 


};

// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:


#endif