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

        int getRank() const;
        Suit getSuit() const;

        void update(int r, Suit s);

        std::string toString();
        // Extra logic to help with common operations
        
        // Checks if card is red (♥/♦)
        bool isRed() const;
        // Checks if card is black (♠/♣)
        bool isBlack() const;
        // Checks if card is a face card (J/Q/K)
        bool isFace() const;
        // Checks if card is an ace (A)
        bool isAce() const;
        // Guess
        bool isJoker() const;
        // Compares if two cards have the same rank
        bool sameRank(Card other) const;
        // Compares if two cards have the same suit. Red jokers match ♥ | ♦, etc.
        bool sameSuit(Card other) const;
        bool operator == (const Card &card) const;
};
#endif