#include <stdio.h>
#include <stdlib.h>
#include "createlinkedlist.h"

int main()
{
	int n,choice;
	int c,d,t;
	node* HEAD=NULL;
	node*begin,*mid,*last,*temp;
	printf("How many node do you want ?\n");
	scanf("%d",&n);
	HEAD=insert(n);
	traverse(HEAD);
    beginning:
    printf("------------------MENU----------------\n\nTo insert a node press 1 :\nTo delete a node press 2 :\nTo traverse list press 3 :\nTo exit press any other key : ");
    scanf("%d",&c);
    if(c==1)
    {
    	
    insert:
    printf("------------------MENU----------------\n\nPress 1 to insert at beginning:\nPress 2 to insert at last:\nPress 3 to insert at a location: ");
    scanf("%d",&choice);
    begin=(node*)malloc(sizeof(node));
    printf("Enter the data of the node: \n");
    scanf("%d",&begin->data);
    begin->next=NULL;

    switch(choice)
    {
    	case 1:
    	{

    		begin->next=HEAD;
    		HEAD=begin;
    		printf("The updated list is :\n");
    		traverse(HEAD);
    		printf("Enter more data ?\nPress 1 for yes :\nAny other key for no :");
    		scanf("%d",&t);
    		if (t==1)
    		{
    			goto insert;
    		}
    		else
    		{
    			goto beginning;
    		}
    	}
    	case 2:
    	{
    		if(HEAD==NULL)
    		{
    		   HEAD=begin;
    		   traverse(HEAD);
    		   printf("Enter more data ?\nPress 1 for yes :\nAny other key for no :");
    		   scanf("%d",&t);
    		   if (t==1)
    		   {
    			goto insert;
    		    }
    		   else
    			{
    				goto beginning;
    			}
    		}
    		mid=HEAD;
    		while(mid->next!=NULL)
    		{
    			mid=mid->next;
    		}
    		mid->next=begin;
    		printf("The updated list is :\n");
    		traverse(HEAD);
    		printf("Enter more data ?\nPress 1 for yes :\nAny other key for no :");
    		scanf("%d",&t);
    		if (t==1)
    		   {
    			goto insert;
    		    }
    		else
    			{
    				goto beginning;
    			}
    	}
    	case 3:
    	{
    		printf("At which location do you want to insert ? : ");
    		scanf("%d",&d);
    		if(d==1)
    		{
    			begin->next=HEAD;
    			HEAD=begin;
    			traverse(HEAD);
    			printf("Enter more data ?\nPress 1 for yes :\nAny other key for no :");
    		   scanf("%d",&t);
    		   if (t==1)
    		   {
    			goto insert;
    		    }
    		   else
    			{
    				goto beginning;
    			}
    		}
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
    		printf("The updated list is :\n");
    		traverse(HEAD);
    		printf("Enter more data ?\nPress 1 for yes :\nAny other key for no :");
    		   scanf("%d",&t);
    		   if (t==1)
    		   {
    			goto insert;
    		    }
    		   else
    			{
    				goto beginning;
    			}
    	}
    	default:
    	{
    		printf("Error input !\n");
    		goto insert;
    	}
    }
    }
    else if(c==2)
    {


     int a;
     int c;

     top:
     if (HEAD==NULL)
     {
     	printf("Error The list is empty!! \n");
     	goto beginning;
     }
     printf("Enter 1 to delete the first node :\nEnter 2 to delete the Last node :\nEnter 3 to delete from a pos : ");
     scanf("%d",&a);
     
     switch(a)
     {
     	case 1:
     	{
     
     	    if(HEAD->next==NULL)
            {
                printf("There is only one data in the list\nSure to delete?\nPress 1 to confirm\nPress any other to cancel : ");
     			scanf("%d",&a);
     			if(a==1)
     			     {
     			     	printf("The deleted data is %d\n",HEAD->data);
     			     	HEAD=NULL;
     			        printf("The list is now empty.\n");
     			        goto beginning;}

     			else
     				goto top;
            }
     		printf("The deleted data is :%d\n",HEAD->data);     		
     		HEAD=HEAD->next;
     		printf("The updated list is :\n");
     		traverse(HEAD);
     		printf("Do you want to delete more data ?\n1 for yes\nAny other key for no : ");
     		scanf("%d",&c);
     		if(c==1)
     		{
     			goto top;
     		}
     		else
     		{
     			goto beginning;;
     		}
     	}
     	case 2:
     	{
     		if (HEAD->next==NULL)
     		{
     			printf("There is only one data in the list\nSure to delete?\nPress 1 to confirm\nPress any other to cancel : ");
     			scanf("%d",&a);
     			if(a==1)
     			    {
     			    	
     			    	printf("The deleted data is %d\n",HEAD->data);
     			    	HEAD=NULL;
     			        printf("The list is now empty \n");
     			        goto beginning;
     			    }
     			else
     				goto top;
     		}
     		else
     		{
     		last=HEAD;
     		while(last->next!=NULL)
     		{
                temp=last;
     			last=last->next;
     		}
     		printf("The deleted data is :%d\n",last->data);
     		temp->next=NULL;
     		printf("The updated list is :\n");
     		traverse(HEAD);
     		printf("Do you want to delete more data ?\n1 for yes\nAny other key for no : ");
     		scanf("%d",&c);
     		if(c==1)
     		{
     			goto top;
     		}
     		else
     		{
     			goto beginning;;
     		}
     	}
     	}
     	case 3:
     	{
     		int a,b,nodes=1,count=1;
     		node*ptr,*temp,*tem;
     		ptr=HEAD;
     		temp=HEAD;
     		her:
     		
	        while(temp->next!=NULL)
	        {
		   
		     temp=temp->next;
		     nodes++;
	        }
     		
     	    printf("The list has %d nodes : \n",nodes);
     		printf("Which node do you want to delete ? : ");
     		scanf("%d",&a);
     		if(a==0)
     		{
     			printf("Error input \n");
     			goto her;
     		}
     		if(a==1)
     			{
     				if(HEAD->next==NULL)
     				{
     				printf("The deleted data is :%d\n",HEAD->data);
     				HEAD=NULL;
     				traverse(HEAD);
     				printf("The list is now empty :\n");
     				goto beginning;
     			}
     				else
     				{
     					printf("The deleted data is %d\n",HEAD->data);
                        HEAD=HEAD->next;
                        traverse(HEAD);
                        goto beginning;
     				}

     	        }
     	    else if(a<1)
     	    {
     	    	printf("Invalid input :\n");
     	    	goto her;
     	    }
     	    else if(a>nodes)
     	        {
     	    	printf("Error enter correct input ! \n");
     	    	goto her;
     	        }

     	    else
     	    {
                
         	    while(count!=a)
     		    {
     			
     			tem=ptr;
     			ptr=ptr->next;
     			count++;

     		    }
     		printf("The deleted data is %d\n",ptr->data);
     		tem->next=ptr->next;
     		printf("The updated list is :\n");
     		traverse(HEAD);	
     		printf("Do you want to delete more data ?\nPress 1 for yes\nPress any other key for no :");
     		scanf("%d",&b);
     		if(b==1)
     		{
     			goto top;
     		}
            else
            {

                 goto beginning;;	
            }
            }
     		
     	}
     	default:
     	{
     		printf("Invalid option please enter a valid option \n");
     		goto top;
     	}
     }

    }
    else if(c==3)
    {
    	traverse(HEAD);
    	goto beginning;
    }
    else 
    {
    	printf("Thank you for using my program\n");
    	return;
    }
}
