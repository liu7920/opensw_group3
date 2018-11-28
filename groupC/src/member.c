#include "common.h"
#include "menu.h"
#include "dbconn.h"

void member_menu(){

	int i;
	int q,w;
	time_t now;
	struct tm *d;
	int hour,min,sec,hour1,min1,sec1;
	char str[20];
	char s1[20];
	char rank[10][100];
	char _rank[10][50];
	char _temp[50];
	char _temp1[100];
	int temp,cu=0;

	while(1){
		printf("***** 공지사항 ******\n");
		print_Notice();
		printf("*********************\n");

		printf("1.게임 시작 2.랭크 보기 3.회원 정보 수정 4.회원 탈퇴 5.로그아웃 \n");
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
			
			//game();
			sleep(10);
			
        	now=time(NULL);
       	d=localtime(&now);
			hour1=d->tm_hour;
			min1=d->tm_min;
			sec1=d->tm_sec;
			printf("완료 시간 : %d시 %d분 %d초\n",hour1,min1,sec1);
			printf("%d_%d_%d_%d_%d_%d\n",hour1*3600,min1*60,sec1,hour*3600,min*60,sec);
			printf("경과 시간 : %d초\n",((hour1*3600)+(min1*60)+sec1) - ((hour*3600)+(min*60)+sec));
			temp=((hour1*3600)+(min1*60)+sec1) - ((hour*3600)+(min*60)+sec);
			sprintf(s1,"%d",temp); // int형에서 char문자열 변환
			user_ClTime_Insert(s1);

		}
		else if(i==2){
			cu=0;
			printf(">>랭크 보기<<\n");
			
			for(q=0;q<10;q++){
				if(/* db에서 불러올 데이터가 없을 경우 */){
					break;	
				}
				rank[i] = /* db의 데이터 아이디 + 시간  */
				_rank[i] /* db의 시간만 넣기*/
				cu++;
			}
			
			for(q=0;q<cu;q++){
				for(w=1;w<cu;w++){
					if(strcmp(_rank[i],_rank[o]) > 0 ){
						//시간만 정렬
						strcpy(_temp,_rank[i]);
						strcpy(_rank[i],_rank[w]);
						strcpy(_rank[w],_temp);
						//아이디 + 시간 들어가있는것 정렬
						strcpy(_temp1,rank[i]);
						strcpy(rank[i],rank[w]);
						strcpy(rank[w],_temp1);
					}
				}
			}
			printf("***** 랭킹 *****\n");
			for(i=0;i<cu;i++){
				printf("%s\n",rank[i]);
			}
			
		}
		else if(i==3){
			printf(">>회원 정보 수정<<\n");
			printf("비밀번호  입력  : ");
			scanf("%s",str);
			modifiy_user(str);

		}
		else if(i==4){
			printf(">>회원 탈퇴<<\n");
			printf("%s 회원님 비밀번호 입력 : ", login_id);
			scanf("%s",str);
			leave_user(str);
			break;
		}
		else if(i==5){
			printf(">>로그아웃<<\n");
			break;
		}

	}
	return ;
}
