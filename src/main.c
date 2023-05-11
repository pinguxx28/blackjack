#include <stdio.h>
#include <stdlib.h>

#define DEF_N_PLAYERS 4
#define EXIT(m) ({ fprintf(stderr, m); exit(1); })

int main(int argc, char *argv[])
{
	int n_players;

	if (argc == 1) n_players = DEF_N_PLAYERS;
	else if (argc == 2) n_players = atoi(argv[1]); /* TODO: what if NaN */
	else EXIT("usage: blackjack [n_players] (default = 4)\n");



	
}
