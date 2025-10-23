#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Expand around center and return palindrome length
int expandFromCenter(const char *s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

// Function to find the longest palindromic substring
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) {
        char *empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int start = 0, end = 0;

    for (int i = 0; i < len; i++) {
        int len1 = expandFromCenter(s, i, i, len);
        int len2 = expandFromCenter(s, i, i + 1, len);
        int max_len = (len1 > len2) ? len1 : len2;

        if (max_len > end - start + 1) {
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }

    int res_len = end - start + 1;
    char *result = (char*)malloc((res_len + 1) * sizeof(char));
    strncpy(result, s + start, res_len);
    result[res_len] = '\0';

    return result;
}

