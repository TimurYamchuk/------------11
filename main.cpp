#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int MAX_QUEUE_SIZE = 100;

struct PrintRequest {
    string user;
    int priority;
    time_t timestamp;

    PrintRequest(const string& u, int p) : user(u), priority(p) {
        timestamp = time(nullptr);
    }
};

int main() {
    PrintRequest printQueue[MAX_QUEUE_SIZE];
    int front = 0; 
    int rear = -1;
    int historyIndex = 0;
    PrintRequest printHistory[MAX_QUEUE_SIZE];

    while (true) {
        string userName;
        int userPriority;

        cout << "Enter username (or 'exit' to quit): ";
        cin >> userName;

        if (userName == "exit") {
            break;
        }

        cout << "Enter priority (1 - low, 2 - medium, 3 - high): ";
        cin >> userPriority;

        if (userPriority < 1 || userPriority > 3) {
            cout << "Invalid priority. Please choose 1, 2, or 3." << endl;
            continue;
        }

        PrintRequest newRequest(userName, userPriority);

        if (rear < MAX_QUEUE_SIZE - 1) {
            rear++;
            printQueue[rear] = newRequest;
            printHistory[historyIndex++] = newRequest;
            cout << "Print request added to the queue." << endl;
        } else {
            cout << "Print queue is full. Cannot add more requests." << endl;
        }
    }

    cout << "Printing queue:" << endl;
    for (int i = front; i <= rear; i++) {
        PrintRequest req = printQueue[i];
        cout << "User: " << req.user << " Priority: " << req.priority << endl;
    }

    cout << "\nPrint history:" << endl;
    for (int i = 0; i < historyIndex; i++) {
        PrintRequest req = printHistory[i];
        cout << "User: " << req.user << " Priority: " << req.priority << " Time: " << ctime(&req.timestamp);
    }

    return 0;
}
