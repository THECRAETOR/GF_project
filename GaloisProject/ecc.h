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


//�ж�ƽ�����Ƿ�Ϊ���� 
int int_sqrt(int s);
//ȡģ����
int mod_p(int s);
// ��ӡ�㼯
void print();
//task1:�����Բ���������е� 
void get_all_points();
//task2:��������ĵݹ��㷨
Point timesPiont(int k, Point p0);
//task3:������Ԫ�Լ���
void get_generetor_class();
// �� a mod b ����Ԫ
void exGcd(int a, int b);
int calculate3(int y, int k, int p);
Point eccmutiply(int n, Point p);
Point mul(Point p1, Point p2);
int inverse(int n, int b);
//����ļӷ����� 
Point add_two_points(Point p1, Point p2);
