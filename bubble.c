#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)  //FILE�Լ��� ���� �� �� ������ �����ڵ� ����

#define SIZE 10000 //���� 10000���� ���� ������ 

void bubbleSort(int* A, int n) { //�������� �ڵ�
	int i, j, temp;
	for (i = n - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			/*compare neighboring elements*/
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

int main(void) {

	FILE* fp3; //���� 3�� 4 ����
	FILE* fp4;
	int* testArr2;

	fp3 = fopen("inputb.txt", "a+"); //�������Ŀ� input���� ����
	testArr2 = (int*)malloc(sizeof(int) * SIZE);

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		testArr2[i] = (int)(((double)rand() / (double)RAND_MAX * 10000 + 1));
	}

	printf("\n\n** ���� ���� �׽�Ʈ\n\n");

	printf("**���� ��\n\n");
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr2[i]);
		fprintf(fp3, " %d", testArr2[i]); //�������Ŀ� ���Ͽ� �Է�
	}
	fclose(fp3); //���� �ݱ�

	fp4 = fopen("outputb.txt", "a+"); //�������Ŀ� output���� ����

	printf("\n\n ���� ���� ����Ʈ\n\n");

	bubbleSort(testArr2, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr2[i]);
		fprintf(fp4, " %d", testArr2[i]); //output���Ͽ� �Է�
	}

	fclose(fp4); //���� �ݱ�
	free(testArr2); //�� �ʱ�ȭ

	return 0;

}

