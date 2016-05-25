#include <iostream>

using namespace std;

void print_arr(int a[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int sort(int a[], int n)
{
    int key, i;
    for(int j = 1; j<n; j++)
    {
        key = a[j];
        i = j-1;
        while (i>=0 && a[i]>key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    print_arr(a, n);
    return 0;
}

int main()
{
    int n;
    cin >> n;
    if(n<=0)
    {
        cout << "No array to work with !!" << endl;
        return 0;
    }
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, n);
}
