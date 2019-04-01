#include<stdio.h>
int main()
{
 int a[10],b[10],x[10];
 int waiting[10],turnaround[10],completion[10];
 int i,j,largest,count=0,time,n,s;
 double avg=0,tt=0,end;
 //printf("\nEnter the number of students: ");
 //scanf("%d",&n);
 for(i=0,s=96;i<10;i++,s++)
 {
   printf("\nEnter arrival time of student %c : ",s+1);
   scanf("%d",&a[i]);
 }
 for(i=0,s=96;i<10;i++,s++)
 {
   printf("\nEnter no.of gifts taken by student %c : ",s+1);
   scanf("%d",&b[i]);
 }
 for(i=0;i<10;i++)
 x[i]=b[i];

  b[9]=0;
 //printf("time => process number");
 for(time=0;count!=10;time++)
 {
   largest=9;
  for(i=0;i<10;i++)
  {
   if(a[i]<=time && b[i]>b[largest] && b[i]>0 )
   largest=i;
  }
  b[largest]--;
  //printf("\n%d => p%d",time+1,smallest);
  if(b[largest]==0)
  {
   count++;
   end=time+1;
   completion[largest] = end;
   waiting[largest] = end - a[largest] - x[largest];
   turnaround[largest] = end - a[largest];
  }
 }
 printf("pname \t burst \t arrival \twaiting \tturnaround \tcompletion");
 for(i=0,s=96;i<10;i++,s++)
 {
   printf("\n %c \t   %d \t %d\t\t%d   \t\t%d\t\t%d",s+1,x[i],a[i],waiting[i],turnaround[i],completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
 //printf("\n\n %f   %f",avg,tt);
 printf("\n\nAverage waiting time = %lf\n",avg/10);
 printf("Average Turnaround time = %lf",tt/10);
}
