#include<iostream> 
using namespace std;

void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
    n = n / 10;    

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";
    
    return;
}

int main() {

    string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    cout<<"Enter a Number->"<<endl;
    int n;
    cin >> n;
    sayDigit(n, arr);



    return 0;
}