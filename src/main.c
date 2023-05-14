#include <stdlib.h>
#include "card.h"
#include "debug.h"

#define DEF_N_PLAYERS 4

int main(int argc, char *argv[])
{
	int num_players;
	if (argc == 1) num_players = DEF_N_PLAYERS;
	else if (argc == 2) num_players = atoi(argv[1]); /* TODO: what if NaN */
	else EXIT("usage: blackjack [num_players] (default = 4)\n");

	deck_init();

	hand *players = (hand *) malloc(num_players * sizeof(hand));
	for (int n = 0; n < 2; n++)
		for (int i = 0; i < num_players; i++)
			get_card(&players[i]);

	hand dealer = { 0 };
	for (int n = 0; n < 2; n++)
		get_card(&dealer);

	PRINT_BINARY(dealer.hand[0].value | dealer.hand[0].suit << 6);
	PRINT_BINARY(dealer.hand[1].value | dealer.hand[1].suit << 6);
	


	
}

