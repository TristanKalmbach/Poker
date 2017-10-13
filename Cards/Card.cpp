//
// Created by Tristan Kalmbach on 10/11/17.
//

#include "Card.hpp"
#include "../Game/Game.hpp"

void Card::PrintCardDetails() const
{
	const std::string out = GetNameFromRank() + " of " + GetNameFromSuit();
    std::cout << out;
	std::cout << " -- Flags: 0x" << std::hex << GetFlags() << '\n';
}

std::pair<int, int> Card::GetCardAsIntPair() const
{
	int suit = GetNumericalValueFromSuit();
	int rank = GetNumericalValueFromRank();

	return std::make_pair(suit, rank);
}

std::string Card::GetNameFromRank() const
{
    switch (getRank())
    {
        case CardRank::Ace:
            return "Ace";
        case CardRank::Two:
            return "Two";
        case CardRank::Three:
            return "Three";
        case CardRank::Four:
            return "Four";
        case CardRank::Five:
            return "Five";
        case CardRank::Six:
            return "Six";
        case CardRank::Seven:
            return "Seven";
        case CardRank::Eight:
            return "Eight";
        case CardRank::Nine:
            return "Nine";
        case CardRank::Ten:
            return "Ten";
        case CardRank::Jack:
            return "Jack";
        case CardRank::Queen:
            return "Queen";
        case CardRank::King:
            return "King";
        default:
            return "Error";
    }
}

std::string Card::GetNameFromSuit() const
{
    switch (getSuit())
    {
        case CardSuits::Club:
            return "Clubs";
        case CardSuits::Diamond:
            return "Diamonds";
        case CardSuits::Heart:
            return "Hearts";
        case CardSuits::Spade:
            return "Spades";
        default:
            return "Error";
    }
}

bool Card::IsCardRoyal() const
{
    switch (getRank())
    {
        case CardRank::Ten:
        case CardRank::Jack:
        case CardRank::Queen:
        case CardRank::King:
        case CardRank::Ace:
            return true;
        default:
            return false;
    }
}

int Card::GetNumericalValueFromRank() const
{
    switch (getRank())
    {
        case CardRank::Ace:
            return 14;
        case CardRank::Two:
            return 2;
        case CardRank::Three:
            return 3;
        case CardRank::Four:
            return 4;
        case CardRank::Five:
            return 5;
        case CardRank::Six:
            return 6;
        case CardRank::Seven:
            return 7;
        case CardRank::Eight:
            return 8;
        case CardRank::Nine:
            return 9;
        case CardRank::Ten:
            return 10;
        case CardRank::Jack:
            return 11;
        case CardRank::Queen:
            return 12;
        case CardRank::King:
            return 13;
        default:
            return 0;
    }
}

int Card::GetNumericalValueFromSuit() const
{
	switch (getSuit())
	{
	case CardSuits::Club:
		return 1;
	case CardSuits::Diamond:
		return 2;
	case CardSuits::Heart:
		return 3;
	case CardSuits::Spade:
		return 4;
	default:
		return 0;
	}
}

int Card::GetCardRankValue() const
{
	switch (getRank())
	{
		case CardRank::Ace:
			return AcesHigh ? 5 : 1;
		case CardRank::Jack:
			return 2;
		case CardRank::Queen:
			return 3;
		case CardRank::King:
			return 4;
		default:
			return 1;
	}
}
