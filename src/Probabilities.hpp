//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Deck.hpp"
#include "HandEvaluator.hpp"
#include "HandRankings.hpp"

#include <chrono>

namespace Testing
{
	class Probabilities
	{
	public:

		static void GetProbabilitiesOfHandConditions(const HandRanks handRanks, const int desiredFavorableOutcomes)
		{
			// Create a deck and hand
			std::unique_ptr<Deck> deck(new Deck());
			std::vector<Card> cards;

			int numRuns = 0;
			int outcomes = 0;

			switch (handRanks)
			{
			case HandRanks::Pair:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						const auto hand = deck->CreateHand();
						cards = hand;

						if (HandEvaluator::HasPair(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::Flush:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						if (HandEvaluator::HasFlush(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::Straight:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						if (HandEvaluator::HasStraight(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::StraightFlush:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						if (HandEvaluator::HasStraightFlush(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::RoyalFlush:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						// Check if the hand is a straight flush
						if (HandEvaluator::HasRoyalFlush(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::ThreeOfAKind:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						// Check if the hand is a straight flush
						if (HandEvaluator::HasThreeOfKind(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::FourOfAKind:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						// Check if the hand is a straight flush
						if (HandEvaluator::HasFourOfKind(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
				break;
			case HandRanks::FullHouse:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						// Check if the hand is a straight flush
						if (HandEvaluator::HasFullHouse(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
			case HandRanks::AllRoyal:
				{
					// Start time benchmark
					const auto begin = std::chrono::steady_clock::now();

					while (outcomes < desiredFavorableOutcomes)
					{
						auto const& hand = deck->CreateHand();
						cards = hand;

						// Check if the hand is a straight flush
						if (HandEvaluator::IsEveryCardRoyal(hand))
							++outcomes;

						++numRuns;
					}

					// End time benchmark and print results
					const auto end = std::chrono::steady_clock::now();
					PrintTestResults(numRuns, outcomes, cards, begin, end);
				}
			default:
				break;
			}
		}

		static void PrintTestResults(const int numRuns, const int favorableOutcomes, std::vector<Card> cards,
		                             const std::chrono::steady_clock::time_point begin,
		                             const std::chrono::steady_clock::time_point end)
		{
			const auto timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

			std::cout << "Check ran: " << numRuns << " times." << '\n';
			std::cout << "Number of favorable outcomes: " << favorableOutcomes << '\n';
			std::cout << "\nTime elapsed: " << timeElapsed << " ms. " << '\n';
			std::cout << "\nHand Value: " << HandEvaluator::GetHandRankValue(cards) << '\n';
			std::cout << "\nCards drawn were: " << '\n';
			for (auto const& c : cards)
				c.PrintCardDetails();
		}
	};
}
