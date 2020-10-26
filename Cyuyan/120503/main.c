#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//定义结构体
struct tongxunlu                     //定义通讯录结构体变量
{
    char name[20];
    char num[20];
    char qq[20];
    char dz[40];
} to[100];                          //默认100个数据
int n=0;                            //记录数据联系人数量
int m[0];                           //记录个人收藏的下标
int count = 0;                          //记录个人收藏的人数
FILE *fp;                           //定义文件指针
void zhucaidan();                   //主菜单    函数
void lianxi();                      //联系人    函数
void tianjia();                     //增加      函数
void readfile();                    //文件中读入函数
void writefile();                   //文件中写入函数
void xiugai();                      //修改      函数
void chazhao();                     //查找
void shoucang();                    //个人收藏  函数
void shanchu_dan();                 //删除单个联系人函数
void shanchu_quan();                //删除全部联系人函数
void xiugai_shoucang();             //修改个人收藏  函数
//--------------------------------------------------------主函数
int main()
{
    readfile();
    while(1)
    {
        zhucaidan();
    }
    return 0;
}
//主菜单--------------------------------------------------主模块
void zhucaidan()
{
    char c;
    system("cls");
    printf("\n\t   1-联系人        2-添加联系人   ");
    printf("\n\t   3-修改联系人    4-查找联系人   ");
    printf("\n\t   5-个人收藏      0-保存退出     \n");
    printf("\n\t   请选择您所所要的服务：");
    c=getch();
    switch (c)                      //对于上边的选择项目
    {
    case '1':
        lianxi();                //显示联系人
        break;
    case '2':
        tianjia();               //添加联系人
        break;
    case '3':
        xiugai();                //修改联系人
        break;
    case '4':
        chazhao();                //查找联系人
        break;
    case '5':
        shoucang();               //个人收藏
        break;
    case '0':
        writefile();              //保存退出
        break;
    default:
        zhucaidan();              //如果没有则返回主菜单等待输入
    }
}
//------------------------------------------模块一--------显示联系人
void lianxi()
{
    int k;
    char cn;
    system("cls");                                  //清空屏幕
    printf("\n\t    1-个人收藏        2-所有联系人");
    printf("\n\t    3-修改联系人      4-查找联系人  ");
    printf("\n\t    5-全部删除        0-返回主菜单");
    printf("\n\t    请选择你要的服务：");
    cn = getch();
    switch(cn)
    {
    case '1':
        if(count!= 0)
        {
            system("cls");
            printf("\n\n\t显示联系人：");
            printf("\n\n\t个人收藏:");
            printf("\n\n序号     姓名\t     电话\t    QQ\t\t    地址");
            for(k = 0; k<count; k++)
            {
                printf("\n %2d %10s%14s%14s%14s",m[k]+1,to[m[k]].name,to[m[k]].num,to[m[k]].qq,to[m[k]].dz);
            }
            getch();
            lianxi();
        }
        else
        {
            printf("\n\n\t个人收藏为空！");
            getch();
            lianxi();
        }
        getch();
        break;
    case '2':
        if(n!= 0)
        {
            system("cls");
            printf("\n\n\t 所有联系人:");
            printf("\n\n序号     姓名\t     电话\t    QQ\t\t    地址 ");
            for(k = 0; k<n; k++)
            {
                printf("\n %2d %10s%14s%14s%14s",k+1,to[k].name,to[k].num,to[k].qq,to[k].dz);
            }
            getch();
            lianxi();
        }
        else
        {
            printf("\n\n\t联系人为空！");
            getch();
            lianxi();
        }
        break;
    case '3':
        xiugai();
        break;
    case '4':
        chazhao();
        break;
    case '5':
        shanchu_quan();
        break;
    case '0':
        zhucaidan();
        break;
    default:
        lianxi();
        return;
    }
}
//-------------------------------------------模块二--------添加联系人
void tianjia()
{
    system("cls");
    printf("\n\t请输入联系人的信息(返回主菜单请按#)");
    printf("\n\t输入姓名：");
    scanf("%s",to[n].name);
    if(strcmp(to[n].name,"#")==0)
        zhucaidan();
    printf("\n\t输入电话：");
    scanf("%s",to[n].num);
    if(strcmp(to[n].num,"#")==0)
        zhucaidan();
    printf("\n\t输入QQ：");
    scanf("%s",to[n].qq);
    if(strcmp(to[n].qq,"#")==0)
        zhucaidan();
    printf("\n\t输入地址：");
    scanf("%s",to[n].dz);
    if(strcmp(to[n].dz,"#")==0)
        zhucaidan();

    printf("\n\t是否收藏该联系人（y/Y）？");      //-加入----个人收藏
    if(getch()=='y'||getch()=='Y')
    {
        m[count] = n;
        count++;
    }
    n++;
    fclose(fp);
    printf("\n\t是否继续添加联系人（y/Y）？");
    if(getch()=='y'||getch()=='Y')
        tianjia();
    return;
}
//-------------------------------------------模块三--------修改联系人
void xiugai()
{
    int c,m;
    system("cls");
    if(n == 0)
    {
        printf("\n\t    无联系人！");
        printf("\n\t    按任意键返回主菜单");
        getch();
        return;
    }
    system("cls");
    printf("\n\t    请输入你要修改的联系人的序号！（按0返回联系人）");
    scanf("%d",&c);
    if(c == 0)
        lianxi();
    if(c < 0||c > n)
    {
        printf("\n\t    输入错误！");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   以下是你要修改的联系人的信息：");
        printf("\n\t     姓名：%s",to[c-1].name);
        printf("\n\t     电话：%s",to[c-1].num);
        printf("\n\t     QQ：  %s",to[c-1].qq);
        printf("\n\t     地址：%s",to[c-1].dz);
        printf("\n\n\t   是否修改（y/Y）?");
        if(getch()=='y'||getch()=='Y')
        {
            printf("\n\t    1-修改姓名      2-修改电话");
            printf("\n\t    3-修改QQ        4-修改地址");
            printf("\n\t    5-修改个人收藏  6-删除联系人");
            printf("\n\t    0-返回主菜单");
            printf("\n\t   请选择你要修改的选项：");
            scanf("%d",&m);
            switch(m)
            {
            case 1:
                printf("\n\t   请输入姓名：");
                scanf("%s",to[c-1].name);
                printf("\n\t   以下是修改后的联系人的信息：");
                printf("\n\t     姓名：%s",to[c-1].name);
                printf("\n\t     电话：%s",to[c-1].num);
                printf("\n\t     QQ：  %s",to[c-1].qq);
                printf("\n\t     地址：%s",to[c-1].dz);
                getch();
                break;
            case 2:
                printf("\n\t   请输入电话：");
                scanf("%s",to[c-1].num);
                printf("\n\t   以下是修改后的联系人的信息：");
                printf("\n\t     姓名：%s",to[c-1].name);
                printf("\n\t     电话：%s",to[c-1].num);
                printf("\n\t     QQ：  %s",to[c-1].qq);
                printf("\n\t     地址：%s",to[c-1].dz);
                getch();
                break;
            case 3:
                printf("\n\t   请输入QQ：");
                scanf("%s",to[c-1].qq);
                printf("\n\t   以下是修改后的联系人的信息：");
                printf("\n\t     姓名：%s",to[c-1].name);
                printf("\n\t     电话：%s",to[c-1].num);
                printf("\n\t     QQ：  %s",to[c-1].qq);
                printf("\n\t     地址：%s",to[c-1].dz);
                getch();
                break;
            case 4:
                printf("\n\t   请输入地址：");
                scanf("%s",to[c-1].dz);
                printf("\n\t   以下是修改后的联系人的信息：");
                printf("\n\t     姓名：%s",to[c-1].name);
                printf("\n\t     电话：%s",to[c-1].num);
                printf("\n\t     QQ：  %s",to[c-1].qq);
                printf("\n\t     地址：%s",to[c-1].dz);
                getch();
                break;
            case 5:
                shanchu_dan();
                break;
            case 6:
                xiugai_shoucang();
                break;
            case 0:
                zhucaidan();
                break;
            default:
                printf("\n\t    输入错误!");
                printf("\n\t    是否继续修改（y/Y）：");
                if(getch()=='y'||getch()=='Y')
                    xiugai();
                else
                    zhucaidan();
            }
        }
    }
}
//-------------------------------------------模块四--------查找联系人
void chazhao()
{
    char nam[20],uu;
    int i;
    system("cls");
    printf("\n\t");
    printf("\n\t*********查找*********");
    printf("\n\t     请输入：");
    scanf("%s",nam);
    for(i = 0; i<n; i++)
    {
        if(strcmp(to[i].name,nam)==0||strcmp(to[i].num,nam)==0 || strcmp(to[i].qq,nam)==0 || strcmp(to[i].dz,nam)==0)
        {
            printf("\n\t******查找信息如下******");
            printf("\n\t\t 姓名： %s",to[i].name);
            printf("\n\t\t 电话： %s",to[i].num);
            printf("\n\t\t QQ：   %s",to[i].qq);
            printf("\n\t\t 地址： %s",to[i].dz);

            printf("\n\t\t 1-修改联系人   2- 返回主菜单");
            uu = getch();
            switch(uu)
            {
            case '1':
                xiugai();
                break;
            case '2':
                zhucaidan();
                break;
            default:
                chazhao();
            }
        }
        else
        {
            printf("\n\t    没有找到您输入的内容！");
            getch();
            printf("\n\t\t 是否继续查找？（y/Y）");

            if(getch()=='y'||getch()=='Y')
                chazhao();
            else
                zhucaidan();
        }
    }
}
//--------------------------------------------模块五--------个人收藏
void shoucang()
{
    int k;
    system("cls");
    if(count!= 0)
    {
        system("cls");
        printf("\n\n\t显示联系人：");
        printf("\n\n\t个人收藏:");
        printf("\n\n\t     姓名\t电话\t        QQ\t\t地址 ");
        for(k = 0; k<count; k++)
        {
            printf("\n\t%10s%14s%14s%14s",to[m[k]].name,to[m[k]].num,to[m[k]].qq,to[m[k]].dz);
        }
        printf("\n\t是否修改个人收藏：");
        if(getch()=='y'||getch()=='Y')
            xiugai_shoucang();
        getch();
        zhucaidan();
    }
    else
    {
        printf("\n\n\t个人收藏为空！");
        getch();
        zhucaidan();
    }
    getch();

}
//-----------------------------------------模块六--------写入并保存文件
void writefile()
{
    int k;
    if((fp==fopen("to.txt","w"))==NULL)
    {
        printf("\n\t       文件打开失败");
    }
    for(k = 0; k<n; k++)
    {
        if(fwrite(&to[k],sizeof(struct tongxunlu),1,fp) != 1)
        {
            printf("\n\t    写入文件错误！\n");
        }
    }
    fclose(fp);
    printf("\n\t     通讯录文件已保存");
    printf("\n\t    按任意键退出程序\n\t\t");
    exit(0);
}
//-----------------------------------------模块七--------建立并读写文件
void readfile()
{
    if((fp=fopen("to.txt","r"))==NULL)
    {
        printf("\n\t\t\t    通讯录文件不存在");
        if((fp = fopen("to.txt","w"))==NULL)
        {
            printf("\n\t       建立失败");
            exit(0);
        }
        else
        {
            printf("\n\t    成功建立通讯录文件    ");
            printf("\n\t    按任意键进去主菜单    ");
            getch();
            return;
        }
        exit(0);
    }
    fseek(fp,0,2);
    if(ftell(fp)>0)
    {
        rewind(fp);
        for(n = 0; !feof(fp)&&fread(&to[n],sizeof (struct tongxunlu),1,fp); n++);
        printf("\n\t       文件导入成功");
        printf("\n\t    按任意键进去主菜单    ");
        return;
    }
    printf("\n\t       文件导入成功");
    printf("\n\t    按任意键进去主菜单    ");
    return;
}
//----------------------------------------模块八--------附件小模块

void shanchu_dan()                            //删除单个联系人函数
{
    int c,e;
    system("cls");
    if(n == 0)
    {
        printf("\n\t    无联系人！");
        printf("\n\t    按任意键返回主菜单");
        getch();
        return;
    }
    system("cls");
    printf("\n\t    请输入你要删除的联系人的序号(按0返回联系人)：");
    scanf("%d",&c);
    if(c == 0)
        lianxi();
    if(c < 0||c > n-1)
    {
        printf("\n\t    输入错误！");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   以下是你要删除的联系人的信息：");
        printf("\n\t     姓名：%s",to[c-1].name);
        printf("\n\t     电话：%s",to[c-1].num);
        printf("\n\t     QQ：  %s",to[c-1].qq);
        printf("\n\t     地址：%s",to[c-1].dz);
        printf("\n\n\t   是否删除（y/Y）?");
        if(getch()=='y'||getch()=='Y')
        {
            for(e = c; e < n-1; e++)
                to[e]= to[e+1];
            n--;
            printf("\n\t   删除成功！");
            printf("是否继续删除（y/Y）：");
            if(getch()=='y'||getch()=='Y')
                shanchu_dan();
            return;
        }
        else
            return;
    }
}
void shanchu_quan()                           //删除全部联系人函数
{
    printf("\n\t\t 确认删除(y/Y)?");
    if(getch()=='y'||getch()=='Y')
    {
        fclose(fp);
        if((fp=fopen("to.txt","w"))==NULL)
        {
            printf("\n\t   删除失败！");
            readfile();
        }
        n = 0;
        count = 0;
        printf("\n\t 记录已删除，按任意键返回主菜单");
        getch();
        return;
    }
    else
        return;
}
void xiugai_shoucang()
{

    int i,c,j,m1;
    system("cls");
    printf("\n\t*******修改个人收藏*******");
    if(n == 0)
    {
        printf("\n\t    无联系人！");
        printf("\n\t    按任意键返回主菜单");
        getch();
        return;
    }

    printf("\n\t    请输入你要修改的联系人的序号(按0返回联系人)：");
    scanf("%d",&c);
    if(c == 0)
        return;
    if(c < 0||c > n-1)
    {
        printf("\n\t    输入错误！");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   以下是你要修改的联系人的信息：");
        printf("\n\t     姓名：%s",to[c-1].name);
        printf("\n\t     电话：%s",to[c-1].num);
        printf("\n\t     QQ：  %s",to[c-1].qq);
        printf("\n\t     地址：%s",to[c-1].dz);
        for(i = 0;i<count; i++)
        {
            if(m[i]==c)
            {
                printf("\n\t    该联系人为个人收藏！");
                printf("\n\t    是否修改联系人为不收藏（y/Y）?");
                if(getch()=='y'||getch()=='Y')
                {
                    for(j = i; j < count; j++)
                         m[j]= m[j+1];
                }
                printf("\n\t    修改成功!");
                getch();
                zhucaidan();

            }
            else
            {
                printf("\n\t    该联系人不是个人收藏！");
                printf("\n\t   是否修改联系人为个人收藏（y/Y）?");
                if(getch()=='y'||getch()=='Y')
                {
                    for(j = count; j > i; j--)
                         m[j]= m[j-1];
                }
                m[i]=c;
                printf("\n\t    修改成功!");
                getch();
                zhucaidan();
            }
        }

    }
}
