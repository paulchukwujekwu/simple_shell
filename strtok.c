#include <stdio.h>
#include <string.h>

/** Function to split a string into words
 * Create a copy of the input string
 * Free the copy of the input string
 * Free the array of words
 */
char** splitStringIntoWords(const char* input, const char* delimiter, int* wordCount) {
    char* copy = strdup(input); 
    char** words = NULL;
    *wordCount = 0;

    char* token = strtok(copy, delimiter);
    while (token != NULL) {
        (*wordCount)++;
        words = (char**)realloc(words, *wordCount * sizeof(char*));
        words[*wordCount - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    free(copy); 
    return words;
}

int main() {
    const char* input = "This is a sample sentence";
    const char* delimiter = " ";
    int wordCount;

    char** words = splitStringIntoWords(input, delimiter, &wordCount);

    for (int i = 0; i < wordCount; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
        free(words[i]);
    }

    free(words); 
    return 0;
}

