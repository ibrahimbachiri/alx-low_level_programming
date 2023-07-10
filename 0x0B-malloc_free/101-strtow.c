#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
    int i, count = 0, len = strlen(str);
    int word_started = 0;

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (!word_started) {
                word_started = 1;
                count++;
            }
        } else {
            word_started = 0;
        }
    }

    return count;
}

char **strtow(char *str)
{
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int i, j, len = strlen(str);
    int word_started = 0, word_count = count_words(str);
    char **words = malloc((word_count + 1) * sizeof(char *));

    if (words == NULL) {
        return NULL;
    }

    j = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (!word_started) {
                word_started = 1;
                int word_len = 1, k;

                for (k = i + 1; k < len && str[k] != ' '; k++, word_len++);

                words[j] = malloc((word_len + 1) * sizeof(char));

                if (words[j] == NULL) {
                    for (k = 0; k < j; k++) {
                        free(words[k]);
                    }
                    free(words);
                    return NULL;
                }

                strncpy(words[j], &str[i], word_len);
                words[j][word_len] = '\0';
                j++;
            }
        } else {
            word_started = 0;
        }
    }

    words[word_count] = NULL;

    return words;
}
