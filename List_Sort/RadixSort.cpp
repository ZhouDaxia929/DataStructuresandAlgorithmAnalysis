//
// Created by ggggg on 2017/3/11.
//

#include <cstdlib>

/*
 * 找到num的从第到高的第pos位的数据
 */
int GetNumInPos(int num, int pos){
    int temp = 1;
    for(int i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}

/*
 * 基数排序
 */
#define RADIX_10 10
#define KEYNUM_31 31
void RadixSort(int *pDataArray, int iDataNum){
    int *radixArrays[RADIX_10]; //分别为0-9的序列空间
    for(int i = 0; i < 10; i++){
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
        radixArrays[i][0] = 0; //index为0处记录这组数据的个数
    }
    for(int pos = 1; pos <= KEYNUM_31; pos++){ //从个位开始到31位
        for(int i = 0; i < iDataNum; i++){ //分配过程
            int num = GetNumInPos(pDataArray[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = pDataArray[i];
        }

        for(int i = 0, j = 0; i < RADIX_10; i++){
            for(int k = 1; k <= radixArrays[i][0]; k++)
                pDataArray[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0; //复位
        }
    }
}
