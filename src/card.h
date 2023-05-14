#ifndef __CARD_H
#define __CARD_H

#define SUITS 4
#define VALUES 13
#define FULL_DECK 52
#define MAX_CARDS_ON_HAND 8

typedef struct {
	int value;
	int suit;
} card;

typedef struct {
	card hand[MAX_CARDS_ON_HAND];
	int hand_p;
	int total_value;
	int num_cards;
} hand;

void deck_init(void);
card draw_card(void);
void get_card(hand *h);

#endif
