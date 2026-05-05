#include <iostream> 
#define SIZE 5 
using namespace std; 
 
// Global Queue and Pointers 
int queue[SIZE]; 
int front = -1, rear = -1; 
 
// Enqueue: Insert element 
void enqueue(int value) { 
    if (rear == SIZE - 1) { 
        cout << "Queue Overflow! Cannot insert " << value << endl; 
        return; 
    } 
    if (front == -1) front = 0; // First insertion 
    rear++; 
    queue[rear] = value; 
    cout << value << " inserted at position " << rear << endl; 
} 
 
// Dequeue: Remove element 
void dequeue() { 
    if (front == -1 || front > rear) { 
        cout << "Queue Underflow! No elements to remove." << endl; 
        return; 
    } 
    cout << queue[front] << " removed from position " << front << 
endl; 
    front++; 
    if (front > rear) { 
        // Reset queue when all elements removed 
        front = rear = -1; 
    } 
} 
 
// Display queue elements 
void display() { 
    if (front == -1 || front > rear) { 
        cout << "Queue is Empty." << endl; 
        return; 
    } 
    cout << "Queue Elements: "; 
    for (int i = front; i <= rear; i++) { 
        cout << queue[i] << " "; 
    } 
    cout << endl; 
} 
 
// Main Function: Menu using while loop and switch-case 
int main() { 
    int choice, value; 
 
    cout << "Queue Implementation using Array (Menu-Based)\n"; 
 
    while (true) { 
        // Menu 
        cout << "\n=== MENU ===\n"; 
        cout << "1. Enqueue (Insert)\n"; 
        cout << "2. Dequeue (Remove)\n"; 
        cout << "3. Display Queue\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice (1-4): "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter value to enqueue: "; 
                cin >> value; 
                enqueue(value); 
                break; 
 
            case 2: 
                dequeue(); 
                break; 
 
            case 3: 
                display(); 
                break; 
 
            case 4: 
                cout << "Exiting program. Thank you!\n"; 
                return 0; // End the program 
 
            default: 
                cout << "Invalid choice. Please enter a number between 1 and 4.\n"; 
        } 
    } 
 
    return 0; 
}
