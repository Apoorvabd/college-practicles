#include<iostream>
using namespace std;
class stack{
    int size;
    int* arr;
    int t;

public:
    stack(int size){
       this->size=size;
       arr=new int[size];
       this->t = -1;
    }

    ~stack(){
        delete[] arr;
    }

    void top(){
        if(t==-1){
            cout<<"underflow";
            return ;
        }
        cout<<arr[t]<<endl;
    }
    void push(int val){
        if(t==size-1){
            cout<<"overflow";
            return ;
        }
        t++;
        arr[t]=val;

    }
    void pop(){
        if(t<=0){
            cout<<"stack is empty";
            return ;
        }
        t--;
    }
    void print(){
        for(int i=t;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    stack st(10);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(2);
    st.push(9);
    st.print();
    st.top();
    st.pop();
    st.print();

    return 0;
    

}