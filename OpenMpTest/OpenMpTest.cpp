#include <stdio.h>
#include <omp.h>
#include "stdafx.h"

int main() {
#pragma omp parallel
	{
		printf("Hello World %d\n", _OPENMP);
	}
	return 0;
}