#pragma once
#pragma once
#define MAXSIZE 100
#define END '\n'
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"

void push_ops(char x); //运算符进栈
void push_ovs(int x); //操作数进栈
char pop_ops(); //运算符出栈
int pop_ovs();//操作数出栈

char gettop_ops();  //取出运算符栈顶元素
int gettop_ovs();  //取出操作数栈顶元素
void inistack_ops();  //初始化运算符栈
void inistack_ovs(); //初始化操作数栈
char Precede(char t1, char t2);  //判断t1与t2的优先级别
int char_In(char c); //判断c是否为运算符
int Operate(int a, char theta, int b); //对出栈的两个数计算
int  EvaluateExpression();//使用算符优先算法进行算术表示式求值
int convertBinaryToDecimal(long long n);
//扩展欧几里得算法
int Expend_gcd(int a, int b, int * x, int * y);
//求m模n的乘法逆元
int Mul_invense(int m, int n);
//定义GF(p)的加法
int add(int a, int b, int p);
//定义GF(p)的减法
int sub(int a, int b, int p);
//定义GF(p)的乘法
int mul(int a, int b, int p);
//定义GF(p)的除法
int div(int a, int b, int p);
//输入p的
int input(int p);
//有限域GF(p)计算
void GF_cal();
//有限域GF(2^n)计算
void GF2n_cal();
//有限域GF(2^n)计算（二进制）
void GF2n_cal_bin();
//有限域GF(2^n)计算（十六进制）
void GF2n_cal_hex();