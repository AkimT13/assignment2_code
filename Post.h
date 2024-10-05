
#ifndef POST_H
#define POST_H
// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
#include <chrono>
// To DO: define the class Post with the necessary functions' prototypes and data fields

class Post{
    protected:
        std::string title;
        std::chrono::steady_clock::time_point time_stamp;
        int likes;
        std::string URL;

    public:
        
       Post(std::string title, std::string URL);
       bool operator==(const Post& otherPost) const;
       
       void modify(std::string newTitle);
       virtual void display() const = 0;
       virtual void edit();
       
       virtual ~Post();
       



};




#endif

