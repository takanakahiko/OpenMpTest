#include <stdio.h>
#include <omp.h>
#include "stdafx.h"

int static_i = 0; //thread間で共有される
int main() {
	int dynamic_i = 0; //thread間で共有される
#pragma omp parallel
	{
		int local_i = 0; //thread毎に区別される
		for (int i = 0; i < 100000; i++) {
			static_i++; //ロード後に足して代入する際にラグがあり，ハザードが発生
			dynamic_i++; //同様
			local_i++;
		}
		printf("static_i=%d, dynamic_i=%d, local_i=%d \n", static_i, dynamic_i, local_i);
	}
	printf("static_i=%d, dynamic_i=%d \n", static_i, dynamic_i);
	return 0;
}