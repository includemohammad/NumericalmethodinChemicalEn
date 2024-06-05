#include <iostream>
#include <string>
using namespace std ;

int main() {
    string st;
    cout<<"Please Enter your Number : "<<endl;
    cin >> st;
    int num = stoi(st); 

    cout << "Convert string to integer : " << num << endl;
    
    return 0;
}
