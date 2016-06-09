#pragma once

/* Constantes globale à tout le jeu */
static const float playerHitDistance = 20;
static const float playerPosition = 50;
static const float cooldown = 10;
static const int startingLifePoints = 5;
static const int scoreForKill = 1;
static const int lifeTimeText = 2;


enum SceneNames
{
	MENU,
	RNB1,
	RNB2,
	VILAIN1,
	VILAIN2,
	WIN,
	DEFEAT,
	EXIT
};