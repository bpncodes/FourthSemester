#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node* insert(int a)
{
	int i;
	node *head=NULL;
	node *new;
	node *temp;
	for(i=1;i<=a;i++)
	{
		new=(node*)malloc(sizeof(node));
		printf("Enter the data at node : %d \n",i);
		scanf("%d",&new->data);
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			temp=head;
			while(temp->next !=NULL)
			{
				temp=temp->next;
			}
			temp->next=new;
		}
        

	}
	return head;
}

void traverse(head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		printf("%d ->", temp->data);
		temp=temp->next;
	}
	printf("NUll");
}
int main()
{
	int n;
	node* HEAD=NULL;
	printf("How many node do you want ?\n");
	scanf("%d",&n);
	HEAD=insert(n);
	traverse(HEAD);

}