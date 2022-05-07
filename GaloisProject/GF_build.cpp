#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>

#define size 10000


//����������
long long binaryPow(int base, int p) {
	long long ans = 1, tmp = base;//�ӵ�����ʼ�ˣ���ͣ�Գ�
	while (p != 0) {//ָ������0
		if (p & 1) {
			ans = (ans*tmp);
		}
		tmp = (tmp*tmp);//�Գ�
		p = p >> 1;//������һλ
	}
	return ans;
}

//����GF(p)ȫ��Ԫ��
int  GF_structure(int p) {
	printf("���GF(%d)�����е�Ԫ�أ�\n",p);
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

//����GF(2^n)ȫ��Ԫ�أ�ʮ���ƣ�
int  GF2_structure(int n) {

	int array[size] = { 0 };
	printf("���GF(2^%d)�����е�Ԫ�أ�ʮ���ƣ���\n", n);
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


//����GF(2^n)ȫ��Ԫ�أ������ƣ�
int  GF2_structure_bin(int n) {
	printf("���GF(2^%d)�����е�Ԫ�أ������ƣ���\n", n);
	int array[size] = { 0 };
	char str[size];
	int i = 1;
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		array[i] = i;
	}
	for (i = 0; i < binaryPow(2, n); ++i)
	{
		_itoa_s(array[i], str, 2);//itoa��������ֵת��Ϊ�ַ�����ͨ���涨ת������ʵ��
		printf("%3s ", str);
	}
	printf("\n");
	return 0;

}

//������תʮ����
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




//ʮ����תn����
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

//ʮ����תn���Ƶ�ʵ��
void MToB_implement() {

	void MToB(unsigned long long m, int n, char s[]);
	unsigned long long m;
	char s[80] = { 0 };
	int n;
	printf("������ʮ��������");
	scanf_s("%llu", &m);
	printf("��������Ҫת���Ľ�����p��");
	scanf_s(" %d", &n);
	printf("���Ϊ��");
	MToB(m, n, s);
	puts(s);

}

/* ����ch�ַ���sign�����е���� 
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

/* ʮ��������ת��Ϊʮ������ 
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

//ʮ��������ת��Ϊʮ������
int hexToDec(char a[])
{
	int n = strlen(a);//�ж��ַ����ĳ��Ⱥ���
	int i, j = 0, num = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 'A')
			num += 10 * pow(16, n - i - 1); //pow() ���������� x �� y �η���ֵ��
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



//GF(p)����Ԫ�����㷨
void GF_generator_build() {
	int base, p, i;
	int table[size];
	int arc_table[size];
	int inverse_table[size];
	printf("����������Ԫ��");
	scanf_s("%d", &base);
	printf("������p��");
	scanf_s("%d", &p);
	GF_structure(p);
	//����
	table[0] = 1;//g^0
	for (i = 1; i < p - 1; ++i)//����ԪΪbase
	{
		table[i] = binaryPow(base, i) % p;
	}
	//����
	for (i = 0; i < p - 1; ++i) {
		arc_table[table[i]] = i;
	}
	//��Ԫ��
	for (i = 1; i < p - 1; ++i)//0û����Ԫ�����Դ�1��ʼ
	{
		int k = i;
		k = p - 1 - k;
		inverse_table[i] = binaryPow(base, k) % p;
	}
	//�����������Ԫ����
	printf("����Ԫ���ݴ�:\n");
	for (i = 0; i < p - 1; i++) {
		printf("%4d ", i);
	}
	printf("\n");
	//�������g^p-1
	printf("g^p-1��ֵ:\n");
	for (i = 0; i < p - 1; i++) {
		printf("%4d ", table[i]);
	}
	printf("\n");

	//�����������Ԫ����Ԫ
	printf("����Ԫ����Ԫg^(p-1-n):\n");
	printf("     ");
	for (i = 1; i < p - 1; i++) {
		printf("%4d ", inverse_table[i]);
	}
	printf("\n");

	printf("������λ������\n");
	int a, b;
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	printf("%d", table[(arc_table[a] + arc_table[b]) % (p - 1)]);
}

//GF(2^n)����Ԫ�����㷨
void GF2_generator_build() {

	int i, a, b, n;
	int table[size];
	int arc_table[size];
	int inverse_table[size];

	int hex01;//����ʮ��������
	int hex02;

	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);

	scanf_s("%x", &hex01);
	scanf_s("%x", &hex02);

	//����
	table[0] = 1;//g^0
	for (i = 1; i < binaryPow(2, n) - 1; ++i)
	{
		//������m_table[i] = m_table[i-1] * (x + 1)�ļ�д��ʽ
		table[i] = (table[i - 1] << 1) ^ table[i - 1];

		//���ָ���Ѿ�����n����Ҫģ��m(x)
		if (table[i] & hex01)//��ʮ�����Ƶ���ʽ����
		{
			table[i] ^= hex02;//x^2 * f(x) = x*[x*f(x)]
		}
	}
	//����
	for (i = 0; i < binaryPow(2, n) - 1; ++i) {
		arc_table[table[i]] = i;
	}
	//��Ԫ��
	for (i = 1; i < binaryPow(2, n); ++i)//0û����Ԫ�����Դ�1��ʼ
	{
		int k = arc_table[i];
		k = binaryPow(2, n) - 1 - k;
		k %= binaryPow(2, n) - 1;//m_table��ȡֵ��ΧΪ [0, 254]
		inverse_table[i] = table[k];
	}


	printf("%d * %d = %d\n", a, b, table[(arc_table[a] + arc_table[b]) % (binaryPow(2, n) - 1)]);
	printf("%d / %d = %d\n", a, b, table[(arc_table[a] + arc_table[inverse_table[b]]) % (binaryPow(2, n) - 1)]);

}