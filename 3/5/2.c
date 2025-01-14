#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {
    const card_t * cp1 = vp1;
    const card_t * cp2 = vp2;

    if (cp2->value == cp1->value) {
        return cp2->suit > cp1->suit;
    }

    return cp2->value - cp1->value;
}

suit_t flush_suit(deck_t * hand) {
  assert(hand->n_cards == 5);
  if (hand->cards[0]->suit == hand->cards[1]->suit == hand->cards[2]->suit == hand->cards[3]->suit == hand->cards[4]->suit) {
    return hand->cards[0]->suit;
  }

  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {
    int i;
    unsigned max = arr[0];
    for (i=1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}


size_t get_match_index(unsigned * match_counts, size_t n, unsigned n_of_akind){
    int i;
    for (i=0;i<n;i++) {
        if (match_counts[i] == n_of_akind) {
            return i;
        }
    }
    // if no matches
    exit(1);
}

ssize_t find_secondary_pair(deck_t * hand,
                             unsigned * match_counts,
                             size_t match_idx)
{
    int i;
    assert(hand->n_cards == 5);
    for (i=0; i<5; i++) {
        if (match_counts[i] > 1 && i != match_idx) {
            return i;
        }
    }
    return -1;
}


//  - int is_straight_at(deck_t * hand, size_t index, suit_t fs)
//    This function should determine if there is a straight
//    starting at index (and only starting at index) in the
//    given hand.  If fs is NUM_SUITS, then it should look
//    for any straight.  If fs is some other value, then
//    it should look for a straight flush in the specified suit.
//     This function should return:
//     -1 if an Ace-low straight was found at that index (and that index is the Ace)
//      0  if no straight was found at that index
//      1  if any other straight was found at that index

//    When writing this function, you can assume
//    that the hand is sorted by value: the
//    values of cards will appear in descending order.
//    (A K Q ... 4 3 2).

//    There are two things that make this function
//    tricky (probably the trickiest function in
//    this assignment):
//      (1) Ace low straights. An Ace low straight
//          will appear in the hand with the Ace
//          first, then possibly some other cards,
//          then the 5 4 3 2.  For example, you
//          might have
//            As Ks Qc 5s 4c 3d 2c
//      (2) You may have multiple cards with the
//          same value, but still have a straight:
//            As Ac Ks Kc Qh Jh 0d
//          has a straight even though A K Q
//          do not appear next to each other in
//          our sorted order.
//   Hint: I made this easier on myself, by writing
//   two helper functions:
//   int is_n_length_straight_at(deck_t * hand, size_t index, suit_t fs, int n) ;
//    and
//   int is_ace_low_straight_at(deck_t * hand, size_t index, suit_t fs);

//   The second of these lets me pull out the complexities of an ace
//   low straight.  However, in doing so, I realized that there
//   would be a lot of duplication of code between the ace low straight
//   helper and the original function (for an ace low, you want to find
//   a 5, then a straight of length 4: 5, 4, 3, 2).   This realization
//   caused me to pull out much of the code into is_n_length_straight_at,
//   so that I could call it with n=4 to search for the 5,4,3,2 part
//   of an ace low straight.


int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  return 0;
}

hand_eval_t build_hand_from_match(deck_t * hand,
                                  unsigned n,
                                  hand_ranking_t what,
                                  size_t idx) {

  hand_eval_t ans;
  return ans;
}


int compare_hands(deck_t * hand1, deck_t * hand2) {

  return 0;
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) ;

// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
        (fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
        assert(hand->cards[i]->value == VALUE_ACE &&
               (fs == NUM_SUITS || hand->cards[i]->suit == fs));
        ans->cards[4] = hand->cards[i];
        size_t cpind = i+1;
        while(hand->cards[cpind]->value != 5 ||
              !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
          cpind++;
          assert(cpind < hand->n_cards);
        }
        copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
        copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
        ans.cards[copy_idx] = hand->cards[i];
        copy_idx++;
        if (copy_idx >=5){
          break;
        }
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
