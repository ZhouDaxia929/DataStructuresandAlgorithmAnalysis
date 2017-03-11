//
// Created by ggggg on 2017/3/11.
//
#include <cstdio>
int find_max(int A[], int N){
    int max = A[0];
    for(int i = 1; i < N; i++)
        if(A[i] > max)
            max = A[i];
    return max;
}

void bucketSort(int A[], int N){
    int M = find_max(A, N);
    int count[M + 1]; //下标从0开始，保证最大下标为数组A中的最大数值
    for(int i = 0; i <= M; i++)
        count[i] = 0;
    for(int i = 0; i < N; i++)
        count[A[i]]++;
    for(int i = 0; i <= M; i++)
        while(count[i] > 0){
            printf("%d ", i);
            count[i]--;
        }
    printf("\n");
}

void testBucketSort(){
    int A[] = {3, 2, 4, 5, 8, 1, 7, 6};
    printf("before sorted: ");
    for(int i = 0; i < 8; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("after sorted: ");
    bucketSort(A, 8);
}