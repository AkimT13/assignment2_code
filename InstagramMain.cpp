#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"


using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 * 
 * */
void displayUserManu(User* user){
	int userChoice = 0;
	do {
		cout << "\n Hi, "<< user->getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
		<< "8. Edit a Post\n"
		<< "0. Logout\n"
		<< "Choice: \n";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{
				// TO DO: display user's profile information
				//      : e.g. user.displayProfile();
				user->display();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update user's password
				cout << "Enter new password" << endl;
				string newPassword;
				cin >> newPassword;
				user->setPassword(newPassword);
				break;
			}
			case 3: {
				// TO DO: ask user to choose between Reel and Story, ask them to input post details:
				//        (title, media URL, video length in seconds)
				//        Your program should set the time stamp to current time (code provided in Post.cpp) 
				// then create the post and add it to the user's posts
				cout<< "Would you like to post a Reel or Story?" << endl;
				string postType;
				cin >> postType;
				cout << "What is the title of your post?" << endl;
				string title;
				cin >> title;
				cout << "What is the URL?" << endl;
				string URL;
				cin >> URL;
				cout << "What is the length?"<< endl;
				int length;
				cin >> length;

				user->createPost(postType,title,URL,length);


				break;
			}
			case 4:{
				// TO DO: display all user's posts
				//        You may re-use code from class demo

				user->displayPosts();


				break;
			}
			case 5: {
				// TO DO: ask the user for a value k
				// Find the Kth post, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				cout << "Enter K" << endl;
				int k=0;
				cin >> k;
				if(k >= user->getSize()){
					cout << "K out of bounds" << endl;
					break;
				}
				user->displayKthPost(k);
				break;
			}
			case 6: {
				// TO DO: ask the user for the index of the post they want to modify and the new title
				// Find the post, then update the title. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				cout << "Enter K"<< endl;
				int k = 0;
				cin >> k;
				if(k >= user->getSize()){
					cout << "K out of bounds" << endl;
					break;
				}
				cout << "Enter new title" << endl;
				string newTitle;
				cin >> newTitle;
				user->modifyKthPost(k,newTitle);
				break;
			}
			case 7: {
				// TO DO: ask the user for the index of the post they want to delete 
				// Find the post, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				cout << "enter k" << endl;
				int k = 0;
				cin>> k;
				if(k >= user->getSize()){
					cout << "K out of bounds" << endl;
					break;
				}
				user->deletePost(k);
				break;
			}
			case 8: {
				//edit
				cout<< "Enter K: " << endl;
				int k = 0;
				cin >> k;
				user->editPost(k);
				break;


			}
			case 0: {
				cout << "Logging you out." << endl;

				
				
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
				
		}

	} while (userChoice != 0);
	
	return;
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	Instagram340 instagram; 

	cout << "\n Welcome to Instagram340:" << endl;
	// TO DO: Ask the user to enter their information 
	//        Instantiate a new User object
	cout << "Enter your username" << endl;
	string username;
	cin >> username;
	cout << "Enter your password" << endl;
	string password;
	cin >> password;
	cout << "Enter your bio" << endl;
	string bio;
	cin >> bio;
	cout << "Enter your email" << endl;
	string email;
	cin >> email;
	cout << "Enter path to profile picture" << endl;
	string profilePic;
	cin>> profilePic;

	


	// call instagram createUser function 
	// replace /*...*/ with the right parameters
	instagram.createUser(username,email,password,bio,profilePic);

	// Retrieve the user 
	User* currentUser = instagram.getUser(0);
	displayUserManu(currentUser);
				
	return 0;
}