#include <stdio.h>
typedef struct employee
{
	char name[100];
	int id;
	float sal;
	char post[100];
}employee;

void create()
{
	FILE *ptr;
	int num,i;
	employee emp;
	ptr=fopen("Employee.txt","w");
	if(ptr)
	{
		printf("\nHow many records you want to enter: ");
		scanf("%d",&num);
		for(i=1;i<=num;i++)
		{
			printf("\nEnter the details employee %d: ",i);
			printf("\nName: ");
			scanf("%s",&emp.name);
			printf("Employee Id: ");
			scanf("%d",&emp.id);
		      printf("Salary(Rs.):  ");
			scanf("%f",&emp.sal);
			printf("Post: ");
			scanf("%s",&emp.post);
			fwrite(&emp,sizeof(employee),1,ptr);
		}
		fclose(ptr);
	}
	else
		printf("File Opening Error!!");
}

void display()
{
	FILE *ptr;
	int num,i;
	employee emp;
	ptr=fopen("Employee.txt","r");
	if(ptr==NULL)
		printf("\nFile Opening Error!");
	else
	{
		printf("\n___________________________________");
		printf("\n Name\tId\tSalary(Rs.)\tPost");
		printf("\n___________________________________");
		fread(&emp,sizeof(employee),1,ptr);
		while(!feof(ptr))
		{
			printf("\n %s",emp.name);
			printf("\t %d",emp.id);
			printf("\t %f",emp.sal);
			printf("\t %s",emp.post);
			fread(&emp,sizeof(employee),1,ptr);
		}
		fclose(ptr);
	}
}

int retrieve(int Id)
{
	int i=0,flag=0;
	employee emp;
	FILE *ptr=fopen("Employee.txt","r");
	if(ptr==NULL)
		printf("\nFile Opening Error!");
	else
	{

		fread(&emp,sizeof(employee),1,ptr);
		while(!feof(ptr))
		{
			if(Id==emp.id)
			{
				printf("\nRecord Found!");
				printf("\n___________________________________");
				printf("\n Name\tId\tSalary\tPost");
				printf("\n___________________________________");
				printf("\n %s",emp.name);
				printf("\t %d",emp.id);
				printf("\t %f",emp.sal);
				printf("\t %s",emp.post);
				flag=1;
				break;
			}
			else
			{
				i++;
				fread(&emp,sizeof(employee),1,ptr);
			}
		}
		fclose(ptr);
		 if(flag==0)
            return -1;
		 else
		 return i;
	}
}

void delete()
{
	int Id,i=0,d;
	employee emp;
	FILE *ptr,*temp;
	ptr=fopen("Employee.txt","r");
	temp=fopen("Temp.txt","w");
	if(ptr==NULL)
		printf("\nFile Opening Error!");
	else
	{
		printf("\n\nEnter Employee Id to be deleted: ");
		scanf("%d",&Id);
		d=retrieve(Id);
		if(d!=-1)
		{
			fread(&emp,sizeof(employee),1,ptr);
			while(!feof(ptr))
			{
				if(d!=i)
					fwrite(&emp,sizeof(employee),1,temp);
				i++;
				fread(&emp,sizeof(employee),1,ptr);
			}
			fclose(ptr);
			fclose(temp);

			remove("Employee.txt");
			rename("Temp.txt","Employee.txt");
		}
	}
}

int modify()
{
	int Id,i=0,m;
	employee emp;
	FILE *ptr,*temp;
	ptr=fopen("Employee.txt","r");
	temp=fopen("Temp1.txt","w");
	if(ptr==NULL)
		printf("File Opening Error!");
	else
	{
		printf("\nEnter Id of the record to be modified: ");
		scanf("%d",&Id);
		m=retrieve(Id);
		if(m!=-1)
		{
			fread(&emp,sizeof(employee),1,ptr);
			while(!feof(ptr))
			{
				if(m!=i)
					fwrite(&emp,sizeof(employee),1,temp);
				else
				{
					printf("\nModify the Record:- ");
					printf("New Salary(Rs.): ");
					scanf("%f",&emp.sal);
					printf("New Post: ");
					scanf("%s",&emp.post);
					fwrite(&emp,sizeof(employee),1,temp);
				}
				i++;
				fread(&emp,sizeof(employee),1,ptr);
			}
			fclose(ptr);
			fclose(temp);

			remove("Employee.txt");
			rename("Temp1.txt","Employee.txt");
		}
	}
}

void main()
{
	int Id,ch,a;
	create();
	do
	{
		printf("\n1.Display\n2.Retrieve\n3.Delete\n4.Modify");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display();
				break;

			case 2:
				printf("\n\nEnter Employee Id to be searched: ");
				scanf("%d",&Id);
				retrieve(Id);
				break;

			case 3:
				delete();
				printf("\n\nRecord Deleted!");
				display();
				break;

			case 4:
				modify();
				printf("\n\nRecord Modified!");
				display();
				break;
		}

		printf("\nWould you like to continue(1/0): ");
		scanf("%d",&a);
	}while(a==1);
}
