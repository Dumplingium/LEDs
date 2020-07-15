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
        Node<T> *object;
    public:
        NewList();
        NewList(T NewContent);
        ~NewList();
        void Add(T NewContent);
        void Delete();
        void Swap(Node<T> *temp1, Node<T> *temp2);
        void PrintList();
        void PrintListBuff(int num);
        Node<T>* back();
};

template<typename T>
NewList<T>::NewList()
{
    this->object = NULL;
}

template<typename T>
NewList<T>::~NewList()
{
    if(object != NULL)
    {
        while (object != object->Next)
        {
            Delete();
        }
        delete object;
    }
}

template<typename T>
void NewList<T>::Add(T NewContent)
{
    Node<T> *new_obj = new Node<T>;
    new_obj->content = NewContent;
    
    if(this->object == NULL)
    {
        new_obj->Next = new_obj;
        object = new_obj;
    }
    else
    {
        new_obj->Next = object->Next;
        object->Next = new_obj;
        object = new_obj;
    }
}

template<typename T>
void NewList<T>::Delete()
{
    if(object != NULL)
    {
        Node<T> *temp = object->Next;
        object->content = temp->content;
        object->Next = temp->Next;
        delete temp;
    }

    if(object != object->Next)
    {
        Node<T> *tempPrev = object;
        while(tempPrev->Next != object)
        {
            tempPrev = tempPrev->Next;
        }
        object = tempPrev;
    }
}

template<typename T>
void NewList<T>::Swap(Node<T> *temp1, Node<T> *temp2)
{
    Node<T> *tempPrev1 = object;
    Node<T> *tempPrev2 = object;
    Node<T> *Next1 = temp1->Next;
    Node<T> *Next2 = temp2->Next;

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

    if(object == temp1)object = temp2;
    else if(object == temp2)object = temp1;

}

template<typename T>
void NewList<T>::PrintList()
{
    cout << "! ";

    Node<T> *temp_object = object->Next;
    do
    {
        cout << static_cast<unsigned>(temp_object->content) << " ";
        temp_object = temp_object->Next;
    }while(temp_object != object->Next);
    
    cout << endl;
} 

template<typename T>
void NewList<T>::PrintListBuff(int num)
{
    cout << "! ";

    Node<T> *temp_object = object->Next;
    do
    {
        for(int i = 0; i < num; i++)
        {
            cout << static_cast<unsigned>(temp_object->content[i]) << " ";
        }
        cout << " -> " << endl;
        temp_object = temp_object->Next;
    }while(temp_object != object->Next);
    
    cout << endl;
}

template<typename T>
Node<T>* NewList<T>::back()
{
    return object;
}
