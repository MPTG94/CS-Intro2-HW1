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

void convert_num_to_array(int trimmed, int arr[], int len);

int check_legal_two_digit_char(int num, int printed);

int check_legal_three_digit_char(int num, int printed);

void print_decoded_word_opening();

void print_decode_success_message();

void print_decode_fail_message();

void print_arr(int arr[]);

/**
 * Defines
 */
#define UPPER_A 'A'
#define LOWER_A 'a'
#define LOWER_Z 'z'
#define MAX_NUM_LENGTH 9

int main() {
    print_enter_encoded_word_message();
    unsigned long int encoded;
    int printed = 0;
    int error = 0;
    scanf(" %lu", &encoded);
    int num = find_true_num(encoded);
    int digits = find_num_digits(num);
    int arr[MAX_NUM_LENGTH] = {0};
    convert_num_to_array(num, arr, MAX_NUM_LENGTH);
//    print_arr(arr);
    for (int i = MAX_NUM_LENGTH - digits;
         i <= MAX_NUM_LENGTH - 2 && error == 0; i++) {
//        printf("i is: %d\n", i);
        int temp = arr[i] * 10 + arr[i + 1];
//        printf("temp is: %d\n", temp);
        if (check_legal_two_digit_char(temp, printed) == 1) {
            printed = 1;
            i += 1;
        } else if (i + 2 < MAX_NUM_LENGTH) {
//            printf("Checking 3 digit\n");
            temp = temp * 10 + arr[i + 2];
            if (check_legal_three_digit_char(temp, printed) == 1) {
                printed = 1;
                i += 2;
            } else {
                error = 1;
            }
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
//    printf("LEGAL CEHCK START\n");
    int reverse = num % 10;
    if (reverse == num) {
        reverse = reverse * 10;
    } else {
        reverse = reverse * 10 + num / 10;
    }

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
 * @param printed Whether letters were already printed
 * @return 1 if an encoded letter was found, 0 otherwise
 */
int check_legal_three_digit_char(int num, int printed) {
    int digits = find_num_digits(num);
    int reverse = num % 10;
    num = num / 10;
    reverse = reverse * 10 + num % 10;
    num = num / 10;
    reverse = reverse * 10 + num % 10;
    if (digits == 2) {
        reverse = reverse * 10;
    }
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
 * receives the trimmed number and converts it to an array of digits
 * @param trimmed The trimmed encoded number
 * @param arr An empty array to fill with digits
 * @param len The length of the array
 */
void convert_num_to_array(int trimmed, int arr[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        arr[i] = trimmed % 10;
        trimmed /= 10;
    }
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

void print_arr(int arr[]) {
    for (int i = 0; i < MAX_NUM_LENGTH; i++) {
        printf("%d", arr[i]);
        if (i == MAX_NUM_LENGTH - 1) {
            printf("\n");
        }
    }
}