#include <string.h>

int lengthOfLongestSubstring(char *s) {

    int lastSeen[128];

    for (int i = 0; i < 128; i++)
        lastSeen[i] = -1;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        char ch = s[right];

        if (lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;

        int currentLength = right - left + 1;

        if (currentLength > maxLength)
            maxLength = currentLength;
    }

    return maxLength;
}