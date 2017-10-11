#include "Cards/Card.hpp"
#include "Cards/Deck.hpp"

int main()
{
    std::unique_ptr<Deck> deck(new Deck());

    deck->PrintDeckDetails();

    system("pause");
    return 0;
}