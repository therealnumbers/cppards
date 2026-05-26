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
}