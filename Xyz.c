#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Structure to store word information
typedef struct {
    char word[MAX_WORD_LEN];
    int occurrences;
    int line_numbers[100]; // Assuming max 100 occurrences on different lines
    int num_lines;
} WordInfo;

// Function to compare words case-insensitively
int compare_words(const char* word1, const char* word2) {
    while (*word1 && *word2) {
        if (tolower(*word1) != tolower(*word2)) {
            return *word1 - *word2;
        }
        word1++;
        word2++;
    }
    return *word1 - *word2;
}

// Function to check if a word is to be ignored
int is_ignored_word(const char* word) {
    const char* ignored_words[] = {"There", "Is", "Are", "Were", "Was", "I", "We", "Of", "In"};
    const int num_ignored_words = sizeof(ignored_words) / sizeof(ignored_words[0]);

    for (int i = 0; i < num_ignored_words; i++) {
        if (compare_words(word, ignored_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to add word occurrence to the WordInfo array
void add_word_occurrence(WordInfo* words, int* num_words, const char* word, int line_number) {
    int i;
    for (i = 0; i < *num_words; i++) {
        if (compare_words(words[i].word, word) == 0) {
            words[i].occurrences++;
            if (words[i].num_lines < 100) {
                words[i].line_numbers[words[i].num_lines] = line_number;
                words[i].num_lines++;
            }
            break;
        }
    }

    if (i == *num_words) {
        strncpy(words[*num_words].word, word, MAX_WORD_LEN);
        words[*num_words].word[MAX_WORD_LEN - 1] = '\0';
        words[*num_words].occurrences = 1;
        words[*num_words].line_numbers[0] = line_number;
        words[*num_words].num_lines = 1;
        (*num_words)++;
    }
}

// Function to sort words based on their occurrences
void sort_words(WordInfo* words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].occurrences < words[j].occurrences) {
                WordInfo temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    char line[1024];
    WordInfo words[100];
    int num_words = 0;
    int line_number = 1;

    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            if (!is_ignored_word(word)) {
                add_word_occurrence(words, &num_words, word, line_number);
            }
            word = strtok(NULL, " \t\n");
        }
        line_number++;
    }

    fclose(fp);

    sort_words(words, num_words);

    for (int i = 0; i < num_words; i++) {
        printf("Category %s-Count %d\n", words[i].word, words[i].occurrences);
        for (int j = 0; j < words[i].num_lines; j++) {
            printf("Line %d: %s\n", words[i].line_numbers[j], words[i].word);
        }
        printf("\n");
    }

    return 0;
}
