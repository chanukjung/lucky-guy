#include "def.h"  //<-def가 맨위로 가야되요.
#include <stdio.h>
#include "student.h"
#include "stdmenu.h"
void stFileWrite(adultstudent st)
{
	FILE* fpw = fopen("AAA.bin", "ab");    //<-내가 만들고자하는 FILE의포인트   fopen: fileopen, fp:filepoint
	if (fpw == NULL) {                  //<-NULL이 아니면 탈출!
		printf("파일을 생성할 수가 없습니다. \n");
		return;                    //<-함수종료, void니까 return만.
	}
	fwrite(&st, sizeof(adultstudent), 1, fpw);     //<-  st라는 주소에 sizeof이라는 것을 한덩어리만큼 열겠다.
	fclose(fpw);                                   //<-  이 파일에 대한 권한을 반환한다.
}

void stFileRead()
{
	FILE* fpr = fopen("AAA.bin", "rb");
	if (fpr == NULL) {
		printf("파일을 읽을 수 없습니다. \n");
		return;                  //<-void이니까 그냥 return만
	}
	printf("================\n");
	printf("학생 정보 파일에서 읽기\n");
	printf("================\n");
	adultstudent stempty = { 0 };  //<-빈 구조체 (파일에서 구조체 크기만큼 정보를 읽어서 담는 구조체 변수.)
	int num = 1;
	while (fread(&stempty, sizeof(adultstudent), 1, fpr) == 1) { //<-한덩어리를 제대로 읽었을때 1값을 리턴한다(void값이아니기때문에 return값을 반환시키라)
		printf("번호: %d\n", num);
		printf("이름: %s \n", stempty.name);   //<-위에stempty라고주소썼다.
		printf("성별: %c \n", stempty.gen);
		printf("학번: %d \n", stempty.hok);
		printf("1점수: %d\n", stempty.jum1);
		printf("2점수: %d\n", stempty.jum2);
		printf("3점수: %d\n", stempty.jum3);
		printf("평균: %f\n", stempty.avg);
		printf("==================\n");
		num++;                    //<-증가시키서 또 1이되면 참이어서 동작하고 더이상 동작할게 없어지면 while문 탈출
	}
	fclose(fpr);
}
void stFileDelAll()
{
	FILE* fpw = fopen("AAA.bin", "wb");    //<-내가 만들고자하는 FILE의포인트   fopen: fileopen, fp:filepoint
	if (fpw == NULL) {                  //<-NULL이 아니면 탈출!
		printf("파일을 생성할 수가 없습니다. \n");
		return;                    //<-함수종료, void니까 return만.
	}
	fclose(fpw);                                   //<-  이 파일에 대한 권한을 반환한다.
}