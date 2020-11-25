#include<stdio.h>
	#include<stdlib.h>

	struct node
	{
		int data;
		struct node *next;
	};	//structure

	struct node *createlist()
	{
		int i,n,x;
		struct node *headnd,*tempnd,*newnd;
		headnd=NULL;
		printf("\nEnter number of elements:");
		scanf("%d",&n);
		printf("\nEnter the elements now:\n");
		for(i=0;i<n;i++)
		{
			scanf("\n%d",&x);
			newnd=(struct node*)malloc(sizeof(struct node));
			newnd->data=x;
			newnd->next=NULL;
			if(headnd==NULL)	//if SLL is Empty
			{
				headnd=tempnd=newnd;
			}//if
			else				//if SLL not empty
			{
				tempnd->next=newnd;
				tempnd=newnd;
			}//else
		}//for
		return headnd;
	};	//createlist

	void display(struct node *headnd)
	{
			if(headnd!=NULL)
			{
				printf("\t%d",headnd->data);
				display(headnd->next);
			}//if
	}//display

	void revert(struct node* headnd)
	{
		struct node *tempnd,*headnd1;
		tempnd=headnd1=headnd;
		tempnd=tempnd->next->next;
		headnd=headnd->next;
		headnd1->next=NULL;
		headnd->next=headnd1;
		while(tempnd!=NULL)
		{
			headnd1=headnd;
			headnd=tempnd;
			tempnd=tempnd->next;
			headnd->next=headnd1;
		}//while
		for( ;headnd!=NULL;headnd=headnd->next)
		printf("\t%d",headnd->data);
	}//revert

	void reverse(struct node *headnd)
	{
			if(headnd!=NULL)
			{
				reverse(headnd->next);
				printf("\t%d",headnd->data);
			}//if
	}//reverse

	int countnodes(struct node *headnd)
	{
	  struct node *current;
	  int n;
	  for(n=0,current=headnd;current!=NULL; current=current->next)
	  {
	    n++;
	  }//for
	return n;
	}//countnodes

	struct node *insert(struct node *headnd,int pos)
	{
		int i,value,n;
		struct node *current,*newnd;
		n=countnodes(headnd);
		if(pos>n||pos<0)
		{
			printf("\nWrong position!!");
			return headnd;
		}//if
		printf("\nEnter data:");
		scanf("%d",&value);
		newnd=(struct node*)malloc(sizeof(struct node));
		newnd->data=value;
		if(pos==0)		//add node at beginning
		{
			newnd->next=headnd;
			headnd=newnd;
		}//if
		else
		{
			for(i=0,current=headnd;i<pos-1;current=current->next,i++)
			{
				continue;
			}//for
			if(pos==n)
			{		//add node at end
			newnd->next=NULL;
			current->next=newnd;
			}
			else			//add node in between
			{
				newnd->next=current->next;
				current->next=newnd;
			}//else
		}//else
		return headnd;
	}//insert

	struct node *delet(struct node *headnd,int pos)
	{
		int i,n;
		struct node *current,*tempnd;
		n=countnodes(headnd);
		if(pos>n||pos<0)
		{
			printf("\nWrong position!!");
			return headnd;
		}//if
		if(pos==0)		//delete node at beginning
		{
			tempnd=headnd;
			headnd=headnd->next;
		}//if
		else
		{
			for(i=0,current=headnd;i<pos-1;current=current->next,i++)
			{
				continue;
			}//for
			tempnd=current->next;
			if(pos==n-1)		//add node at end
				current->next=NULL;
			else			//add node in between
			{
				current->next=tempnd->next;
			}//else
		}//else
		free(tempnd);
		return headnd;
	}//delete

	int main()
	{
		struct node *headnd,*headnd1;
		int choice,pos;
		while(1)
		{
			printf("\n******MENU*******");
			printf("\n1.Create\n2.Display");
			printf("\n3.Insert\n4.Delete\n5.Reverse");
			printf("\n6.Revert\n7.Exit");
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
					printf("\nEnter position where data is to be inserted");
					scanf("%d",&pos);
					headnd=insert(headnd,pos);
					display(headnd);
					break;
				case 4:
					printf("\nEnter position where data is to be deleted");
					scanf("%d",&pos);
					headnd=delet(headnd,pos);
					display(headnd);
					break;
				case 5:
					printf("\nReverse:");
					reverse(headnd);
					break;
				case 6:
					printf("\nRevert:");
					revert(headnd);
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
