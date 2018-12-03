#include <iostream>

template <class T>
struct node
{
    T value;
    node<T>* prev;
    node<T>* next;

    node()
    {
        value = -1;
        prev = nullptr;
        next = nullptr;
    }
};

template <class T>
class linkedList
{
    private:
        node<T>* head;
        node<T>* tail;
        int sizeD;
        void copyList(const linkedList<T>&);

    public:
        linkedList(); //Constructor *
        
        linkedList (const linkedList<T>&); //Copy constructor * NOT WORKING
        linkedList<T>& operator=(const linkedList<T>&); //Operator= *
        
        //All are ready
        bool operator==(const linkedList<T>&) const; 
        bool operator>(const linkedList<T>&) const;
        bool operator<(const linkedList<T>&) const;
        bool operator>=(const linkedList<T>&) const;
        bool operator<=(const linkedList<T>&) const;

        void push_front(T); //pushes an element at the front *
        T pop_front(); //pops the first element *
        void push_back(T); //pushes an element at the back *
        T pop_back(); //pops the last element *

        void insertAt(T, int); //Inserts an element at *
        T returnAt(int) const; //Returns the element at *
        void removeAt(int); //Removes an element at *

        int search(T) const; //Returns the position of an element *

        int size() const; //Returns the size *
        void clear(); //Clears the list *

        void merge(const linkedList<T>&); //Merges two lists in the current one *
        void reverse(); //Reverses the list *

        void print(); //prints the stack
        
        node<T>* begin() const; //Returns the head *
        node<T>* end() const; //Returns the tail *

        T front() const; //Returns the value infront *
        T back() const; //Returns the value at the back *

        ~linkedList(); //Destructor *


};


template <class T>
void linkedList<T>::copyList(const linkedList<T>& rhs)
{
    node<T>* temp = rhs.head;

    while(temp != nullptr)
    {
        push_back(temp->value);
        temp = temp->next;
    }
}

template <class T>
linkedList<T>::linkedList()
{
    head = new node<T>();
    tail = new node<T>();

    sizeD = 0;
}

template <class T>
linkedList<T>::linkedList(const linkedList<T>& rhs)
{
    head = new node<T>();
    tail = new node<T>();

    sizeD = 0;

    copyList(rhs);
}

template <class T>
linkedList<T>& linkedList<T>::operator=(const linkedList<T>& rhs)
{
    clear();
    copyList(rhs);
    return *this;
}
template <class T>
bool linkedList<T>::operator==(const linkedList<T>& rhs) const
{
    node<T>* temp1 = head;
    node<T>* temp2 = rhs.head;

    if(sizeD == rhs.size())
    {
        while(temp1->next != nullptr)
        {
            if(temp1->value != temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    else return false;
}

template <class T>
bool linkedList<T>::operator>(const linkedList<T>& rhs) const
{
    node<T>* temp1 = head;
    node<T>* temp2 = rhs.head;

    if(sizeD == rhs.size())
    {
        while(temp1->next != nullptr)
        {
            if(temp1->value <= temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    else if(sizeD > rhs.size()) return true;
    else return false;
    
}

template <class T>
bool linkedList<T>::operator<(const linkedList<T>& rhs) const
{
    node<T>* temp1 = head;
    node<T>* temp2 = rhs.head;

    if(sizeD == rhs.size())
    {
        while(temp1->next != nullptr)
        {
            if(temp1->value >= temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    else if(sizeD < rhs.size()) return true;
    else return false;
}

template <class T>
bool linkedList<T>::operator>=(const linkedList<T>& rhs) const
{
    node<T>* temp1 = head;
    node<T>* temp2 = rhs.head;

    if(sizeD == rhs.size())
    {
        while(temp1->next != nullptr)
        {
            if(temp1->value < temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    else if(sizeD > rhs.size()) return true;
    else return false;
}

template <class T>
bool linkedList<T>::operator<=(const linkedList<T>& rhs) const
{
    node<T>* temp1 = head;
    node<T>* temp2 = rhs.head;

    if(sizeD == rhs.size())
    {
        while(temp1->next != nullptr)
        {
            if(temp1->value > temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    else if(sizeD < rhs.size()) return true;
    else return false;
}


template <class T>
void linkedList<T>::push_front(T value)
{
    node<T>* temp = new node<T>;
    temp->value = value;
    temp->prev = nullptr;

    if(sizeD == 0)
    {
        head = temp;
        tail = temp;
        temp->next = nullptr;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
   sizeD++;
}

template <class T>
T linkedList<T>::pop_front()
{ 
    node<T>* temp = head;
    T value = temp->value;

    if(sizeD != 1)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
    }
    
    sizeD--;
    delete temp;
    return value;

}

template <class T>
void linkedList<T>::push_back(T value)
{
    node<T>* temp = new node<T>();

    temp->value = value;
    temp->next = nullptr;
    

    if(sizeD == 0)
    {
        head = temp;
        tail = temp;
        temp->prev = nullptr;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    sizeD++;
}

template <class T>
T linkedList<T>::pop_back()
{
    node<T>* temp = tail;
    T value = temp->value;

    if(sizeD != 1)
    {
        
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        tail = nullptr;
        head = nullptr;
    }
    sizeD--;
    delete temp;
    return value;
    
}

template <class T>
void linkedList<T>::insertAt(T value, int pos)
{
    node<T>* temp = head;
    if(pos <= sizeD)
    {
        for(int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
    }   
    node<T>* add = new node<T>;

    add->value = value;
    add->prev = temp->prev;
    add->next = temp;
    
    temp->prev->next = add;   
    temp->prev = add;
    sizeD++;
}

template <class T>
T linkedList<T>::returnAt(int pos) const
{
    if(pos > sizeD) return T();
    else
    {
        node<T>* temp = head;
        for(int i = 0; i < pos; i++) temp = temp->next;

        return temp->value;
    }
}

template <class T>
void linkedList<T>::removeAt(int pos)
{
    if(pos <= sizeD)
    {
        node<T>* temp = head;
        for(int i = 0; i < pos; i++) temp = temp->next;

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;        

        sizeD--;
    }
}

template <class T>
int linkedList<T>::search(T value) const
{
    node<T>* temp = head;
    int n = 0;
    while(temp->next != nullptr)
    {
        if(temp->value == value) return n;
        else
        {
            n++;
            temp = temp->next;
        }
    }
    return temp->value;
}

template <class T>
int linkedList<T>::size() const
{
    return sizeD;
}

template <class T>
void linkedList<T>::clear()
{
    if(sizeD != 0)
    {
        node<T>* temp = head;
        node<T>* nextN = temp->next;
        for(int i = 0; i < sizeD-1; i++)
        { 
            delete temp;
            temp = nextN;
            nextN = nextN->next;
        }
        delete nextN;

        head = nullptr;
        tail = nullptr;
    
    }
}

template <class T>
void linkedList<T>::merge(const linkedList<T>& rhs)
{
    for(int i = 0; i < rhs.size(); i++)
    {
        push_back(rhs.returnAt(i));
    }
}


template <class T>
void linkedList<T>::reverse()
{
    node<T>* prev;
    node<T>* current;
    node<T>* next;

    prev = head;
    current = head;
    next = head->next;

    current->next = nullptr;
    current->prev = next;
    current = next;
    next = next->next;

    while(next != nullptr)
    {
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }

    current->prev = nullptr;
    current->next = prev;

    next = head;
    head = tail;
    tail = next;
}
template <class T>
node<T>* linkedList<T>::begin() const
{
    return head;
}

template <class T>
node<T>* linkedList<T>::end() const
{
    return tail;
}

template <class T>
T linkedList<T>::front() const
{
    return head->value;
}

template <class T>
T linkedList<T>::back() const
{
    return tail->value;
}

template <class T>
void linkedList<T>::print()
{
    node<T>* temp = head;
    while(temp->next != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << temp->value;
}


template <class T>
linkedList<T>::~linkedList()
{
    clear();
}