#include <iostream>
#include <cstdint>

using namespace std;

template<typename Type_t>
struct  Node
{
    Type_t content;
    Node<Type_t> *Next;
};

template<typename T>
class NewList
{
    private:
        Node<T> *Head, *Tail;
    public:
        NewList();
        ~NewList();
        void Add(T NewContent);
        void DeleteBack();
        void Swap(Node<T> *temp1, Node<T> *temp2);
        void PrintList();
        Node<T>* back();
        Node<T>* front();
};

template<typename T>
NewList<T>::NewList()
{
    Head = NULL;
    Tail = NULL;
    SizeList = 0;
}

template<typename T>
NewList<T>::~NewList()
{
    while (Head != NULL)
    {
        Node<T> *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

template<typename T>
void NewList<T>::Add(T NewContent)
{
    Node<T> *temp = new Node<T>;
    temp->content = NewContent;
    temp->Next = Head;

    if(Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else 
    {
        Head = temp;
        Tail = temp;
    }
}

template<typename T>
void NewList<T>::DeleteBack()
{
    Node<T> *prevTail = Head;
    Node<T> *tempTail = Tail;
    while(prevTail->Next != Tail)
    {
        prevTail = prevTail->Next;
    }
    prevTail->Next = Head;
    Tail = prevTail;
    delete tempTail;
}

template<typename T>
void NewList<T>::Swap(Node<T> *temp1, Node<T> *temp2)
{
    Node<T> *tempPrev1 = Head;
    Node<T> *tempPrev2 = Head;
    Node<T> *Next1 = temp1->Next;
    Node<T> *Next2 = temp2->Next;
    
    if(Head == temp1)Head = temp2;
    else if(Head == temp2)Head = temp1;
    if(Tail == temp1)Tail = temp2;
    else if(Tail == temp2)Tail = temp1;

    while(tempPrev1->Next != temp1)
    {
        tempPrev1 = tempPrev1->Next;
    }
    while(tempPrev2->Next != temp2)
    {
        tempPrev2 = tempPrev2->Next;
    }

    if(Next1 == temp2)
    {
        tempPrev1->Next = temp2;
        temp2->Next = temp1;
        temp1->Next = Next2;
    }
    else if(Next2 == temp1)
    {
        tempPrev2->Next = temp1;
        temp1->Next = temp2;
        temp2->Next = Next1;
    }
    else
    {
        tempPrev1->Next = temp2;
        tempPrev2->Next = temp1;
        temp1->Next = Next2;
        temp2->Next = Next1;
    }

}

template<typename T>
void NewList<T>::PrintList()
{
    Node<T> *tempHead = Head;
    for(int i = 0; i < SizeList; i++)
    {
        for(int j=0; j < 3; j++)
        {
            cout << static_cast<unsigned>(tempHead->content[j]) << " ";
        }
        cout << " -> ";
        tempHead = tempHead->Next;
    }
    cout << endl;
}

template<typename T>
Node<T>* NewList<T>::back()
{
    return Tail;
}

template<typename T>
Node<T>* NewList<T>::front()
{
    return Head;
}
