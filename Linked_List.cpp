#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
    //template below:
    node(){
        val = 0;
        next = NULL;
    }
    node(int k){
        val = k;
        next = NULL;
    }

 //    int       node*
 //   --------------
 //   |_____|____*__|
//      val     next
};

struct SinglyLinkedList{
    node *head, *tail;
    SinglyLinkedList();
    void insertIntoHead(int);
    void insertIntoTail(int);
    int deleteFromHead();
    void printList();
};

SinglyLinkedList::SinglyLinkedList(){
    head = NULL;
    tail = NULL;
}

void SinglyLinkedList::insertIntoTail(int x){
    node *cur = new node(x);
    if(tail==NULL){
        head = tail = cur;
        return;
    }
    tail->next = cur;
    tail = tail->next;
}

void SinglyLinkedList::insertIntoHead(int x){

}

int SinglyLinkedList::deleteFromHead(){
    if(head==NULL){
        cout << "Underflow" << endl;
        return -1;
    }
    node *temp = head;//ekta temp node er moddhe head takey niye rakhlam..
    int ret = temp->val;//temp er value mane head ta..
    if(head->next == NULL){//single element..
        head = tail = NULL;//duitai null hoye jabey tokhn..
    }
    else {
        head = head->next;//head er next ke head korey dilam..
    }

    delete temp;//temp(ager head)takey delete korey dilam..
    return ret;
}

void SinglyLinkedList::printList(){

}

int main(){
    SinglyLinkedList sl;
    sl.insertIntoTail(5);
    sl.printList();
    sl.insertIntoTail(56);
    sl.printList();
    sl.insertIntoHead(156);
    sl.printList();
    sl.insertIntoTail(6);
    sl.printList();
    sl.deleteFromHead();
    sl.printList();
    sl.deleteFromHead();
    sl.printList();
    sl.deleteFromHead();
    sl.printList();
    sl.insertIntoTail(79);
    sl.printList();
    sl.deleteFromHead();
    sl.printList();
    sl.deleteFromHead();
    sl.printList();
    sl.deleteFromHead();
    sl.printList();

    return 0;
}