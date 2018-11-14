#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y){int t;t=x;x=y;y=t;}

void shakersort(int[]);

int main(void) {
	int number[MAX] = {0};
	int i;
	srand(time(NULL));
	printf("�Ƨǫe:");
	for (i = 0;i < MAX;i++) {
		number[i] = rand() % 100;
		printf("%d ", number[i]);
	}
	shakersort(number);
	printf("\n");
	system("pause");
	return 0;
}
void shakersort(int number[]) {
	int i, flag,left = 0,right = MAX-1,shift = 0;
	while (left < right) {
		flag = 0;
		//�V�k�i���w�Ƨ�
		for (i = left;i < right;i++) {
			if (number[i] > number[i + 1]) {
				SWAP(number[i], number[i + 1]);
				shift = i;
				flag = 1;
			}
		}
		right = shift;
		if (flag == 0) break;
		printf("\n���k�Ƨ�:");
		for (i = 0;i < MAX;i++) {
			printf("%d ", number[i]);
		}
		flag = 0;
		//�V���i���w�Ƨ�
		for (i = right;i > left;i--) {
			if (number[i] < number[i - 1]) {
				SWAP(number[i], number[i - 1]);
				shift = i;
				flag = 1;
			}
		}
		left = shift;
		if (flag == 0) break;
		printf("\n�V���Ƨ�:");
		for (i = 0;i < MAX;i++) {
			printf("%d ", number[i]);
		}
	}

}