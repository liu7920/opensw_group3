#include "common.h"

void member_menu(){

	int i;
	time_t now;
	struct tm *d;
	int hour,min,sec,hour1,min1,sec1;	

	while(1){
		printf("1.게임 시작 2.랭크 보기 3.회원 정보 수정 4.로그아웃 \n");
		printf("입력 : ");
		scanf("%d",&i);
		if(i==1){

        	now=time(NULL);
       	d=localtime(&now);
			printf(">>게임 시작<<\n");
			hour=d->tm_hour;
			min=d->tm_min;
			sec=d->tm_sec;			
			printf("시작 시간 : %d시 %d분 %d초\n",hour,min,sec);
			
			game();

        	now=time(NULL);
       	d=localtime(&now);
			hour1=d->tm_hour;
			min1=d->tm_min;
			sec1=d->tm_sec;
			printf("완료 시간 : %d시 %d분 %d초\n",hour1,min1,sec1);
			printf("%d_%d_%d_%d_%d_%d\n",hour1*3600,min1*60,sec1,hour*3600,min*60,sec);
			printf("경과 시간 : %d초\n",((hour1*3600)+(min1*60)+sec1) - ((hour*3600)+(min*60)+sec));

		}
		else if(i==2){
			printf(">>랭크 보기<<\n");
		}
		else if(i==3){
			printf(">>회원 정보 수정<<\n");
		}
		else if(i==4){
			printf(">>로그아웃<<\n");
			break;
		}

	}

	return ;
}
