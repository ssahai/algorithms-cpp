/*
 * Code to add two arbitrary large integers using arrays
 */

#include <iostream>

using namespace std;

int main() {
    int l1, l2;
    cout << "Enter length of first integer  : ";
    cin  >> l1;
    cout << "Enter length of second integer : ";
    cin  >> l2;
    int i1[l1], i2[l2];         // array to represent integers
    int l_res = max(l1,l2) + 1;     // length of resultant (a+b)
    // Taking inputs
    string n1, n2;
    cout <<endl;
    cout << "Enter first integer \t: ";
    cin >> n1;
    for (int i = l1-1; i>=0 ; i--) {
        i1[i] = n1[l1-i-1] - '0';
    }
    cout << "Enter second integer \t: ";
    cin >> n2;
    for (int i = 0; i<l2 ; i++) {
        i2[i] = n2[l2-i-1] - '0';
    }
    int res[l_res];             // array to store result ( = i1 + i2 )
    
    int res_temp = 0, temp = 0;
    for (int j = 0; j<l_res; j++) {
        if (j < min(l1,l2)) {
            res_temp = i1[j] + i2[j];
        }
        else if (j >= l1 and j< l2 ) {
            res_temp = i2[j];
        }
        else if (j < l1 and j >= l2 ) {
            res_temp = i1[j];
        }
        else {
            res_temp = 0;}
        res[j]   = (res_temp + temp)%10;
        temp     = (res_temp+temp)/10;
    }
    cout <<"\nThe sum of two integers is :"<<endl;
    for (int i = l_res-1; i>=0; i--) {
        if (i ==l_res-1 and res[i]==0)
            continue;
        cout << res[i];
    }
    cout <<endl;
}
