#include <iostream>
#include "player.h"
#include "highscore.h"
#include "subject.h"

using namespace std;
int main() 

{
    std::cout << "HIGHSCORE PLAYER" << endl << endl;

    Subject *subject = new Subject();

    Highscore *highscore = new Highscore(*subject);

    Player *player1 = new Player(*subject, " Danika ", 98);
    highscore->addPlayer(*player1);
    subject->notifyObservers();

    Player *player2 = new Player(*subject, " Icha ", 97);
    highscore->addPlayer(*player2);
    subject->notifyObservers();
    
    Player *player3 = new Player(*subject, " ADE ", 99);
    highscore->addPlayer(*player3);
    subject->notifyObservers();

    return 0;
}	
