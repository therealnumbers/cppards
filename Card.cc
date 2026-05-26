#include "Card.h"
// Jokers are rank 0, and are Red(Hearts) or Black(Spades), just for simplicity
Card::Card(int r, Suit s){
    if (r < 0 || r > 13) r = 0; // clamp invalid ranks to joker
    rank = r;
    if (r == 0) {
        if (s == Suit::Diamonds) s = Suit::Hearts; // red jokers are hearts
        if (s == Suit::Clubs) s = Suit::Spades; // black jokers are spades
    };
    suit = s;
};

int Card::getRank() const {return rank;};
Suit Card::getSuit() const {return suit;};

void Card::update(int r, Suit s) {
    const Card newCard = Card(r,s);
    rank = newCard.getRank();
    suit = newCard.getSuit();
};

std::string Card::toString() {
    std::string rankPart;
    std::string suitPart;
    switch (rank) {
        case 0:  {rankPart = 'j'; break;}
        case 1:  {rankPart = 'A'; break;}
        case 10: {rankPart = 'T'; break;}
        case 11: {rankPart = 'J'; break;}
        case 12: {rankPart = 'Q'; break;}
        case 13: {rankPart = 'K'; break;}
        default: rankPart = std::to_string(rank);
        };
        switch (suit) {
        case Suit::Spades: {suitPart = "♠";break;}
        case Suit::Hearts: {suitPart = "♥";break;}
        case Suit::Clubs: {suitPart = "♣";break;}
        case Suit::Diamonds: {suitPart = "♦";break;}
        };
        return suitPart+rankPart;
};

bool Card::isRed() const {return suit == Suit::Hearts || suit == Suit::Diamonds;};
bool Card::isBlack() const {return suit == Suit::Spades || suit == Suit::Clubs;};
bool Card::isFace() const {return rank == 11 || rank == 12 || rank == 13;};
bool Card::isAce() const {return rank == 1;}
bool Card::isJoker() const {return rank == 0;};
bool Card::sameRank(Card other) const {return rank == other.rank;};
bool Card::sameSuit(Card other) const {
    if (this->isJoker() || other.isJoker()) {return this->isRed() == other.isRed();};
    return this->suit == other.suit;
};
bool Card::operator==(const Card &other) const {return this->sameRank(other) && this->sameSuit(other);};