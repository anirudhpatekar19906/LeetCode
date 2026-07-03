#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {

    int n = strlen(s);

    if (numRows == 1 || numRows >= n)
        return s;

    char **rows = (char **)malloc(numRows * sizeof(char*));
    int *index = (int *)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = (char *)malloc((n + 1) * sizeof(char));

    int curRow = 0;
    int direction = 1; // 1 = down, -1 = up

    for (int i = 0; i < n; i++) {

        rows[curRow][index[curRow]++] = s[i];

        if (curRow == 0)
            direction = 1;
        else if (curRow == numRows - 1)
            direction = -1;

        curRow += direction;
    }

    char *result = (char *)malloc((n + 1) * sizeof(char));
    int pos = 0;

    for (int i = 0; i < numRows; i++) {

        for (int j = 0; j < index[i]; j++)
            result[pos++] = rows[i][j];

        free(rows[i]);
    }

    result[pos] = '\0';

    free(rows);
    free(index);

    return result;
}