//Brandon Jacobson and Isabella Katz

#include <iostream>
#include <chrono>
#include "StringData.h"
using namespace std;

//Initializing functions
int linear_search(vector<string> container, string element);
int binary_search(vector<string> container, string element);

//Linear search function
//Iterates through the container vector until finding the target element
int linear_search(vector<string> container, string element){
    for (int i = 0; i < container.size(); i++){
        if (container[i] == element){
            return i;
        }
    }
    return -1;
}

//Binary Search Function
//Cuts container vector in half and checks which half the element is in
//Repeats this until the element is found
int binary_search(vector<string> container, string element){
    int low = 0;
    int high = container.size() - 1;

    while (low <= high){
        int middle = (low + high) / 2;
        if (container[middle] < element){
            low = middle + 1;
        } else if (container[middle] > element){
           high = middle - 1;
        }
        if (container[middle] == element){
            return middle;
        }
    }
    return -1;
}

int main(){
    //Each search is conducted after checking the time and then the total time is printed
    std::vector<string> container = getStringData();
    auto beginning_time = chrono::system_clock::now();
    linear_search(container, "not_here");
    auto end_time = chrono::system_clock::now();
    auto total_time = end_time - beginning_time;
    cout << "Time for Linear Search for 'not_here': " << total_time.count() << endl;

    cout;
    beginning_time = chrono::system_clock::now();
    binary_search(container, "not_here");
    end_time = chrono::system_clock::now();
    total_time = end_time - beginning_time;
    cout << "Time for Binary Search for 'not_here': " << total_time.count() << endl;

    cout;
    beginning_time = chrono::system_clock::now();
    linear_search(container, "mzzzz");
    end_time = chrono::system_clock::now();
    total_time = end_time - beginning_time;
    cout << "Time for Linear Search for 'mzzzz': " << total_time.count() << endl;

    cout;
    beginning_time = chrono::system_clock::now();
    binary_search(container, "mzzzz");
    end_time = chrono::system_clock::now();
    total_time = end_time - beginning_time;
    cout << "Time for Binary Search for 'mzzzz': " << total_time.count() << endl;

    cout;
    beginning_time = chrono::system_clock::now();
    linear_search(container, "aaaaa");
    end_time = chrono::system_clock::now();
    total_time = end_time - beginning_time;
    cout << "Time for Linear Search for 'aaaaa': " << total_time.count() << endl;

    cout;
    beginning_time = chrono::system_clock::now();
    binary_search(container, "aaaaa");
    end_time = chrono::system_clock::now();
    total_time = end_time - beginning_time;
    cout << "Time for Binary Search for 'aaaaa': " << duration_cast(total_time) << endl;
}
