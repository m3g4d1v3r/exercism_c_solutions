#ifndef YACHT_H
#define YACHT_H

#define ARRAYLEN(x) sizeof(x) / sizeof(x[0])
#include <stdbool.h>
#include <stddef.h>

typedef enum {
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    LITTLE_STRAIGHT,
    BIG_STRAIGHT,
    CHOICE,
    YACHT
} category_t;

typedef struct {
    int faces[5];
} dice_t;

bool my_xor(bool a, bool b);
int count(dice_t dice, int target);
int score(dice_t dice, category_t category);
int just_sum(dice_t dice);
bool validate_dice(dice_t dice);

#endif
