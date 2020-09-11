#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

#define SIZE 10000

void insertionSort(int arr[], int n) //삽입정렬 코드
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(void) {

	FILE* fp5;
	FILE* fp6;
	int* testArr3;

	fp5 = fopen("inputI.txt", "a+");
	testArr3 = (int*)malloc(sizeof(int) * SIZE);

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		testArr3[i] = (int)(((double)rand() / (double)RAND_MAX * 10000 + 1));

	}


	printf("\n\n** 삽입 정렬 테스트\n\n");

	printf("*정렬 전 \n\n");
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr3[i]);
		fprintf(fp5, " %d", testArr3[i]);
	}
	fclose(fp5);

	fp6 = fopen("outputI.txt", "a+");

	printf("\n\n 정렬 후의 리스트\n\n");

	insertionSort(testArr3, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr3[i]);
		fprintf(fp6, " %d", testArr3[i]);
	}

	fclose(fp6);
	free(testArr3);

	return 0;
}