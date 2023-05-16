#include <time.h>
#include <stdlib.h>
#include "card.h"
#include "debug.h"

#define DEF_N_PLAYERS 4

int get_line(char line[], int max)
{
	int c, i;

	for (i = 0; i < max; i++) {
		line[i] = c = getchar();
		if (c == '\n')
			break;
	}

	line[i] = '\0';
	return i;
}

int main(int argc, char *argv[])
{
	srand(time(0));

	int num_players;
	if (argc == 1) num_players = DEF_N_PLAYERS;
	else if (argc == 2) num_players = atoi(argv[1]); /* TODO: what if NaN */
	else EXIT("usage: blackjack [num_players] (default = 4)\n");

	/* get bet */
	int bet;
	char bet_l[10];
	printf("bet: ");
	get_line(bet_l, 10);
	bet = atoi(bet_l);


	deck_init();

	hand dealer = { 0 };
	hand player = { 0 };

	for (int n = 0; n < 2; n++)
		get_card(&player);
	
	while (dealer.total_value < 17)
		get_card(&dealer);

	printf("dealer: %d + x\n", dealer.hand[0].value);
	printf("player: %d\n", player.total_value);

	int hit = 1;
	char option;
	while (hit == 1) {
		scanf("%c", &option);
		hit = option == 'h' ? 1 : 0;
		if (!hit) break;

		get_card(&player);
		printf("%d\n", player.hand[player.hand_p-1].value);
	}
	
	printf("-- result --\n");

	printf("dealer: ");
	for (int i = 0; i < dealer.hand_p; i++)
		printf("%d ", dealer.hand[i].value);
	printf(" = %d\n", dealer.total_value);

	printf("player: %d\n", player.total_value);
	
	int state; /* 1 win, 0 push, -1 loss */
	if (player.total_value > 21) {
		printf("Player busts, you lose!\n");
		state = -1;
	} else if (dealer.total_value > 21) {
		printf("Dealer busts, you win!\n");
		state = 1;
	} else if (player.total_value > dealer.total_value) {
		printf("You win!\n");
		state = 1;
	} else if (player.total_value == dealer.total_value) {
		printf("It's a push!\n");
		state = 0;
	} else if (player.total_value < dealer.total_value) {
		printf("You lose!\n");
		state = -1;
	}

	printf("money += %d\n", bet * state);
	


	
}

