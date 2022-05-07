
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include"ecc.h"

int xy[22];

int geneLen;


ECCPoint eccPoint;
GENE_SET geneSet[100];

Point mul(Point p1, Point p2);
Point add_two_points(Point p1, Point p2);

//判断平方根是否为整数 
int int_sqrt(int s)
{
	int temp;
	temp = (int)sqrt(s);//转为整型 
	if (temp*temp == s)
	{
		return temp;
	}
	else {
		return -1;
	}
}
//取模函数
int mod_p(int s)
{
	int i;	//保存s/p的倍数
	int result;	//模运算的结果
	i = s / N;
	result = s - i * N;
	if (result >= 0)
	{
		return result;
	}
	else
	{
		return result + N;
	}
}
//打印点集 输出全部的点
void print()
{
	int i;
	int len = eccPoint.len;
	printf("\n该椭圆曲线上共有%d个点(包含无穷远点)\n", len + 1);
	for (i = 0; i < len; i++)
	{
		if (i % 8 == 0)
		{
			printf("\n");
		}
		printf("(%2d,%2d)\t", eccPoint.p[i].x, eccPoint.p[i].y);
	}
	printf("\n");
}
//task1:求出椭圆曲线上所有点 
void get_all_points()
{
	int i = 0;
	int j = 0;
	int s, y = 0;
	int n = 0, q = 0;
	int modsqrt = 0;
	int flag = 0;
	if (a1 * a1 * a1 + b1 * b1 + 4 != 0)
	{
		for (i = 0; i <= N - 1; i++)
		{
			flag = 0;
			n = 1;
			y = 0;
			s = i * i * i + a1 * i + b1;
			while (s < 0)
			{
				s += N;
			}
			s = mod_p(s);
			modsqrt = int_sqrt(s);
			if (modsqrt != -1)
			{
				flag = 1;
				y = modsqrt;
			}
			else {
				while (n <= N - 1)
				{
					q = s + n * N;
					modsqrt = int_sqrt(q);
					if (modsqrt != -1)
					{
						y = modsqrt;
						flag = 1;
						break;
					}
					flag = 0;
					n++;
				}
			}
			if (flag == 1)
			{
				eccPoint.p[j].x = i;
				eccPoint.p[j].y = y;
				j++;
				if (y != 0)
				{
					eccPoint.p[j].x = i;
					eccPoint.p[j].y = (N - y) % N;
					j++;
				}
			}
		}
		eccPoint.len = j;//点集个数 
		print(); //打印点集 
	}
}

//task3:求生成元以及阶
void get_generetor_class()
{
	int i, j = 0;
	int count = 1;
	Point p1, p2;
	get_all_points();
	printf("\n------------------------------输出生成元以及阶：-----------------------------\n");
	for (i = 0; i < eccPoint.len; i++)
	{
		count = 1;
		p1.x = p2.x = eccPoint.p[i].x;
		p1.y = p2.y = eccPoint.p[i].y;
		while (1)
		{
			p2 = add_two_points(p1, p2);
			if (p2.x == -1 && p2.y == -1)
			{
				break;
			}
			count++;
			if (p2.x == p1.x)
			{
				break;
			}
		}
		count++;
		if (count <= eccPoint.len + 1)
		{
			geneSet[j].p.x = p1.x;
			geneSet[j].p.y = p1.y;
			geneSet[j].p_class = count;
			printf("(%d,%d)--->>%d\t", geneSet[j].p.x, geneSet[j].p.y, geneSet[j].p_class);
			j++;
			if (j % 6 == 0) {
				printf("\n");
			}
		}
		geneLen = j;
	}
}

// 求 a mod b 的逆元
void exGcd(int a, int b) {
	if (b == 0) {
		xy[0] = 1;
		xy[1] = 0;
	}
	else {
		exGcd(b, a % b);
		int x = xy[0];
		xy[0] = xy[1];
		xy[1] = x - (a / b) * xy[1];
	}

}
int calculate3(int y, int k, int p) {

	int l = 1;
	for (int i = 0; i < k; i++) {
		l = l * y;
		l = l % p;
	}

	return l;
}

Point eccmutiply(int n, Point p) {
	int a, b, l, k, m;
	a = p.x;
	b = p.y;
	for (int i = 0; i < n - 1; i++) {

		if (a == p.x&&b == p.y) {
			exGcd(2 * p.y, N);
			k = xy[0];
			if (k < 0)k = k + N;
			printf("逆元=%d\n", k);
			l = (3 * p.x*p.x + A)*k;
			l = calculate3(l, 1, N);
			if (l < 0) {
				l = l + N;
			}
		}
		else {
			exGcd(a - p.x + N, N);
			k = xy[0];
			if (k < 0)k = k + N;
			//printf("else逆元=%d\n", k);
			l = (b - p.y)*k;
			l = calculate3(l, 1, N);
			if (l < 0) {
				l = l + N;
			}
			//printf("l=%d\n", l);
		}
		m = p.x;
		a = l * l - a - p.x;
		a = calculate3(a, 1, N);
		if (a < 0) {
			a = a + N;
		}
		b = l * (m - a) - p.y;
		b = calculate3(b, 1, N);

		if (b < 0) {
			b = b + N;
		}
		//printf("%d(a,b)=(%d,%d)\n", i + 2, a, b);
		//if(a==4&&b==5)break;
	}
	Point p3;
	p3.x = a;
	p3.y = b;
	return p3;
}

//点乘运算
Point mul(Point p1, Point p2) {
	int k, l;
	exGcd(p2.x - p1.x + N, N);
	k = xy[0];
	if (k < 0)k = k + N;
	//printf("else逆元=%d\n",k);
	l = (p2.y - p1.y)*k;
	l = calculate3(l, 1, N);
	if (l < 0) {
		l = l + N;
	}
	//printf("l=%d\n",l);	
	Point p3;
	p3.x = l * l - p1.x - p2.x;
	p3.x = calculate3(p3.x, 1, N);
	if (p3.x < 0)p3.x = p3.x + N;

	p3.y = l * (p1.x - p3.x) - p1.y;
	p3.y = calculate3(p3.y, 1, N);
	if (p3.y < 0)p3.y = p3.y + N;
	return p3;
}

//求b关于n的逆元 
int inverse(int n, int b)
{
	int q, r, r1 = n, r2 = b, t, t1 = 0, t2 = 1, i = 1;
	while (r2 > 0)
	{
		q = r1 / r2;
		r = r1 % r2;
		r1 = r2;
		r2 = r;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	if (t1 >= 0)
		return t1 % n;
	else {
		while ((t1 + i * n) < 0)
			i++;
		return t1 + i * n;
	}
}


//两点的加法运算 
Point add_two_points(Point p1, Point p2)
{
	long t;
	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;
	int tx, ty;
	int x3, y3;
	int flag = 0;
	//求 
	if ((x2 == x1) && (y2 == y1))
	{
		//相同点相加 
		if (y1 == 0)
		{
			flag = 1;
		}
		else {
			t = (3 * x1*x1 + a1)*inverse(N, 2 * y1) % N;
		}
		//printf("inverse(p,2*y1)=%d\n",inverse(p,2*y1));
	}
	else {
		//不同点相加
		ty = y2 - y1;
		tx = x2 - x1;
		while (ty < 0)
		{
			ty += N;
		}
		while (tx < 0)
		{
			tx += N;
		}
		if (tx == 0 && ty != 0)
		{
			flag = 1;
		}
		else {
			t = ty * inverse(N, tx) % N;
		}
	}
	if (flag == 1)
	{
		p2.x = -1;
		p2.y = -1;
	}
	else {
		x3 = (t*t - x1 - x2) % N;
		y3 = (t*(x1 - x3) - y1) % N;
		//使结果在有限域GF(P)上 
		while (x3 < 0)
		{
			x3 += N;
		}
		while (y3 < 0)
		{
			y3 += N;
		}
		p2.x = x3;
		p2.y = y3;
	}
	return p2;

}
//task2:倍点运算的递归算法
Point timesPiont(int k, Point p0)
{
	if (k == 1) {
		return p0;
	}
	else if (k == 2) {
		return add_two_points(p0, p0);
	}
	else {
		return add_two_points(p0, timesPiont(k - 1, p0));
	}
}
