#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//����ṹ��
struct tongxunlu                     //����ͨѶ¼�ṹ�����
{
    char name[20];
    char num[20];
    char qq[20];
    char dz[40];
} to[100];                          //Ĭ��100������
int n=0;                            //��¼������ϵ������
int m[0];                           //��¼�����ղص��±�
int count = 0;                          //��¼�����ղص�����
FILE *fp;                           //�����ļ�ָ��
void zhucaidan();                   //���˵�    ����
void lianxi();                      //��ϵ��    ����
void tianjia();                     //����      ����
void readfile();                    //�ļ��ж��뺯��
void writefile();                   //�ļ���д�뺯��
void xiugai();                      //�޸�      ����
void chazhao();                     //����
void shoucang();                    //�����ղ�  ����
void shanchu_dan();                 //ɾ��������ϵ�˺���
void shanchu_quan();                //ɾ��ȫ����ϵ�˺���
void xiugai_shoucang();             //�޸ĸ����ղ�  ����
//--------------------------------------------------------������
int main()
{
    readfile();
    while(1)
    {
        zhucaidan();
    }
    return 0;
}
//���˵�--------------------------------------------------��ģ��
void zhucaidan()
{
    char c;
    system("cls");
    printf("\n\t   1-��ϵ��        2-�����ϵ��   ");
    printf("\n\t   3-�޸���ϵ��    4-������ϵ��   ");
    printf("\n\t   5-�����ղ�      0-�����˳�     \n");
    printf("\n\t   ��ѡ��������Ҫ�ķ���");
    c=getch();
    switch (c)                      //�����ϱߵ�ѡ����Ŀ
    {
    case '1':
        lianxi();                //��ʾ��ϵ��
        break;
    case '2':
        tianjia();               //�����ϵ��
        break;
    case '3':
        xiugai();                //�޸���ϵ��
        break;
    case '4':
        chazhao();                //������ϵ��
        break;
    case '5':
        shoucang();               //�����ղ�
        break;
    case '0':
        writefile();              //�����˳�
        break;
    default:
        zhucaidan();              //���û���򷵻����˵��ȴ�����
    }
}
//------------------------------------------ģ��һ--------��ʾ��ϵ��
void lianxi()
{
    int k;
    char cn;
    system("cls");                                  //�����Ļ
    printf("\n\t    1-�����ղ�        2-������ϵ��");
    printf("\n\t    3-�޸���ϵ��      4-������ϵ��  ");
    printf("\n\t    5-ȫ��ɾ��        0-�������˵�");
    printf("\n\t    ��ѡ����Ҫ�ķ���");
    cn = getch();
    switch(cn)
    {
    case '1':
        if(count!= 0)
        {
            system("cls");
            printf("\n\n\t��ʾ��ϵ�ˣ�");
            printf("\n\n\t�����ղ�:");
            printf("\n\n���     ����\t     �绰\t    QQ\t\t    ��ַ");
            for(k = 0; k<count; k++)
            {
                printf("\n %2d %10s%14s%14s%14s",m[k]+1,to[m[k]].name,to[m[k]].num,to[m[k]].qq,to[m[k]].dz);
            }
            getch();
            lianxi();
        }
        else
        {
            printf("\n\n\t�����ղ�Ϊ�գ�");
            getch();
            lianxi();
        }
        getch();
        break;
    case '2':
        if(n!= 0)
        {
            system("cls");
            printf("\n\n\t ������ϵ��:");
            printf("\n\n���     ����\t     �绰\t    QQ\t\t    ��ַ ");
            for(k = 0; k<n; k++)
            {
                printf("\n %2d %10s%14s%14s%14s",k+1,to[k].name,to[k].num,to[k].qq,to[k].dz);
            }
            getch();
            lianxi();
        }
        else
        {
            printf("\n\n\t��ϵ��Ϊ�գ�");
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
//-------------------------------------------ģ���--------�����ϵ��
void tianjia()
{
    system("cls");
    printf("\n\t��������ϵ�˵���Ϣ(�������˵��밴#)");
    printf("\n\t����������");
    scanf("%s",to[n].name);
    if(strcmp(to[n].name,"#")==0)
        zhucaidan();
    printf("\n\t����绰��");
    scanf("%s",to[n].num);
    if(strcmp(to[n].num,"#")==0)
        zhucaidan();
    printf("\n\t����QQ��");
    scanf("%s",to[n].qq);
    if(strcmp(to[n].qq,"#")==0)
        zhucaidan();
    printf("\n\t�����ַ��");
    scanf("%s",to[n].dz);
    if(strcmp(to[n].dz,"#")==0)
        zhucaidan();

    printf("\n\t�Ƿ��ղظ���ϵ�ˣ�y/Y����");      //-����----�����ղ�
    if(getch()=='y'||getch()=='Y')
    {
        m[count] = n;
        count++;
    }
    n++;
    fclose(fp);
    printf("\n\t�Ƿ���������ϵ�ˣ�y/Y����");
    if(getch()=='y'||getch()=='Y')
        tianjia();
    return;
}
//-------------------------------------------ģ����--------�޸���ϵ��
void xiugai()
{
    int c,m;
    system("cls");
    if(n == 0)
    {
        printf("\n\t    ����ϵ�ˣ�");
        printf("\n\t    ��������������˵�");
        getch();
        return;
    }
    system("cls");
    printf("\n\t    ��������Ҫ�޸ĵ���ϵ�˵���ţ�����0������ϵ�ˣ�");
    scanf("%d",&c);
    if(c == 0)
        lianxi();
    if(c < 0||c > n)
    {
        printf("\n\t    �������");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   ��������Ҫ�޸ĵ���ϵ�˵���Ϣ��");
        printf("\n\t     ������%s",to[c-1].name);
        printf("\n\t     �绰��%s",to[c-1].num);
        printf("\n\t     QQ��  %s",to[c-1].qq);
        printf("\n\t     ��ַ��%s",to[c-1].dz);
        printf("\n\n\t   �Ƿ��޸ģ�y/Y��?");
        if(getch()=='y'||getch()=='Y')
        {
            printf("\n\t    1-�޸�����      2-�޸ĵ绰");
            printf("\n\t    3-�޸�QQ        4-�޸ĵ�ַ");
            printf("\n\t    5-�޸ĸ����ղ�  6-ɾ����ϵ��");
            printf("\n\t    0-�������˵�");
            printf("\n\t   ��ѡ����Ҫ�޸ĵ�ѡ�");
            scanf("%d",&m);
            switch(m)
            {
            case 1:
                printf("\n\t   ������������");
                scanf("%s",to[c-1].name);
                printf("\n\t   �������޸ĺ����ϵ�˵���Ϣ��");
                printf("\n\t     ������%s",to[c-1].name);
                printf("\n\t     �绰��%s",to[c-1].num);
                printf("\n\t     QQ��  %s",to[c-1].qq);
                printf("\n\t     ��ַ��%s",to[c-1].dz);
                getch();
                break;
            case 2:
                printf("\n\t   ������绰��");
                scanf("%s",to[c-1].num);
                printf("\n\t   �������޸ĺ����ϵ�˵���Ϣ��");
                printf("\n\t     ������%s",to[c-1].name);
                printf("\n\t     �绰��%s",to[c-1].num);
                printf("\n\t     QQ��  %s",to[c-1].qq);
                printf("\n\t     ��ַ��%s",to[c-1].dz);
                getch();
                break;
            case 3:
                printf("\n\t   ������QQ��");
                scanf("%s",to[c-1].qq);
                printf("\n\t   �������޸ĺ����ϵ�˵���Ϣ��");
                printf("\n\t     ������%s",to[c-1].name);
                printf("\n\t     �绰��%s",to[c-1].num);
                printf("\n\t     QQ��  %s",to[c-1].qq);
                printf("\n\t     ��ַ��%s",to[c-1].dz);
                getch();
                break;
            case 4:
                printf("\n\t   �������ַ��");
                scanf("%s",to[c-1].dz);
                printf("\n\t   �������޸ĺ����ϵ�˵���Ϣ��");
                printf("\n\t     ������%s",to[c-1].name);
                printf("\n\t     �绰��%s",to[c-1].num);
                printf("\n\t     QQ��  %s",to[c-1].qq);
                printf("\n\t     ��ַ��%s",to[c-1].dz);
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
                printf("\n\t    �������!");
                printf("\n\t    �Ƿ�����޸ģ�y/Y����");
                if(getch()=='y'||getch()=='Y')
                    xiugai();
                else
                    zhucaidan();
            }
        }
    }
}
//-------------------------------------------ģ����--------������ϵ��
void chazhao()
{
    char nam[20],uu;
    int i;
    system("cls");
    printf("\n\t");
    printf("\n\t*********����*********");
    printf("\n\t     �����룺");
    scanf("%s",nam);
    for(i = 0; i<n; i++)
    {
        if(strcmp(to[i].name,nam)==0||strcmp(to[i].num,nam)==0 || strcmp(to[i].qq,nam)==0 || strcmp(to[i].dz,nam)==0)
        {
            printf("\n\t******������Ϣ����******");
            printf("\n\t\t ������ %s",to[i].name);
            printf("\n\t\t �绰�� %s",to[i].num);
            printf("\n\t\t QQ��   %s",to[i].qq);
            printf("\n\t\t ��ַ�� %s",to[i].dz);

            printf("\n\t\t 1-�޸���ϵ��   2- �������˵�");
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
            printf("\n\t    û���ҵ�����������ݣ�");
            getch();
            printf("\n\t\t �Ƿ�������ң���y/Y��");

            if(getch()=='y'||getch()=='Y')
                chazhao();
            else
                zhucaidan();
        }
    }
}
//--------------------------------------------ģ����--------�����ղ�
void shoucang()
{
    int k;
    system("cls");
    if(count!= 0)
    {
        system("cls");
        printf("\n\n\t��ʾ��ϵ�ˣ�");
        printf("\n\n\t�����ղ�:");
        printf("\n\n\t     ����\t�绰\t        QQ\t\t��ַ ");
        for(k = 0; k<count; k++)
        {
            printf("\n\t%10s%14s%14s%14s",to[m[k]].name,to[m[k]].num,to[m[k]].qq,to[m[k]].dz);
        }
        printf("\n\t�Ƿ��޸ĸ����ղأ�");
        if(getch()=='y'||getch()=='Y')
            xiugai_shoucang();
        getch();
        zhucaidan();
    }
    else
    {
        printf("\n\n\t�����ղ�Ϊ�գ�");
        getch();
        zhucaidan();
    }
    getch();

}
//-----------------------------------------ģ����--------д�벢�����ļ�
void writefile()
{
    int k;
    if((fp==fopen("to.txt","w"))==NULL)
    {
        printf("\n\t       �ļ���ʧ��");
    }
    for(k = 0; k<n; k++)
    {
        if(fwrite(&to[k],sizeof(struct tongxunlu),1,fp) != 1)
        {
            printf("\n\t    д���ļ�����\n");
        }
    }
    fclose(fp);
    printf("\n\t     ͨѶ¼�ļ��ѱ���");
    printf("\n\t    ��������˳�����\n\t\t");
    exit(0);
}
//-----------------------------------------ģ����--------��������д�ļ�
void readfile()
{
    if((fp=fopen("to.txt","r"))==NULL)
    {
        printf("\n\t\t\t    ͨѶ¼�ļ�������");
        if((fp = fopen("to.txt","w"))==NULL)
        {
            printf("\n\t       ����ʧ��");
            exit(0);
        }
        else
        {
            printf("\n\t    �ɹ�����ͨѶ¼�ļ�    ");
            printf("\n\t    ���������ȥ���˵�    ");
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
        printf("\n\t       �ļ�����ɹ�");
        printf("\n\t    ���������ȥ���˵�    ");
        return;
    }
    printf("\n\t       �ļ�����ɹ�");
    printf("\n\t    ���������ȥ���˵�    ");
    return;
}
//----------------------------------------ģ���--------����Сģ��

void shanchu_dan()                            //ɾ��������ϵ�˺���
{
    int c,e;
    system("cls");
    if(n == 0)
    {
        printf("\n\t    ����ϵ�ˣ�");
        printf("\n\t    ��������������˵�");
        getch();
        return;
    }
    system("cls");
    printf("\n\t    ��������Ҫɾ������ϵ�˵����(��0������ϵ��)��");
    scanf("%d",&c);
    if(c == 0)
        lianxi();
    if(c < 0||c > n-1)
    {
        printf("\n\t    �������");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   ��������Ҫɾ������ϵ�˵���Ϣ��");
        printf("\n\t     ������%s",to[c-1].name);
        printf("\n\t     �绰��%s",to[c-1].num);
        printf("\n\t     QQ��  %s",to[c-1].qq);
        printf("\n\t     ��ַ��%s",to[c-1].dz);
        printf("\n\n\t   �Ƿ�ɾ����y/Y��?");
        if(getch()=='y'||getch()=='Y')
        {
            for(e = c; e < n-1; e++)
                to[e]= to[e+1];
            n--;
            printf("\n\t   ɾ���ɹ���");
            printf("�Ƿ����ɾ����y/Y����");
            if(getch()=='y'||getch()=='Y')
                shanchu_dan();
            return;
        }
        else
            return;
    }
}
void shanchu_quan()                           //ɾ��ȫ����ϵ�˺���
{
    printf("\n\t\t ȷ��ɾ��(y/Y)?");
    if(getch()=='y'||getch()=='Y')
    {
        fclose(fp);
        if((fp=fopen("to.txt","w"))==NULL)
        {
            printf("\n\t   ɾ��ʧ�ܣ�");
            readfile();
        }
        n = 0;
        count = 0;
        printf("\n\t ��¼��ɾ������������������˵�");
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
    printf("\n\t*******�޸ĸ����ղ�*******");
    if(n == 0)
    {
        printf("\n\t    ����ϵ�ˣ�");
        printf("\n\t    ��������������˵�");
        getch();
        return;
    }

    printf("\n\t    ��������Ҫ�޸ĵ���ϵ�˵����(��0������ϵ��)��");
    scanf("%d",&c);
    if(c == 0)
        return;
    if(c < 0||c > n-1)
    {
        printf("\n\t    �������");
        getch();
        xiugai();
    }
    else
    {
        printf("\n\t   ��������Ҫ�޸ĵ���ϵ�˵���Ϣ��");
        printf("\n\t     ������%s",to[c-1].name);
        printf("\n\t     �绰��%s",to[c-1].num);
        printf("\n\t     QQ��  %s",to[c-1].qq);
        printf("\n\t     ��ַ��%s",to[c-1].dz);
        for(i = 0;i<count; i++)
        {
            if(m[i]==c)
            {
                printf("\n\t    ����ϵ��Ϊ�����ղأ�");
                printf("\n\t    �Ƿ��޸���ϵ��Ϊ���ղأ�y/Y��?");
                if(getch()=='y'||getch()=='Y')
                {
                    for(j = i; j < count; j++)
                         m[j]= m[j+1];
                }
                printf("\n\t    �޸ĳɹ�!");
                getch();
                zhucaidan();

            }
            else
            {
                printf("\n\t    ����ϵ�˲��Ǹ����ղأ�");
                printf("\n\t   �Ƿ��޸���ϵ��Ϊ�����ղأ�y/Y��?");
                if(getch()=='y'||getch()=='Y')
                {
                    for(j = count; j > i; j--)
                         m[j]= m[j-1];
                }
                m[i]=c;
                printf("\n\t    �޸ĳɹ�!");
                getch();
                zhucaidan();
            }
        }

    }
}
