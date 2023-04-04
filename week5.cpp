#include <iostream>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int my_stack[100];
int n = 100;
int Top = -1;

//push function
void Push(int val) {
    if(Top >= n-1){
        cout << "Stack Overflow" << endl;
    }
    else {
        Top++;
        my_stack[Top]=val;
    }
}

//pop function
void Pop() {
    if (Top <=- 1){
        cout << "Stack Underflow" << endl;
    }
    else {
        Top--;
        cout << "The popped element is " << my_stack[Top+1] << endl;
    }
}

//display function
void Display() {
    if(Top >= 0) {
        cout << "Stack elements are:";
        for (int i=Top; i>=0; i--)
        cout << my_stack[i] <<" ";
        cout << endl;
    } 
    else {
        cout << "Stack is empty";
    }
}

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
	cout << "Total time taken is "<< duration.count() <<" microseconds"<< endl;
	cout << "\n";
    return 0;
}