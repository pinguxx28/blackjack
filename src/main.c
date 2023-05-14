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



	
}

