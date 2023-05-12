#include <stdio.h>
#include <stdlib.h>

#define DEF_N_PLAYERS 4
#define MAX_CARDS_ON_HAND 8
#define FULL_DECK 52
#define SUITS 4
#define VALUES 13
#define EXIT(m) ({ fprintf(stderr, m); exit(1); })

/* always 0-255 */
typedef unsigned char byte;

typedef struct {
	byte value;
	byte suit;
} card;

typedef struct {
	card hand[MAX_CARDS_ON_HAND];
	byte total_value;
	byte num_cards;
} hand;


void deck_init(card deck[FULL_DECK]);

int main(int argc, char *argv[])
{
	byte num_players;
	if (argc == 1) num_players = DEF_N_PLAYERS;
	else if (argc == 2) num_players = atoi(argv[1]); /* TODO: what if NaN */
	else EXIT("usage: blackjack [num_players] (default = 4)\n");

	card deck[FULL_DECK];
	deck_init(deck);



	
}

void deck_init(card deck[FULL_DECK])
{
	/* fill deck (sorted) */
	byte card_count = 0;
	for (byte suit = 0; suit < SUITS; suit++) {
		for (byte value = 0; value < VALUES; value++) {
			card c = { value, suit };
			deck[card_count++] = c;
		}
	}

	/* shuffle the deck */
	/* just swap current index with random */
	for (byte i = 0; i < FULL_DECK; i++) {
		byte j = rand() % FULL_DECK;
		card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}
