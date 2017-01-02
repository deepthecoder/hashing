//C Code For Hashing
//Author:Shubharthi Dey

#include<stdio.h>
#include<malloc.h>
struct node
{
	  int data;
	  int key;
};//declaring a structure

struct node *arr[15];  //Creating an array of pointers
void insert(int,int);
void display();
void main()
{
	  int empno;
	  int key;
  	FILE *fp;
  	fp=fopen("emp.txt","r");
  	while(fscanf(fp,"%d",&empno)!=EOF)   //taking input from a file 
  	{
	     	key=empno%100;              //creation of a key
	     	insert(empno,key);
	  }
  	display();
	  fclose(fp);
}

void insert(int empno,int key)
{
	  struct node *item=(struct node *)malloc(sizeof(struct node));     //Creation of a Structure
  	item->data=empno;
  	item->key=key;
  	int k;	
  	k=key%10;
  	while(arr[k]!=NULL) //Linear Probing
  	{
  	  	++k;
  	  	k=k%15;        // Concept Of Circular Queue
  	}
  	arr[k]=item;
}

void display()
{
  	int i;
  	for(i=0;i<15;i++)
   	{
		    if(arr[i]!=NULL)
		  	printf("%d\t%d\n",arr[i]->key,arr[i]->data);
	    	else
		  	printf("-1\n");
  	}	
}
