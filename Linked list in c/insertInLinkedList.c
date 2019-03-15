#include <stdio.h>
#include <stdlib.h>
#include "createLinkedList.h"

int main()
{
	int n,choice;
	int c,d;
	node* HEAD=NULL;
	node*begin,*mid,*last,*temp;
	printf("How many node do you want ?\n");
	scanf("%d",&n);
	HEAD=insert(n);
	traverse(HEAD);
    
    printf("To insert a node press 3 :");
    scanf("%d",&c);
    if(c==3)
    {
    begin=(node*)malloc(sizeof(node));
    printf("Enter the data of the node: \n");
    scanf("%d",&begin->data);
    begin->next=NULL;
    
    printf("------------------MENU----------------\n\nPress 1 to insert at beginning:\nPress 2 to insert at last:\nPress 3 to insert at a location:\n ");
    scanf("%d",&choice);

    switch(choice)
    {
    	case 1:
    	{
    		
    		begin->next=HEAD;
    		HEAD=begin;
    		traverse(HEAD);
    		break;
    	}
    	case 2:
    	{   
    		mid=HEAD;
    		while(mid->next!=NULL)
    		{
    			mid=mid->next;
    		}
    		mid->next=begin;
    		traverse(HEAD);
    		break;
    	}
    	case 3:
    	{
    		printf("At which location do you want to insert ?");
    		scanf("%d",&d);
    		int count=1;
    		last=HEAD;
    		while(count!=d)
    		{
    			count++;
                temp=last;
    			last=last->next;
    		}
    		begin->next=temp->next;
    		temp->next=begin;
    		traverse(HEAD);
    		break;
    	}
    	default:
    	{
    		printf("Error input\n");
    	}
    }
    }
    else
    {
    	return 0;
    }
}