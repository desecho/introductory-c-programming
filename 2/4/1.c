#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
    switch (r) {
        case STRAIGHT_FLUSH:
            return "STRAIGHT_FLUSH";
        case FOUR_OF_A_KIND:
            return "FOUR_OF_A_KIND";
        case FULL_HOUSE:
            return "FULL_HOUSE";
        case FLUSH:
            return "FLUSH";
        case STRAIGHT:
            return "STRAIGHT";
        case THREE_OF_A_KIND:
            return "THREE_OF_A_KIND";
        case TWO_PAIR:
            return "TWO_PAIR";
        case PAIR:
            return "PAIR";
        case NOTHING:
            return "NOTHING";
    }

    return "";
}


char value_letter(card_t c) {
    switch (c.value) {
        case 10:
            return '0';
        case VALUE_JACK:
            return 'J';
        case VALUE_QUEEN:
            return 'Q';
        case VALUE_KING:
            return 'K';
        case VALUE_ACE:
            return 'A';
        default:
            return '0' + c.value;
    }
}

char suit_letter(card_t c) {
    switch (c.suit) {
        case SPADES:
            return 's';
        case HEARTS:
            return 'h';
        case DIAMONDS:
            return 'd';
        case CLUBS:
            return 'c';
        // Not necessary
        case NUM_SUITS:
            return ' ';
        // Not necessary
        default:
            return ' ';
    }
}

void print_card(card_t c) {
    char suit;
    char value;
    suit = suit_letter(c);
    value = value_letter(c);
    printf("%c%c", value, suit);
}

card_t card_from_letters(char value_let, char suit_let) {
    card_t card;
    switch (suit_let) {
        case 's':
            card.suit = SPADES;
            break;
        case 'h':
            card.suit = HEARTS;
            break;
        case 'd':
            card.suit = DIAMONDS;
            break;
        case 'c':
            card.suit = CLUBS;
            break;
        default:
            printf("Invalid suit %c\n", suit_let);
            exit(EXIT_FAILURE);
    }

    switch (value_let) {
        case '0':
            card.value = 10;
            break;
        case 'J':
            card.value = VALUE_JACK;
            break;
        case 'Q':
            card.value = VALUE_QUEEN;
            break;
        case 'K':
            card.value = VALUE_KING;
            break;
        case 'A':
            card.value = VALUE_ACE;
            break;
        case '2':
            card.value = 2;
            break;
        case '3':
            card.value = 3;
            break;
        case '4':
            card.value = 4;
            break;
        case '5':
            card.value = 5;
            break;
        case '6':
            card.value = 6;
            break;
        case '7':
            card.value = 7;
            break;
        case '8':
            card.value = 8;
            break;
        case '9':
            card.value = 9;
            break;
        default:
            printf("Invalid value %c\n", value_let);
            exit(EXIT_FAILURE);
    }

    return card;
}

card_t card_from_num(unsigned c) {
    card_t card;

    switch (c) {
        case 0:
            card.suit = SPADES;
            card.value = 2;
            break;
        case 1:
            card.suit = SPADES;
            card.value = 3;
            break;
        case 2:
            card.suit = SPADES;
            card.value = 4;
            break;
        case 3:
            card.suit = SPADES;
            card.value = 5;
            break;
        case 4:
            card.suit = SPADES;
            card.value = 6;
            break;
        case 5:
            card.suit = SPADES;
            card.value = 7;
            break;
        case 6:
            card.suit = SPADES;
            card.value = 8;
            break;
        case 7:
            card.suit = SPADES;
            card.value = 9;
            break;
        case 8:
            card.suit = SPADES;
            card.value = 10;
            break;
        case 9:
            card.suit = SPADES;
            card.value = VALUE_JACK;
            break;
        case 10:
            card.suit = SPADES;
            card.value = VALUE_QUEEN;
            break;
        case 11:
            card.suit = SPADES;
            card.value = VALUE_KING;
            break;
        case 12:
            card.suit = SPADES;
            card.value = VALUE_ACE;
            break;

        case 13:
            card.suit = HEARTS;
            card.value = 2;
            break;
        case 14:
            card.suit = HEARTS;
            card.value = 3;
            break;
        case 15:
            card.suit = HEARTS;
            card.value = 4;
            break;
        case 16:
            card.suit = HEARTS;
            card.value = 5;
            break;
        case 17:
            card.suit = HEARTS;
            card.value = 6;
            break;
        case 18:
            card.suit = HEARTS;
            card.value = 7;
            break;
        case 19:
            card.suit = HEARTS;
            card.value = 8;
            break;
        case 20:
            card.suit = HEARTS;
            card.value = 9;
            break;
        case 21:
            card.suit = HEARTS;
            card.value = 10;
            break;
        case 22:
            card.suit = HEARTS;
            card.value = VALUE_JACK;
            break;
        case 23:
            card.suit = HEARTS;
            card.value = VALUE_QUEEN;
            break;
        case 24:
            card.suit = HEARTS;
            card.value = VALUE_KING;
            break;
        case 25:
            card.suit = HEARTS;
            card.value = VALUE_ACE;
            break;

        case 26:
            card.suit = DIAMONDS;
            card.value = 2;
            break;
        case 27:
            card.suit = DIAMONDS;
            card.value = 3;
            break;
        case 28:
            card.suit = DIAMONDS;
            card.value = 4;
            break;
        case 29:
            card.suit = DIAMONDS;
            card.value = 5;
            break;
        case 30:
            card.suit = DIAMONDS;
            card.value = 6;
            break;
        case 31:
            card.suit = DIAMONDS;
            card.value = 7;
            break;
        case 32:
            card.suit = DIAMONDS;
            card.value = 8;
            break;
        case 33:
            card.suit = DIAMONDS;
            card.value = 9;
            break;
        case 34:
            card.suit = DIAMONDS;
            card.value = 10;
            break;
        case 35:
            card.suit = DIAMONDS;
            card.value = VALUE_JACK;
            break;
        case 36:
            card.suit = DIAMONDS;
            card.value = VALUE_QUEEN;
            break;
        case 37:
            card.suit = DIAMONDS;
            card.value = VALUE_KING;
            break;
        case 38:
            card.suit = DIAMONDS;
            card.value = VALUE_ACE;
            break;

        case 39:
            card.suit = CLUBS;
            card.value = 2;
            break;
        case 40:
            card.suit = CLUBS;
            card.value = 3;
            break;
        case 41:
            card.suit = CLUBS;
            card.value = 4;
            break;
        case 42:
            card.suit = CLUBS;
            card.value = 5;
            break;
        case 43:
            card.suit = CLUBS;
            card.value = 6;
            break;
        case 44:
            card.suit = CLUBS;
            card.value = 7;
            break;
        case 45:
            card.suit = CLUBS;
            card.value = 8;
            break;
        case 46:
            card.suit = CLUBS;
            card.value = 9;
            break;
        case 47:
            card.suit = CLUBS;
            card.value = 10;
            break;
        case 48:
            card.suit = CLUBS;
            card.value = VALUE_JACK;
            break;
        case 49:
            card.suit = CLUBS;
            card.value = VALUE_QUEEN;
            break;
        case 50:
            card.suit = CLUBS;
            card.value = VALUE_KING;
            break;
        case 51:
            card.suit = CLUBS;
            card.value = VALUE_ACE;
            break;
    }

    return card;
}
