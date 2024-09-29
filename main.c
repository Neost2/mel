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
        if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
     int userinput;
    char str[MAX_INPUT_STRING_SIZE];
    char input[10];
    strncpy(str, argv[1], MAX_INPUT_STRING_SIZE - 1);
    str[MAX_INPUT_STRING_SIZE - 1] = '\0';

    do {

        printf("\nString Processing Tool\n");
        printf("1. Count characters\n");
        printf("2. Reverse string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Check palindrome\n");
        printf("5. Count occurrences of a character\n");
        printf("6. Exit\n");
        printf("Enter your input_selection: ");

        fgets(input, sizeof(input), stdin); 
            userinput = atoi(input);
    


        switch (userinput) {
        case 1:
            count_characters(str);
            printf("Press Enter to continue...");
            getchar();
            break;
        case 2:
        {
            char temp[MAX_INPUT_STRING_SIZE];
            strncpy(temp, str, MAX_INPUT_STRING_SIZE);
            temp[MAX_INPUT_STRING_SIZE - 1] = '\0';
            reverse_string(temp);
            printf("Reversed string: %s\n", temp);
            printf("Press Enter to continue...");
            getchar();
            break;
        }

        case 3: {
            char temp[MAX_INPUT_STRING_SIZE];
            strncpy(temp, str, MAX_INPUT_STRING_SIZE);
            temp[MAX_INPUT_STRING_SIZE - 1] = '\0';
            to_uppercase(temp);
            printf("Uppercase string: %s\n", temp);
            printf("Press Enter to continue...");
            getchar();
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
               printf("Press Enter to continue...");
            getchar();
            break;
        case 5: {
            char ch;
            printf("Enter a character to count: ");
            scanf("%c", &ch);
            count_occurrences(str, ch);
            while (getchar() != '\n');
             printf("Press Enter to continue...");
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
       

    } while (userinput != 6);
    return 0;
}

void count_characters(const char* str) {
    int i = 0;
    while (*str != '\0') {
        i++;
        str++;
    }
    printf("Number of characters: %d\n", i);
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
    while (*ptr != '\0') {
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
