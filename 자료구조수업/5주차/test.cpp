#include <iostream>

using namespace std;

void sub(int b[])
{
    b[0] = 0;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6};
    sub(a);

    cout << a[0];
    
    return 0;
}
