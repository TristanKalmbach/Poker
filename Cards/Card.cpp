//
// Created by Tristan Kalmbach on 10/11/17.
//

#include "Card.hpp"

void Card::PrintCardDetails() const
{
    std::string out = Card::GetNameFromRank(getRank()) + " of " + Card::GetNameFromSuit(getSuit());
    std::cout << out << "\n";
}


