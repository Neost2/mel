#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_STRING_SIZE 100
#define PALINDROME_FOUND 1
#define PALINDROME_NOT_FOUND 0


void count_characters(const char* str);
void reverse_string(char* str);
void to_uppercase(char* str);
int check_palindrome(const char* str);
void count_occurrences(const char* str, char ch);


int main(int argc, char* argv[]) {
    int userinput;
    char str[MAX_INPUT_STRING_SIZE];
    char input[10];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    strncpy(str, argv[1], MAX_INPUT_STRING_SIZE - 1);
    str[MAX_INPUT_STRING_SIZE - 1] = '\0';

    do {

        printf("String Processing Tool\n");
        printf("1. Count characters\n");
        printf("2. Reverse string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Check palindrome\n");
        printf("5. Count occurrences of a character\n");
        printf("6. Exit\n");
        printf("Enter your input_selection: ");

        if (fgets(input, sizeof(input), stdin) != NULL) {
            userinput = atoi(input);
        }


        switch (userinput) {
        case 1:
            printf("Number of characters: %zu\n", strlen(str));
            break;
        case 2:
        {
            char temp[MAX_INPUT_STRING_SIZE];
            strncpy(temp, str, MAX_INPUT_STRING_SIZE);
            temp[MAX_INPUT_STRING_SIZE - 1] = '\0';
            reverse_string(temp);
            printf("Reversed string: %s\n", temp);
            break;
        }

        case 3: {
            char temp[MAX_INPUT_STRING_SIZE];
            strncpy(temp, str, MAX_INPUT_STRING_SIZE);
            temp[MAX_INPUT_STRING_SIZE - 1] = '\0';
            to_uppercase(temp);
            printf("Uppercase string: %s\n", temp);
            break;
        }

        case 4: {
            if (check_palindrome(str) == PALINDROME_FOUND) {
                printf("%s is a palindrome\n", str);
            }
            else {
                printf("%s is not a palindrome\n", str);
            }
        }
              break;
        case 5: {
            char ch;
            printf("Enter a character to count: ");
            scanf(" %c", &ch);
            count_occurrences(str, ch);
            getchar();
            break;
        }
        case 6: {
            printf("Exiting the program.\n");
            return 0;
        }
        default:
            printf("Invalid selection. Please choose a number between 1 and 6.\n");
            break;
        }
        printf("Press Enter to continue...\n");
        getchar();

    } while (1);
    return 0;
}

void count_characters(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    printf("Number of characters: %s\n", str);
}

// Function to reverse a string
void reverse_string(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to convert a string to uppercase
void to_uppercase(char* str) {
    char* ptr = str;
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

// Function to check if a string is a palindrome
int check_palindrome(const char* str) {
    const char* start = str;
    const char* end = str + strlen(str) - 1;

    while (end > start) {
        if (tolower(*start) != tolower(*end)) {
            return PALINDROME_NOT_FOUND;
        }
        start++;
        end--;
    }
    return PALINDROME_FOUND;
}

// Function to count occurrences of a character in a string
void count_occurrences(const char* str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    printf("Occurrences of '%c': %d\n", ch, count);
}
