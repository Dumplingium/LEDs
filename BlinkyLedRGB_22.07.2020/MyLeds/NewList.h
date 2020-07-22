#ifndef DLIST
#define DLIST

#include <iostream>

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
        NewList()
        {
            this->object = NULL;
        }
        ~NewList()
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
        void Add(T *NewContent)
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
        void Delete()
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
        void Swap(Node *temp1, Node *temp2)
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
        void rewrite(T *NewContent)
        {
            object->content = NewContent;
        }
        T* back(){
            if(object != NULL) return object->content;
            else return NULL;
        }
        T* next()
        {
            object = object->Next;
            return object->content;
        }
};

#endif