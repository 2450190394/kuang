#include "stdio.h"
#include <stdlib.h>
//利用C语言实现饮料购买系统，要求：
//1、列出三种饮料选择编号及对应价格；
//2、根据用户选择的编号和购买数量提示用户需要付款的金额；
//3、判断用户付款金额是否正确，如果正确提示“付款成功，请
//
//取走饮料（变量）”，如果金额不正确提示“付款失败”。
//*********************************
//	饮料价格表
//  编号 名称    单价（元）
//  1    橙汁      2
//  2    雪碧      3
//  3    啤酒      4
//*********************************
//请选择需购买的饮料编号及购买数量！
  ordergen(int drinktype,int totalmoney )
{	int i;
	FILE *fp;
	char filemsg[30];
            //定义文件指针变量
	sprintf(filemsg,"某用户购买了%d类型饮料，并付款%d元",drinktype,totalmoney);  
    fp=fopen("d:\\order.txt","a");     
	if(fp==NULL)                    
	{
		printf("写文件打开失败!");
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
      printf("\t\t饮料价格表\t\t\n");
      printf("\t编号\t名称\t单价（元）\n");
      printf("\t1\t橙汁\t2\n");
      printf("\t2\t雪碧\t3\n");
      printf("\t3\t啤酒\t4\n");
      printf("***************************************\n");
      printf("请选择需购买的饮料编号！\n");
      scanf("%s",drinktype);
      printf("请选择需购买的饮料数量！\n");
      scanf("%s",drinkcount);
	waterno=isintnum(drinktype);
	buycount=isintnum(drinkcount);	
      if(buycount!=0||waterno!=0)
                     printf("您的输入错误！\n");
      else
        {  switch(atoi(drinktype))
              {   case 1:totalmoney=atoi(drinkcount)*2;break;
                  case 2:totalmoney=atoi(drinkcount)*3;break;
                  case 3:totalmoney=atoi(drinkcount)*4;break;
                 }
           printf("您共需付款%d元,请输入付款金额！\n",totalmoney); 
           scanf("%d",&inputmoney);
           
      if(inputmoney==totalmoney)
                     {               switch(atoi(drinktype))
                                        {   case 1:printf("付款成功，请及时取走橙汁\n");break;
                                            case 2:printf("付款成功，请及时取走雪碧\n");break;
                                            case 3:printf("付款成功，请及时取走啤酒\n");break;
                                           }
                                          ordergen(atoi(drinktype),totalmoney); 
                                           }
      
           else
               printf("付款失败，再见!\n");
               }}
	system("pause");
	return 0;
}

