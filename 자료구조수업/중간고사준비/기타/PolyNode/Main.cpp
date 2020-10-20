#include "polyList.h"

int main(int argc, char const *argv[])
{
    polyList A, B, C;
    cout << "다항식 A를 입력하세요.\n";
    A.input();
    A.Poly_Print();
    cout << "다항식 B를 입력하세요.\n";
    B.input();
    B.Poly_Print();
    cout << "C= ";
    A.Poly_Add(&B);
    return 0;
}
