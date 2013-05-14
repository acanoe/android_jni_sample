#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <termios.h>
#include <jni.h>


#define CHAR_BUFFER_1          0x01
#define CHAR_BUFFER_2          0x02
#define CHAR_BUFFER_3          0x03
#define CHAR_BUFFER_4		   0x04
#define MODEL_BUFFER           0x05
#define FINGERLIB_SUM  	       500
#define Continue_input_Finger_Num	 3
int fd;
int fd_485;
int open_port(char * dev)
{
	int fcntl_ret;

	//------------------ �Էǿ���̨ģʽ���豸�����ԶԶ�״̬ -------------------
	fd = open(dev, O_RDWR | O_NOCTTY);
	if (-1 == fd)
		printf("open dev error\n");
	printf("open dev  fd is %d\n",fd);

	//------------------ �ָ��򿪶˿�Ϊ����ģʽ ------------------
	fcntl_ret = fcntl (fd, F_SETFL, 0);
	// fcntl_ret = fcntl (fd, F_GETFL, 0);
	if (fcntl_ret < 0)
		printf("fcntl error\n");

}
int init_port(int fds,int baud_rate)
{
	struct termios option;

	//------------------ ��õ�ǰ����ѡ�� ------------------
	tcgetattr( fds,&option );    
#if 1
	//------------------ ����Ϊ����ģʽ��ʹ�ܽ��� -----------------
	option.c_cflag |= (CLOCAL | CREAD);

	//----------------- ��������λλ��Ϊ 8 ------------------ 
	option.c_cflag &= ~CSIZE; 
	option.c_cflag |= CS8;

	//------------------ ����Ϊ����żУ�� ------------------       
	option.c_cflag &= ~PARENB;

	//------------------ ����ֹͣλΪ1 -----------------
	option.c_cflag &= ~CSTOPB;

	//------------------- ����Ϊ�����/Ӳ�������� ------------------
	option.c_cflag &= ~(CRTSCTS);

	option.c_iflag &= ~(IXON | INLCR | ICRNL | IGNCR | IUCLC);

	//------------------ �������ģʽΪ��Ԥ���� ------------------
	option.c_oflag &= ~OPOST;

	//------------------ ��������Ϊ�Ǹ�ʽ������ ------------------
	option.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);


	//------------------ ������С�ַ��� ------------------
	option.c_cc[VMIN] = 1;

	//------------------ �ȴ�����ʱ�� -----------------
	option.c_cc[VTIME] = 10;

	option.c_cc[VINTR] = 0;  
	option.c_cc[VQUIT] = 0;  
	option.c_cc[VERASE] = 0;  
	option.c_cc[VKILL] = 0;  
	option.c_cc[VEOF] = 0;  
	option.c_cc[VTIME] = 10;  
	option.c_cc[VMIN] = 1;  
	option.c_cc[VSWTC] = 0;  
	option.c_cc[VSTART] = 0;  
	option.c_cc[VSTOP] = 0;  
	option.c_cc[VSUSP] = 0;  
	option.c_cc[VEOL] = 0;  
	option.c_cc[VREPRINT] = 0;  
	option.c_cc[VDISCARD] = 0;  
	option.c_cc[VWERASE] = 0;  
	option.c_cc[VLNEXT] = 0;  
	option.c_cc[VEOL2] = 0;  


#endif

	//------------------ ���ò����� ------------------  
	switch(baud_rate)
	{
		case 2400:
			cfsetispeed(&option, B2400);
			cfsetospeed(&option, B2400);
			break;
		case 4800:
			cfsetispeed(&option, B4800);
			cfsetospeed(&option, B4800);
			break;
		case 9600:
			cfsetispeed(&option, B9600);
			cfsetospeed(&option, B9600);
			break;
		case 115200:
			cfsetispeed(&option, B115200);
			cfsetospeed(&option, B115200);
			break;
		default:
			cfsetispeed(&option, B9600);
			cfsetospeed(&option, B9600);
			break;
	}


	tcflush(fds, TCIOFLUSH);
	//------------------ ���������������� -----------------    
	if((tcsetattr (fds,TCSANOW,&option)) != 0)
	{
		return -1;
	}

	return 0;
}


int main(int argc, char * argv[]) 
{
	int i,ret;
	int timeout;
	int *p;
	int TempleteNum_ret[3];
	int Finger_Num =0;
	int Buffernum[4]={CHAR_BUFFER_1,CHAR_BUFFER_2,CHAR_BUFFER_3,CHAR_BUFFER_4};

	open_port(argv[1]);

	if (fd < 0)
		printf("open %s error\n",argv[1]);

	if (init_port(fd, 115200) < 0)
		printf("JNIMsg", "finger port error\n");

	ret=ZAZ_addnewuser_To_Pc(Buffernum[0],Finger_Num);
	if(ret==0){
		while(1){
			ret=ZAZ_Match_Comparison(Buffernum[0],Buffernum[1]);	
			if(ret!=0){
				printf("Match error\n");
				//return -1;
			}else {
				printf("Matck OK!\n");
			}
		}
	} else {
		printf("ZAZ_addnewuser_To_Pc  ERROR!\n");
	}
	return 0;
}

int getkey3()
{
	int read_data = 0;
	read(fd,&read_data,1);
//	printf("getkey read_data = 0x%x\n,",read_data);
	return read_data;
}

SER_PutChar3(int a)
{
	write(fd, &a,1);
}

clear_buf()
{
#if 0
	usleep(100000);
	printf("clear buf\n");
	tcflush(fd,TCIOFLUSH);
	usleep(20000);
#endif
}
