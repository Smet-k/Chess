#ifndef List_h
#define List_h
#include "ICollection.h"
#include <iostream>
#include "Element.h"
#include "Point.h"
// exceptions for - get() - StackOverFlowException (out of stack)
//                  remove() - NullReferenceException (removing something out of bounds)
//                  KeyDublicateException - in dictionary - dublicating keys
template<class T>
class List : ICollection<T>
{
public:
    Element<T>* first;
    Element<T>* last;

    List<T>()
    {
        this->first = nullptr;
        this->last = nullptr;
    };

    List<T>(Element<T>* first, Element<T>* last)
    {
        this->first = first;
        this->last = last;
    }

    void remove(int index)
    {
        Element<T>* nextToCurrent = this->first;
        Element<T>* current = this->first;
        Element<T>* beforeCurrent = this->first;

        if (index == 0)
        {
            nextToCurrent = this->first->next;
            this->first->value = nextToCurrent->value;
            this->first->next = nextToCurrent->next;
        }
        else
        {
            int size = length();
            for (int i = 0; i < index; i++)
            {
                beforeCurrent = current;
                current = current->next;
            }

            if (index < size - 1)
            {
                nextToCurrent = current->next;

                current->value = nextToCurrent->value;
                current->next = nextToCurrent->next;
            }
            else
            {
                current = beforeCurrent;
                nextToCurrent = current->next;

                current->next = nextToCurrent->next;
            }

        }
        delete nextToCurrent;
    }

    void add(T data) override
    {
        if (!this->first)
        {
            this->first = new Element<T>;
            this->first->value = data;
            this->first->next = nullptr;
            this->last = this->first;
        }
        else
        {
            if (this->first == this->last)
            {
                this->last = new Element<T>;
                this->last->value = data;
                this->last->next = nullptr;
                this->first->next = this->last;
            }
            else
            {
                Element<T>* item = new Element<T>;
                item->value = data;
                item->next = nullptr;
                this->last->next = item;
                this->last = item;
            }
        }
    }

    T operator [](int index) override
    {
        return get(index);
    }

    T get(int index) override
    {
        if (index == 0)
        {
            return this->first->value;
        }
        else
        {
            Element<T>* current = this->first;
            for (int i = 0; i < index; i++)
            {

                current = current->next;
            }
            return current->value;
        }

    }

    void remove(Element<T>* element)
    {
        Element<T>* current = this->first;
        int size = length();
        for (int i = 0; i < size; i++)
        {
            if (current == element) { remove(i); break; }
            current = current->next;
        }
    }

    int length()
    {
        Element<T>* current = this->first;
        int length = 0;
        while (true)
        {
            length++;
            current = current->next;
            if (current == NULL) { return length; }
        }
        return length;
    }

    void print()
    {
        int size = this->length();
        for (int i = 0;i < size;i++)
        {
            std::cout << " [" << get(i) << "] ";
        }

    }


    Element<T>* getElement(int index)
    {
        if (index == 0)
        {
            return this->first;
        }
        else
        {
            Element<T>* current = this->first;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current;
        }
    }


    List<T>* take(int count)
    {
        List<T>* output = new List<T>;

        for (int i = 0;i < count;i++)
        {
            int number = get(i);
            output->add(number);
        }
        return output;
    }

    List<T>* take(int start, int count)
    {
        List<T>* output = new List<T>;

        for (int i = start;i < count;i++)
        {
            int number = get(i);
            output->add(number);
        }
        return output;
    }

    List<T> Reverse()
    {
        List<T>* current = this;
        int size = length();
        T input;
        List<T> output;

        for (int i = size - 1;i >= 0; i--)
        {
            input = get(i);
            output.add(input);
        }

        return output;
    }


    //true - increment, false decrement 
    List<T> OrderBy(bool asc = true)
    {

        int size = this->length();

        List<T> input = { this->first,this->last };
        List<T> output = {};
        if (asc)
        {
            for (int j = 0;j < size - 1;j++)
            {
                int size2 = this->length();
                Element<T>* nextToCurrent = input.first;
                Element<T>* current = input.first;
                int min = 2147483647;
                int index = 0;
                for (int i = 0;i < size2;i++)
                {
                    if (min > current->value)
                    {
                        min = current->value;
                        index = i;
                    }
                    current = current->next;
                }
                output.add(min);
                input.remove(index);
            }
            output.add(getElement(0)->value);
        }
        else
        {
            for (int j = 0;j < size - 1;j++)
            {
                int size2 = this->length();
                Element<T>* nextToCurrent = input.first;
                Element<T>* current = input.first;
                int max = -2147483648;
                int index = 0;
                for (int i = 0;i < size2;i++)
                {
                    if (max < current->value)
                    {
                        max = current->value;
                        index = i;
                    }
                    current = current->next;
                }
                output.add(max);
                input.remove(index);
            }
            output.add(get(0));
        }
        List<T> linkOutput = { output.first,output.last };
        return linkOutput;
    }

    ~List()
    {
        //if (first != NULL && first != nullptr) { delete first; }

        //if(last != NULL && last != nullptr){ delete last; }
    }




};

#endif