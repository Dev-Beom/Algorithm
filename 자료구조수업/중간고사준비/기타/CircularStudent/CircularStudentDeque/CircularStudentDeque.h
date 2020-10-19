/*
(3)덱을 이용하여 남학생 큐와 여학생 큐를 구현하고 큐에 입력될 때 즉시 원하는지를
물어보고 즉시 원한다고 하면 큐의 맨 처음에 삽입한다.
*/
#include "CircularStudent.h"
 
class CircularStudentDeque :public CircularStudent
{
public:
        CircularStudentDeque()
        {
               front = rear = 0;
               data = new char*[MAX_QUEUE_SIZE];
               for (int i = 0; i < MAX_QUEUE_SIZE; i++)
                       data[i] = new char[20];
        }
        ~CircularStudentDeque()
        {
               for (int i = 0; i < MAX_QUEUE_SIZE; i++)
                       delete[]data[i];
               delete[]data;
        }
        void addRear(char *name)
        {
               enqueue(name);
        }
        char *deleteFront()
        {
               return dequeue();
        }
        char *getFront()
        {
               return peek();
        }
        void addFront(char *name) //전단에 삽입
        {
               if (isFull())
                       error("Error: 덱이 포화상태입니다\n");
               else
               {
                       strcpy(data[front], name);
                       front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //front 감소
               }
        }
        char *deleteRear() //후단에서 삭제
        {
               if (isEmpty())
                       error("Error: 덱이 공백상태입니다\n");
               else
               {
                       char *ret;
                       strcpy(ret, data[rear]);
                       rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                       return ret;
               }
        }
        char *getRear() //후단에서 peek
        {
               if (isEmpty())
                       error("Error: 덱이 공백상태이빈다\n");
               else
                       return data[rear];
        }
        void display() //CircularQueue::display() 오버라이딩
        {
               cout << "덱의 내용: ";
               if (!isEmpty())
               {
                       int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
                       for (int i = front + 1; i <= maxi; i++)
                              cout << data[i%MAX_QUEUE_SIZE] << " ";
               }
               else
                       cout<<"학생이 아직 없습니다";
               cout << endl;
        }
};