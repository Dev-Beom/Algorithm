#include "polyList.h"

int main(int argc, char const *argv[])
{
    polyList A, B, C;
    A.input();
    B.input();
    cout << "A = (" << A.size() << "항) = ";
    A.display();
    cout << "B = (" << B.size() << "항) = ";
    B.display();
    A.Add(&B);
    return 0;
}
