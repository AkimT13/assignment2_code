#ifndef STORY_H
#define STORY_H

#include "Post.h"
#include <chrono>
#include <string>


class Story : public Post {
    private:
        int duration;  
        std::chrono::steady_clock::time_point expirationTime;
    public:
    Story(std::string title, std::string URL, int durationInSeconds);
    ~Story();


    bool hasExpired() const;
    int computeTimeToExpiration() const;


    void display() const override; 
    void edit() override;



};

#endif