#include <stdio.h>
#include <string.h>
#include <jni.h>
#include <android/log.h>
static const char *TAG="Acanoe";
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO,  TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)
#ifndef  __FINGER_H
#define  __FINGER_H


/**********************���󷵻���***********************/

#define ZAZ_OK                0x00	    //��ʾָ��ִ��OK
#define ZAZ_COMM_ERR          0x01		//��ʾ���ݰ����ܴ���
#define ZAZ_NO_FINGER         0x02		//��ʾ��ָ������
#define ZAZ_GET_IMG_ERR       0x03		//��ʾ¼��ָ��ͼ��ʧ��
#define ZAZ_FP_TOO_DRY        0x04		
#define ZAZ_FP_TOO_WET        0x05
#define ZAZ_FP_DISORDER       0x06
#define ZAZ_LITTLE_FEATURE    0x07	   //��ʾ������̫�ٶ�����������
#define ZAZ_NOT_MATCH         0x08	   //��ʾָ�Ʋ�ƥ��
#define ZAZ_NOT_SEARCHED      0x09	   //��ʾû������ָ��
#define ZAZ_MERGE_ERR         0x0a	   //��ʾ�����ϲ�ʧ��
#define ZAZ_ADDRESS_OVER      0x0b	   //��ʾ����ָ�ƿ�ʱ��ַ��ų���ָ�ƿⷶΧ
#define ZAZ_READ_ERR          0x0c	   //��ʾָ�ƿ��ģ��������Ч
#define ZAZ_UP_TEMP_ERR       0x0d	   //��ʾ�ϴ�����ʧ��
#define ZAZ_RECV_ERR          0x0e	   //��ʾ�������ܽ��ܺ������ݰ�
#define ZAZ_UP_IMG_ERR        0x0f	   //��ʾ�ϴ�ͼ��ʧ��
#define ZAZ_DEL_TEMP_ERR      0x10	   //��ʾɾ��ģ��ʧ��
#define ZAZ_CLEAR_TEMP_ERR    0x11	   //��ʾ���ָ�ƿ�ʧ��
#define ZAZ_SLEEP_ERR         0x12
#define ZAZ_INVALID_PASSWORD  0x13	   //��ʾ�����ȷ
#define ZAZ_RESET_ERR         0x14	   //��ʾ��λʧ��
#define ZAZ_INVALID_IMAGE     0x15	   
#define ZAZ_HANGOVER_UNREMOVE 0x17
#define ZAZ_FLASH_ERR         0x18
#define ZAZ_NODEFINE_ERR      0x19


/**********************������*************************/
#define CHAR_BUFFER_1          0x01
#define CHAR_BUFFER_2          0x02
#define CHAR_BUFFER_3          0x03
#define CHAR_BUFFER_4		   0x04
#define MODEL_BUFFER           0x05

/************************ϵͳ�����������*****************/
int SysPara_num[3]={0x04,0x05,0x06};

//int ZAZ_Read_SysPara[6]={0x01,0x00,0x03,0x3f,0x00,0x43}; //��ϵͳ����
int ZAZ_Read_SysPara[6]={0x01,0x00,0x01,0x3f,0x00,0x41}; //��ϵͳ����

/**************************Ӧ���************************/
int UART_RECEVICE_BUFFER[24]={0};			  //Ӧ���
int Subsequent_RECEVICE_BUFFER[2048];				  //������	  
int Subsequent_RECEVICE_DATA[1024]= {0};
int Subsequent_RECEVICE_LENGTH[24]={0};
int Subsequent_RECEVICE_SUM[10]={0};

int BUFFER_NUM;

/*********************ZAZ-404-Bͨ��Э�鶨��*********************/
int ZAZ_Pack_Head[6]     = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF};      //Э���ͷ
// system command
int ZAZ_Templete_Num[6]  ={0x01,0x00,0x03,0x4D,0x00,0x51 };      //���ģ������															 

// Fingerprint processing 
int ZAZ_Set_Syspara[8]   ={0x01,0x00,0x05,0x3e,0x05,0x02,0x00,0x4b};	 //����ϵͳ����������ȫ�ȼ�Ϊ2
int ZAZ_Get_Img[6]       = {0x01,0x00,0x03,0x31,0x00,0x35};       //¼ָ��ͼ��
int ZAZ_Up_Image[6]      = {0x01,0x00,0x03,0x3a,0x00,0x3e};      //�ϴ�ͼ��
int ZAZ_Down_Image[6]    = {0x01,0x00,0x03,0x3b,0x00,0x3f};      //����ͼ��
int ZAZ_Img_To_Buffer[7] = {0x01,0x00,0x04,0x32,0x01,0x00,0x38}; //��ͼ����뵽CHAR_BUFFER
int ZAZ_Reg_Model[6]     = {0x01,0x00,0x03,0x35,0x00,0x39};        //��CHAR_BUFFER_1��2��3��4�ϳ�����ģ��
int ZAZ_Up_Buffer[7]    = {0x01,0x00,0x04,0x38,0x01,0x00,0x3e};  //��CHAR_BUFFER�ϴ�����λ��
int ZAZ_Down_To_Buffer[7] = {0x01,0x00,0x04,0x39,0x01,0x00,0x3f};	//��λ�����������ļ���CHAR_BUFFER
int ZAZ_Match[6]       = {0x01,0x00,0x03,0x33,0x00,0x37};        //��ȷ�ȶ���öָ������
int ZAZ_Search[11]     ={0x01,0x00,0x08,0x34,0x01,0x00,0x00,0x03,0xA1,0x00,0xe2}; //����ָ��������Χ0 - 929
int ZAZ_Delet_All_Model[6]={0x01,0x00,0x03,0x3d,0x00,0x41};//ɾ��ָ��ģ�������е�ģ��
int ZAZ_Save_Finger[9]={0x01,0x00,0x06,0x36,0x01,0x00,0x0B,0x00,0x49};//��BUFFER1�е��������ŵ�ָ����λ��
int ZAZ_Load_Char[9]  ={0x01,0x00,0x06,0x37,0x01,0x00,0x0A,0x00,0x49};	 //�� flash ���ݿ���ָ�� ID �ŵ�ָ��ģ����뵽ģ�建����
int ZAZ_Delete_Model[10]={0x01,0x00,0x07,0x3C,0x00,0x00,0x00,0x01,0x00,0x45}; //ɾ��ָ����ģ��
int * FINGERCODE;


#endif








/*------------------ FINGERPRINT������ --------------------------*/
//���շ������ݻ���
int FINGERPRINT_Recevice_Data(int ucLength)
{
	int i=0;
	int ch;
	int timeout = 0;
	while(1) {	 
		if(timeout++ >= 1000000000) {
			return -1;
		} 
		ch = getkey3();		
		if(ch != -1) {	
			UART_RECEVICE_BUFFER[i] = ch;
			i++;
			if(i==ucLength){
				break;
			}
		} 
	}


	return 	UART_RECEVICE_BUFFER[9];
}


//��ģ��ϵͳ��������
int ZAZ_SetSysPara(void)
{
	int i;
	for(i=0;i<6;i++) //���Ͱ�ͷ 
	{
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}

	for(i=0;i<8;i++){
		SER_PutChar3(ZAZ_Set_Syspara[i]);

	}

	FINGERPRINT_Recevice_Data(12);

	return 0; 

}

int * ZAZ_ReadSysPara(void)
{
	int i;
	int ret[17];
	for(i=0;i<6;i++) //���Ͱ�ͷ 
	{
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}
	for(i=0;i<6;i++) //�������� 0x1d
	{
		SER_PutChar3(ZAZ_Read_SysPara[i]);
	}

	FINGERPRINT_Recevice_Data(28);
	for(i=0;i<17;i++){
		ret[i]=	UART_RECEVICE_BUFFER[i+9];
	}

	return ret;
}

static int FINGERPRINT_Cmd_Get_Img(void)
{
	int i;

	for(i=0;i<6;i++) //���Ͱ�ͷ
	{  
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}

	for(i=0;i<6;i++) //�������� 0x1d
	{
		SER_PutChar3(ZAZ_Get_Img[i]);
	}

	return 0;
}

//¼��ָ��ͼ��
int ZAZ_GetImag(void)
{
	int ret;
	do{	
		FINGERPRINT_Cmd_Get_Img(); //���ָ��ͼ��
		ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����
	}while(ret!=ZAZ_OK);	

	return ret;
}



static void FINGERPRINT_Img_To_Buffer(int BufferID)
{
	unsigned long temp = 0;
	int i;
	ZAZ_Img_To_Buffer[4]=BufferID;

	for(i=0;i<5;i++)   //����У���
		temp = temp + ZAZ_Img_To_Buffer[i];

	ZAZ_Img_To_Buffer[5]=(temp & 0xFF00) >> 8; //���У������
	ZAZ_Img_To_Buffer[6]= temp & 0x00FF;

	for(i=0;i<6;i++)    //���Ͱ�ͷ
		SER_PutChar3(ZAZ_Pack_Head[i]);   

	for(i=0;i<7;i++)
		SER_PutChar3(ZAZ_Img_To_Buffer[i]);


}

//ͼ��������������BufferID��
int ZAZ_GenChar(int BufferID)
{
	int ret=0;
	FINGERPRINT_Img_To_Buffer(BufferID); //�������� ��ͼ��ת���� ������ ����� CHAR_buffer
	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����
	return ret;

}


//��BUFFER1 �� BUFFER2 �е�������ϲ���ָ��ģ��
int ZAZ_RegModel(void)
{
	int i;    
	int ret=0;
	for(i=0;i<6;i++) //��ͷ
	{
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}  

	for(i=0;i<6;i++)  //����ϲ�ָ��ģ��
	{
		SER_PutChar3(ZAZ_Reg_Model[i]); 
	}
	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����

	return ret;
}

//���պ������ݰ�
// /***start: 2 adder: 4  pid: 1 length: 2 data: 128 sum: 2  ��139���ֽ�  ����7�����ݰ� 1���������ݰ�****/
static int Subsequent_Recevice_Data()
{
	int ch;
	static int n=0;
	int cnt;
	int DATA_LONG=0;
	int Subsequent_RECEVICE_HEAD[6]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF};
	int Subsequent_PID[2]={0x02,0x08};
	int NUM=0;
	BUFFER_NUM=0;

	while(1){
		ch=getkey3();
		if(ch!=-1){
			Subsequent_RECEVICE_BUFFER[BUFFER_NUM] = ch;
			//	SER_PutChar2(Subsequent_RECEVICE_BUFFER[BUFFER_NUM]); 
			if(BUFFER_NUM >= 1111){
				break;
			}
			BUFFER_NUM++;
		}
	}

	while(1){
		if((Subsequent_RECEVICE_BUFFER[NUM]==Subsequent_RECEVICE_HEAD[0])&&(Subsequent_RECEVICE_BUFFER[NUM+1]==Subsequent_RECEVICE_HEAD[1])&&(Subsequent_RECEVICE_BUFFER[NUM+2]==Subsequent_RECEVICE_HEAD[2])&&(Subsequent_RECEVICE_BUFFER[NUM+3]==Subsequent_RECEVICE_HEAD[3])&&(Subsequent_RECEVICE_BUFFER[NUM+4]==Subsequent_RECEVICE_HEAD[4])&&(Subsequent_RECEVICE_BUFFER[NUM+5]==Subsequent_RECEVICE_HEAD[5])){		
			NUM+=6;
			if(Subsequent_RECEVICE_BUFFER[NUM]==Subsequent_PID[0]){
				Subsequent_RECEVICE_LENGTH[0]=Subsequent_RECEVICE_BUFFER[++NUM];
				Subsequent_RECEVICE_LENGTH[1]=Subsequent_RECEVICE_BUFFER[++NUM];
				DATA_LONG=Subsequent_RECEVICE_LENGTH[0];
				DATA_LONG=DATA_LONG << 8 | Subsequent_RECEVICE_LENGTH[1];
				DATA_LONG -= 2;
				cnt=0;
				while(cnt < DATA_LONG){	  	
					Subsequent_RECEVICE_DATA[n]=Subsequent_RECEVICE_BUFFER[++NUM];
					n++;
					cnt++;
				} 
				Subsequent_RECEVICE_SUM[0]=Subsequent_RECEVICE_BUFFER[++NUM];
				Subsequent_RECEVICE_SUM[1]=Subsequent_RECEVICE_BUFFER[++NUM];

			}else if(Subsequent_RECEVICE_BUFFER[NUM]==Subsequent_PID[1]){

				Subsequent_RECEVICE_LENGTH[0]=Subsequent_RECEVICE_BUFFER[++NUM];
				Subsequent_RECEVICE_LENGTH[1]=Subsequent_RECEVICE_BUFFER[++NUM];
				DATA_LONG=Subsequent_RECEVICE_LENGTH[0];
				DATA_LONG=DATA_LONG << 8 | Subsequent_RECEVICE_LENGTH[1];
				DATA_LONG -= 2;
				cnt=0;
				while(cnt < DATA_LONG){	  	
					Subsequent_RECEVICE_DATA[n]=Subsequent_RECEVICE_BUFFER[++NUM];				 	
					n++;
					cnt++;
				} 
				Subsequent_RECEVICE_SUM[0]=Subsequent_RECEVICE_BUFFER[++NUM];
				Subsequent_RECEVICE_SUM[1]=Subsequent_RECEVICE_BUFFER[++NUM];

				break;

			}
		}

		NUM++;
	}


	return 0;
}

//���ͺ������ݰ�
//static int Subsequent_Send_Data()
//{
//	int i;
//	int ret;
//	BUFFER_NUM=1112;
//	for(i=0;i < BUFFER_NUM;i++){
//			SER_PutChar3(Subsequent_RECEVICE_BUFFER[i]);
//	}
//	  	
//	ret=FINGERPRINT_Recevice_Data(12);
//		
//	   return ret;
//
//}

//���ͺ������ݰ�
static int Subsequent_Send_Data()
{
	int i=0,ret;
	int cnt=0;
	static int n=0;
	int ZAZ_CMD_LENGTH[3]={0x02,0x00,0x82};
	int ZAZ_CMD_LENGTH_END[3]={0x08,0x00,0x82};
	unsigned long temp=0;
	int DATA[1024]={0};
	int SUM[2]={0};

	for(i=0;i<1024;i++){
		DATA[i]=*FINGERCODE++;
//		__android_log_print(ANDROID_LOG_INFO, "Acanoe", "DATA[%d] = %x,",i,DATA[i]);
	}

	while(cnt<7){
		for(i=0;i<6;i++)    //���Ͱ�ͷ
			SER_PutChar3(ZAZ_Pack_Head[i]);

		for(i=0;i<3;i++)    //���Ͱ���ʾ�Ͱ�����
		{
			SER_PutChar3(ZAZ_CMD_LENGTH[i]);
			temp=temp+ZAZ_CMD_LENGTH[i];
		}
		for(n = cnt*128;n<(cnt+1)*128;n++){
			SER_PutChar3(DATA[n]);
			temp=temp+DATA[n];
		}
		SUM[0]=(temp & 0xFF00) >> 8; //���У������
		SUM[1]=(temp & 0xFF);

		for(i=0;i<2;i++)
			SER_PutChar3(SUM[i]);

		temp=0;

		cnt++;	  	   
	}

	for(i=0;i<6;i++)    //���Ͱ�ͷ
		SER_PutChar3(ZAZ_Pack_Head[i]);

	for(i=0;i<3;i++)    //���Ͱ�ͷ
	{
		SER_PutChar3(ZAZ_CMD_LENGTH_END[i]);
		temp=temp+ZAZ_CMD_LENGTH_END[i];
	}
	for(n=cnt*128;n<(cnt+1)*128;n++){
		SER_PutChar3(DATA[n]);
		temp=temp+DATA[n];
	}

	SUM[0]=(temp & 0x00FF00) >> 8; //���У������
	SUM[1]= (temp & 0x0000FF);	

	for(i=0;i<2;i++)
		SER_PutChar3(SUM[i]);

	ret=FINGERPRINT_Recevice_Data(12);

	return ret;


}

//������������ CharBuffer�е������ļ��ϴ�����λ��
int ZAZ_UpChar( int BufferID)
{
	unsigned long temp=0x3d;
	int i,ret;
	ZAZ_Up_Buffer[4]= BufferID;

	//		  for(i=0;i<5;i++)   //����У���
	//		   	   temp = temp + ZAZ_Up_Buffer[i];

	temp=temp+ZAZ_Up_Buffer[4]; 

	ZAZ_Up_Buffer[5]=(temp & 0x00FF00) >> 8; //���У������
	ZAZ_Up_Buffer[6]= (temp & 0x0000FF);

	for(i=0;i<6;i++)    //���Ͱ�ͷ
	{
		SER_PutChar3(ZAZ_Pack_Head[i]); 
	}
	for(i=0;i<7;i++)
	{
		SER_PutChar3(ZAZ_Up_Buffer[i]);
	}

	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����
	if(ret==0){
		Subsequent_Recevice_Data();
		printf("ret_Subsequent_Recevice_Data success");
	}
	return ret;

}

//��λ�����������ļ���ģ���һ��������������
int ZAZ_DownChar(int BufferID)
{
	unsigned long temp=0x3e;
	int i,ret=0,ret1=0;
	ZAZ_Down_To_Buffer[4]=BufferID;

	temp=temp+ ZAZ_Down_To_Buffer[4];
	ZAZ_Down_To_Buffer[5]=(temp & 0xFF00) >> 8; //���У������
	ZAZ_Down_To_Buffer[6]= temp & 0x00FF;

	for(i=0;i<6;i++)    //���Ͱ�ͷ
	{
		SER_PutChar3(ZAZ_Pack_Head[i]); 
	}
	for(i=0;i<7;i++)
	{
		SER_PutChar3(ZAZ_Down_To_Buffer[i]);
	}

	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����
	printf("ret=%x\n",ret);
	if(ret==ZAZ_OK){
		printf("Begin Subsequent_Send_Data\n");
		//		  ret1=Subsequent_Send_Data(Subsequent_RECEVICE_DATA);
		ret1=Subsequent_Send_Data();
		printf("ret1=%x\n",ret1);
		if(ret1==ZAZ_OK){
			printf("ret_Subsequent_Recevice_Data success\n");
		}else{
			printf("ret_Subsequent_Recevice_Data error!!\n");
		}
	}


	return 0;


}


//ɾ��ָ��ģ���������ָ��ģ��
int ZAZ_Empty(void)
{
	int i;    
	int ret=0;
	for(i=0;i<6;i++) //��ͷ
		SER_PutChar3(ZAZ_Pack_Head[i]);   

	for(i=0;i<6;i++) //����ϲ�ָ��ģ��
		SER_PutChar3(ZAZ_Delet_All_Model[i]);

	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����

	return ret;



}



//ɾ��ָ��ģ�����ָ��ָ��ģ��
int ZAZ_DeletChar(int uiID_temp,int N_temp )
{
	int uiSum_temp = 0;
	int i,ret=0;    

	ZAZ_Delete_Model[4]=(uiID_temp&0xFF00)>>8;
	ZAZ_Delete_Model[5]=(uiID_temp&0x00FF);

	ZAZ_Delete_Model[6]=(N_temp&0xFF00)>>8;
	ZAZ_Delete_Model[7]=(N_temp&0x00FF);

	for(i=0;i<8;i++)
		uiSum_temp = uiSum_temp +ZAZ_Delete_Model[i];


	ZAZ_Delete_Model[8]=(uiSum_temp&0xFF00)>>8;
	ZAZ_Delete_Model[9]=uiSum_temp&0x00FF;


	for(i=0;i<6;i++) //��ͷ
		SER_PutChar3(ZAZ_Pack_Head[i]);   

	for(i=0;i<10;i++) //����ϲ�ָ��ģ��
		SER_PutChar3(ZAZ_Delete_Model[i]);   

	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����

	return ret;

}




//���ָ��ģ������
int *ZAZ_TempleteNum(void)
{ 
	int i;
	int *p =(int *)malloc(12);
	for(i=0;i<6;i++) //��ͷ
	{
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}
	//�������� 0x1d
	for(i=0;i<6;i++)
	{
		SER_PutChar3(ZAZ_Templete_Num[i]);
	}

	FINGERPRINT_Recevice_Data(14); //ȷ����	
	for(i=0;i<3;i++)
		p[i] = UART_RECEVICE_BUFFER[i+9];


	return p;		
}

//��ȷ�ȶ���öָ��
int * ZAZ_Two_Match(void)
{
	int i;
	int ret[3]={0};

	for(i=0;i<6;i++) //��ͷ
	{
		SER_PutChar3(ZAZ_Pack_Head[i]);
	}

	for(i=0;i<6;i++)
	{
		SER_PutChar3(ZAZ_Match[i]);
	}

	FINGERPRINT_Recevice_Data(14); //����14�����ȵķ�����
	ret[0]=UART_RECEVICE_BUFFER[9];
	ret[1]=UART_RECEVICE_BUFFER[10];
	ret[2]=UART_RECEVICE_BUFFER[11];

	return ret;

}



//����ָ�ƿ�
int * ZAZ_Search_Finger(int BufferID,int StartPage,int PageNum)
{
	int i;
	unsigned long temp;
	int ret[3]={0};
	ZAZ_Search[4] = BufferID;

	ZAZ_Search[5]=(StartPage&0xFF00)>>8;
	ZAZ_Search[6]=(StartPage&0x00FF);

	ZAZ_Search[7]=(PageNum&0xFF00)>>8;
	ZAZ_Search[8]=(PageNum&0x00FF);

	for(i=0;i<9;i++)
		temp = temp +ZAZ_Search[i];

	//UART0_Send_Byte(uiSum_temp);	

	ZAZ_Search[9]=(temp&0xFF00)>>8;
	ZAZ_Search[10]=temp&0x00FF;


	for(i=0;i<6;i++)   //������������ָ�ƿ�
	{
		SER_PutChar3(ZAZ_Pack_Head[i]); 
	}

	for(i=0;i<11;i++)
	{
		SER_PutChar3(ZAZ_Search[i]); 
	}

	FINGERPRINT_Recevice_Data(16); //����16�����ȵķ�����
	ret[0]=UART_RECEVICE_BUFFER[9];
	ret[1]=UART_RECEVICE_BUFFER[10];
	ret[2]=UART_RECEVICE_BUFFER[11];

	return ret;

}



//�洢ָ��ģ��
int ZAZ_StoreChar( int BuffID,int Finger_Num)
{
	unsigned long temp = 0;
	int i,ret=0;

	ZAZ_Save_Finger[4] = BuffID;

	ZAZ_Save_Finger[5]=(Finger_Num&0xFF00)>>8;
	ZAZ_Save_Finger[6]=(Finger_Num&0x00FF);
	//           ZAZ_Save_Finger[5] = ucH_Char;
	//           ZAZ_Save_Finger[6] = ucL_Char;

	for(i=0;i<7;i++)   //����У���
		temp = temp + ZAZ_Save_Finger[i];

	ZAZ_Save_Finger[7]=(temp & 0x00FF00) >> 8; //���У������
	ZAZ_Save_Finger[8]= temp & 0x0000FF;

	for(i=0;i<6;i++){    
		SER_PutChar3(ZAZ_Pack_Head[i]);        //���Ͱ�ͷ
	} 
	for(i=0;i<9;i++){  
		SER_PutChar3(ZAZ_Save_Finger[i]);      //�������� ��ͼ��ת���� ������ ����� CHAR_buffer1
	}
	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����

	return ret;

}

// ����ģ�� ���� flash ���ݿ���ָ�� ID �ŵ�ָ��ģ����뵽ģ�建����
int ZAZ_Loadchar(int BufferID,int Finger_Num)
{
	unsigned long temp = 0;
	int i,ret=0;

	ZAZ_Load_Char[4] = BufferID;

	ZAZ_Load_Char[5]=(Finger_Num&0xFF00)>>8;
	ZAZ_Load_Char[6]=(Finger_Num&0x00FF);
	//           ZAZ_Load_Char[5] = ucH_Char;
	//           ZAZ_Load_Char[6] = ucL_Char;

	for(i=0;i<7;i++)   //����У���
		temp = temp + ZAZ_Load_Char[i];

	ZAZ_Load_Char[7]=(temp & 0x00FF00) >> 8; //���У������
	ZAZ_Load_Char[8]= temp & 0x0000FF;

	for(i=0;i<6;i++){    
		SER_PutChar3(ZAZ_Pack_Head[i]);        //���Ͱ�ͷ
	} 
	for(i=0;i<9;i++){  
		SER_PutChar3(ZAZ_Load_Char[i]);      //�������� ��ͼ��ת���� ������ ����� CHAR_buffer
	}
	ret=FINGERPRINT_Recevice_Data(12); //����12�����ȵķ�����

	return ret;


}

//*********************************************************//

//ָ��������û� ������ָ�ƿ���
int ZAZ_add_new_user(int BufferID,int Finger_Num)
{
	int i,ret;
	int Buffer[4]={CHAR_BUFFER_1,CHAR_BUFFER_2,CHAR_BUFFER_3,CHAR_BUFFER_4};

	for(i=0;i<4;i++){
		printf("please Input fingerprint\n");
		ret=ZAZ_GetImag();	  //¼��ָ��ͼ��
		if(ret==0){
			printf("Input fingerprint succeed\n");
		}
		printf("Fingerprint image stored in Buffer[%d]\n",i);
		ret=ZAZ_GenChar(Buffer[i]);     // ��ͼ��ת�������������CHAR_BUFFER
		printf("ret=%x\n",ret);
		if(ret!=ZAZ_OK){
			return -1;
		} 
	}

	printf("Synthetic fingerprint template\n");		
	ret=ZAZ_RegModel();		//�ϳ�ָ��ģ��
	printf("ret=%x\n",ret);
	if(ret != ZAZ_OK )
	{
		return -1;
	}
	printf("Fingerprint template stored in fingerprint library\n");
	ret=ZAZ_StoreChar(BufferID,Finger_Num);
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK){
		return -1;
	}	


	return 0;

}

//�Ӵ�������ȡָ�Ʋ���������Ȼ���ϴ�����λ��
int ZAZ_addnewuser_To_Pc(int BufferID,int Finger_Num)
{
	int i,ret;
	int Buffer[4]={CHAR_BUFFER_1,CHAR_BUFFER_2,CHAR_BUFFER_3,CHAR_BUFFER_4};

	for(i=0;i<4;i++){
		printf("please Input fingerprint\n");
		ret=ZAZ_GetImag();	  //¼��ָ��ͼ��
		if(ret==0){
			printf("Input fingerprint succeed\n");
		} else {
			printf("Input fingerprint error\n");
		}
		printf("Fingerprint image stored in Buffer[%d]\n",i);
		ret=ZAZ_GenChar(Buffer[i]);     // ��ͼ��ת�������������CHAR_BUFFER
		printf("ret=%x\n",ret);
		if(ret!=ZAZ_OK){
			return -1;
		} 
	}

	printf("Synthetic fingerprint template\n");		
	ret=ZAZ_RegModel();		//�ϳ�ָ��ģ��
	printf("ret=%x\n",ret);
	if(ret != ZAZ_OK )
	{
		return -1;
	}
	printf("uploading char\n");
	ret=ZAZ_UpChar(BufferID);
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK ) {
		return -1;
	}



	return 0;

}


//�� flash ָ�ƿ��ж�ȡһ��ָ����ģ���ϴ�
int ZAZ_flashlib_to_pc(int BufferID,int Finger_Num)
{
	int ret;
	ret=ZAZ_Loadchar(BufferID,Finger_Num);
	if(ret!=0){
		printf("ZAZ_Loadchar()error\n");
		return -1;
	}
	printf("uploading char\n");
	ret=ZAZ_UpChar(BufferID);
	printf("ret=%x\n",ret);
	if(ret != ZAZ_OK){
		return -1;
	}
	ret=Subsequent_Recevice_Data();
	printf("ret=%x\n",ret);

	return 0;

}

//ָ��ģ���ڱȶ� (1:N)
int ZAZ_Search_Comparison(int BufferID,int StartPage,int PageNum)
{	 	
	int i,ret;
	int Search_ret[3];	
	printf("please Input fingerprint\n");
	ret=ZAZ_GetImag();	  //¼��ָ��ͼ��
	if(ret==0){
		printf("Input fingerprint succeed\n");
	}
	printf("Fingerprint image stored in Buffer\n");
	ret=ZAZ_GenChar(BufferID);     // ��ͼ��ת�������������CHAR_BUFFER
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK){
		return -1;
	}

	ZAZ_Search_Finger(BufferID,StartPage,PageNum);
	for(i=0;i<3;i++){
		Search_ret[i] = UART_RECEVICE_BUFFER[i+9]; 
		printf("Search_ret[%d]=%x\n",i,Search_ret[i]);
	}

	if(Search_ret[0]!=ZAZ_OK){
		return -1;
	}
	return 0;
}


//��λ������ģ�鵽ָ��ģ���ڱȶԣ�1:1��
int ZAZ_Match_Comparison(int BufferID1,int BufferID2,int * code)
{
	int i,ret;
	int Match_ret[3];
/*	for(i = 0;i < 1024; i++){
		__android_log_print(ANDROID_LOG_INFO, "Acanoe", "code  %x,",*code++);
	}*/
	FINGERCODE = code;
	printf("please Input fingerprint\n");
	ret=ZAZ_GetImag();	  //¼��ָ��ͼ��
	if(ret==0){
		printf("Input fingerprint succeed\n");
	}
	printf("Fingerprint image stored in Buffer\n");
	ret=ZAZ_GenChar(BufferID1);     // ��ͼ��ת�������������CHAR_BUFFER
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK){
		return -1;
	} 

	printf("Begain Downchar\n");
	ret=ZAZ_DownChar(BufferID2);
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK){
		return -1;
	}

	ZAZ_Two_Match();
	for(i=0;i<3;i++){ 
		Match_ret[i] = UART_RECEVICE_BUFFER[i+9];
	}
	if(Match_ret[0]!=ZAZ_OK){
		return -1;
	}
	return  0;
}

//	����λ������һ��ָ���������Ը���������ָ�ƿ�
int ZAZ_FingerLIB_Search_Comparison(int BufferID,int StartPage,int Finger_Num)
{
	int i,ret;
	int Search_ret[3];

	printf("Begain Downchar\n");
	ret=ZAZ_DownChar(BufferID);
	printf("ret=%x\n",ret);
	if(ret!=ZAZ_OK){
		return -1;
	} 
	ret=Subsequent_Recevice_Data();
	printf("ret=%x\n",ret);          


	ZAZ_Search_Finger(BufferID,StartPage,Finger_Num);
	for(i=0;i<3;i++){
		Search_ret[i] = UART_RECEVICE_BUFFER[i+9]; 
		printf("Search_ret[%d]=%x\n",i,Search_ret[i]);
	}

	if(Search_ret[0]!=ZAZ_OK){
		return -1;
	}

	return  0;
}
