   #define KUW 40*240/240
   #define KUH (80*400/400)/3
   #define X_ZR 0 
   #define X_UP 40*240/240

   #define X_YR X_UP*2

   #define X_1 X_UP*3

   #define X_2 X_UP*4

   #define X_3 X_UP*5

   #define Y_1 400-KUH*3

   #define Y_2 400-KUH*2

   #define Y_3 400-KUH




   void prevn()
{
   drect(X_ZR,Y_1,KUW,KUH,100,200,100);//�����
   shaderect(X_UP,Y_1,KUW,KUH,0x55cdaf,0x96a5c8,0);//�ϼ�

   dtext("��",X_UP+KUW/3,Y_1+KUH/3,50,50,50,0,0);

   drect(X_YR,Y_1,KUW,KUH,100,200,100);//�����
   shaderect(X_1,Y_1,KUW,KUH,0xbec855,0x5fcd55,0);//1��

   dtext("1",X_1+KUW/3,Y_1+KUH/3,50,50,50,0,0);

   shaderect(X_2,Y_1,KUW,KUH,0xbec855,0x5fcd55,0);//2��

   dtext("2",X_2+KUW/3,Y_1+KUH/3,50,50,50,0,0);

   shaderect(X_3,Y_1,KUW,KUH,0xbec855,0x5fcd55,0);//3��

   dtext("3",X_3+KUW/3,Y_1+KUH/3,50,50,50,0,0);

   shaderect(X_ZR,Y_2,KUW,KUH,0x55cdaf,0x96a5c8,1);//���

   dtext("��",X_ZR+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   drect(X_UP,Y_2,KUW,KUH,100,200,100);//OK��

   dtext("��",X_UP+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   shaderect(X_YR,Y_2,KUW,KUH,0x55cdaf,0x96a5c8,3);//�Ҽ�

   dtext("��",X_YR+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   shaderect(X_1,Y_2,KUW,KUH,0xbec855,0x5fcd55,0);//4��

   dtext("4",X_1+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   shaderect(X_2,Y_2,KUW,KUH,0xbec855,0x5fcd55,0);//5��

   dtext("5",X_2+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   shaderect(X_3,Y_2,KUW,KUH,0xbec855,0x5fcd55,0);//6��

   dtext("6",X_3+KUW/3,Y_2+KUH/3,50,50,50,0,0);

   drect(X_ZR,Y_3,KUW,KUH,100,200,100);//���ż�
   shaderect(X_UP,Y_3,KUW,KUH,0x55cdaf,0x96a5c8,2);//�¼�

   dtext("��",X_UP+KUW/3,Y_3+KUH/3,50,50,50,0,0);

   drect(X_YR,Y_3,KUW,KUH,100,200,100);//�һ���
   shaderect(X_1,Y_3,KUW,KUH,0xbec855,0x5fcd55,0);//7��

   dtext("7",X_1+KUW/3,Y_3+KUH/3,50,50,50,0,0);

   shaderect(X_2,Y_3,KUW,KUH,0xbec855,0x5fcd55,0);//8��

   dtext("8",X_2+KUW/3,Y_3+KUH/3,50,50,50,0,0);

   shaderect(X_3,Y_3,KUW,KUH,0xbec855,0x5fcd55,0);//9��

   dtext("9",X_3+KUW/3,Y_3+KUH/3,50,50,50,0,0);

   for(int i=0;i<=3;i++)dline(0,400-KUH*i,240,400-KUH*i,250,250,250);
   for(int in=0;in<=6;in++)dline(KUW*in,400-KUH*3,KUW*in,400,250,250,250);




   ref(0,400-KUH*3,240,KUH*3);









}




   int EVENT(int type,int p1,int p2)
{
   prevn();
  if(p1>=X_ZR&&p1<=X_ZR+KUW&&p2>=Y_1&&p2<=Y_1+KUH)
event(type-2,_SLEFT,0);
  if(p1>=X_UP&&p1<=X_UP+KUW&&p2>=Y_1&&p2<=Y_1+KUH)event(type-2,_UP,0);
  if(p1>=X_YR&&p1<=X_YR+KUW&&p2>=Y_1&&p2<=Y_1+KUH)event(type-2,_SRIGHT,0);

  if(p1>=X_1&&p1<=X_1+KUW&&p2>=Y_1&&p2<=Y_1+KUH)event(type-2,_1,0);
  if(p1>=X_2&&p1<=X_2+KUW&&p2>=Y_1&&p2<=Y_1+KUH)event(type-2,_2,0);

  if(p1>=X_3&&p1<=X_3+KUW&&p2>=Y_1&&p2<=Y_1+KUH)event(type-2,_3,0);

   if(p1>=X_1&&p1<=X_1+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_4,0);

   if(p1>=X_2&&p1<=X_2+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_5,0);

   if(p1>=X_3&&p1<=X_3+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_6,0);

   if(p1>=X_1&&p1<=X_1+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_7,0);

   if(p1>=X_2&&p1<=X_2+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_8,0);

   if(p1>=X_3&&p1<=X_3+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_9,0);

   if(p1>=X_ZR&&p1<=X_ZR+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_LEFT,0);

   if(p1>=X_UP&&p1<=X_UP+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_SELECT,0);

   if(p1>=X_YR&&p1<=X_YR+KUW&&p2>=Y_2&&p2<=Y_2+KUH)event(type-2,_RIGHT,0);

   if(p1>=X_ZR&&p1<=X_ZR+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_SEND,0);





   if(p1>=X_UP&&p1<=X_UP+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_DOWN,0);

   if(p1>=X_YR&&p1<=X_YR+KUW&&p2>=Y_3&&p2<=Y_3+KUH)event(type-2,_0,0);









  return 0;
}

int even(int type, int p1, int p2)
{
if(KY_DOWN == type)
{
}
return 0;
}