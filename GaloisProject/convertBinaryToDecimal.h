#pragma once

#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000

typedef struct {
	int len;
	char value[MAX_LEN];
} TBigInt, *pBigInt;

void AddBit(pBigInt s, char BitValue);
void OutputBigInt(pBigInt s);