#pragma once
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>

#define size 10000

//����������
long long binaryPow(int base, int p);
//����GF(p)ȫ��Ԫ��
int  GF_structure(int p);

//����GF(2^n)ȫ��Ԫ�أ�ʮ���ƣ�
int  GF2_structure(int n);
//����GF(2^n)ȫ��Ԫ�أ������ƣ�
int  GF2_structure_bin(int n);
//������תʮ����
int convertBinaryToDecimal(long long n);

//ʮ����תn����
void MToB(unsigned long long m, int n, char s[]);
//ʮ����תn���Ƶ�ʵ��
void MToB_implement();
//GF(p)����Ԫ�����㷨
void GF_generator_build();
//GF(2^n)����Ԫ�����㷨
void GF2_generator_build();

//ʮ��������ת��Ϊʮ������ 
int hexToDec(char a[]);