#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *rear=NULL,*front=NULL;
	int z,c=0;
	void enqueue(int val)
	{
	  	node *newnode=new node();
	  	newnode->data=val;
	  	newnode->next=NULL;
	  	if(rear==NULL)
	  	{
		  front=newnode;
		  rear=newnode;
		  c++;
	    }
	  	else
	  	{
	  	  rear->next=newnode;
	  	  rear=newnode;
	  	  c++;
		}

		 for(int i=1;i<c;i++)
		 {
		 	node *temp=front;
 			front=front->next;
 			rear->next=temp;
 			temp->next=NULL;
 			rear=temp;
		 }
}
int dequeue()
{
	if(isempty())
	
		cout<<"queue is empty. Can't dequeue....";
	else
	{
	node *temp=front;      
	int x=temp->data;
	front=front->next;
	if(front==NULL)
	  rear=NULL;
	delete(temp);
	return(x);
	
    }
}
void display()
{
	node *temp=front;
	for(int i=1;i<=c;i++)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
	

int isempty()
{
	if(rear==NULL)
	  return 1;
	else
	  return 0;
}
};

int main()
{
	int n,r;
	node obj;
	cout<<"Enter a decimal number";
	cin>>n;
	do
	{
		r=n%2;
		n=n/2;
		obj.enqueue(r);
	}while(n!=1);
	obj.enqueue(n);
	obj.display();
}


