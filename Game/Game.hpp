﻿#pragma once

#include "../Cards/CardProperties.hpp"

static const bool AcesHigh = true;

class Poker
{
public:
	static void Draw();
	static void Check();
	static void Stand();
	static void Bet();
	static void Fold();
	static void Showdown();

private:
};

class Game
{
public:
	Game();
	~Game();

	static void InitializeGame();
	static void GameLoop();
};
