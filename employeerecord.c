#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
	char name[30];
	int id;
	float salary;
	struct address{
		char city[20];
		char state[20];
	}a1;
	struct DOB{
		int date1;
		int month1;
		int year1;
	}b1;
	struct DOJ{
		int date2;
		int month2;
		int year2;
	}j1;
};
int main()
{
	int n,i,x;
	struct employee *ptr;
	printf("Enter the number of employees:");
	scanf("%d",&n);
	ptr=(struct employee*)malloc(n*sizeof(struct employee));
	if(ptr==NULL)
	{
		printf("Not enough space.");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of employee %d",i+1);
		printf("\nEnter employee name:");
		scanf("%s",&(ptr+i)->name);
		printf("\nEnter employee id:");
		scanf("%d",&(ptr+i)->id);
		printf("\nEnter address(city and state):");
		scanf("%s %s",&(ptr+i)->a1.city,&(ptr+i)->a1.state);
		printf("\nEnter the date of birth(dd/mm/yyyy):");
		scanf("%d %d %d",&(ptr+i)->b1.date1,&(ptr+i)->b1.month1,&(ptr+i)->b1.year1);
		printf("\nEnter the date of joining(dd/mm/yyyy):");
		scanf("%d %d %d",&(ptr+i)->j1.date2,&(ptr+i)->j1.month2,&(ptr+i)->j1.year2);
		printf("\nEnter salary:");
		scanf("%f",&(ptr+i)->salary);
	}
    printf("\nEnter the ID of employee you want to access details of. Enter 0 to exit:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
	 if(x==(ptr+i)->id)
	 {
	 	printf("\nThe details of the employee are:");
	 	printf("\nName: %s",(ptr+i)->name);
	    printf("\nAddress: %s, %s",(ptr+i)->a1.city,(ptr+i)->a1.state);
	    printf("\nDate of Birth: %d/%d/%d",(ptr+i)->b1.date1,(ptr+i)->b1.month1,(ptr+i)->b1.year1);
	    printf("\nDate of Joining: %d/%d/%d",(ptr+i)->j1.date2,(ptr+i)->j1.month2,(ptr+i)->j1.year2);
	    printf("\nSalary: %.2f",(ptr+i)->salary);
	 }
	 else if(x==0)
	 {
		printf("\nThe program has now ended. Thank you!");
		exit(0);
	 }
    }
    free(ptr);
    return 0;
}
