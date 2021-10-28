#include<stdio.h>
#include<stdlib.h>

void traverse();
void insertbegin();
void insertend();
void insertafternode();
void insertspecificlocation();
void deletebegin();
void deleteend();
void deleteafternode();
void deletefromspecificlocation();

struct node
{
	int info;
	struct node *next;
};
struct node *start = NULL;
struct node *start1 = NULL;
main()
{
	int choice;
	while(1)
	{
		printf("\n1.Traverse\n2.Insert at begin\n3.Insert at end\n4.Insert after a given node\n5.Insert at a specific location\n6.Delete from beginning\n7.Delete from end\n8.Delete After a given node\n9.Delete from specific location\n10.EXIT\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					traverse();
					break;
			case 2:
					insertbegin();
					break;
			case 3:
					insertend();
					break;
			case 4:
					insertafternode();
					break;
			case 5:
					insertspecificlocation();
					break;
			case 6:
					deletebegin();
					break;
			case 7:
					deleteend();
					break;
			case 8:
					deleteafternode();
					break;
			case 9:
					deletefromspecificlocation();
					break;
			case 10:
					exit(0);
			default:
					printf("\nWrong Choice\n");
		}
	}
}
void traverse()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp = start;
		printf("\nValues of list are\n");
		do
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}while(temp != start);
	}
}
void insertbegin()
{
	struct node *temp,*last;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = temp;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		last = start;
		while(last->next != start)
		{
			last = last->next;
		}
		temp->next = start;
		start = temp;
		last->next = temp;
	}	
}
void insertend()
{
	struct node *temp,*ptr;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = temp;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		ptr = start;
		while(ptr->next != start)	
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = start;
	}
}

void insertafternode()
{
	struct node *temp,*ptr,*ptr1;
	int item,value;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = temp;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		printf("\nEnter the value after which you want to insert\n");
		scanf("%d",&value);
		ptr = start;
		while(ptr->next != start && ptr->info != value)
		{
			ptr = ptr->next;
			ptr1 = ptr->next;
		}
		if(ptr->info != value)
		{
			printf("\nNode is not present\n");
		}
		else if(ptr->next == start)
		{
			ptr->next = temp;
			temp->next = start;
		}
		else if(ptr == start)
		{
			temp->next = ptr->next;
			start->next = temp;
		}
		else
		{
			temp->next = ptr1;
			ptr->next = temp;
			
		}
	}		
}
void insertspecificlocation()
{
	struct node *temp,*ptr,*ptr1;
	int item,loc,count=1;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		printf("\nEnter the location at which you want to insert\n");
		scanf("%d",&loc);
		if(loc == 1)
		{
			temp->next = ptr->next;
			start->next = temp;
		}
		else
		{
			ptr = start;
			while(ptr->next != start && count!=loc)
			{
				ptr1 = ptr;
				ptr = ptr->next;
				count++;
			}
			if(loc > count)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr1->next = temp;
				temp->next = ptr;
			}
		}
	}
}

void deletebegin()
{
	struct node *temp,*last;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else if(start->next == start)
	{
			printf("\nDelete node = %d\n",start->info);
			start = NULL;
	}
	else
	{
		last = start;
		while(last->next != start)
		{
			last = last->next;	
		}
		temp = start;
		start = start->next;
		last->next = start;
		printf("\nDelete node = %d\n",temp->info);
		free(temp);
	}
}
void deleteend()
{
	struct node *temp1,*temp2;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else if(start->next == start)
	{
		printf("\nDelete node = %d\n",start->info);
		start = NULL;		
	}
	else
	{
		temp1 = start;
		while(temp1->next != start)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = temp1->next;
		printf("\nDelete node = %d\n",temp1->info);
		free(temp1);
	}	
}
void deleteafternode()
{
	struct node *ptr1,*ptr2;
	int value;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the value after which you want to delete\n");
		scanf("%d",&value);
		ptr1 = start;
		while(ptr1->next != start && ptr1->info != value)
		{
			ptr1 = ptr1->next;
		}
		if(ptr1->info != value)
		{
			printf("\nNode is not present\n");
		}
		else if(start->next == start)
		{
			start = NULL;
		}
		else
		{
			ptr2 = ptr1->next;
			ptr1->next = ptr2->next;
			printf("\nDelete node = %d\n",ptr2->info);
			free(ptr2);
		}	
	}
}
void deletefromspecificlocation()
{
	struct node *ptr1,*ptr,*temp;
	int loc,count=1;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the location from which you want to delete\n");
		scanf("%d",&loc);
		if(loc == 1)
		{
			if(start->next == start)
			{
				printf("\nDelete node = %d\n",start->info);
				start = NULL;	
			}
			else
			{
				temp = start;
				while(temp->next != start)
				{
					temp = temp->next;
				}
			
				ptr1 = start;
				start = start->next;
				temp->next = start;
				printf("\nDelete node = %d\n",ptr1->info);
				free(ptr1);
			}
		}
		else
		{
			ptr1 = start;
			do
			{
				ptr = ptr1;
				ptr1 = ptr1->next;
				count++;
			}while(ptr1 != start && count!=loc);
			if(ptr1 == start)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr->next = ptr1->next;
				printf("\nDelete node = %d\n",ptr1->info);
				free(ptr1);
			}	
		}	
	}
}
