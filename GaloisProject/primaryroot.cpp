#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include <math.h> 
#include<stdlib.h>


#define size 10000
#define ll long long
int in = 0;

//�ж�����
bool juge_ifprime(long long m) {		//�ж������m�Ƿ�Ϊ������ 
	for (int i = 2; i <= m / 2; i++) {
		if (m%i == 0)
			return false;		//����������Ϊ1����false 
	}
	return true;				//���򷵻�true
}

//���������m�������ֽ�ʽ
void count_EulerNot(int m, int* array) {
	int temp1 = m;
	if (int(juge_ifprime(m)) == 1) {		//��������mΪ�������������һ֮������ 
		temp1 -= 1;
	}
	int number = 0;						//���������������ָ�� 
	int temp = temp1;
	while (temp != 1) {
		for (int i = 2; i <= temp; i++) {
			if (int(juge_ifprime(i)) == 1 && temp%i == 0 && i != m)
			{
				array[number++] = i;
				temp /= i;				//�ҵ�һ��������(��i=m)֮��temp����i�ı�temp��ֵʹ����������ѭ��
			}
		}
	}
}

//����ŷ������
int count_Euler(int *array, int m) {
	int Eulernumber;
	if (int(juge_ifprime(m)) == 1) {
		return m - 1;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (array[i] != -1) {
				Eulernumber = m / array[i] * (array[i] - 1);
			}
		}
		return Eulernumber;
	}
}

//�ж������Ƿ���,�����ǵ����Լ���Ƿ�Ϊ1
bool juge_HUSU(int a, int m) {
	for (int i = 2; i <= a; i++) {
		if (a%i == 0 && m%i == 0) {
			return false;
		}
	}
	return true;
}

//����m���ص���������ĺ���,�������Сԭ��(�ڶ��ε��õ�ʱ������Ǻ�ŷ���������ص�����)
void count_mHUSU(int *brrby, int m) {
	int number = 0;					//�������洢brrby�����int��ָ�� 
	int temp = m;
	for (int i = 1; i < temp; i++) {
		if (juge_HUSU(i, temp) != 0 && number < size) {
			brrby[number++] = i;
		}
	}
}

//��brrby������ѡһ����m���ص�����������temp�η��Ƿ�mod m��m-1�ж����Ƿ�Ϊ��Сԭ��
bool juge_MinPrimitiveRoot(int temp, int brrby, int m) {
	int number = 1;			//����һ��number���ڴ�Ŵ����temp��ֵ 
	for (int i = 0; i < temp; i++) {
		number *= brrby;
		number = number % m;
		if (number == 1)
			return false;
	}
	if (number == m - 1)
		return true;
	else
		return false;
}

//������Сԭ��,����arrayΪ����������,brrbyΪ��ŷ���������ص���������
int count_MinPrimitiveRoot(int m, int *array, int *brrby, int Eulernumber) {
	int temp;
	for (int i = 0; i < size; i++) {
		if (array[i] != -1) {
			for (int j = 0; j < size; j++) {
				temp = Eulernumber / array[i];	//ŷ���������������ĳ���q
				if (int(juge_MinPrimitiveRoot(temp, brrby[j], m)) == 0) {

				}
				if (int(juge_MinPrimitiveRoot(temp, brrby[j], m)) == 1 && brrby[j] != -1) {
					return brrby[j];
				}
			}
		}
	}
	return -1;
}

//��array����Ӵ�С����
void Sort(int* array) {
	int temp;				//��ʱ�������ڽ�������Ԫ�� 
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] != -1 && array[j] != -1 && array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

//���������������ͬԪ���޳� 
void Delete_same(int *array) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] == array[j]) {
				array[j] = -1;
			}
		}
	}
}

//����Ĳ���Ϊ��Сԭ������m���ص�����drrdy������������е�ԭ��������crrcy������
void ALL_primeroot(int minprimerroot, int *drrdy, int *crrcy, int m) {
	int temp = 1;
	for (int i = 0; i < size; i++) {
		if (drrdy[i] != -1) {
			for (int j = 0; j < drrdy[i]; j++) {
				temp *= minprimerroot;
				temp %= m;
			}
			crrcy[i] = temp;
			temp = 1;
		}
	}
}

//����GF(p)����Ԫ(ԭ��)�ĸ���
void Generator_sum() {
	int m = 0;
	printf("����p��ֵ��");
	scanf_s("%d", &m);
	int array[size];					//���ڴ��������������array 
	int brrby[size];					//���ڴ����m���ص����ֵ����� 
	int crrcy[size];					//���ڴ��m������ԭ�������� 
	int drrdy[size];
	for (int i = 0; i < size; i++) {			//��������ȫ�����ݳ�ʼ��Ϊ-1,�������� 
		array[i] = -1;
		brrby[i] = -1;
		crrcy[i] = -1;
		drrdy[i] = -1;
	}
	count_EulerNot(m, array);		//��ʱarray�����ﲻΪ-1�ľ���m���������ֽ� 
	Delete_same(array);				//�޳�array��������ͬ����
	int Eulernumber = count_Euler(array, m);	//����m��ŷ������ 
	count_EulerNot(Eulernumber, array);		//��ʱarray�����ﲻΪ-1�ľ���m���������ֽ� 
	Delete_same(array);				//�޳�array��������ͬ����
	Sort(array);					//������array���дӴ�С������ 
	count_mHUSU(brrby, m);			//����m���ص�Ԫ�أ�����brrby��
	int minprimerroot = count_MinPrimitiveRoot(m, array, brrby, Eulernumber);//����Сԭ�� 
	if (minprimerroot == -1) {
		printf("����û��ԭ����\n");
	}
	printf("��Сԭ��Ϊ��%d\n", minprimerroot);	//��ӡ��Сԭ��
	count_mHUSU(drrdy, Eulernumber);			//����Eulernumber���ص�Ԫ�أ�����brrby��
	ALL_primeroot(minprimerroot, drrdy, crrcy, m);	//֪����Сԭ��֮����б��������������ԭ�� 
	Sort(crrcy);					//������crrcy���дӴ�С������ 
	int primernumber = 0;				//�������ڼ���ԭ�������ı��� 
	for (int i = 0; i < size; i++) {		//��brrby������б������ҳ��ж��ٸ�ԭ�� 
		if (drrdy[i] != -1) {
			primernumber++;
		}
	}
	//printf("ŷ��������ֵΪ��%d\n",Eulernumber);	//���ŷ��������ֵ 
	printf("һ����%d��ԭ����\nԭ���Ӵ�С����Ϊ��", primernumber);//���ԭ���ĸ��� 
	for (int i = 0; i < size; i++) {		//��ӡ����crrcy������� 
		if (crrcy[i] != -1) {
			printf("%5d", crrcy[i]);
		}
	}
	printf("\n");
}
