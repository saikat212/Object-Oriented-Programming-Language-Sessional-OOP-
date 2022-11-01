#include<iostream>
using namespace std;

class Stack
{

    int *stck;
    int tos;
    int maxsize;


    void Resize_expanding(int);
    void Resize_shrinking(int);
public:

    Stack();
    ~Stack();
    Stack(int sz);
    Stack(const Stack &obj);

    void push(int n);
    void push(int arr[],int n);
    void push(Stack s);
    int pop();
    float similarity(Stack s1);
    int top();

    bool isEmpty()
    {
        return (!tos);
    }

    int Size()
    {
        return tos;
    }
};



Stack::Stack()
{
    cout<<"Default constructor"<<endl;
    stck=new int[10];

    if(!stck)
        cout<<"Allocation error"<<endl;

    tos=0;

}




Stack::Stack(int sz)
{
    cout<<"parameterized constructor"<<endl;

    maxsize=sz;
    stck=new int[maxsize];
    if(!stck)
        cout<<"Allocation error"<<endl;

    tos=0;

}



Stack::Stack(const Stack &obj)
{
    cout<<"copy constructor"<<endl;

    tos=obj.tos;
    maxsize=obj.maxsize;
    stck=new int[maxsize];
    if(!stck)
        cout<<"Allocation error"<<endl;

    for(int i=0; i<tos; i++)
    {
        stck[i]=obj.stck[i];
    }
}



Stack::~Stack()
{
    cout<<"Destructor"<<endl;
    delete [] stck;

}


void Stack::push(int n)
{
    if(tos>=maxsize)
    {
        Resize_expanding(maxsize);
    }
    stck[tos++]=n;
}



void Stack::push(int arr[],int n)
{
    int SIZE_n=n;

    for(int j=0; j<SIZE_n; j++)
    {
        push(arr[j]);
    }

}



void Stack::push(Stack s)
{

    while(!s.isEmpty())
    {
        push(s.pop());
    }

}


int Stack::pop()
{

    Resize_shrinking(Size());
    return stck[--tos];

}



void Stack::Resize_expanding(int maxsize)
{
    int tos=maxsize;
    int *new_stck=new int(maxsize);
    maxsize=maxsize+10;
    for(int i=0; i<tos; i++)
    {
        new_stck[i]=stck[i];
    }
    delete [] stck;
    stck=new int(maxsize);
    for(int i=0; i<tos; i++)
    {
        stck[i]=new_stck[i];
    }

}



void Stack::Resize_shrinking(int s_z)
{
    int tos=s_z;
    int *new_stck=new int(s_z);

    for(int i=0; i<tos; i++)
    {
        new_stck[i]=stck[i];
    }

    delete [] stck;
    stck=new int(s_z);

    for(int i=0; i<tos; i++)
    {
        stck[i]=new_stck[i];
    }

}

float Stack:: similarity(Stack s1)
{

    int match_num=0,i=tos-1;
    float average_num;
    average_num=(tos + s1.Size())/2.0;

    while(tos!=0 && !s1.isEmpty())
    {

    if(stck[i]==s1.pop())
        {
            match_num++;
        }
        i--;
    }

    return (match_num/average_num);
}




int Stack::top()
{
    int i=tos-1;
    return stck[i];
}




int main()
{
    Stack mainStack(10),*tempStack;
    int menu_num=0;


    while (menu_num!=8)
    {

        cout<<"1: push an element\t\t";
        cout<<"5: Top"<<endl;
        cout<<"2: push an array\t\t";
        cout<<"6: Size"<<endl;
        cout<<"3: Push a stack\t\t\t";
        cout<<"7: Similarity"<<endl;
        cout<<"4: Pop\t\t\t\t";
        cout<<"8: Exit"<<endl;

        cin>>menu_num;

        if(menu_num==1)
        {
            int n;
            cout<<"Enter the element"<<endl;
            cin>>n;
            mainStack.push(n);
        }



        if(menu_num==2)
        {
            int n;
            cout<<"Enter the total element  of array"<<endl;
            cin>>n;
            int arr[n];
            cout<<"Enter the array value sequentially"<<endl;
            for(int i=0; i<n; i++)
            {
                cin>>arr[i];

            }
            mainStack.push(arr,n);
        }




        if(menu_num==3)
        {
            int n,m;
            cout<<"Enter the stack size"<<endl;
            cin>>n;
            tempStack=new Stack(n);
            cout<<"Enter the value of tempstack sequentially"<<endl;
            for(int i=0; i<n; i++)
            {
                cin>>m;
                tempStack->push(m);
            }

            mainStack.push(*tempStack);
            tempStack->~Stack();

        }




        if(menu_num==4)
        {
            if(!mainStack.isEmpty())
                cout<<mainStack.pop()<<"  is poped"<<endl;
            else
                cout<<"stack is empty:"<<endl;
        }





        if(menu_num==5)
        {
            if(!mainStack.isEmpty())
                cout<<mainStack.top()<<"  is top "<<endl;
            else
                cout<<"stack is empty:"<<endl;
        }






        if(menu_num==6)
        {
            if(!mainStack.isEmpty())
                cout<<mainStack.Size()<<"  is size of mainstack "<<endl;
            else
                cout<<"stack is empty:"<<endl;
        }







        if(menu_num==7)
        {
            int n,m;
            cout<<"Enter the stack size"<<endl;
            cin>>n;
            tempStack=new Stack(n);
            cout<<"Enter the value of tempstack sequentially"<<endl;
            for(int i=0; i<n; i++)
            {
                cin>>m;
                tempStack->push(m);
            }

            cout<<"similarity:"<<mainStack.similarity(*tempStack)<<endl;
            tempStack->~Stack();




        }






        if(menu_num==8)
        {
            while(!mainStack.isEmpty())
                cout<<mainStack.pop()<<endl;
        }

    }

    return 0;
}


