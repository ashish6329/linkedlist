#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *start;
class linked_list
{
	
public:
node *create_node(int value)
{
     struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"list be empty"<<endl;
        return 0;
    }
    else
    {
        temp->data = value;
        temp->next = NULL;     
        return temp;
    }
}
    

void insert_beginning()
{
     
     int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}
void insert_last()
{
	int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element Inserted at last"<<endl; 
}
		
		
void print()
{
	struct node*p;
	if(start==NULL)
	{
		cout<<" list is empty"<<endl;
		return;
		}
				
			p=start;
			while(p!=NULL)
			{
				cout<<p->data<<"\t";
				p=p->next;
		}
				
			
	}
	void insert_position()
	{
		int value,pos,count=0,i;
		cout<<"enter the value to be inserted"<<endl;
		cin>>value;
		node *temp,*s,*ptr;
		temp=create_node(value);
		cout<<"enter which position to be inserted"<<endl;
		cin>>pos;
		s=start;
		while(s!=NULL)
		{
			s=s->next;
			count=count+1;
			
		}
		if(pos==1)
		{
			if(start==NULL)
			{
				start=temp;
				start->next=NULL;
			}
			else
			{
				ptr=start;
				start=temp;
				start->next=ptr;
				
			}
		}
		else if(pos>1 || pos<=count)
		{
			s=start;
			for(i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=temp;
			temp->next=s;
		}
		else
		cout<<"out of range"<<endl;
		
	}
void deleteposition()
{
	int pos,i,count=0;
	struct node *s,*ptr;
	if(start==NULL)
	{
		cout<<"list is empty"<<endl;
		return;
	}
	cout<<"enter the position to be deleted"<<endl;
	cin>>pos;
	s=start;
	if(pos==1)
	{
		start=s->next;
	}
	else
	{
		while(s!=NULL)
		{
			s=s->next;
			count=count+1;
		}
		if(pos>0 || pos<=count)
		{
			s=start;
			for(i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=s->next;
		}
		free(s);
		
	}
	
}
};
main()
{
	start=NULL;
	int ch;
	linked_list l1;
	while(1)
	{
		cout<<endl;
		cout<<"enter choice"<<endl;
		cout<<"1 insert beginning"<<endl;
		cout<<"2 insert last node"<<endl;
		cout<<"3 insert value at certain position"<<endl;
		cout<<"4  position to be deleted"<<endl;
		cout<<"5 print the linked list"<<endl;
		cout<<"6.exit"<<endl;
		cout<<endl;
		cin>>ch;
		switch(ch)
	    {
		
	
		    case 1:
		     	cout<<"insert at begin"<<endl;
		     	l1.insert_beginning();
		     	l1.print();
		     	break;
		    case 2:
		    	cout<<"insert at last"<<endl;
		    	l1.insert_last();
		    	l1.print();
		    	break;
		    case 3:
		    	cout<<"enter value at positon"<<endl;
		    	l1.insert_position();
		    	l1.print();
		    	break;
		    case 4:
		    	cout<<"enter the positon at which element is deleted"<<endl;
		    	l1.deleteposition();
		    	l1.print();
		    	break;
		    case 5:
		    	cout<<"print"<<endl;
		    	l1.print();
		    	break;
		    
		    case 6:
		    	cout<<"exit";
		    	exit(1);
		    	break;
		    default:
		    	cout<<"oops! wrong choice";
		}
	}
}
