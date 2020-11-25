#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node * getnode()
{
	node *newnode;
	newnode=(struct node *)malloc(sizeof(node));
	printf("\nEnter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;//returning address of newnode
}
node * create(node *first)
{
	node *temp,*newnode;
	char ch='y';
	while(ch=='y')
	{
		newnode=getnode();//allocate memory
		if(first==NULL)//for first node only
		{
			first=newnode;//points to 1st node
			temp=newnode;
		}
		else
		{
			temp->next=newnode;//linking next node with prev. node
			temp=newnode;//move temp to last node
		}
		printf("\nDo you want to Add a node (y/n):");
		scanf(" %c",&ch);
	}
	return first;
}
void display(node *first)
{
	node *temp;
	temp=first;//temp points 1st node
	if(temp==NULL)
	{
		printf("\nList Empty");
		exit(0);
	}
	while(temp!=NULL)
	{
		printf("\t%d->",temp->data);
		temp=temp->next;//move temp to next node
	}
	printf("NULL");
}
node * addatbeg(node *first)
{
	node *newnode;
	newnode=getnode();//new node is created
	newnode->next=first;//link is created between newnode and first
	first=newnode;//first points to newnode
	return first;
}
node * addatend(node *first)
{
	node *newnode,*temp;
	temp=first;
	newnode=getnode();//new node is created
	while(temp->next!=NULL)//temp points till last node
	{
		temp=temp->next;
	}
	temp->next=newnode;//link is created between temp and newnode
	return first;
}
node *addatmid(node *first)
{
	int key;
	node *newnode,*temp;
	printf("\nEnter after which node you want to enter:");
	scanf("%d",&key);
	newnode=getnode();
	temp=first;//temp is pointing to 1st node
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			newnode->next=temp->next;//linking newnode with temp
			temp->next=newnode;//temp is linked with newnode
			break;
		}
		temp=temp->next;//move temp to next node
	}
	return first;
}
node *delatbeg(node *first)
{
	node *temp;
	temp=first;//temp points to 1st node
	first=first->next;//move first to next node
	temp->next=NULL;
	free(temp);
	return first;
}
node *delatend(node *first)
{
	node *t1,*t2;
	t1=first;//t1 points to first node
	t2=first->next;//t2 points to 2nd node
	while(t2->next!=NULL)
	{
		t1=t1->next;
		t2=t2->next;
	}
	t1->next=NULL;
	free(t2);
	return first;//return address of first
}
node *delatmid(node *first)
{
	node *t1,*t2;
	t1=first;//t1 points 1st node
	t2=first->next;//t2 points 2nd node
	int val;
	printf("\nEnter the node you want to Delelte:");
	scanf("%d",&val);
	while(t2!=NULL)
	{
		if(t2->data==val)
		{
			t1->next=t2->next;
			t2->next=NULL;//break link between nodes
			free(t2);//free memory pointed by t2
		}
		t1=t1->next;//move t1 to next node
		t2=t2->next;//t2 moves to next node
	}
	return first;//return address of first
}
node * rev(node *first)
{
	node *temp,*mid;
	node *back=NULL;
	temp=first;
	while(temp!=NULL)
	{
		mid=temp;//mid points to temp
		temp=temp->next;//move temp to next node
		mid->next=back;//mid of next points back
		back=mid;//back points mid
	}
	first=back;
	return first;
}
void reverse(node *first)
{
	if(first!=NULL)
	{
		//printf("\t%d",first->data);
		reverse(first->next);
		printf("\t %d",first->data);//Reverse using Recursion
	}
}
void main()
{
	node *first=NULL;
	int ch;
	first=create(first);
	do
	{
		printf("\n1.Display\n2.Add at Begning\t3.Add at End\t4.Add at Middle\n5.Delete at begning\t6.Delete at End\t7.Delete at Middle\n8.Reverse\t9.Reverse using Recurssion\n10.Exit");
		printf("\nChose any one operation:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display(first);
				break;
			case 2:
				first=addatbeg(first);//calling Add at Begining
				display(first);
				break;
			case 3:
				first=addatend(first);//calling Add at End function
				display(first);
				break;
			case 4:
				first=addatmid(first);//calling Add at Middle function
				display(first);
				break;
			case 5:
				first=delatbeg(first);//calling Delete at Begining function
				display(first);
				break;
			case 6:
				first=delatend(first);//calling Delete at End function
				display(first);
				break;
			case 7:
				first=delatmid(first);//calling Delete at Middle function
				display(first);
				break;
			case 8:
				first=rev(first);//Calling Reverse function
				display(first);
				break;
			case 9:printf("\n Reverse using Recursion \n");
				reverse(first);//calling Reverse
				break;
		}
	}while(ch<10);
}
