/*
* William Beach 
* COP2220
* Program 8 - A program that utilizes functions in the string.h library to manipulate and target string data.
* November 6th, 2022
*
 */


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void greeting(char name[]); //greets user and stores their name
void getWord(char input[], char copy[]); //gets word from user and stores a copy of the word
void uppercaseWord(char upper[]); //takes in a word and uppercases all of its letters
int countVowels(char upper[]); //displays number of each vowel and its index location, returned total number of vowels
void reverseTheWord(char upper[], char reverse[]); //reverses word

int main() {
    char firstName[30], word[30], copyOfWord[30], upperCase[30], reversed[30];
    char sentinel;
    greeting(firstName);
    while (sentinel != 'n') {
        printf("%s, Would you like to enter a word? 'y' (YES) 'n' (NO) ", firstName);
        scanf(" %c", &sentinel);
        if (sentinel == 'n') {
            break;
        }
        getWord(word, copyOfWord);
        uppercaseWord(copyOfWord);
        strcpy(upperCase, copyOfWord);
        reverseTheWord(upperCase, reversed);
        printf("Printing the words in the main function:\n");
        printf("original word: %s\n", word);
        printf("uppercase: %s\n", upperCase);
        printf("reverse: %s\n", reversed);
        int totalVowels = countVowels(upperCase);
        printf("The total number of vowels is %d\n", totalVowels);
        printf("----------------------------------------------\n");
    }
    printf("Thank you %s, have a great day!", firstName);
    return 0;
};

void greeting(char name[]) {
    printf("Hello there, please enter your first name: \n");
    scanf(" %s", name);
    printf("***  Welcome to the character array practice program  ***\n");
    printf("---------------------------------------------------------\n");
};

void getWord(char input[], char copy[]) {
    printf("Please enter a word: ");
    scanf(" %s", input);
    strcpy(copy, input);
};

void uppercaseWord(char upper[]) {
    int i;
    int length = strlen(upper);
    for (i = 0; i < length; i++) {
        upper[i] = toupper(upper[i]);
    }
};

int countVowels(char upper[]) {
    int j;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    int length = strlen(upper);
    for (j = 0; j < length; j++) {
        switch (upper[j]) {
            case 'A':
                printf("There is an 'A' located at index %d\n", i);
                a += 1;
                break;
            case 'E':
                printf("There is an 'E' located at index %d\n", i);
                e += 1;
                break;
            case 'I':
                printf("There is an 'I' located at index %d\n", i);
                i += 1;
                break;
            case 'O':
                printf("There is an 'O' located at index %d\n", i);
                o += 1;
                break;
            case 'U':
                printf("There is an 'U' located at index %d\n", i);
                u += 1;
                break;
        }
    }
    printf("The total number of A's is %d\n", a);
    printf("The total number of E's is %d\n", e);
    printf("The total number of I's is %d\n", i);
    printf("The total number of O's is %d\n", o);
    printf("The total number of U's is %d\n", u);
    printf("Printing the total number of vowels in the main function: \n");
    return a + e + i + o + u;
};

void reverseTheWord(char upper[], char reverse[]) {
    int i, count = 0;
    int length = strlen(upper);
    for (i = length - 1; i >= 0; i--) {
        reverse[count] = upper[i];
        count++;
    }
    reverse[length] = '\0';
};