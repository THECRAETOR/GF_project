#include <stdio.h>
#include <string.h>
#include"convertBinaryToDecimal.h"
#define MAX_LEN 10000



void AddBit(pBigInt s, char BitValue) { //加一位， 0或者1。
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

void OutputBigInt(pBigInt s) { //输出大整数类型
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
