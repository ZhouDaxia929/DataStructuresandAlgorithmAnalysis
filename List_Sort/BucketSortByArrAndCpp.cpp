//
// Created by ggggg on 2017/3/11.
//

#include <iostream>
#include <cstdlib>

#define N 10 //N表示要排序数组的数字个数  
#define M 22 //M表示要排序元素中的最大值（元素值从0到M）  

using namespace std;
template <class T>
void bucketSortCpp(T arr[], int n){
    //定义一个数组，存放各数字出现的次数。初始值均赋值为0  
    int times[M + 1] = {0};
    //定义一个临时数组  
    T *tempArray = new T[n];
    //统计各数字出现的次数 
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0 && arr[i] <= M)
            times[arr[i]]++;
        else{
            cout << "数组中元素值越界！" << endl;
            exit(-1);
        }
    }
    //重新组织存放出现次数的数组 
    for(int i = 1; i < M + 1; i++)
        times[i] += times[i - 1];
    //对元素进行分配(即是所谓的“收集”）（从后面开始）
    for(int i = n - 1; i >= n; i--)
        tempArray[--times[arr[i]]] = arr[i];
    //把临时数组中的元素复制到原数组中 
    for(int i = 0; i < n; i++)
        arr[i] = tempArray[i];
}

template <class T>
void print(T arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void testBucketSortCpp(){
    int arr[N] = {5,4,0,3,9,22,7,22,0,10};
    cout << "原始数据：" << endl;
    print(arr, N);
    bucketSortCpp(arr, N);
    cout << "排序后：" << endl;
    print(arr, N);
}
