#include "base.h"
#include "net.h"


#define MR_SUCCESS  0    //�ɹ�
#define MR_FAILED   -1    //ʧ��
#define MR_IGNORE   1     //������
#define MR_WAITING  2     //�첽(������)ģʽ

#define  MR_SOCK_STREAM 0 //������
#define  MR_SOCK_DGRAM  1 //���ݰ�
#define  MR_IPPROTO_TCP  0 //TCP
#define  MR_IPPROTO_UDP  1 //UDP

#define  MR_SOCKET_BLOCK   0       //������ʽ��ͬ����ʽ��
#define  MR_SOCKET_NONBLOCK   1    //��������ʽ���첽��ʽ��




#define BUFLEN 1024*4

int32 usedTime;//��ʱ����

char hostName[128];
char httpHead[256];
uint16 port;


int32 socketHandle, timerHandle;
char *url;


void StopDownload(void)
{
    if (timerHandle)
    {
        timerdel(timerHandle);
        timerHandle = 0;
    }

    if (socketHandle)
    {
        closesocket(socketHandle);
        socketHandle = 0;
    }
    closenetwork();
    //exit();
}
void ErrorStop(int i)
{
printf("�����%d",i);
    cls(0,0,0);
    dtext("���س���",0,0,255,255,255,0,1);
    ref(0,0,240,320);
    StopDownload();
}
void ReceiveCb(int32 data)//�������ݻص�
{
    int32 len;
    static char RecvBuffer[BUFLEN];

    len = recv(socketHandle, RecvBuffer, sizeof(RecvBuffer));
    if (0 == len)//�ȴ���������
    {
        usedTime++;
        if (usedTime > 200)
        {
            // �������ݳ�ʱ��
            ErrorStop(1);
        }
    }
    else if (MR_FAILED == len)
    {
        ErrorStop(2);
    }
    else//��Ϊ�Է����͵�����ʵ����̫����,��������Ϊ����һ�ξ���ȫ���յ�
    {
		char *startPos = strstr(RecvBuffer,"[");
		char *endPos = strstr(RecvBuffer,"]");
		int len1=endPos-startPos+1;
		char ipTxt[64];

		strcpy(ipTxt,"���IP��:");
		strncat(ipTxt,startPos,len1);
            printf("\r\n%s\r\n",ipTxt);
            cls(0,0,0);
            dtext(ipTxt,0,0,255,255,255,0,1);
            ref(0,0,240,320);
            StopDownload();
    }
}

void httpSendGet(void)//������������
{
    int32 dataLen, sendLen = 0;

    dataLen = strlen(httpHead);
    // �������󡭡�
    do{
        sendLen += send(socketHandle, &httpHead[sendLen], dataLen - sendLen);
    } while (sendLen < dataLen);
}


void ConnectCb(int32 data)//����״̬��ѯ�ص�
{
    int32 conState = getsocketstate(socketHandle);

    switch (conState)
    {
    case MR_WAITING:// �������ӷ�����        
        usedTime++;
        if (usedTime > 100)// ���ӷ�������ʱ
        {            
            ErrorStop(3);
        }
    	break;
    case MR_SUCCESS: //�ɹ���ʼ���ͺͽ�������
        timerstop(timerHandle);
        httpSendGet();
        usedTime = 0;
        timerstart(timerHandle, 100, 0, "ReceiveCb", 1);
        break;
    case MR_FAILED:
    case MR_IGNORE:
        ErrorStop(4);
        break;
    }
}

void Connect(int32 ip)//��ʼ����
{
    socketHandle = socket(MR_SOCK_STREAM, MR_IPPROTO_TCP); //����TCP Socket
    connect(socketHandle, ip, port, MR_SOCKET_NONBLOCK); //����Socket
    timerHandle = timercreate();
    timerstart(timerHandle, 200, 0, "ConnectCb", 1);
    printf("\r\nip=%x",ip);
}

int cbGetHostIp(int32 ip)//����IP�ص�����
{
    if(ip!=-1)//��ȡ�ɹ�
   {
    if(ip!=2)
        Connect(ip);
   }
    else
        ErrorStop(5);
    return 0;
}

int cbInitNetwork(int32 result)  //��ʼ���ص�����
{
    switch(result)
    {
    case MR_SUCCESS:
        cbGetHostIp(gethostbyname(hostName, "cbGetHostIp")); //��ȡ�Է�����IP
        break;
    case MR_FAILED:
        ErrorStop(6);
        break;
    }
    return 0;
}
void parseUrl(void)
{
    int32 hostNameLen;
    char *p;
    char *findPos;

    //http://xxx.xxx.xxx:xxxx/x.xxx
    p = findPos = (char*)strstr(&url[7], "/");//����http://�ҵ�һ��/
    

    //��ȡ�������Ͷ˿ں�
    p = (char*)strstr(&url[7], ":");
    if (findPos != NULL)
        hostNameLen = findPos - &url[7];
    else
        hostNameLen = strlen(url) - 7;
    if (p != NULL)//����ж˿ںţ����¼�������������
        hostNameLen = p - &url[7];
    strncat(hostName, &url[7], hostNameLen);//ȡ��������

    if (p == NULL)//ȡ���˿ں�
        port = 80;
    else
        port = strtoul(p+1, NULL, 10);

    //����HTTP����ͷ
    if (findPos == NULL)//����"http://"���������/���ʾ�Ǿ�����ļ�
        findPos="/";//������ҳ
    sprintf(httpHead, "GET %s HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\nConnection: close\r\n\r\n", findPos, hostName);
    printf(httpHead);
}

void StartDownLoad(void)//��ʼ���أ���ʼ�����磩
{
    usedTime = 0;
    parseUrl();
    cbInitNetwork(initnetwork("cbInitNetwork", "cmnet"));
}

int init()
{
    url="http://iframe.ip138.com/ic.asp";//�鱾��IP����ַ
    StartDownLoad();
    return MR_SUCCESS;
}


int event(int32 code, int32 param0, int32 param1)
{
	return MR_SUCCESS;
}

int pause()
{
	return 0;
}

int resume()
{
	return 0;
}
