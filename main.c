#include <stdio.h>
#include <stdlib.h>
struct student {
    int id;
    char name[15];
    int grade[3];
};
struct student arr[3];
struct student temp[3];
struct student fillstud (void);
void printstud(struct student *s);
int binary_search(struct student arr[3],int lb,int ub,int ID);

int main()
{
    int ID;int lb=0;int ub=0;int loc;
    for(int i=0;i<3;i++){
           printf("please fill the data of student number %d \n",i+1);
           temp[i]=fillstud();

    }
    printf("enter the id u want to search for");
    scanf("%d",&ID);
   loc= binary_search(temp,lb,ub,ID);
   if(loc==-1){
    printf("the id is not existed");
   }
   else{
    printstud(&(temp[loc]));
   }


    return 0;
}
int binary_search(struct student arr[3],int lb,int ub,int ID){
    int mid;
    int loc=-1;
    while(lb<=ub && loc==-1){
        mid=((lb+ub)/2);
        if(arr[mid].id==ID){
            loc=mid;
        }
        else if(arr[mid].id<ID){
            lb=mid+1;
        }
        else{
            ub=mid-1;
        }
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
