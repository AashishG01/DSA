#include<iostream>
using namespace std;

class stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~stack(){
        delete[] arr;
    }

    void push(int value){
        if(isFull()){
            cout<<"stack oveflow! cannot push"<< value << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << "pushed" << value << "int the stack"<<endl;
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack underflow! cannot pop from an empty stack"<<endl;
            return;
        }
        cout<< "popped"<<arr[top]<<"from the stack"<<endl;
        top--;
    }

    int peek(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity-1;
    }

    int size(){
        return top + 1;
    }

};

int main(){
    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout<< "top element is:"<< st.peek() << endl;

    st.pop();

    cout << "top element is:"<< st.peek() << endl;

    st.pop();

    cout << "top element is:"<< st.peek() << endl;

    cout<< "size of stack after popping is" << st.size()<< endl;

    st.push(50);
    st.push(60);
    st.push(70);

    while(!st.isEmpty()){
        cout<<"popping:"<<st.peek()<<endl;
        st.pop();
    }

    cout<< "stack empty?"<<(st.isEmpty()? "yes":"No")<<endl;
     
    return 0;
}

