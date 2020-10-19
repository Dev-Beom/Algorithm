/*
NOTE
단순 연결리스트 클래스
*/

#include "listNode.h"

class LinkedList
{
private:
    Node org; //  헤드 노드(헤드 포인터 아님)
public:
    LinkedList() : org(0)
    {
    }
    ~LinkedList()
    {
        clear();
    }
    void clear()
    {
        while (!isEmpty())
        {
            delete remove(0);
        }
    }
    Node *getHead()
    {
        return org.getLink();
    }
    bool isEmpty()
    {
        return getHead() == NULL;
    }

    //pos번째 항목을 반환
    Node *getEntry(int pos)
    {
        Node *n = &org;
        for (int i = -1; i < pos; i++, n = n->getLink())
        {
            if (n == NULL)
            {
                break;
            }
        }
        return n;
    }

    //리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node *n)
    {
        Node *prev = getEntry(pos - 1);
        if (prev != NULL)
        {
            prev->insertNext(n);
        }
    }

    //리스트의 어떤 위치의 항목 삭제
    Node *remove(int pos)
    {
        Node *prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    //탐색 함수
    Node *find(int val)
    {
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            if (p->hasData(val))
            {
                return p;
            }
            return NULL;
        }
    }

    //리스트의 어떤 위치에 항목 삽입
    void replace(int pos, Node *n)
    {
        Node *prev = getEntry(pos - 1);
        if (prev != NULL)
        {
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }

    //리스트의 항목 개수를 반환
    int size()
    {
        int count = 0;
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            count++;
        }
        return count;
    }

    //화면에 보기좋게 출력
    void display()
    {
        cout << "[전체 항목 수 = " << size() << "] : ";
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            p->display();
        }
        cout << endl;
    }

    //모든 데이터 값을 더한 합을 출력하는 함수
    void sum()
    {
        int Add = 0;
        cout << "[전체 항목의 합 = ";
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            Add += p->getData();
        }
        cout << Add << "]" << endl;
    }

    //단순 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수
    int count(int val)
    {
        int cnt = 0;
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            if (p->hasData(val))
            {
                cnt++;
            }
        }
        return cnt;
    }

    //연결리스트의 모든 노드의 순서를 반대로 바꾸는 연산
    void reverse()
    {
        int count = 0;
        for (int i = 0; i < size(); i++)
        {
            Node *p = remove(size() - 1);   //  마지막 노드를 삭제하고
            insert(count++, p); //  count번째에 입력, count는 계속 늘어난다.
        }
    }

    //다른 리스트 객체 that의 노드 정보를 현재 리스트에 병합하는 다음 연산을 구현하라.
    void merge(LinkedList *that)
    {
        while(!that->isEmpty())
        {
            Node *p = that -> remove(0);    //  that을 삭제하고
            insert(size(), p);  //  삭제된 노드를 입력
        }
    }
};