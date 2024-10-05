#include "Post.h"
#include "Story.h"
#include <chrono>
#include <string>
#include <iostream>
using namespace std;





    Story::Story(string title, string URL, int durationInSeconds):
        Post(title,URL) { // used parent constructor to make fields that are shared among reels and stories
            if( durationInSeconds > 60) { //checking if duration exceed limit
                duration = 60;     // will cap the duration to its max
            }
            else{
                duration = durationInSeconds; 
            }
            expirationTime = time_stamp;
        };
    Story::~Story(){};
    
    int Story::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour; 

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;


	return timeToExpiration;
	};

    void Story::display() const{
        if(this->computeTimeToExpiration() < 0){ // if story expired then no need to display info
                cout << "Story has expired" << endl;
                return;
        }
        cout << "*Story*" << endl;

        cout << "Title: " << title << endl;
        cout << "URL: " << URL << endl;
        cout << "Expires in " << this->computeTimeToExpiration() << " hours"  << endl;
        cout << "Duration: " << duration << endl;
        

        
    }
    void Story::edit() {
        cout << "A filter, music, sticker, and effects have been added to your post!" <<endl;
    }
    


       