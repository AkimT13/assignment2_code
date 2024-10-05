#ifndef REEL_H
#define REEL_H

#include "Post.h"
#include <chrono>
#include <string>
#include <iostream>

class Reel: public Post {
    private:
        int duration;
    public:
        Reel(std::string title, std::string URL, int durationInSeconds);
        ~Reel();

        

        void display() const override;
        void edit() override;
        





};

#endif