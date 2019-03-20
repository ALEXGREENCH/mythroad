#include <base.h>

int32 timer;


int init(void)
{
    cls(0,0,0);
    ref(0,0,SCRW,SCRH);
    timer=timercreate();
    timerstart(timer,1,0,"draw",1);
    return 0;
}

//�ƶ��ٶ�
#define XSPEED 5
#define YSPEED 10

int xSpeed=XSPEED,ySpeed=YSPEED;
int x=30,y=30,w=20,h=20;
int lastx,lasty;//�������Ƴ����ٶ�

void draw(int data){
    lastx=x; lasty=y;//������һ�ε�λ��
    //�ж��Ƿ�Խ��
    if(x>SCRW-w-XSPEED || x<XSPEED) xSpeed=-xSpeed;
    if(y>SCRH-h-YSPEED || y<YSPEED) ySpeed=-ySpeed;
    //�ı�λ��
    x+=xSpeed;
    y+=ySpeed;

    drect(lastx,lasty,w,h,0,0,0);
    drect(x,y,w,h,255,0,0);
    ref(lastx,lasty,w,h);
    ref(x,y,w,h);
}

int event(int type, int p1, int p2)
{
    if(KY_UP == type)
    {
        switch(p1)
        {
        case _SELECT:
            timerdel(timer);
            exit();
            break;
        case _1:
            break;
        }
    }

    return 0;
}

int pause(void)
{
    return 0;
}

int resume(void)
{
    return 0;
}