#include "stdio.h"
#include <stdlib.h>
//����C����ʵ�����Ϲ���ϵͳ��Ҫ��
//1���г���������ѡ���ż���Ӧ�۸�
//2�������û�ѡ��ı�ź͹���������ʾ�û���Ҫ����Ľ�
//3���ж��û��������Ƿ���ȷ�������ȷ��ʾ������ɹ�����
//
//ȡ�����ϣ������������������ȷ��ʾ������ʧ�ܡ���
//*********************************
//	���ϼ۸��
//  ��� ����    ���ۣ�Ԫ��
//  1    ��֭      2
//  2    ѩ��      3
//  3    ơ��      4
//*********************************
//��ѡ���蹺������ϱ�ż�����������
  ordergen(int drinktype,int totalmoney )
{	int i;
	FILE *fp;
	char filemsg[30];
            //�����ļ�ָ�����
	sprintf(filemsg,"ĳ�û�������%d�������ϣ�������%dԪ",drinktype,totalmoney);  
    fp=fopen("d:\\order.txt","a");     
	if(fp==NULL)                    
	{
		printf("д�ļ���ʧ��!");
		exit(0);
	}

	fwrite(&filemsg,strlen(filemsg),1,fp);
    fputc('\n',fp);
	fclose(fp);         
}

int isintnum(char putstr[20])
{
 	
   int i=0,flag=0;
  
   for(i=0;putstr[i]!='\0';++i)
   {
   if (('0'>putstr[i]||'9'<putstr[i])&&'.'!=putstr[i])
      {
       flag = 2; // char
       break;
       }
  else if ('.' == putstr[i])
      {
       flag = 1; // float
      }
      else{}
     }
	return flag;
}

main()
{  for(;;)
   {   int waterno=0,buycount=0;
	   char drinktype[20],drinkcount[10];
      int totalmoney=0,inputmoney=0;
     // char filename[]="d:\\order.txt";
      printf("***************************************\n");
      printf("\t\t���ϼ۸��\t\t\n");
      printf("\t���\t����\t���ۣ�Ԫ��\n");
      printf("\t1\t��֭\t2\n");
      printf("\t2\tѩ��\t3\n");
      printf("\t3\tơ��\t4\n");
      printf("***************************************\n");
      printf("��ѡ���蹺������ϱ�ţ�\n");
      scanf("%s",drinktype);
      printf("��ѡ���蹺�������������\n");
      scanf("%s",drinkcount);
	waterno=isintnum(drinktype);
	buycount=isintnum(drinkcount);	
      if(buycount!=0||waterno!=0)
                     printf("�����������\n");
      else
        {  switch(atoi(drinktype))
              {   case 1:totalmoney=atoi(drinkcount)*2;break;
                  case 2:totalmoney=atoi(drinkcount)*3;break;
                  case 3:totalmoney=atoi(drinkcount)*4;break;
                 }
           printf("�����踶��%dԪ,�����븶���\n",totalmoney); 
           scanf("%d",&inputmoney);
           
      if(inputmoney==totalmoney)
                     {               switch(atoi(drinktype))
                                        {   case 1:printf("����ɹ����뼰ʱȡ�߳�֭\n");break;
                                            case 2:printf("����ɹ����뼰ʱȡ��ѩ��\n");break;
                                            case 3:printf("����ɹ����뼰ʱȡ��ơ��\n");break;
                                           }
                                          ordergen(atoi(drinktype),totalmoney); 
                                           }
      
           else
               printf("����ʧ�ܣ��ټ�!\n");
               }}
	system("pause");
	return 0;
}

