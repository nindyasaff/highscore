#include "observer.h"
#include "subject.h"
#include <iostream>
#include <string.h>

using namespace std;

#pragma once

using namespace std;

class Player : public Observer
{
protected:
    Subject *subject;
    string name;
    int score;
    int pos;

public:
    Player(Subject &subject, string name, int score);
    int getScore();
    void setPos(int pos);
    void update();
};

Player::Player(Subject &subject, string name, int score)
{
    this->subject = &subject;
    this->name = name;
    this->score = score;
    pos = 0;

    subject.attach(*this);
}

int Player::getScore()
{
    return score;
}

void Player::setPos(int pos)
{
    this->pos = pos;
}

void Player::update()
{
    std::cout << name << "HighScore =  " << pos << endl<< endl <<"Updating..." <<endl << endl ;
}
