
//���η��������
void rect_text(char *txt,int x,int y,int w,int h)
{
 rectst rect; 
 colorst color;
 rect.x=x;
 rect.y=y;
 rect.w=w;
 rect.h=h;

color.r=R;
color.g=G;
color.b=B;

dtextex(txt,rect.x,rect.y,&rect,&color,2,1);

}
void bei()
{
 cls(10,10,10);
drect(0,th,240,1,R/2,G/2,B/2);
int H=320-th;
drect(0,H,240,1,R/2,G/2,B/2);
text("����",240-tw*2,H);
time(240/2-tw,H);

}

//��Ϸ����
void about()
{
bei();
dtext("��Ϸ����",(240-tw*4)/2,0,155,255,255,0,0);
rect_text("
����Ϸ������:wildly[QQ:319965592]
MOCתMPC�޸���:earring[QQ:394921907]
��Ϸ�˵����������:����[QQ:643552878]
���޸���:�������[QQ:347799812]",0,th,240,320);
ref(0,0,240,320);
}


//��Ϸ����
void help()
{
bei();
dtext("��Ϸ����",(240-tw*4)/2,0,155,255,255,0,0);
rect_text("[��Ϸ����]��
���ص�HP��ս��HPΪ0ʱ��Ϸʧ�ܣ����л��ɵ�������ػ�����
�����Ż������ӱ�ըЧ����BOSS�Ĺ�����ǿ��
�������ﵽһ����Ϸʤ����
<��ʾ>_���ִﵽһ����������������������仯��
[����]:0���򣣼�ȫ����ɱ��������˳���
"
,0,th,240,320);
ref(0,0,240,320);
}

typedef struct
//ʱ��ṹ��
{
uint16 year;
uint8  month;
uint8  day;
uint8  hour;
uint8  minute;
uint8  second;
} datetime;

//����Ļ�ϵ�xx,yyλ����ʾʱ��

void time(int xx,int yy)
{
datetime date;
getdatetime(&date);

char *da=malloc(5);

sprintf(da,"%d:%02d",date.hour,date.minute,date.second);
text(da,xx,yy);
free(da);

}