#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int id;
    char name[15];
    int grade[3];
};
//char temp[3];

struct student arr[3];
void merge_sort(int lb,int ub);
void merge(int lb,int mid,int high);
struct student fillstud (void);
void printstud(struct student *s);

int main()
{
    for (int i =0;i<3;i++){
      printf("please fill the menu for the student number %d\n",i+1);
      arr[i]= fillstud();
   }
   merge_sort(0,2);
   printf("the sorted data is\n");
   for (int i=0;i<3;i++){
       //printf ("the data sorted:\n");
        printstud(&(arr[i]));


   }




    return 0;
}
void merge_sort(int lb,int ub){
    printf("test1\n");
    int mid;
    if(lb<ub){
    printf("entered the merge sort part 1\n");

        mid=((lb+ub)/2);
        merge_sort(lb,mid);
        merge_sort(mid+1,ub);
        merge(lb,mid,ub);
        printf("entered the merge sort\n");
    }
}
void merge(int lb, int mid,int ub){
    struct student temp[3];
    int list1;
    int list2;
    int i;
    list1=lb;
    list2=mid+1;
    i=lb;
    while(list1<=mid && list2<=ub){
        if(arr[list1].id<arr[list2].id){
            temp[i]=arr[list1];
            list1++;i++;
        }
        else{
            temp[i]=arr[list2];
            list2++;
            i++;
        }
    }
    while(list1<=mid)
    {
        temp[i]=arr[list1];
        list1++;
        i++;
    }
    while (list2<=ub)
    {
        temp[i]=arr[list1];
        list2++;
        i++;
    }
    for(i=lb;i<=ub;i++){
        arr[i]=temp[i];
    }
}
struct student fillstud(void){
   static int i =0;struct student s;
    //for (count =0;count<)
    printf ("enter the id :\n");
    scanf ("%d",&s.id);
    printf ("enter the name:\n");
    scanf("%s",s.name);
   // printf ("enter the grade");
    for (i=0;i<3;i++){
        printf ("enter the grade of subject no %d\n",i+1);
        scanf("%d",&(s.grade[i]));
    }
    return s;
    }
    ////////////////////
    void printstud (struct student *s){
    int i ;int sum=0;
    printf ("student id is %d",s->id);
    printf ("the name is %s",s->name);
    for (i=0;i<3;i++){
        printf ("\nthe grade of subject %d is : %d \n",i+1,s->grade[i]);
    }
    for (i=0;i<3;i++){
        sum+=s->grade[i];
    }
    printf ("the sum of the grades are : %d \n",sum);

}
