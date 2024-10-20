Intuition
we need to find the combination of n dice that will satisfy the mean given it can be of any order any value
thus greedy approach is faster here lets see how

Approach
we first calculate the sum of given dice throws
we create an array of n throws where each of them is at least a 1 as wecant have a 0
we will update our sum
now we will calculate the difference in the sum we have and the mean he expects
we will check if this difference is even attainable if yes
lets traverse the 1's array we created and add the max amount possible that is a 5
we will continue the same process and return the array after
this can be further optimised
I will Iam in a bit of a hurry

Complexity
Time complexity:O(N+M)
Space complexity:O(N)
wallhaven-l8x1pr.jpg

Code
#include <stdio.h>
#include <stdlib.h>

int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int sum = n;
    for (int i = 0; i < rollsSize; i++) {
        sum += rolls[i];
    }

    int totalSum = mean * (rollsSize + n);
    int diff = totalSum - sum;

    if (diff > n * 5 || diff < 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = 1;
    }

    int i = 0;
    while (diff > 0) {
        int increment = diff < (6 - result[i]) ? diff : (6 - result[i]);
        result[i] += increment;
        diff -= increment;
        if (result[i] == 6) {
            i++;
        }
    }

    *returnSize = n;
    return result;
}

int main() {
    int rolls[] = {1, 2, 3};
    int rollsSize = sizeof(rolls) / sizeof(rolls[0]);
    int mean = 4;
    int n = 2;
    int returnSize;

    int* result = missingRolls(rolls, rollsSize, mean, n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
