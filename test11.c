#include<stdio.h>
	#include<stdlib.h>

	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	};	//node

	struct node *getnewnd()
	{
		struct node *newnd;
		int x;
		scanf("%d",&x);
		newnd=(struct node*)malloc(sizeof(struct node));
		newnd->data=x;
		newnd->next=NULL;
		newnd->prev=NULL;
		return newnd;
	}//getnewnd

	struct node *insert(struct node *headnd,struct node *newnd)
	{
		struct node *tempnd;
		tempnd=headnd;
		if(newnd->data<tempnd->data)
		{
			newnd->next=tempnd;
			tempnd->prev=newnd;
			headnd=newnd;
			return headnd;
		}
		while(newnd->data>tempnd->data && tempnd->next!=NULL)
		{
			tempnd=tempnd->next;
		}//while
		if(newnd->data<tempnd->data)
			tempnd=tempnd->prev;
		if(tempnd->next==NULL)
		{
			newnd->prev=tempnd;
			tempnd->next=newnd;
		}//if
		else
		{
			newnd->next=tempnd->next;
			tempnd->next->prev=newnd;
			newnd->prev=tempnd;
			tempnd->next=newnd;
		}//else
		return headnd;
	}//insert

	struct node *createlist()
	{
		int i,n,value;
		struct node *headnd,*newnd,*tempnd;
		headnd=NULL;
		printf("\nEnter the no of elements : ");
		scanf("%d",&n);
		printf("\nEnter the elements\n");
		for(i=0;i<n;i++)
		{
			newnd=getnewnd();
			if(headnd==NULL)
			{
				headnd=tempnd=newnd;
			}//if
			else
			{
				headnd=insert(headnd,newnd);
			}//else
		}//for loop
		return headnd;
	};	//Create DLL

	void display(struct node *headnd)
	{
		struct node *current;
		for(current=headnd;current!=NULL;current=current->next)
		{
			printf(" %d ",current->data);
		}//for
	}	//display

struct node *delet(struct node *headnd,int key)
	{
		struct node *tempnd,*temp1;
		tempnd=headnd;
		if(key==tempnd->data)
		{
			headnd=headnd->next;
			//free(tempnd);
			return headnd;
		}
		while(key!=tempnd->data)
		{
			temp1=tempnd;
			tempnd=tempnd->next;
		}//while
		 if(tempnd->next==NULL)
		{
			temp1->next=NULL;
			//free(tempnd);
		}//if
		else
		{
			temp1->next=tempnd->next;
			tempnd->next->prev=temp1;
			//free(tempnd);
		}//else
		free(tempnd);
		return headnd;
	}//delete

	void reverse(struct node *headnd)
	{
		struct node *current;
		current=headnd;
		while(current->next!=NULL)
			current=current->next;
		while(current!=NULL)
		{
			printf(" %d ",current->data);
			current=current->prev;
		}//while
	}	//reverse

	void modify(struct node *headnd)
	{
		int x,d;
		struct node *tempnd,*temp1;
		printf("\nEnter data to be modified:");
		scanf("%d",&x);
		//temp1=tempnd;
		tempnd=headnd;
		while(tempnd->data!=x)
		{
			tempnd=tempnd->next;
		}//while
			printf("\nEnter new data:");
			scanf("%d",&x);
			tempnd->data=x;
	}//modify

	int main()
	{
		struct node *headnd,*newnd;
		int choice,key;
		while(1)
		{
			printf("\n******MENU*******");
			printf("\n1.Create\n2.Display");
			printf("\n3.Insert\n4.Delete\n5.Reverse");
			printf("\n6.Modify\n7.Exit");
			printf("\nEnter choice:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					headnd=createlist();
					break;
				case 2:
					display(headnd);
					break;
				case 3:
					printf("\nEnter data:");
					newnd=getnewnd();
					headnd=insert(headnd,newnd);
					display(headnd);
					break;
				case 4:
					printf("\nEnter record to be deleted:");
					scanf("%d",&key);
					headnd=delet(headnd,key);
					display(headnd);
					break;
				case 5:
					printf("\nReverse:");
					reverse(headnd);
					break;
				case 6:
					modify(headnd);
					break;
				case 7:
					exit(0);
					break;
				default:
					printf("\nWrong choice entered");
			}//switch
		}//while
		return 0;
	}//main
