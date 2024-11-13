// In this problem we can find any loop in a LL;

#include<iostream>
using namespace std;

class node{
    public: 
        int data;
        node* next;

        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void printData(node* head)
{
    if(head == NULL){
        cout << "list is empty!" << endl;
        return;
    }

    node* temp = head;
    while(temp != NULL){
        cout<<temp->data << "-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

bool findLoopInLL(node* head){
    if(head == NULL)return false;

    node* slow = head;
    node* fast = head;
    int c = 0;

    while(fast != NULL){
        c++;
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next;
        }

        if(fast == slow){
            cout << c << endl;
            return true;
        }
    }

    cout << c << endl;
    return false;
}


int main()
{

    node* head = NULL;

    // create a LL in which a loop exist
    node* fst = new node(5);
    head = fst;
    node* Snd = new node(6);
    fst->next = Snd;
    node* Trd = new node(7);
    Snd->next = Trd;
    node* Frth = new node(8);
    Trd->next = Frth;
    node* FFth = new node(9);
    Frth->next = FFth;
    node* Sth = new node(10);
    FFth->next = Sth;
    // Sth->next = Frth;

    if(findLoopInLL(head))
        cout << "Loop exist in this list"<< endl;
    else    
        cout << "loop is not exitst" << endl;
}