#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
    Node* head;
public:
    List() : head(nullptr) {}
    
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    List list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(2);
    list.insert(2);
    list.insert(5);
    
    int key = 2;
    int occurrences = list.countOccurrences(key);
    
    cout << "Количество вхождений ключа " << key << ": " << occurrences << endl;
    
    return 0;
}
