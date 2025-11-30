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
class stack {
    public:
    int size;
    int curr=0;
    node* head;

    stack(int size){
        head=nullptr;
        this->size=size;
    }
    void push(int val){
        if(curr>size){
            cout<<"overflow";
            return ;
        }
        node* nn=new node(val);
        nn->next=head;
        head=nn;
        curr++;
    }

    void pop(){
        if(curr==0){
            cout<<"underflow";
            return ;
        }
        node* del=head;
        head=head->next;
        free(del);
        curr--;
    }
    void top(){
        if(curr==0){
            return ;
        }
        cout<<"top is:--  "<<head->val<<endl;
    }
    void print(){
        node *pre=head;
        while(pre){
            cout<<pre->val<<"->";
            pre=pre->next;
        }
        cout<<endl;
    }


};

int main(){
    stack st(5);
    st.push(5);
    st.push(4);
    st.push(3);st.push(1);
    st.print();
    st.pop();
    st.top();

    return 0;

    

}