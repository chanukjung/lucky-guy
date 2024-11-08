#include "def.h"  //<-def�� ������ ���ߵǿ�.
#include <stdio.h>
#include "student.h"
#include "stdmenu.h"
void stFileWrite(adultstudent st)
{
	FILE* fpw = fopen("AAA.bin", "ab");    //<-���� ��������ϴ� FILE������Ʈ   fopen: fileopen, fp:filepoint
	if (fpw == NULL) {                  //<-NULL�� �ƴϸ� Ż��!
		printf("������ ������ ���� �����ϴ�. \n");
		return;                    //<-�Լ�����, void�ϱ� return��.
	}
	fwrite(&st, sizeof(adultstudent), 1, fpw);     //<-  st��� �ּҿ� sizeof�̶�� ���� �ѵ����ŭ ���ڴ�.
	fclose(fpw);                                   //<-  �� ���Ͽ� ���� ������ ��ȯ�Ѵ�.
}

void stFileRead()
{
	FILE* fpr = fopen("AAA.bin", "rb");
	if (fpr == NULL) {
		printf("������ ���� �� �����ϴ�. \n");
		return;                  //<-void�̴ϱ� �׳� return��
	}
	printf("================\n");
	printf("�л� ���� ���Ͽ��� �б�\n");
	printf("================\n");
	adultstudent stempty = { 0 };  //<-�� ����ü (���Ͽ��� ����ü ũ�⸸ŭ ������ �о ��� ����ü ����.)
	int num = 1;
	while (fread(&stempty, sizeof(adultstudent), 1, fpr) == 1) { //<-�ѵ���� ����� �о����� 1���� �����Ѵ�(void���̾ƴϱ⶧���� return���� ��ȯ��Ű��)
		printf("��ȣ: %d\n", num);
		printf("�̸�: %s \n", stempty.name);   //<-����stempty����ּҽ��.
		printf("����: %c \n", stempty.gen);
		printf("�й�: %d \n", stempty.hok);
		printf("1����: %d\n", stempty.jum1);
		printf("2����: %d\n", stempty.jum2);
		printf("3����: %d\n", stempty.jum3);
		printf("���: %f\n", stempty.avg);
		printf("==================\n");
		num++;                    //<-������Ű�� �� 1�̵Ǹ� ���̾ �����ϰ� ���̻� �����Ұ� �������� while�� Ż��
	}
	fclose(fpr);
}
void stFileDelAll()
{
	FILE* fpw = fopen("AAA.bin", "wb");    //<-���� ��������ϴ� FILE������Ʈ   fopen: fileopen, fp:filepoint
	if (fpw == NULL) {                  //<-NULL�� �ƴϸ� Ż��!
		printf("������ ������ ���� �����ϴ�. \n");
		return;                    //<-�Լ�����, void�ϱ� return��.
	}
	fclose(fpw);                                   //<-  �� ���Ͽ� ���� ������ ��ȯ�Ѵ�.
}