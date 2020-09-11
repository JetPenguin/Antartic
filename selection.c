#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996) //FILE�Լ��� ���� �� �� ������ �����ڵ� ����


#define SIZE 10000 //���� 10000���� ���� ������ 


void selectionSort(int* A, int n) { //���� ���� �ڵ�
	int max, i, temp;
	while (n > 0) {
		max = 0;
		for (i = 1; i < n; i++)
			if (A[i] > A[max])
				max = i;

		/*swap(A[n-1], A[max[*/
		temp = A[n - 1];
		A[n - 1] = A[max];
		A[max] = temp;
		n--;
	}
}

int main(void) {
	
	FILE* fp1;  //���� 1�� 2 ����
	FILE* fp2;
	int* testArr;

	fp1 = fopen("input.txt", "a+"); //input txt ���� ���� �� �а� ����� ���� �ڵ�
	testArr = (int*)malloc(sizeof(int) * SIZE);

	srand(time(NULL));


	for (int i = 0; i < SIZE; i++) {
		testArr[i] = (int)(((double)rand() / (double)RAND_MAX * 10000 + 1)); //���� �ѹ� ���� ���� �ڵ�

	}
	
	

	printf("**���� ���� �׽�Ʈ\n\n");

	printf("*���� ��\n\n");
	for (int i = 0; i < SIZE; i++){
		printf(" %d", testArr[i]);
		fprintf(fp1, " %d", testArr[i]); //input ���Ͽ� �Է�
		}
	fclose(fp1);

	fp2 = fopen("output.txt", "a+"); //���� �ݱ�

	printf("\n\n ���� ���� ����Ʈ\n\n");

	selectionSort(testArr, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr[i]);
		fprintf(fp2, " %d", testArr[i]); //output ���� �Է�
	}
	fclose(fp2);
	free(testArr); //��Ȳ �ʱ�ȭ

	return 0;
}

