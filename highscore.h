#include <vector>
#include "player.h"

#pragma once

class Highscore : public Observer
{
private:
    Subject *subject;
    std::vector<Player *> players;

public:
    Highscore(Subject &subject);
    void addPlayer(Player &player);
    void update();
};

Highscore::Highscore(Subject &subject)
{
    this->subject = &subject;

    subject.attach(*this);
}

void Highscore::addPlayer(Player &player)
{
    players.push_back(&player);
}

void Highscore::update()
{
    for (int i = 0; i < players.size(); i++)
    {
        for (int j = i + 1; j < players.size(); j++)
        {
            if (players[j]->getScore() > players[i]->getScore())
            {
                Player *tmp = players[i];
                players[i] = players[j];
                players[j] = tmp;
            }
        }
    }

    for (int i = 0; i < players.size(); i++)
    {
        players[i]->setPos(i + 1);
    }
}
