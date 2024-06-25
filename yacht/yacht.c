#include "yacht.h"

bool my_xor(bool a, bool b) { return (a || b) && !(a && b); }

int count(dice_t dice, int target) {
    int acc = 0;

    for (size_t idx = 0; idx < ARRAYLEN(dice.faces); idx++) {
        int face = dice.faces[idx];
        if (face == target) acc++;
    }
    return (acc);
}

int just_sum(dice_t dice) {
    int acc = 0;

    for (size_t idx = 0; idx < ARRAYLEN(dice.faces); idx++) {
        acc += dice.faces[idx];
    }
    return (acc);
}

bool validate_dice(dice_t dice) {
    for (size_t idx = 0; idx < ARRAYLEN(dice.faces); idx++) {
        int face = dice.faces[idx];
        if (face < 0 || face > 6) return (false);
    }
    return (true);
}

int score(dice_t dice, category_t category) {
    int acc, total_score = 0;

    if (validate_dice(dice) == false) return (0);
    switch (category) {
        case ONES:
            total_score += 1 * count(dice, 1);
            break;
        case TWOS:
            total_score += 2 * count(dice, 2);
            break;
        case THREES:
            total_score += 3 * count(dice, 3);
            break;
        case FOURS:
            total_score += 4 * count(dice, 4);
            break;
        case FIVES:
            total_score += 5 * count(dice, 5);
            break;
        case SIXES:
            total_score += 6 * count(dice, 6);
            break;
        case FULL_HOUSE:
            bool threes = false;
            bool twos = false;

            acc = 0;
            for (size_t nb = 1; nb <= 6; nb++) {
                int curr_count = count(dice, nb);
                if (curr_count == 3) {
                    acc += nb * 3;
                    threes = true;
                } else if (curr_count == 2) {
                    acc += nb * 2;
                    twos = true;
                }
            }
            if (threes && twos) total_score += acc;
            break;
        case FOUR_OF_A_KIND:
            bool fours_or_more = false;

            acc = 0;
            for (size_t nb = 1; nb <= 6; nb++) {
                int curr_count = count(dice, nb);
                if (curr_count >= 4) {
                    acc += nb * 4;
                    fours_or_more = true;
                }
            }
            if (fours_or_more) total_score += acc;
            break;
        case LITTLE_STRAIGHT:
            bool little_straight = true;

            for (size_t nb = 1; nb <= 6; nb++) {
                int curr_count = count(dice, nb);
                bool expr_a = curr_count == 1;
                bool expr_b = nb == 6;

                if (!my_xor(expr_a, expr_b)) {
                    little_straight = false;
                }
            }
            if (little_straight) total_score += 30;
            break;
        case BIG_STRAIGHT:
            bool big_straight = true;

            for (size_t nb = 1; nb <= 6; nb++) {
                int curr_count = count(dice, nb);
                bool expr_a = curr_count == 1;
                bool expr_b = nb == 1;

                if (!my_xor(expr_a, expr_b)) {
                    big_straight = false;
                }
            }
            if (big_straight) total_score += 30;
            break;
        case CHOICE:
            total_score += just_sum(dice);
            break;
        case YACHT:
            bool fives = false;

            for (size_t nb = 1; nb <= 6; nb++) {
                int curr_count = count(dice, nb);
                if (curr_count == 5) {
                    fives = true;
                    break;
                }
            }
            if (fives) total_score += 50;
            break;
    }
    return (total_score);
}
