#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "deck.h"

void print_hand(deck_t * hand) {
    int i;
    for (i=0; i < hand->n_cards; i++) {
        print_card(*hand->cards[i]);
        printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
    int i;
    for (i=0; i < d->n_cards; i++) {
        if (d->cards[i]->suit == c.suit && d->cards[i]->value == c.value) {
            return 1;
        }
    }

    return 0;
}

void shuffle(deck_t * d) {
    int n = d->n_cards;
    int i;
    int r1, r2;
    card_t *tmp;
    for (i=0; i<n; i++) {
        r1 = random() % n;
        r2 = random() % n;
        tmp = d->cards[r1];
        d->cards[r1] = d->cards[r2];
        d->cards[r2] = tmp;
    }
}

void assert_full_deck(deck_t * d) {
    int i;
    card_t card;
    if (d->n_cards != 52) {
        return;
    }
    for (i=0; i < 52; i++) {
        card = card_from_num(i);
        assert(deck_contains(d, card));
    }
}
