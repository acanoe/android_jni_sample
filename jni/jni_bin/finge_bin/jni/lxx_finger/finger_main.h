 /*****************����ʵ�ֶ���******************/
  
int FINGERPRINT_Recevice_Data(unsigned int ucLength); //���շ������ݻ���
int * ZAZ_ReadSysPara(void);     						//��ģ��ϵͳ��������
int ZAZ_GetImag(void);								//¼��ָ��ͼ��
int ZAZ_GenChar(int BufferID);        // ͼ��������������BufferID��
int ZAZ_RegModel(void);     		 //��BUFFER1 �� BUFFER2 �е�������ϲ���ָ��ģ��
int ZAZ_UpChar(int BufferID);			//������������ CharBuffer1��2��3��4�е������ļ��ϴ�����λ��
int ZAZ_DownChar(int BufferID);			//��λ�����������ļ���ģ���һ��������������
int ZAZ_Empty(void); 	  //ɾ��ָ��ģ���������ָ��ģ��
int ZAZ_DeletChar(int uiID_temp,int N_temp );	//ɾ��ָ��ģ�����ָ��ָ��ģ��
int * ZAZ_TempleteNum(void);					 //���ָ��ģ������
int * ZAZ_Two_Match(void);						 //��ȷ�ȶ���öָ�Ƶ�����
int * ZAZ_Search_Finger(int BufferID,int StartPage,int PageNum); //����ָ�ƿ�
int ZAZ_StoreChar( int BuffID,int Finger_Num ); //�洢ָ��ģ��
int ZAZ_Loadchar(int BuffID,int Finger_Num);  // ����ģ�� ���� flash ���ݿ���ָ�� ID �ŵ�ָ��ģ����뵽ģ�建����

int ZAZ_add_new_user(int BufferID,int Finger_Num);   //ָ��������û� ������ָ�ƿ���
int ZAZ_addnewuser_To_Pc(int BufferID,int Finger_Num);	//ָ��������û� ��������λ����
int ZAZ_flashlib_to_pc(int BufferID,int Finger_Num);   //�� flash ָ�ƿ��ж�ȡһ��ָ����ģ���ϴ�
int ZAZ_Search_Comparison(int BufferID,int StartPage,int PageNum);	//ָ��ģ���ڱȶ�
int ZAZ_Match_Comparison(int BufferID1,int BufferID2);								//��λ������ģ�鵽ָ��ģ���ڱȶԣ�1:1��

int ZAZ_FingerLIB_Search_Comparison(int BufferID,int StartPage,int PageNum); //��λ������ģ�鵽ָ�ƿ��ڱȶԣ�1:N��

