#pragma   once   

#define N 23
#define A 1
//#define M 29
#define a1 1
#define b1 4

typedef struct point {
	int x;
	int y;
}Point;
typedef struct ecc {
	struct point p[100];
	int len;
}ECCPoint;
typedef struct generator {
	Point p;
	int p_class;
}GENE_SET;


//判断平方根是否为整数 
int int_sqrt(int s);
//取模函数
int mod_p(int s);
// 打印点集
void print();
//task1:求出椭圆曲线上所有点 
void get_all_points();
//task2:倍点运算的递归算法
Point timesPiont(int k, Point p0);
//task3:求生成元以及阶
void get_generetor_class();
// 求 a mod b 的逆元
void exGcd(int a, int b);
int calculate3(int y, int k, int p);
Point eccmutiply(int n, Point p);
Point mul(Point p1, Point p2);
int inverse(int n, int b);
//两点的加法运算 
Point add_two_points(Point p1, Point p2);
