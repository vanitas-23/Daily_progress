//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node * reverse(Node * head)
    {
        Node * q=head,*r=NULL,*p;
        
        while(q)
        {
            Node * p=q->next;
            q->next=r;
            r=q;
            q=p;
        }
        return r;
    }
    
    void rearrange(struct Node *head)
    {
        Node * even=head,*ehead=even,*odd=head->next,*ohead=odd;
        while((even && odd) && (even->next || odd->next))
        {
            if(even->next)
            {
                 even->next=even->next->next;
                 if(even->next)
                    even=even->next;
            }
   
            if(odd->next)
            {
                 odd->next=odd->next->next;
                 if(odd->next)
                    odd=odd->next;
            }
            
        }
        
        ohead=reverse(ohead);
        
        while(ehead->next)
            ehead=ehead->next;
        
        ehead->next=ohead;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends