#include <stdio.h>
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
  int GPA;
  int rank;//排名  

}stu;
int stu_count;
stu students[100];
void Add();
void Adds();
void Delet();
void Search();
void Sort_by_id();
void Sort_by_score();
void Max();
void Min();
void Ave();
void prime();
void coprime();
int str_turn_int(int str[],int num);
int main()
{
    
    while (1)
    {       
     printf("ababab");   




    }
    
}

void Add()
{
    char year[4] = "2021";
    printf("please input a student\n");

    printf("please input student's first-name and last-name:\n");//输入名字
    scanf("%s %s",&students[stu_count].first_name,&students[stu_count].last_name);

    printf("please input student's id number:\n"); //输入学号
    for (int i = 0; i < 12; i++)
    {
        scanf("%d",&students[stu_count].id_number[i]);
    }
    students[stu_count].id_number_full =  str_turn_int(students[stu_count].id_number,12);
    students[stu_count].id_number_year =  str_turn_int(students[stu_count].id_number,4);//提取学号中的年份
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

    stu_count++;
    printf("leaving input mode.....\n");
}

void Adds()
{
    int n;
    printf("please input students count you want to input:\n");
    scanf("%d",&n);
    for (int i = stu_count; i < n+stu_count; i++)
    {
        printf("please input student's first-name and last-name:\n");
        scanf("%s %s",&students[i].first_name,&students[i].last_name);
        printf("please input student's id number:\n"); //输入学号
        for (int i = 0; i < 12; i++)
        {
            scanf("%d",&students[i].id_number[i]);
        }
        students[i].id_number_full =  str_turn_int(students[i].id_number,12);
        students[i].id_number_year =  str_turn_int(students[i].id_number,4);//提取学号中的年份
        printf("please inpu studen's score\n");
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
    for (int j = 0; j < 12; j++)
    {
    scanf("%d",&id_number_buff[j]);//输入缓冲区
    }
    for (int i = 0; i < 100; i++)//遍历所有学生
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
    int flag;
    printf("please input student's id you want to search:");
    for (int j = 0; j < 12; j++)
    {
    scanf("%d",&id_number_buff[j]);//输入缓冲区
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 12; j++)//遍历每一个学生的id
        {
            if(id_number_buff[j] == students[i].id_number[j])
            {
                flag++;
            }
            if (flag==12)
            {
            printf("you have searched this students %s",id_number_buff[i]);
            printf("this is his info:");
            printf("firest_name:%s\n",students[i].first_name);
            printf("last_name:%s\n",students[i].last_name);
            if(students[i].C_regrade==0)//判断是否重修，选择输出对应的数据
            printf("C_grade:%d\n",students[i].C_grade);
            else printf("C_regrade:%d\n",students[i].C_regrade);
            printf("rank:%d\n",students[i].rank);
            printf("GPA:%d\n",students[i].GPA);
            }
        }
    }
}

void Sort_by_id()
{
    int mode = 0;
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (students[i].id_number_full<students[i+1].id_number_full)
            {
                exchange_stu(i,i+1);//按id排序
            }   
        }
    }
    printf("output all students info to excel calls: 'students_id_sort.xls'..........\n");
    Create_Excel(mode);

}

int str_turn_int(int str[],int num)//int数组转longlong数据用函数
{
    int out=0;
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
	// if (fp_txt == NULL)
	// {
	// 	printf("fp_txt is fail\n");
	// }
	fprintf(fp_txt, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n","姓","名", "学号","C语言成绩","重修成绩","GPA","排名");
    for (int i = 0; i < stu_count; i++)
    {
        fprintf(fp_txt, "%s\t%s\t%lld\t%d\t%d\t%d\t%d\n",students[i].first_name,students[i].last_name,students[i].id_number_full,students[i].C_grade,students[i].C_regrade,students[i].C_regrade,students[i].GPA,students[i].rank);
    }
	fclose(fp_txt);
}
