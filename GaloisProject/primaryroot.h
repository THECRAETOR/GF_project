#pragma once
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>
#include "cal.h"


//�ж�����
bool juge_ifprime(long long m);
//���������m�������ֽ�ʽ
void count_EulerNot(int m, int* array);
//����ŷ������
int count_Euler(int *array, int m);
//�ж������Ƿ���,�����ǵ����Լ���Ƿ�Ϊ1
bool juge_HUSU(int a, int m);
//����m���ص���������ĺ���,�������Сԭ��(�ڶ��ε��õ�ʱ������Ǻ�ŷ���������ص�����)
void count_mHUSU(int *brrby, int m);
//��brrby������ѡһ����m���ص�����������temp�η��Ƿ�mod m��m-1�ж����Ƿ�Ϊ��Сԭ��
bool juge_MinPrimitiveRoot(int temp, int brrby, int m);
//������Сԭ��,����arrayΪ����������,brrbyΪ��ŷ���������ص���������
int count_MinPrimitiveRoot(int m, int *array, int *brrby, int Eulernumber);
//��array����Ӵ�С����
void Sort(int* array);
//���������������ͬԪ���޳� 
void Delete_same(int *array);
//����Ĳ���Ϊ��Сԭ������m���ص�����drrdy������������е�ԭ��������crrcy������
void ALL_primeroot(int minprimerroot, int *drrdy, int *crrcy, int m);
//����GF(p)����Ԫ(ԭ��)�ĸ���
void Generator_sum();