// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include <string>
#include <iostream>
#include "Post.h"
using namespace std;


// TO DO: function implementations


    
Post::Post(string title, string URL): title(title),time_stamp(std::chrono::steady_clock::now()),likes(0),URL(URL){}
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}
Post::~Post(){}

void Post::modify(string newTitle) {
	title = newTitle;


   
}

void Post::edit() {
	
}





		














