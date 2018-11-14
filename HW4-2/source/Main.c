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
	printf("排序前:");
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
		//向右進行氣泡排序
		for (i = left;i < right;i++) {
			if (number[i] > number[i + 1]) {
				SWAP(number[i], number[i + 1]);
				shift = i;
				flag = 1;
			}
		}
		right = shift;
		if (flag == 0) break;
		printf("\n往右排序:");
		for (i = 0;i < MAX;i++) {
			printf("%d ", number[i]);
		}
		flag = 0;
		//向左進行氣泡排序
		for (i = right;i > left;i--) {
			if (number[i] < number[i - 1]) {
				SWAP(number[i], number[i - 1]);
				shift = i;
				flag = 1;
			}
		}
		left = shift;
		if (flag == 0) break;
		printf("\n向左排序:");
		for (i = 0;i < MAX;i++) {
			printf("%d ", number[i]);
		}
	}

}