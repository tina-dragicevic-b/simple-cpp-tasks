#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>


class Player{
    protected:
    std::string igrac;
    int lCoins[3];
    int leftHandSum;
    int rCoins[3];
    int rightHandSum;
    //int SumOfCoins;
    int SumOfPoints;    //Definiraj kasnije!!

    public:
    Player();
    void PodjelaKovanica(std::vector<int>& a, std::vector<Player*>& vec);
    virtual void SumPoints();   // virtual void CoinsPerHand(Game a);

    virtual void print();

    //virtual void coinSum();
    virtual ~Player();

};

class HumanPlayer : public Player{
    protected:
    int SumOfPoints;
    public:
    HumanPlayer();
    void SumPoints();
    ~HumanPlayer();
};

class Computer : public Player{
    protected:
    int SumOfPoints;
    public:
    Computer();
    void SumPoints();
    ~Computer();
};

class Game : public Player{
    protected:
    int coin1;
    int coin2;
    int coin5;
    int numbOfPlayers;
    int MaxPoints;
    std::vector<Player*> VectorOfPlayers;
    //std::vector<Player> vect;
    public:
    Game();
    //Game(int a, int b, int c, int MaxPoints);
    Game(int a);
    void print();
    void InputPlayers(Player& p, std::vector<int>& arr, std::vector<Player*>& vec);
    
    void P();
    //virtual void Max_Points(int p);
    ~Game();
};

void rand_shuffle(std::vector<int> &arr);