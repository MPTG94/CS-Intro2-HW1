//
// Created by Mor on 30/03/2020.
//

#include <stdio.h>

/**
 * Functions definitions
*/
void print_enter_encoded_word_message();

int reverse_num(int num);

int find_true_num(unsigned long int encoded);

int check_legal_two_digit_char(int num, int printed);

int check_legal_three_digit_char(int num, int printed);

void print_decoded_word_opening();

void print_decode_success_message();

void print_decode_fail_message();

/**
 * Defines
 */
#define UPPER_A 'A'
#define LOWER_A 'a'
#define LOWER_Z 'z'
#define MOD_10 10
#define MOD_100 100
#define MOD_1000 1000
#define MOD_1000000000 1000000000

int main() {
    print_enter_encoded_word_message();
    unsigned long int encoded;
    int printed = 0;
    int error = 0;
    scanf(" %lu", &encoded);
    int num = find_true_num(encoded);
    num = reverse_num(num);
    while (num != 0 && error != 1) {
        int temp = num % MOD_100;
        int temp2 = num % MOD_1000;
        if (check_legal_two_digit_char(temp, printed) == 1) {
            printed = 1;
            num = num / MOD_100;
        } else if (check_legal_three_digit_char(temp2, printed) == 1) {
            printed = 1;
            num = num / MOD_1000;
        } else {
            error = 1;
        }
    }
    if (printed == 1) {
        print_decode_success_message();
    } else {
        print_decode_fail_message();
    }
    return 0;
}

/**
 * Tries to find a 2 digit encoded char code inside the number
 * @param num The encoded number
 * @param printed Whether letters were already printed
 * @return 1 if an encoded letter was found, 0 otherwise
 */
int check_legal_two_digit_char(int num, int printed) {
    if (num >= LOWER_A && num <= LOWER_Z) {
        if (printed == 0) {
            print_decoded_word_opening();
        }
        if (num % 2 == 0) {
            char decoded = num + UPPER_A - LOWER_A;
            printf("%c", decoded);
        } else {
            printf("%c", num);
        }
        return 1;
    }
    return 0;
}

/**
 * Tries to find a 3 digit encoded char code inside the number
 * @param num The encoded number
 * @param printed Whether letters were already printed
 * @return 1 if an encoded letter was found, 0 otherwise
 */
int check_legal_three_digit_char(int num, int printed) {
    if (num >= LOWER_A && num <= LOWER_Z) {
        if (printed == 0) {
            print_decoded_word_opening();
        }
        if (num % 2 == 0) {
            char decoded = num + UPPER_A - LOWER_A;
            printf("%c", decoded);
        } else {
            printf("%c", num);
        }
        return 1;
    }
    return 0;
}

/**
 * Receives a number as input and returns it's returned version
 * @param num The number to reverse
 * @return The reversed number
 */
int reverse_num(int num) {
    int rev = 0;
    while (num != 0) {
        rev = rev * MOD_10 + num % MOD_10;
        num = num / MOD_10;
    }
    return rev;
}

/**
 * Finds the true number without leading zeroes
 * @param encoded The encoded number
 * @return The true number without leading zeroes
 */
int find_true_num(unsigned long int encoded) {
    int mod = MOD_1000000000;
    return encoded % (mod);
}

/**
 * Printing functions
 */
void print_enter_encoded_word_message() {
    printf("Enter an encoded word and I'll do my best:\n");
}

void print_decoded_word_opening() {
    printf("The decoded word is: ");
}

void print_decode_success_message() {
    printf("\n");
    printf("Done and even had time for coffee :)\n");
}

void print_decode_fail_message() {
    printf("\n");
    printf("There is nothing there :(\n");
}