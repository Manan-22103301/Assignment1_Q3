#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

void toLowerStr(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}

int findWord(WordFreq words[], int count, char *word) {
    for(int i = 0; i < count; i++) {
        if(strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[5000];
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char word[MAX_WORD_LEN];
    int index = 0;

    for(int i = 0; i <= strlen(paragraph); i++) {
        if(isDelimiter(paragraph[i]) || paragraph[i] == '\0') {
            if(index != 0) {
                word[index] = '\0';
                toLowerStr(word);
                int pos = findWord(words, wordCount, word);
                if(pos == -1) {
                    strcpy(words[wordCount].word, word);
                    words[wordCount].count = 1;
                    wordCount++;
                } else {
                    words[pos].count++;
                }
                index = 0;
            }
        } else {
            word[index++] = paragraph[i];
        }
    }

    printf("Word Frequencies:\n");
    for(int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
