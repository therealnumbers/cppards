#include "Deck.h"
void Deck::shuffle() {

}
Deck::Deck(std::vector<Card> cards) {
    deck = cards;
    std::random_device rd;
randomEngine.seed(rd());
};

void Deck::shuffle() {
    std::shuffle(deck.begin(),deck.end(),randomEngine);
}
Card Deck::draw() {const Card temp = deck.back(); deck.pop_back(); return temp;};
void Deck::place(Card c) {deck.push_back(c);};
