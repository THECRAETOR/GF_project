#pragma once
#pragma once
#define MAXSIZE 100
#define END '\n'
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

void push_ops(char x); //�������ջ
void push_ovs(int x); //��������ջ
char pop_ops(); //�������ջ
int pop_ovs();//��������ջ

char gettop_ops();  //ȡ�������ջ��Ԫ��
int gettop_ovs();  //ȡ��������ջ��Ԫ��
void inistack_ops();  //��ʼ�������ջ
void inistack_ovs(); //��ʼ��������ջ
char Precede(char t1, char t2);  //�ж�t1��t2�����ȼ���
int char_In(char c); //�ж�c�Ƿ�Ϊ�����
int Operate(int a, char theta, int b); //�Գ�ջ������������
int  EvaluateExpression();//ʹ����������㷨����������ʾʽ��ֵ
int convertBinaryToDecimal(long long n);
//��չŷ������㷨
int Expend_gcd(int a, int b, int * x, int * y);
//��mģn�ĳ˷���Ԫ
int Mul_invense(int m, int n);
//����GF(p)�ļӷ�
int add(int a, int b, int p);
//����GF(p)�ļ���
int sub(int a, int b, int p);
//����GF(p)�ĳ˷�
int mul(int a, int b, int p);
//����GF(p)�ĳ���
int div(int a, int b, int p);
//����p��
int input(int p);
//������GF(p)����
void GF_cal();
//������GF(2^n)����
void GF2n_cal();
//������GF(2^n)���㣨�����ƣ�
void GF2n_cal_bin();
//������GF(2^n)���㣨ʮ�����ƣ�
void GF2n_cal_hex();