#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("0\n");
        return 0;
    }

    int n = argc - 1;
    int arr[n];

    // Convert command-line arguments to integers
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    // DP array: dp[i] = length of LIS ending at index i
    int dp[n];

    // Every element alone is an LIS of length 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    // for (int i = 0; i < n; i++) {
    //     printf("dp[i] = 1: %d i = %d\n", dp[i], i);
    // }

    // printf("%ld\n", sizeof(dp)/sizeof(int));
    int max = 1;

    // LIS Dynamic Programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // printf("dp[j] + 1: %d\n dp[i] : %d \n\n", dp[j] + 1,  dp[i]);
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max)
            max = dp[i];
    }
    for (int i = 0; i < n; i++) {
        printf("dp[i]: %d\n", dp[i]);
    } 
    printf("%d\n", max);

    return 0;
}
