#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)  //FILE함수로 오픈 할 시 나오는 오류코드 무시

#define SIZE 10000 //샘플 10000개를 위한 사이즈 

void bubbleSort(int* A, int n) { //버블정렬 코드
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

	FILE* fp3; //파일 3과 4 선언
	FILE* fp4;
	int* testArr2;

	fp3 = fopen("inputb.txt", "a+"); //버블정렬용 input파일 생성
	testArr2 = (int*)malloc(sizeof(int) * SIZE);

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		testArr2[i] = (int)(((double)rand() / (double)RAND_MAX * 10000 + 1));
	}

	printf("\n\n** 버블 정렬 테스트\n\n");

	printf("**정렬 전\n\n");
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr2[i]);
		fprintf(fp3, " %d", testArr2[i]); //버블정렬용 파일에 입력
	}
	fclose(fp3); //파일 닫기

	fp4 = fopen("outputb.txt", "a+"); //버블정렬용 output파일 생성

	printf("\n\n 정렬 후의 리스트\n\n");

	bubbleSort(testArr2, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr2[i]);
		fprintf(fp4, " %d", testArr2[i]); //output파일에 입력
	}

	fclose(fp4); //파일 닫기
	free(testArr2); //값 초기화

	return 0;

}

