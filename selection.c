#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996) //FILE함수로 오픈 할 시 나오는 오류코드 무시


#define SIZE 10000 //샘플 10000개를 위한 사이즈 


void selectionSort(int* A, int n) { //선택 정렬 코드
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
	
	FILE* fp1;  //파일 1과 2 선언
	FILE* fp2;
	int* testArr;

	fp1 = fopen("input.txt", "a+"); //input txt 파일 생성 후 읽고 덮어쓰기 위한 코드
	testArr = (int*)malloc(sizeof(int) * SIZE);

	srand(time(NULL));


	for (int i = 0; i < SIZE; i++) {
		testArr[i] = (int)(((double)rand() / (double)RAND_MAX * 10000 + 1)); //랜덤 넘버 만개 생성 코드

	}
	
	

	printf("**선택 정렬 테스트\n\n");

	printf("*정렬 전\n\n");
	for (int i = 0; i < SIZE; i++){
		printf(" %d", testArr[i]);
		fprintf(fp1, " %d", testArr[i]); //input 파일에 입력
		}
	fclose(fp1);

	fp2 = fopen("output.txt", "a+"); //파일 닫기

	printf("\n\n 정렬 후의 리스트\n\n");

	selectionSort(testArr, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", testArr[i]);
		fprintf(fp2, " %d", testArr[i]); //output 파일 입력
	}
	fclose(fp2);
	free(testArr); //상황 초기화

	return 0;
}

