#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
class Deck {
    private:
        std::vector<Card> deck;
        std::mt19937 randomEngine;
    public:
        Deck(std::vector<Card> cards);
        // shuffles the deck inplace
        void shuffle();
        // takes a card from the end of the deck
        Card draw();
        // places a card onto the end of the deck
        void place(Card c);
};
#endif