/*
NOTE
앞에서 구현한 LinkedList 클래스를 참고하여 원형 연결 리스트 클래스
CircularList를 구현하고 동작을 테스트 해라
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
    Node(int temp)
    {
        data = temp;
        link = NULL;
    }
};

class CircularList
{
private:
    Node *head; //  앞에 노드를 가리키는 포인터
    Node *tail; //  끝 노드를 가리키는 포인터
public:
    CircularList()
    {
        head = tail = NULL;
    }
    ~CircularList()
    {
        clear(); //  소멸자
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
        return head;
    }
    bool isEmpty()
    {
        return getHead() == NULL;
    }

    //리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node *n)
    {
        if (pos == 0) //  head에 입력
        {
            if (head == NULL) //  head가 비어있다면
            {
                head = n;
                tail = n;
                n->link = tail;
                return;
            }
            else if (head != NULL) //  head가 비어있지 않는다면
            {
                n->link = head;
                head = n;
                tail->link = n;
                return;
            }
        }
        //  head 이외의 곳에 입력한다면
        int index = 0;
        Node *current = head;
        while (index > pos - 1)
        {
            current = current->link;
            index++;
        }
        n->link = current->link;
        current->link = n;
    }

    //  리스트의 어떤 위치의 항목 삭제
    Node *remove(int pos)
    {
        if (isEmpty()) //  리스트가 비어있다면
        {
            return NULL;
        }
        if (pos == 0) //  첫번째 요소를 삭제한다면
        {
            if (head == tail) //  데이터가 하나일때
            {
                head = tail = NULL;
                return NULL;
            }
            else //  데이터가 여러개일 때
            {
                Node *del = head;
                head = head->link;
                tail->link = head;
                return del;
            }
        }
        //head 말고 다른 요소를 삭제할 경우
        int index = 0;
        Node *temp = NULL;
        Node *current = head;
        while (index < pos)
        {
            if (current->link == NULL)
            {
                return NULL;
            }
            if (index == pos - 1)
            {
                temp = current;
            }
            current = current->link;
            index++;
        }
        temp->link = current->link;
        if (current == tail) //  만약 삭제된 곳이 tail이였다면
        {
            tail = temp; //  tail을 초기화
        }
        return current;
    }

    int size()
    {
        Node *current = head;
        int index = 1;
        if (!isEmpty())
        {
            current = current->link;
        }
        while (current != head)
        {
            index++;
            current = current->link;
        }
        return index;
    }

    //화면에 보기 좋게 출력
    void display()
    {
        if (size() == 1) //  size()가 1을 반환했다는 것은 리스트가 비어있다는 뜻
        {
            cout << "[전체 항목 수 = 0]: " << endl;
            return;
        }
        cout << "[전체 항목 수 = " << size() << "]: ";
        Node *current = head;
        cout << "<" << current->data << ">";
        current = current->link;
        while (current != head)
        {
            cout << "<" << current->data << ">";
            current = current->link;
        }
        cout << endl;
    }
};