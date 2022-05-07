#include <stdio.h>
#include <string.h>
#include"convertBinaryToDecimal.h"
#define MAX_LEN 10000



void AddBit(pBigInt s, char BitValue) { //��һλ�� 0����1��
	int i;
	for (i = 0; i < s->len; i++)
		s->value[i] *= 2;
	s->value[0] += BitValue;
	for (i = 0; i < s->len; i++)
	{
		s->value[i + 1] += s->value[i] / 10;
		s->value[i] %= 10;
	}
	if (s->value[s->len]) s->len++;
}

void OutputBigInt(pBigInt s) { //�������������
	int i;
	if (s->len == 0) {
		puts("0");
	}
	else {
		for (i = s->len - 1; i >= 0; i--)
			putchar(s->value[i] + 48);
		putchar('\n');
	}
}
