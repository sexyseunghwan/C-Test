#include <iostream>

using namespace std;

int main() {

    int arr[10];

    int* ptr1 = &arr[3];
    int* ptr2 = &arr[5];

    printf("%ld" ,ptr2 - ptr1);



}