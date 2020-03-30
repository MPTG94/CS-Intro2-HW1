//
// Created by Mor on 30/03/2020.
//

#include <stdio.h>

/**
 * Functions definitions
*/
void print_enter_encoded_word_message();

int find_true_num(unsigned long int encoded);

int find_num_digits(int trimmed);

int print_legal_two_digit_char(int num, int mod, int printed);

int print_legal_three_digit_char(int num, int mod, int printed);

void print_decoded_word_opening();

void print_decode_success_message();

void print_decode_fail_message();

/**
 * Defines
 */
#define UPPER_A 'A'
#define LOWER_A 'a'
#define LOWER_Z 'z'

int main() {
    print_enter_encoded_word_message();
    unsigned long int encoded;
    int printed = 0;
    scanf(" %lu", &encoded);
    int num = find_true_num(encoded);
//    printf("number is: %d\n", num);
    int digits = find_num_digits(num);
    int mod = 10;
    for (int i = 1; i < digits - 1; i++) {
        mod *= 10;
    }
//    printf("digits is: %d\n", digits);
//    printf("mod is: %d\n", mod);
    // Begin decoding letters
    while (digits > 0) {
        if (print_legal_two_digit_char(num, mod, printed) == 1) {
            num = num % mod;
            mod = mod / 100;
//            printf("New num is: %d", num);
            printed = 1;
            digits -= 2;
        } else if (digits >= 3 && print_legal_three_digit_char(num, mod, printed) == 1) {
            num = num % mod;
            mod = mod / 1000;
            printed = 1;
            digits -= 3;
        } else {
            digits = 0;
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
 * @param mod The modulo to divide by to find letters
 * @param printed Whether letters were already printed
 * @return 1 if an encoded letter was found, 0 otherwise
 */
int print_legal_two_digit_char(int num, int mod, int printed) {
//    printf("LEGAL CEHCK START\n");
    int temp = num / (mod / 10);
    int reverse = temp % 10;
//    printf("temp is: %d\n", temp);
//    printf("num is: %d\n", reverse);
    temp = temp / 10;
    reverse = reverse * 10 + temp % 10;
//    printf("temp is: %d\n", temp);
//    printf("num is: %d\n", reverse);
    if (reverse >= LOWER_A && reverse <= LOWER_Z) {
        if (printed == 0) {
            print_decoded_word_opening();
        }
        if (reverse % 2 == 0) {
            char decoded = reverse + UPPER_A - LOWER_A;
            printf("%c", decoded);
        } else {
            printf("%c", reverse);
        }
        return 1;
    }
    return 0;
}

/**
 * Tries to find a 3 digit encoded char code inside the number
 * @param num The encoded number
 * @param mod The modulo to divide by to find letters
 * @param printed Whether letters were already printed
 * @return 1 if an encoded letter was found, 0 otherwise
 */
int print_legal_three_digit_char(int num, int mod, int printed) {
    int temp = num / (mod / 100);
    int reverse = temp % 10;
    temp = num / 10;
    reverse = reverse * 10 + temp % 10;
    temp = temp / 10;
    reverse = reverse * 10 + temp % 10;
    if (reverse >= LOWER_A && reverse <= LOWER_Z) {
        if (printed == 0) {
            print_decoded_word_opening();
        }
        if (reverse % 2 == 0) {
            char decoded = reverse + UPPER_A - LOWER_A;
            printf("%c", decoded);
        } else {
            printf("%c", reverse);
        }
        return 1;
    }
    return 0;
}

/**
 * Finds the true number without leading zeroes
 * @param encoded The encoded number
 * @return The true number without leading zeroes
 */
int find_true_num(unsigned long int encoded) {
    int mod = 1000000000;
    return encoded % (mod);
}

/**
 * Calculates the number of digits in the number
 * @param trimmed The encoded number without leading zeroes
 * @return The number of digits in the number
 */
int find_num_digits(int trimmed) {
    int num = 0;
    while (trimmed != 0) {
        trimmed /= 10;
        num++;
    }

    return num;
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