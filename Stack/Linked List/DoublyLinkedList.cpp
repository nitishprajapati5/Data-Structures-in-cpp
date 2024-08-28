#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        //With Data 
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        //Without Data
        Node(){
            this->next = NULL;
            this->prev = NULL;
        }
};

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while (temp != NULL)
    {
        /* code */
        len++;
        temp = temp->next;
        
    }
    return len;
}


void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = getLength(head);
        
        if(position == 1){
            insertAtHead(head,tail,data);
        }
        else if(position == len + 1){
            insertAtTail(head,tail,data);
        }
        else{
            Node* newNode = new Node(data);
            Node *prevNode = NULL;
            Node *currNode = head;

            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }




    }
}

void deleteNode(Node* head,Node* tail,int position){
    if(head == NULL){
        cout << "We Do Not Have Any Nodes here" << endl;
        return;
    }

    if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        return;
    }

    //Delete from Head
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //temp->next = NULL;
        temp->next = NULL;
        head->prev = NULL;

        delete temp;
    }
     //Delete from Tail
    else if(position == getLength(head)){
        Node* prevNode = tail;
        prevNode->next = NULL;
        prevNode->prev = NULL;
        delete tail;
        tail = prevNode;
    }
        //Delete At Position

    else{
        int len = getLength(head);
        Node* prevNode = NULL;
        Node* currNode = head;
        
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;

    }
    

   
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "---->" ;
        temp = temp->next;
    }
    return;
}

int main(){

Node* head = NULL;
Node* tail = NULL;

insertAtHead(head,tail,40);
insertAtHead(head,tail,30);
insertAtHead(head,tail,20);
insertAtHead(head,tail,10);
insertAtTail(head,tail,1000);
insertAtPosition(head,tail,120,4);
print(head);
cout << endl;

deleteNode(head,tail,6);
print(head);

return 0;

}