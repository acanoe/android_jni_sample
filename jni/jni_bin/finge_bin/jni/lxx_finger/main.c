#include "Serial.h"
#include "finger_main.h"

#define CHAR_BUFFER_1          0x01
#define CHAR_BUFFER_2          0x02
#define CHAR_BUFFER_3          0x03
#define CHAR_BUFFER_4		   0x04
#define MODEL_BUFFER           0x05
#define FINGERLIB_SUM  	       500
#define Continue_input_Finger_Num	 3

int main(void) 
 {
	 int i,ret;
	 int timeout;
	 int *p;
	 int TempleteNum_ret[16];
	 int Finger_Num =0;
	 int Buffernum[4]={CHAR_BUFFER_1,CHAR_BUFFER_2,CHAR_BUFFER_3,CHAR_BUFFER_4};
	 int Buffer[2];

	 SER_Init2 ();
	 SER_Init3 ();
	  printf("fafsdsfdfdsfd\n");

   /**************ָ��¼�����ָ�ƿⲢ1��N ƥ��**************/

//      p =ZAZ_TempleteNum();		//�����Чģ�����
//	  for(i=0;i<3;i++)
//	  	TempleteNum_ret[i]=p[i];
//	  printf("Templete_Num=%d\n",TempleteNum_ret[3]);
//	  if(TempleteNum_ret[3]!=0){
//	  	ZAZ_Empty();	 //ɾ������ģ��
//	  }
//
//   while(1){ 
//   		 Finger_Num++;	
//	 	 ret=ZAZ_add_new_user(Buffer[0],Finger_Num);	  //¼��ģ��
//	  	 if(Finger_Num >=Continue_input_Finger_Num){
//	  		break;
//	  	} 
//	  }
//	 if(ret==0){
//		 p =ZAZ_TempleteNum();			 //�����Чģ�����
//	 	 for(i=0;i<3;i++)
//	  	TempleteNum_ret[i]=p[i];
//	  	printf("Templete_Num=%d\n",TempleteNum_ret[3]);	
//
//	   	ret=ZAZ_Search_Comparison(Buffer[0],0,Finger_Num);		//����ָ��ģ�沢ƥ��
//		if(ret!=0){
//			printf("Search error");
//	 		return -1;
//		}
//	}
 /*********************************************************/



/**************ָ��¼�������λ����1:1ƥ��**************/
		 
	 ret=ZAZ_addnewuser_To_Pc(Buffernum[0],Finger_Num);

	 if(ret==0){
	  while(1){
	 	p= ZAZ_ReadSysPara();
		for(i=1;i<17;i++){
		  TempleteNum_ret[i]=p[i];
		  printf("Templete_Num[i]=%d \n",i,TempleteNum_ret[i]);	
		}
	
	 	ret=ZAZ_Match_Comparison(Buffernum[0],Buffernum[1]);	
	 	 if(ret!=0){
			printf("Match error\n");
	 		//return -1;
		}else {
			printf("**************Matck OK!***********\n");
			p= ZAZ_ReadSysPara();
		  for(i=1;i<17;i++){
		    TempleteNum_ret[i]=p[i];
		    printf("********Templete_Num[i]=%d\n",i,TempleteNum_ret[i]);	
	    	}
	
		}
		}
	  } else {
	 	printf("ZAZ_addnewuser_To_Pc  ERROR!\n");
	 }
  	

/*********************************************************/



		return 0;
 }

