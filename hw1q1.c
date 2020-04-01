//
// Created by Mor on 30/03/2020.
//

#include <stdio.h>

/**
 * Functions definitions
*/
int calculate_check_digit();

int validate_id();

int add_input_to_sum(int input, int i);

void print_request_choice_message();

void print_calculating_check_digit();

void print_validating_id();

void print_check_digit_result(int res);

void print_validate_id_input(int res);

void print_validate_id_result(int res);

void print_legal_id_message();

void print_illegal_id_message();

void print_error_message();

/**
 * Defines
 */
#define CALCULATE_ID_CHAR 'C'
#define VALIDATE_ID_CHAR 'V'
#define ZERO_CHAR '0'
#define ID_LENGTH 9
#define CALC_INPUT_LENGTH 8
#define MAX_SINGLE_DIGIT 9
#define MOD_2 2
#define MOD_10 10
#define TEN 10

int main() {
    char choice;
    print_request_choice_message();
    if (scanf(" %c", &choice) != 1) {
        print_error_message();
        return 0;
    }

    if (choice == CALCULATE_ID_CHAR) {
        calculate_check_digit();
    } else if (choice == VALIDATE_ID_CHAR) {
        validate_id();
    } else {
        print_error_message();
    }
    return 0;
}

/**
 * Takes an ID without the CheckDigit as input and prints the CheckDigit
 * @return -1 if there's an input error, 0 otherwise
 */
int calculate_check_digit() {
    print_calculating_check_digit();
    int sum = 0;
    char input = 0;
    int result = 0;
    for (int i = 0; i < CALC_INPUT_LENGTH; i++) {
        scanf(" %c", &input);
        if ((int) (input - ZERO_CHAR) >= 0 &&
            (int) (input - ZERO_CHAR) <= MAX_SINGLE_DIGIT) {
            sum += add_input_to_sum(input, i);
        } else {
            print_error_message();
            return -1;
        }
    }
    if (sum % MOD_10 == 0) {
        result = 0;
    } else {
        result = TEN - sum % MOD_10;
    }
    print_check_digit_result(result);
    return 0;
}

/**
 * Takes as input an ID and prints if the ID is legal or not
 * @return -1 if there's an input error, 0 otherwise
 */
int validate_id() {
    print_validating_id();
    int sum = 0;
    char input = 0;
    int user_check_digit = 0;
    int result = 0;
    for (int i = 0; i < ID_LENGTH; i++) {
        scanf(" %c", &input);
        if ((int) (input - ZERO_CHAR) >= 0 &&
            (int) (input - ZERO_CHAR) <= MAX_SINGLE_DIGIT) {
            if (i == 8) {
                user_check_digit = (int) (input - ZERO_CHAR);
            } else {
                sum += add_input_to_sum(input, i);
            }
        } else {
            print_error_message();
            return -1;
        }
    }
    if (sum % MOD_10 == 0) {
        result = 0;
    } else {
        result = TEN - sum % MOD_10;
    }
    print_validate_id_input(user_check_digit);
    print_validate_id_result(result);
    if (result == user_check_digit) {
        print_legal_id_message();
    } else {
        print_illegal_id_message();
    }
    return 0;
}

int add_input_to_sum(int input, int i) {
    // Multiply every digit by it's weight
    int temp = (int) (input - ZERO_CHAR) * ((i % MOD_2) + 1);
    // Weighted number is larger than 10, calculating sum of decimals
    if (temp > MAX_SINGLE_DIGIT) {
        return temp - MAX_SINGLE_DIGIT;
    } else {
        return temp;
    }
}

/**
 * Printing functions
 */
void print_request_choice_message() {
    printf("Please enter the letter C for calculating CheckDigit and the letter V for validating an ID by its CheckDigit:\n");
}

void print_calculating_check_digit() {
    printf("\n");
    printf("Calculating CheckDigit, please enter 8 digits:\n");
}

void print_validating_id() {
    printf("\n");
    printf("Validating ID, please enter 9 digits ID:\n");
    printf("\n");
}

void print_check_digit_result(int res) {
    printf("\n");
    printf("CheckDigit = %d\n", res);
}

void print_validate_id_input(int res) {
    printf("You have entered CheckDigit = %d\n", res);
}

void print_validate_id_result(int res) {
    printf("Calculated CheckDigit = %d\n", res);
    printf("\n");
}

void print_legal_id_message() {
    printf("Legal ID :)\n");
}

void print_illegal_id_message() {
    printf("Illegal ID\n");
}

void print_error_message() {
    printf("\n");
    printf("ERROR\n");
}