#include <iostream>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
struct Node* Top = NULL;

void Push(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = Top;
    Top = newNode;
}
void Pop() {
    if(Top == NULL)
    cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << Top->data << endl;
        Top = Top -> next;
    }
}
void Display() {
    struct Node* pointer;
    if(Top == NULL)
    cout<<"Stack is empty";
    else {
        pointer = Top;
        cout << "Stack elements are: ";
        while (pointer != NULL) {
            cout << pointer -> data <<" ";
            pointer = pointer -> next;
        }
    }
    cout << endl;
}

//main function
int main() {
    auto start1 = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    auto stop1 = high_resolution_clock::now();
    auto start3 = high_resolution_clock::now();
    Display();
    auto stop3 = high_resolution_clock::now();
    auto start2 = high_resolution_clock::now();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    auto stop2 = high_resolution_clock::now();
    auto start4 = high_resolution_clock::now();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto stop4 = high_resolution_clock::now();
    //auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time taken for first 10 push operations is "<<duration1.count() <<" microseconds"<< endl;
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken for pop operations is "<<duration2.count() <<" microseconds"<< endl;
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time taken for display operation is "<<duration3.count() <<" microseconds"<< endl;
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    auto duration = duration1 + duration2 + duration3 + duration4;
	cout << "Total time taken is "<<duration.count() <<" microseconds"<< endl;
	cout << "\n";
    return 0;
}