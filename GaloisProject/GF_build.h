#pragma once
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>

#define size 10000

//二进制求幂
long long binaryPow(int base, int p);
//生成GF(p)全部元素
int  GF_structure(int p);

//生成GF(2^n)全部元素（十进制）
int  GF2_structure(int n);
//生成GF(2^n)全部元素（二进制）
int  GF2_structure_bin(int n);
//二进制转十进制
int convertBinaryToDecimal(long long n);

//十进制转n进制
void MToB(unsigned long long m, int n, char s[]);
//十进制转n进制的实现
void MToB_implement();
//GF(p)生成元生成算法
void GF_generator_build();
//GF(2^n)生成元生成算法
void GF2_generator_build();

//十六进制数转换为十进制数 
int hexToDec(char a[]);