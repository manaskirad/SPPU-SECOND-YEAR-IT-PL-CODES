//ASSIGNMENT NO.2   (PART A-Without using pointer)
	//Title:Represent matrix using two dimensional arrays and perform following operations with and without pointers:
		//i. Addition
		//ii. multiplication
		//iii. transpose
		//iv. Saddle point

#include<stdio.h>
void addmat(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2);
void mul(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2);
void transpose(int a[10][10],int r1,int c1);
void saddlep(int a[10][10],int r1,int c1);
void main()
{
	int a[10][10],b[10][10],c[10][10],i,j,r1,r2,c1,c2,ch;
	printf("\n Enter the no.s of rows and columns of 1st matrix=");
	scanf("%d %d",&r1,&c1);
	printf("\n Enter the no.s of rows and columns of 2nd matrix=");
	scanf("%d %d",&r2,&c2);
	printf("\n Enter the elements of 1st matrix=");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		scanf("%d", &a[i][j]);
		}
	}
	printf("\n Enter the elements of 2nd matrix=");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
		scanf("%d", &b[i][j]);
		}
	}
	printf("\n Matrix A=\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		printf("%d	", a[i][j]);
		}
		printf("\n");
	}
	printf("\n Matrix B=\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
		printf("%d	", b[i][j]);
		}
		printf("\n");
	}
	do
	{
		printf("\n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle point");
		printf("\n Enter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:addmat(a,b,r1,r2,c1,c2);
				break;
			case 2:mul(a,b,r1,r2,c1,c2);
				break;
			case 3:transpose(a,r1,c1);
				break;
			case 4:saddlep(a,r1,c1);
				break;
			default:printf("\n Invalid choice");
		}
		printf("Do you want to continue?");
	}while(ch!=0);
}
void addmat(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2)
{
	int i,j,c[10][10];
	if(r1==r2 && c1==c2)
	{
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				c[i][j]=a[i][j]+b[i][j];

			}

		}
		printf("\n sum of matrix=\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
			printf("%d	",c[i][j]);
			}
			printf("\n");
		}

	}
	else
	{
		printf("\n Size of both matrix is not matching");
	}
}
void mul(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2)
{
	int i,j,k,c[10][10];
	if(c1==r2)
	{
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				c[i][j]=0;
			}
		}
	}
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				for(k=0;k<c1;k++)
				{
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
			}
		}
	printf("\n multiplication of matrix=\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
			printf("%d	",c[i][j]);
			}
			printf("\n");
		}

}
void transpose(int a[10][10],int r1,int c1)
{
	int i=0,j=0,b[10][10];


		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				b[i][j]=a[j][i];

			}

		}
		printf("\n Transpose of matrix=\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
			printf("%d	",b[i][j]);
			}
			printf("\n");
		}
}
void saddlep(int a[10][10],int r1,int c1)
{
	int i,j,k,min,max,col;

	for(i=0;i<r1;i++)
	{
		min=a[i][0];
		for(j=0;j<c1;j++)
		{
			if(a[i][j]<=min)
			{
				min=a[i][j];
				col=j;
			}
		}
	}
	max=a[0][col];
	for(k=0;k<r1;k++)
	{
		if(a[k][col]>=max)
		{
			max=a[k][col];
		}
	}
	if(min==max)
	{
		printf("\nsaddle point is (%d, %d)",i,col+1);
		printf("\nsaddle point is =%d",max);
	}
	else
	{
		printf("No saddle point");
	}
}

