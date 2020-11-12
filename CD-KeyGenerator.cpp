#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	char ESI[14];
	int EAX, EDX, control;
	do {
		printf("1. CD-key 생성\n");
		printf("2. CD-key 확인\n");
		printf("else. 종료\n");
		printf("작업을 선택하십시오. : ");
		scanf_s("%d", &control);
		switch (control) {
		case 1:
			srand((unsigned int)time(NULL));
			EAX = 3;
			for (EDX = 0; EDX < 12; EDX++) {
				ESI[EDX] = rand() % 10 + 0x30;
				EAX += (ESI[EDX] - 0x30) ^ (EAX * 2);
				printf("%c", ESI[EDX]);
			}
			ESI[EDX] = EAX % 10 + 0x30;
			ESI[EDX + 1] = 0;
			printf("%c\n\n", ESI[EDX]);
			break;
		case 2:
			printf("CD-key: ");
			scanf_s("%s", ESI, sizeof(ESI));
			EAX = 3;
			for (EDX = 0; EDX < 12; EDX++)
				EAX += (ESI[EDX] - 0x30) ^ (EAX * 2);
			if (ESI[EDX] == EAX % 10 + 0x30)
				printf("Valid CD-Key.\n\n");
			else
				printf("Invalid CD-Key.\n\n");
			break;
		}
	} while (control == 1 || control == 2);
}