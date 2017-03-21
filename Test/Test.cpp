//
// Created by ggggg on 2017/3/21.
//

#include "Test.h"

//求解几何级数
int GeometricSeriesSum(int x, unsigned int n){
    int sum = 0;
    for(unsigned int i = 0; i <= n; i++){
        int prod = 1;
        for(unsigned int j = 0; j < i; j++)
            prod *= x;
        sum += prod;
    }
    return sum;
}

//霍纳法则计算几何级数
int GeometricSeriesSum2(int x, unsigned int n){
    int sum = 0;
    for(unsigned int i = 0; i <= n; i++)
        sum = sum * x + 1;
    return sum;
}

//一个稍微优化的幂计算
int Power2(int x, unsigned int n){
    if(n == 0)
        return 1;
    else if(n % 2 == 0) //n is even
        return Power2(x * x, n / 2);
    else //n is odd
        return x * Power2(x * x, n / 2);
}

//直接用公式计算几何级数
int GeometricSeriesSumbyPower2(int x, unsigned int n){
    return (Power2(x, n + 1) - 1) / (x - 1);
}

int Horner(int a[], unsigned int n, int x){
    int result = a[n];
    for(int i = n - 1; i >= 0; i--)
        result = result * x + a[i];
    return result;
}

//求解Fibonacci数的非递归算法
int Fibonacci(unsigned int n){
    int previous = -1;
    int result = 1;
    for (unsigned int i = 0; i <= n; ++i) {
        int const sum = result + previous;
        previous = result;
        result = sum;
    }
    return result;
}

//计算Fibonacci的递归算法
int Fibonacci2(unsigned int n){
    if(n == 0 || n == 1)
        return n;
    else
        return Fibonacci2(n - 1U) + Fibonacci2(n - 2U);
}

//桶式排序
unsigned int const m = 100;
void BucketSort(unsigned int a[], unsigned int n){
    int buckets[m];
    for(unsigned int j = 0; j < m; j++)
        buckets[j] = 0;
    for(unsigned int i = 0; i < n; i++)
        ++buckets[a[i]];
    for(unsigned int i = 0, j = 0; j < m; j++)
        for(unsigned int k = buckets[j]; k > 0; k--)
            a[i++] = j;
}