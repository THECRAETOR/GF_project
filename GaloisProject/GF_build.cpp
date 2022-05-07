#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>

#define size 10000


//二进制求幂
long long binaryPow(int base, int p) {
	long long ans = 1, tmp = base;//从底数开始乘，不停自乘
	while (p != 0) {//指数不是0
		if (p & 1) {
			ans = (ans*tmp);
		}
		tmp = (tmp*tmp);//自乘
		p = p >> 1;//访问下一位
	}
	return ans;
}

//生成GF(p)全部元素
int  GF_structure(int p) {
	printf("输出GF(%d)中所有的元素：\n",p);
	int array[size] = { 0 };
	int i = 1;
	for (i = 0; i < p; ++i)
	{
		array[i] = i;
	}
	for (i = 0; i < p; ++i)
	{
		printf("%3d ", array[i]);
	}
	printf("\n");
	return 0;

}

//生成GF(2^n)全部元素（十进制）
int  GF2_structure(int n) {

	int array[size] = { 0 };
	printf("输出GF(2^%d)中所有的元素（十进制）：\n", n);
	int i = 1;
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		array[i] = i;
	}
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		printf("%3d ", array[i]);
	}
	printf("\n");
	return 0;

}


//生成GF(2^n)全部元素（二进制）
int  GF2_structure_bin(int n) {
	printf("输出GF(2^%d)中所有的元素（二进制）：\n", n);
	int array[size] = { 0 };
	char str[size];
	int i = 1;
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		array[i] = i;
	}
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		_itoa_s(array[i], str, 2);//itoa函数将数值转换为字符串，通过规定转换进制实现
		printf("%3s ", str);
	}
	printf("\n");
	return 0;

}

//二进制转十进制
int convertBinaryToDecimal(long long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}




//十进制转n进制
void MToB(unsigned long long m, int n, char s[])
{
	int i = 0;
	int ys = m % n;
	if (m / n == 0) {
		if (ys < 10)
			s[i++] = m % n + '0';
		else
			s[i++] = m % n + 'A' - 10;
		return;
	}
	MToB(m / n, n, s);
	if (ys < 10)
		s[i++] = m % n + '0';
	else
		s[i++] = m % n + 'A' - 10;
}

//十进制转n进制的实现
void MToB_implement() {

	void MToB(unsigned long long m, int n, char s[]);
	unsigned long long m;
	char s[80] = { 0 };
	int n;
	printf("请输入十进制数：");
	scanf_s("%llu", &m);
	printf("请输入想要转化的进制数p：");
	scanf_s(" %d", &n);
	printf("结果为：");
	MToB(m, n, s);
	puts(s);

}

/* 返回ch字符在sign数组中的序号 
int getIndexOfSigns(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	if (ch >= 'A' && ch <= 'F')
	{
		return ch - 'A' + 10;
	}
	if (ch >= 'a' && ch <= 'f')
	{
		return ch - 'a' + 10;
	}
	return -1;
}

/* 十六进制数转换为十进制数 
long hexToDec(char *source)
{
	long sum = 0;
	long t = 1;
	int i, len;

	len = strlen(source);
	for (i = len - 1; i >= 0; i--)
	{
		sum += t * getIndexOfSigns(*(source + i));
		t *= 16;
	}

	return sum;
}
*/

//十六进制数转换为十进制数
int hexToDec(char a[])
{
	int n = strlen(a);//判断字符串的长度函数
	int i, j = 0, num = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 'A')
			num += 10 * pow(16, n - i - 1); //pow() 函数用来求 x 的 y 次方的值。
		else if (a[i] == 'B')
			num += 11 * pow(16, n - i - 1);
		else if (a[i] == 'C')
			num += 12 * pow(16, n - i - 1);
		else if (a[i] == 'D')
			num += 13 * pow(16, n - i - 1);
		else if (a[i] == 'E')
			num += 14 * pow(16, n - i - 1);
		else
			num += 15 * pow(16, n - i - 1);
	}
	return num;
}



//GF(p)生成元生成算法
void GF_generator_build() {
	int base, p, i;
	int table[size];
	int arc_table[size];
	int inverse_table[size];
	printf("请输入生成元：");
	scanf_s("%d", &base);
	printf("请输入p：");
	scanf_s("%d", &p);
	GF_structure(p);
	//正表
	table[0] = 1;//g^0
	for (i = 1; i < p - 1; ++i)//生成元为base
	{
		table[i] = binaryPow(base, i) % p;
	}
	//反表
	for (i = 0; i < p - 1; ++i) {
		arc_table[table[i]] = i;
	}
	//逆元表
	for (i = 1; i < p - 1; ++i)//0没有逆元，所以从1开始
	{
		int k = i;
		k = p - 1 - k;
		inverse_table[i] = binaryPow(base, k) % p;
	}
	//依次输出生成元的幂
	printf("生成元的幂次:\n");
	for (i = 0; i < p - 1; i++) {
		printf("%4d ", i);
	}
	printf("\n");
	//依次输出g^p-1
	printf("g^p-1的值:\n");
	for (i = 0; i < p - 1; i++) {
		printf("%4d ", table[i]);
	}
	printf("\n");

	//依次输出生成元的逆元
	printf("生成元的逆元g^(p-1-n):\n");
	printf("     ");
	for (i = 1; i < p - 1; i++) {
		printf("%4d ", inverse_table[i]);
	}
	printf("\n");

	printf("计算两位数运算\n");
	int a, b;
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	printf("%d", table[(arc_table[a] + arc_table[b]) % (p - 1)]);
}

//GF(2^n)生成元生成算法
void GF2_generator_build() {

	int i, a, b, n;
	int table[size];
	int arc_table[size];
	int inverse_table[size];

	int hex01;//定义十六进制数
	int hex02;

	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);

	scanf_s("%x", &hex01);
	scanf_s("%x", &hex02);

	//正表
	table[0] = 1;//g^0
	for (i = 1; i < binaryPow(2, n) - 1; ++i)
	{
		//下面是m_table[i] = m_table[i-1] * (x + 1)的简写形式
		table[i] = (table[i - 1] << 1) ^ table[i - 1];

		//最高指数已经到了n，需要模上m(x)
		if (table[i] & hex01)//以十六进制的形式呈现
		{
			table[i] ^= hex02;//x^2 * f(x) = x*[x*f(x)]
		}
	}
	//反表
	for (i = 0; i < binaryPow(2, n) - 1; ++i) {
		arc_table[table[i]] = i;
	}
	//逆元表
	for (i = 1; i < binaryPow(2, n); ++i)//0没有逆元，所以从1开始
	{
		int k = arc_table[i];
		k = binaryPow(2, n) - 1 - k;
		k %= binaryPow(2, n) - 1;//m_table的取值范围为 [0, 254]
		inverse_table[i] = table[k];
	}


	printf("%d * %d = %d\n", a, b, table[(arc_table[a] + arc_table[b]) % (binaryPow(2, n) - 1)]);
	printf("%d / %d = %d\n", a, b, table[(arc_table[a] + arc_table[inverse_table[b]]) % (binaryPow(2, n) - 1)]);

}