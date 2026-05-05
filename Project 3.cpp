#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Patient structure
struct Patient {
    string name;
    int severity; // higher = more critical
    int id;
};

// Comparator for priority queue (emergency patients)
struct Compare {
    bool operator()(Patient const& p1, Patient const& p2) {
        return p1.severity < p2.severity; 
        // Higher severity gets higher priority
    }
};

class HospitalQueue {
    priority_queue<Patient, vector<Patient>, Compare> emergencyQueue; // priority queue
    queue<Patient> regularQueue;                                     // normal queue
    int nextId;

public:
    HospitalQueue() {
        nextId = 1;
    }

    // Add emergency patient
    void addEmergency(string name, int severity) {
        Patient p = {name, severity, nextId++};
        emergencyQueue.push(p);
        cout << "?? Emergency patient added: " << name << " (Severity: " << severity << ")\n";
    }

    // Add regular patient
    void addRegular(string name) {
        Patient p = {name, 0, nextId++};
        regularQueue.push(p);
        cout << "?? Regular patient added: " << name << endl;
    }

    // Serve next patient
    void servePatient() {
        if (!emergencyQueue.empty()) {
            Patient p = emergencyQueue.top();
            emergencyQueue.pop();
            cout << "? Serving EMERGENCY patient: " << p.name 
                 << " (Severity: " << p.severity << ")\n";
        } 
        else if (!regularQueue.empty()) {
            Patient p = regularQueue.front();
            regularQueue.pop();
            cout << "? Serving REGULAR patient: " << p.name << endl;
        } 
        else {
            cout << "? No patients waiting.\n";
        }
    }

    // Display queues
    void displayQueues() {
        cout << "\n--- Queue Status ---\n";
        cout << "Emergency patients waiting: " << emergencyQueue.size() << endl;
        cout << "Regular patients waiting: " << regularQueue.size() << endl;
        cout << "---------------------\n";
    }
};

// Main
int main() {
    HospitalQueue hq;
    int choice, severity;
    string name;

    do {
        cout << "\n1. Add Emergency Patient\n2. Add Regular Patient\n3. Serve Patient\n4. Display Queues\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter severity (1-10): ";
                cin >> severity;
                hq.addEmergency(name, severity);
                break;
            case 2:
                cout << "Enter patient name: ";
                cin >> name;
                hq.addRegular(name);
                break;
            case 3:
                hq.servePatient();
                break;
            case 4:
                hq.displayQueues();
                break;
            case 5:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

