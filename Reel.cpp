#include "Reel.h"
#include <string>
#include <iostream>

using namespace std;


Reel::Reel(string title, string URL, int durationInSeconds ):
Post(title,URL){
    if (durationInSeconds > 90){ // check if duration is greater than max
        duration = 90; //cap at 90 secs
    }
    else{
        duration = durationInSeconds; 
    }
}
Reel::~Reel(){}
void Reel::display() const{ //display Reel
    cout << "*Reel*" << endl;
    cout << "Title:  " << title << endl;
    cout << "URL: " << URL << endl;
    cout << "Duration: " << duration << endl;
}


void Reel::edit(){
    cout << "You have added a filter, AR effects, and music" <<endl;
}


