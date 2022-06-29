#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum GPA
{
    A_pluse=1,
    A,
    B_pluse,
    B,
    C_pluse,
    C,
    D,
    F
}GPA;
typedef struct 
{
  char first_name[10];//名字
  char last_name[10];
  int id_number[12];//学号
  int id_number_year;
  long long id_number_full;
  int C_grade;//成绩
  int C_regrade;//重修成绩
  char GPA[2];
  int rank;//排名  

}stu;
int stu_count;
stu students[100];
void Add();
void Adds();
void Delete();
void Search();
void Sort_by_id();
void Sort_by_score();
void Max();
void Min();
void Ave();
void prime();
void coprime();
long long str_turn_int(int str[],int num);
void GPA_switch(int i);
void exchange_stu(int i,int k);
void Create_Excel (int mode);
int main()
{
    printf("Hello, pls input a student information to star!\n");
    Add();
    while (1)
    {  
        int slect;     
        printf("Okay, data upload finished. What do you what to do next? You can enter a number to tell me.\n1 add\n2 adds\n3 delete\n4 search\n5 sort by id\n6 sort by score\n7 best score\n8 worst score\n9 prime judge\n10 coprime judge\n11 averge score\n0 exit\n");
        scanf("%d",&slect);
        switch (slect)
        {
        case 1:
            Add();
            break;
        case 2:
            Adds();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Search();
            break;
        case 5:
            Sort_by_id();
            printf("output all students info to excel calls: 'students_id_sort.xls'..........\n");
            Create_Excel(0);//使用时请注意修改路径！！！！！！！！！！！！！！！！！！！！
            break;
        case 6:
            Sort_by_score();
            printf("output all students info to excel calls: 'students_score_sort.xls'..........\n");
            Create_Excel(1);//使用时请注意修改路径！！！！！！！！！！！！！！！！！！！！
            break;
        case 7:
            Max();
            break;
        case 8:
            Min();
            break;
        case 9:
            prime();
            break;
        case 10:
            coprime();
            break;
        case 11:
            Ave();
            break;
        case 0:
            goto END;
        default:
            printf("please input a right order number!!!!!!!\n");
            break;
        }
    }
    
    END :
    printf("exit good bey!\n");
    return 0;
}

void Add()
{
    
    printf("please input a student\n");
    printf("please input student's first-name and last-name:\n");//输入名字
    scanf("%s %s",&students[stu_count].first_name,&students[stu_count].last_name);
    getchar();
    printf("please input student's id number:\n"); //输入学号
    for (int i = 0; i < 12; i++)
    {
        char buff;
        scanf("%c",&buff);
        students[stu_count].id_number[i] = atoi(&buff);
    }
    students[stu_count].id_number_full =  str_turn_int(students[stu_count].id_number,12);
    students[stu_count].id_number_year =  (int)str_turn_int(students[stu_count].id_number,4);//提取学号中的年份
    if (students[stu_count].id_number_year==2021)
    {
        printf("please inpu studen's score\n");
        scanf("%d",&students[stu_count].C_grade);
    }
    else if(students[stu_count].id_number_year!=2021)
    {
        printf("please inpu studen's rescore\n");
        scanf("%d",&students[stu_count].C_regrade);
    }
    Sort_by_score();
    GPA_switch(stu_count);
    stu_count++;
    printf("leaving input mode.....\n");
}

void Adds()
{
    int n;
    char buff;
    printf("please input students count you want to input:\n");
    scanf("%d",&n);
    for (int i = stu_count; i < n+stu_count; i++)
    {
        printf("please input student's first-name and last-name:\n");
        scanf("%s %s",&students[i].first_name,&students[i].last_name);
        getchar();
        printf("please input student's id number:\n"); //输入学号
        for (int j = 0; j < 12; j++)
        {
        scanf("%c",&buff);
        students[i].id_number[j] = atoi(&buff);
        }
        students[i].id_number_full =  str_turn_int(students[i].id_number,12);
        students[i].id_number_year =  str_turn_int(students[i].id_number,4);//提取学号中的年份
        if (students[i].id_number_year==2021)
        {
            printf("please inpu studen's score\n");
            scanf("%d",&students[i].C_grade);
        }
        else if(students[i].id_number_year!=2021)
        {
            printf("please inpu studen's rescore\n");
            scanf("%d",&students[i].C_regrade);
        }
        GPA_switch(i);
    }
    stu_count+=n;
    printf("leaving multiinput mode.....\n");
}

void Delete()
{
    int id_number_buff[12];//学号输入缓冲区
    long long id_number;
    int flag;
    printf("please input student's id you want to delete:\n");
    getchar();
    for (int j = 0; j < 12; j++)
    {
        char buff;
        scanf("%c",&buff);
        id_number_buff[j] = atoi(&buff);//输入缓冲区
    }
    for (int i = 0; i < stu_count; i++)//遍历所有学生
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff[j] == students[i].id_number[j])
            {
                flag++;
            }
            if (flag==12)
            {
                printf("you have delated this students %s %s id is:",students[i].first_name,students[i].last_name);
                for (int k = 0; k < 12; k++)//遍历每一个学生的id
                {
                    printf("%d",students[i].id_number[k]);
                }
                students[i].id_number[0]=-1;
            }
        }
    }
    printf("leaving Delete mode.....\n");
}

void Search()
{
    int id_number_buff[12];//学号输入缓冲区
    int flag=0;
    printf("please input student's id you want to search:\n");
    getchar();
    for (int j = 0; j < 12; j++)
    {
        char buff;
        scanf("%c",&buff);
        id_number_buff[j] = atoi(&buff);//输入缓冲区
    }
    getchar();
    for (int i = 0; i <= stu_count; i++)
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff[j] == students[i].id_number[j])
            {
                flag++;
            }
            if (flag==12)
            {
            // printf("you have searched this students %d\n",id_number_buff[i]);
            printf("this is his info:\n");
            printf("firest_name:%s\n",students[i].first_name);
            printf("last_name:%s\n",students[i].last_name);
            if(students[i].C_regrade==0)//判断是否重修，选择输出对应的数据
            printf("C_grade:%d\n",students[i].C_grade);
            else printf("C_regrade:%d\n",students[i].C_regrade);
            printf("rank:%d\n",students[i].rank);
            printf("GPA:%s\n",students[i].GPA);
            goto search_end;
            }
        }
    }
    if(flag!=12)
    {
        printf("no this student!!!!!!!\n");
    }
    search_end: return;
}

void Sort_by_id()
{
    if ( stu_count < 2) 
    {
		return;
	}
    for (int i = 0; i <= stu_count-1; i++)
    {
        for (int i2 = 0; i2 <= stu_count-1-i; i2++)
        {
            for (int j = 0; j < 12; j++)
            {
                if (students[i2].id_number_full>students[i2+1].id_number_full)
                {
                    exchange_stu(i,i+1);//按id排序
                }   
            }
        }
    }
}

void Sort_by_score()
{
    int mode = 1;
    for (int i = 0; i <= stu_count-1; i++)
    {
        for (int i2 = 0; i2 <= stu_count-1-i; i2++)
        {
            for (int j = 0; j < 12; j++)
            {
                if(students[i].id_number_year==2021)
                {
                    if (students[i].C_grade<students[i+1].C_grade)
                    {
                        exchange_stu(i,i+1);//按成绩排序
                    }
                }
                else if(students[i].id_number_year!=2021)
                {
                    if (students[i].C_regrade<students[i+1].C_regrade)
                    {
                        exchange_stu(i,i+1);//按成绩排序
                    }                    
                }
            }
        }
    }
    for (int i = 0; i < 99; i++)
    {
        students[i].rank=i+1;
    }
}

void Max()
{
    Sort_by_score();
    printf("you have searched max score student\n");
    printf("this is his info:\n");
    printf("firest_name:%s\n",students[0].first_name);
    printf("last_name:%s\n",students[0].last_name);
    if(students[0].C_regrade==0)//判断是否重修，选择输出对应的数据
        printf("C_grade:%d\n",students[0].C_grade);
    else 
        printf("C_regrade:%d\n",students[0].C_regrade);
    printf("rank:%d\n",students[0].rank);
    printf("GPA:%s\n",students[0].GPA);
}

void Min()
{
    Sort_by_score();
    printf("you have searched max score student\n");
    printf("this is his info:\n");
    printf("firest_name:%s\n",students[stu_count-1].first_name);
    printf("last_name:%s\n",students[stu_count-1].last_name);
    if(students[stu_count-1].C_regrade==0)//判断是否重修，选择输出对应的数据
        printf("C_grade:%d\n",students[stu_count-1].C_grade);
    else 
        printf("C_regrade:%d\n",students[stu_count-1].C_regrade);
    printf("rank:%d\n",students[stu_count-1].rank);
    printf("GPA:%s\n",students[stu_count-1].GPA);
}

void Ave()
{
    long long sum=0;
    for (int i = 0; i <= stu_count; i++)
    {
        if(students[i].C_regrade==0)
        sum+=students[i].C_grade;
        else
        sum+=students[i].C_regrade;
    }
    double ave=0;
    ave = sum/stu_count;
    printf("The averge of score is %lf\n",ave);
}

void prime()
{
    int a=0;  // 素数的个数
    int num=0;  // 输入的整数
    int id_number_buff[12];//学号输入缓冲区
    int flag;
    printf("please input student's id :\n");
    getchar();
    for (int j = 0; j < 12; j++)
    {
        char buff;
        scanf("%c",&buff);
        id_number_buff[j] = atoi(&buff);//输入缓冲区
    }
    for (int i = 0; i <= stu_count; i++)
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff[j] == students[i].id_number[j])
            {
                flag++;
            }
            if (flag==12)
            {
                if(students[i].C_regrade==0)
                num = students[i].C_grade;
                else
                num = students[i].C_regrade;
            }
        }
        flag=0;
    }
    for(int i=2;i<num;i++){
        if(num%i==0){
            a++;  // 素数个数加1
        }
    }
    if(a==1){
        printf("%d is Prime number.\n",num);
    }else{
        printf("%d is not Prime number.\n",num);
    }
}

void coprime()
{
    int a=0;  // 素数的个数
    int num1=0,num2=0;  // 输入的整数
    int id_number_buff1[12],id_number_buff2[12];//学号输入缓冲区
    int flag1=0,flag2=0;
    printf("please input first student's id :\n");
    getchar();
    for (int j = 0; j < 12; j++)
    {
        char buff;
        scanf("%c",&buff);
        id_number_buff1[j] = atoi(&buff);//输入缓冲区
    }
    getchar();
    for (int i = 0; i <= stu_count; i++)
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff1[j] == students[i].id_number[j])
            {
                flag1++;
            }
            if (flag1==12)
            {
                if(students[i].C_regrade==0)
                num1 = students[i].C_grade;
                else
                num1 = students[i].C_regrade;
            }
        }
        flag1=0;
    }
    //printf("num1 = %d\n",num1);
    printf("please input second student's id :\n");
    //getchar();
    for (int j = 0; j < 12; j++)
    {
        char buff2;
        buff2 = getchar();
        id_number_buff2[j] = buff2-'0';//输入缓冲区
    }
    // for (int i = 0; i < 12; i++)
    // {
    //     printf("%d",id_number_buff2[i]);
    // }
    for (int i = 0; i <= stu_count; i++)
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff2[j] == students[i].id_number[j])
            {
                flag2++;
            }
            if (flag2==12)
            {
                if(students[i].C_regrade==0)
                num2 = students[i].C_grade;
                else
                num2 = students[i].C_regrade;
            }
        }
        flag2=0;
    }
        printf("num2 = %d\n",num2);
    int tmp;
    if(num2==0)
    {
        printf("error\n");
    }
    else
    {
        if(num1<num2)
        {
            tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        while (num1%num2)
        {
            tmp = num2;
            num2 = num1%num2;
            num1 = tmp;
        }
        if(num2==1)
        {
            printf("their id is Coprime.\n");
        }
    else 
    printf("their id is not Coprime.\n");
    }
    
}

void GPA_switch(int i)
{
    if(students[i].C_grade>=95)
    {
        students[i].GPA[0] = 'A';
        students[i].GPA[1] = '+';   
    }
    else if(students[i].C_grade>=90)
    students[i].GPA[0] = 'A';
    else if(students[i].C_grade>=85)
    {
        students[i].GPA[0] = 'B';
        students[i].GPA[1] = '+';  
    }
    else if(students[i].C_grade>=80)
    students[i].GPA[0] = 'B';
    else if(students[i].C_grade>=75)
    {
        students[i].GPA[0] = 'C';
        students[i].GPA[1] = '+';
    }
    else if(students[i].C_grade>=70)
    students[i].GPA[0] = 'C';
    else if(students[i].C_grade>=60||(students[i].C_regrade>60&&students[i].id_number_year!=2021))
    students[i].GPA[0] = 'D';
    else if(students[i].C_grade<60||(students[i].C_regrade<60&&students[i].id_number_year!=2021))
    students[i].GPA[0] = 'F';
}

long long str_turn_int(int str[],int num)//int数组转longlong数据用函数
{
    long long out=0;
    for (int i = 0; i < num; i++)
    {
        out = out*10+str[i];
    }
    return out;
}

void exchange_stu(int i,int k)
{
    stu tmp;
	tmp=students[i];
	students[i]=students[k];
	students[k]=tmp;
}

void Create_Excel (int mode)
{
	FILE* fp_txt = NULL;//D:\2022.2.11\C__homework\C___homework
    if(mode==0)
	fp_txt = fopen("D:\\2022.2.11\\C__homework\\C___homework\\students_id_sort.xls", "w+"); //二进制写入，使用时请注意修改路径！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    else 
    fp_txt = fopen("D:\\2022.2.11\\C__homework\\C___homework\\students_score_sort.xls", "w+");
	fprintf(fp_txt, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n","first name","last name", "id","C score","C rescore","GPA","rank");
    for (int i = 0; i < stu_count; i++)
    {
        fprintf(fp_txt, "%s\t%s\t%lld\t%d\t%d\t%s\t%d\n",students[i].first_name,students[i].last_name,students[i].id_number_full,students[i].C_grade,students[i].C_regrade,students[i].C_regrade,students[i].GPA,students[i].rank);
    }
	fclose(fp_txt);
}

