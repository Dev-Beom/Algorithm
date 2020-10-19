/*
다항식 링크드 리스트
*/
#include "polyNode.h"

class polyList
{
private:
    Node org;

public:
    polyList() : org(0)
    {
    }
    ~polyList()
    {
        clear();
    }
    void clear()
    {
        while (!isEmpty())
            delete remove(0);
    }
    Node *getHead()
    {
        return org.getLink();
    }
    bool isEmpty()
    {
        return getHead() == NULL;
    }
    //pos번째 항목을 반환함
    Node *getEntry(int pos)
    {
        Node *n = &org;
        for (int i = -1; i < pos; i++, n = n->getLink())
            if (n == NULL)
                break;
        return n;
    }
    //리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node *n)
    {
        Node *prev = getEntry(pos - 1);
        if (prev != NULL)
            prev->insertNext(n);
    }
    //리스트의 어떤 위치의 항목 삭제
    Node *remove(int pos)
    {
        Node *prev = getEntry(pos - 1);
        return prev->removeNext();
    }
    //리스트의 항목 개수 반환
    int size()
    {
        int count = 0;
        for (Node *p = getHead(); p != NULL; p = p->getLink())
            count++;
        return count;
    }
    void Add(polyList *that)
    {
        polyList temp;
        int count = 0;
        Node *p = getHead();
        Node *t = that->getHead();
        while (p != NULL && t != NULL)
        {
            if (p->exp == t->exp)
            {
                temp.insert(count++, new Node(p->coef + t->coef, p->exp));
                p = p->getLink();
                t = t->getLink();
            }
            else if (p->exp > t->exp)
            {
                temp.insert(count++, new Node(p->coef, p->exp));
                p = p->getLink();
            }
            else
            {
                temp.insert(count++, new Node(t->coef, t->exp));
                t = t->getLink();
            }
        }
        for (; p != NULL; p = p->getLink())
            temp.insert(count++, new Node(p->coef, p->exp));
        for (; t != NULL; t = t->getLink())
            temp.insert(count++, new Node(t->coef, t->exp));
        cout << "A+B =(" << temp.size() << "항)= ";
        temp.display();
    }
    void input()
    {
        int count, e;
        float c;
        cout << "희소 다항식의 항의 개수를 입력하세요: ";
        cin >> count;
        cout << "각 항의 계수와 지수 입력(최고차항부터 " << count << "개)" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << "번째 항: 계수 지수 = ";
            cin >> c >> e;
            insert(i, new Node(c, e));
        }
    }

    //화면에 보기 좋게 출력
    void display()
    {
        int count = 1;
        if (size() == 0)
        {
            cout << "다항식이 존재하지 않습니다" << endl;
            return;
        }
        else
        {
            for (Node *p = getHead(); p != NULL; p = p->getLink())
            {
                p->display();
            }
            cout << endl;
        }
    }
};