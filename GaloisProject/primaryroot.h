#pragma once
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>
#include "cal.h"


//判断素数
bool juge_ifprime(long long m);
//计算输入的m的素数分解式
void count_EulerNot(int m, int* array);
//计算欧拉函数
int count_Euler(int *array, int m);
//判断两数是否互素,即它们的最大公约数是否为1
bool juge_HUSU(int a, int m);
//求与m互素的数的数组的函数,并求出最小原根(第二次调用的时候求的是和欧拉函数互素的数组)
void count_mHUSU(int *brrby, int m);
//在brrby数组中选一个与m互素的数计算它的temp次方是否mod m余m-1判断它是否为最小原根
bool juge_MinPrimitiveRoot(int temp, int brrby, int m);
//计算最小原根,其中array为素因数数组,brrby为与欧拉函数互素的数的数组
int count_MinPrimitiveRoot(int m, int *array, int *brrby, int Eulernumber);
//对array数组从大到小排序
void Sort(int* array);
//将素因数数组的相同元素剔除 
void Delete_same(int *array);
//传入的参数为最小原根和与m互素的数组drrdy，函数求出所有的原根并存在crrcy数组里
void ALL_primeroot(int minprimerroot, int *drrdy, int *crrcy, int m);
//计算GF(p)生成元(原根)的个数
void Generator_sum();