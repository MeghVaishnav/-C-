#include<iostream>
using namespace std;
struct Node {
	int data;
	Node*next; 
}; 
Node*head=NULL;

void insertAtBeginning (int value) {
	Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at beginning." << endl;
} 
void insertAtEnd (int value) {
	Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << value << " inserted at end." << endl;
}
void deleteFromBeginning() {
	if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp; 
}
void deleteFromEnd() {
	if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return; 
        }
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
}
 
void display() {
	 if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "List elements: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void search(int value) {
	if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << value << " not found in the list." << endl;
}
int main () {
	int choice,value;
	while (true) {
		cout<<"\n---MENU---\n";
		cout<<"1. Inserat at beginning"<<endl;
		cout<<"2. Inseart at End"<<endl;
		cout<<"3. Delete from beginning"<<endl;
		cout<<"4. Delete from end"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Search"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;
		
		switch(choice) {
			case 1:
				cout<<"Enetr the value:";
				cin>>value;
				insertAtBeginning (value);
				break; 
				case 2: 
				cout<<"Enter the value: ";
				cin>>value;
				insertAtEnd ( value);
				break;
				case 3: 
				deleteFromBeginning();
				break;
				case 4: 
				deleteFromEnd();
				break;
				case 5: 
				display();
				break;
				case 6 :
					cout<<"Enter the value to search: ";
				cin>>value;
				search( value);
				break;
				case 7: 
				return 0;
				break;
				default: 
				cout<<"Error!";
					
				
		} 
		
	} 
	return 0;
}

