#include <iostream>
#include <cstdint>

template<typename T>
class NewList
{
    private:
        struct  Node
        {
            T *content;
            Node *Next;
        };
        Node *object;
    public:
        NewList();
        NewList(T NewContent);
        ~NewList();
        void Add(T *NewContent);
        void Delete();
        void Swap(Node *temp1, Node *temp2);
        void rewrite(T *NewContent);
        void PrintList();
        void PrintListBuff(int num);
        T* back();
        T* next();

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
void NewList<T>::Add(T *NewContent)
{
    Node *new_obj = new Node;
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
        Node *temp = object->Next;
        object->content = temp->content;
        object->Next = temp->Next;
        delete temp;
    }

    if(object != object->Next)
    {
        Node *tempPrev = object;
        while(tempPrev->Next != object)
        {
            tempPrev = tempPrev->Next;
        }
        object = tempPrev;
    }
}

template<typename T>
void NewList<T>::Swap(Node *temp1, Node *temp2)
{
    Node *tempPrev1 = object;
    Node *tempPrev2 = object;
    Node *Next1 = temp1->Next;
    Node *Next2 = temp2->Next;

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
    std::cout << "! ";

    Node *temp_object = object->Next;
    do
    {
        std::cout << static_cast<unsigned>(temp_object->content) << " ";
        temp_object = temp_object->Next;
    }while(temp_object != object->Next);
    
    std::cout << std::endl;
} 

template<typename T>
void NewList<T>::PrintListBuff(int num)
{
    std::cout << "! ";

    uint8_t *begin_col = this->next();
    uint8_t *iter = this->back();
    do
	{
		for(int i = 0; i < 3; i++)
		{
			std::cout << static_cast<unsigned>(iter[i]) << "  ";
		}
        std::cout << std::endl;
        iter = this->next();
	}while (iter != begin_col);
    std::cout << std::endl;
}

template<typename T>
T* NewList<T>::back()
{
    if(object != NULL) return object->content;
    else return NULL;
}

template<typename T>
T* NewList<T>::next()
{
    object = object->Next;
    return object->content;
}

template<typename T>
void NewList<T>::rewrite(T *NewContent)
{
    // T* temp = object->content;
    object->content = NewContent;
    // delete temp;
}
