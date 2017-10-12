#include "Cards/Card.hpp"
#include "Cards/Deck.hpp"
#include "Testing/Probabilities.hpp"

int main()
{
    Probabilities* pb = new Probabilities();
    pb->GetProbabilitiesOfHandConditions();

    //std::unique_ptr<Deck> deck(new Deck());
    //deck->PrintDeckDetails();

    system("pause");
    return 0;
}