#ifndef CARD_H
#define CARD_H
#include <string>
enum class Suit {Spades,Hearts,Clubs,Diamonds};
class Card{
    private:
        int rank;
        Suit suit;
    public:
        Card(int r, Suit s);
        std::string toString();
};
#endif