//
// Created by Mor on 30/03/2020.
//

#include <stdio.h>

int calculate_check_digit();

int validate_id();

void print_request_choice_message();

void print_calculating_check_digit();

void print_validating_id();

void print_check_digit_result(int res);

void print_validate_id_input(int res);

void print_validate_id_result(int res);

void print_legal_id_message();

void print_illegal_id_message();

void print_error_message();

#define CALCULATE_ID_CHAR 'C'
#define VALIDATE_ID_CHAR 'V'
#define ZERO_CHAR '0'

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

int calculate_check_digit() {
    print_calculating_check_digit();
    int sum = 0;
    char input = 0;
    int temp = 0;
    int result = 0;
    for (int i = 0; i < 8; i++) {
        scanf(" %c", &input);
        if ((int) (input - ZERO_CHAR) >= 0 && (int) (input - ZERO_CHAR) <= 9) {
            temp = (int) (input - ZERO_CHAR) * ((i % 2) + 1);
            if (temp > 9) {
                sum += temp - 9;
            } else {
                sum += temp;
            }
        } else {
            print_error_message();
            return -1;
        }

    }
    result = 10 - sum % 10;
    print_check_digit_result(result);
    return 0;
}

int validate_id() {
    print_validating_id();
    int sum = 0;
    char input = 0;
    int temp = 0;
    int user_check_digit = 0;
    int result = 0;
    for (int i = 0; i < 9; i++) {
        scanf(" %c", &input);
        if ((int) (input - ZERO_CHAR) >= 0 && (int) (input - ZERO_CHAR) <= 9) {
            if (i == 8) {
                user_check_digit = (int) (input - ZERO_CHAR);
            } else {
                temp = (int) (input - ZERO_CHAR) * ((i % 2) + 1);
                if (temp > 9) {
                    sum += temp - 9;
                } else {
                    sum += temp;
                }
            }
        } else {
            print_error_message();
            return -1;
        }

    }
    result = 10 - sum % 10;
    print_validate_id_input(user_check_digit);
    print_validate_id_result(result);
    if (result == user_check_digit) {
        print_legal_id_message();
    } else {
        print_illegal_id_message();
    }

    return 0;
}

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