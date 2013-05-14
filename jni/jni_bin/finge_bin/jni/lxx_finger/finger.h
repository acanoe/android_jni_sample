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

int ZAZ_Read_SysPara[6]={0x01,0x00,0x03,0x3f,0x00,0x43}; //��ϵͳ����

/**************************Ӧ���************************/
int UART_RECEVICE_BUFFER[24]={0};			  //Ӧ���
int Subsequent_RECEVICE_BUFFER[2048];				  //������	  
int Subsequent_RECEVICE_DATA[1024]={0};
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


#endif

										   