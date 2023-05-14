#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "debug.h"

#define DEF_N_PLAYERS 4

int main(int argc, char *argv[])
{
	srand(time(0));

	int num_players;
	if (argc == 1) num_players = DEF_N_PLAYERS;
	else if (argc == 2) num_players = atoi(argv[1]); /* TODO: what if NaN */
	else EXIT("usage: blackjack [num_players] (default = 4)\n");

	deck_init();

	hand dealer = { 0 };
	hand player = { 0 };

	for (int n = 0; n < 2; n++) {
		get_card(&player);
		get_card(&dealer);
	}

	printf("dealer: %d\n", dealer.total_value);
	printf("player: %d\n", player.total_value);
	


	
}

