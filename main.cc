#include <iostream>
#include <string>
#include "Card.h"
int main() {
  std::cout << "Hello World!" << std::endl;
  Card x = Card(0, Suit::Clubs);
  std::cout << x.toString() << std::endl;
}
