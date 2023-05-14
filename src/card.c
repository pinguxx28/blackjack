#include "card.h"

#include <stdlib.h>
#include "debug.h"

card deck[FULL_DECK];
int deck_p = 0;

void deck_init(void)
{
	/* fill deck (sorted) */
	int card_count = 0;
	for (int suit = 1; suit <= SUITS; suit++) {
		for (int value = 1; value <= VALUES; value++) {
			card c = { value, suit };
			deck[card_count++] = c;
		}
	}

	/* shuffle the deck */
	/* just swap current index with random */
	for (int i = 0; i < FULL_DECK; i++) {
		int j = rand() % FULL_DECK;
		card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

card draw_card(void)
{
	if (deck_p < FULL_DECK-1)
		return deck[deck_p++];
	else
		EXIT("exceeded deck's cards\n");
}

void get_card(hand *h)
{
	card c = h->hand[h->hand_p++] = draw_card();
	
	int value = c.value;
	if (c.value > 10) value = 10;
	else if (c.value == 1) value = 11;
	h->total_value += value;

	h->num_cards++;

	if (h->total_value > 21)
		for (int i = 0; i < h->hand_p; i++)
			if (h->hand[i].value == 1) {
				h->total_value -= 10;
				break;
			}
}
