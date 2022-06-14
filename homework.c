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
  char id_number[12];//学号
  int C_grade;//成绩
  int C_regrade;//重修成绩
  int GPA;
  int rank;//排名  

}stu;
int stu_count;
stu students[100];
void Add();
void Adds();
void Delet(int id);
void Search(int id);
int main()
{
    
    while (1)
    {       
     printf("ababab");   




    }
    
}

void Add()
{
    printf("please input a student\n");
    printf("please input student's first-name and last-name:\n");
    scanf("%s %s",&students[stu_count].first_name,&students[stu_count].last_name);
    printf("please input student's id number:\n"); 
    scanf("%s",&students[stu_count].id_number);
    printf("please inpu studen's score\n");
    scanf("%d",&students[stu_count].rank);
    stu_count++;
    printf("leaving input mode.....\n");
}

void Adds()
{
    int n;
    printf("please input students count you want to input:");
    scanf("%d",&n);
    for (int i = stu_count; i < n+stu_count; i++)
    {
        printf("please input student's first-name and last-name:\n");
        scanf("%s %s",&students[i].first_name,&students[i].last_name);
        printf("please input student's id number:\n"); 
        scanf("%s",&students[i].id_number);
        printf("please inpu studen's score\n");
        scanf("%d",&students[i].rank);
    }
    stu_count+=n;
    printf("leaving input mode.....\n");
}

void Delete