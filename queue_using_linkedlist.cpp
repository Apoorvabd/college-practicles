#include<iostream>
using namespace std;
class node{
    public:
    node* next=nullptr;
    int val;

    node(int data){
        this->val=data;
        this->next=nullptr;
    }

};


class Queue {
    public:
    int size;
    node* rear;
    node* head;
    int t=0;

    Queue(int size){
        this->size=size;
        rear=head;
        head->next=nullptr;
    }

    void enqueue(int val){
        if(t==size){
            return ;
        }
        node* n=new node(val);
        t++;
        rear->next=n;
        rear=rear->next;

    }
    void dequeue(){
        node* n=head;
        head=head->next;
        t--;
    }
    void peek(){
        cout<<head->val;
    }
    void display()
    {
        node* curr=head;
        while(curr){
            cout<<curr->val<<"  ";
            curr=curr->next;
        }
    }

  
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
}