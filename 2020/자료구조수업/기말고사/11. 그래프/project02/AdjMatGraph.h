/*
인접 행렬을 이용한 그래프 클래스 프로그램
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
#define MAX_VTXS 256 //표현 가능한 최대 정점의 개수
 
class AdjMatGraph
{
protected:
        int size; //정점의 개수
        char vertices[MAX_VTXS]; //정점의 이름
        int adj[MAX_VTXS][MAX_VTXS]; //인접 행렬

public:
        AdjMatGraph()
        {
               reset();
        }

        char getVertex(int i)
        {
               return vertices[i];
        }

        int getEdge(int i, int j)
        {
               return adj[i][j];
        }

        void setEdge(int i, int j, int val)
        {
               adj[i][j] = val;
        }

        bool isEmpty()
        {
               return size == 0;
        }

        bool isFull()
        {
               return size >= MAX_VTXS;
        }

        //그래프 초기화==>공백 상태의 그래프
        void reset()
        {
               size = 0;
               for (int i = 0; i < MAX_VTXS; i++)
                       for (int j = 0; j < MAX_VTXS; j++)
                              setEdge(i, j, 0);
        }

        //정점 삽입 연산
        void insertVertex(char name)
        {
               if (!isFull())
                       vertices[size++] = name;
               else
                       cout << "Error: 그래프 정점 개수 초과" << endl;
        }

        //간선 삽입 연산: 무방향 그래프의 경우
        void insertEdge(int u, int v)
        {
               setEdge(u, v, 1);
               setEdge(v, u, 1); //방향 그래프에서는 삭제
        }

        //무작위로 그래프를 발생시키는 함수
        void randomGraph(int numVtx, int numEdge)
        {
               int i = 0;
               for (int j = 0; j < numVtx; j++)
                       insertVertex('A'+j);
               while (i < numEdge)
               {
                       int count = 0;
                       do
                       {
                              int first = rand() % numVtx;
                              int second;
                              do
                              {
                                      second = rand() % numVtx;
                              } while (first == second);
                              if (!adj[first][second])
                              {
                                      insertEdge(first, second);
                                      count++;
                              }
                       } while (!count);
                       i++;
               }
        }

        //모든 정점이 연결된 "연결 그래프"를 무작위로 발생시키는 함수
        void randomConnectedGraph(int numVtx)
        {
               for (int j = 0; j < numVtx; j++)
                       insertVertex('A' + j);
               for (int i = 0; i < numVtx; i++)
                       for (int j = 0; j < numVtx; j++)
                              if (i != j)
                                      insertEdge(i, j);
        }

        //그래프 정보 출력
        void display(FILE *fp = stdout)
        {
               fprintf(fp, "%d\n", size);
               for (int i = 0; i < size; i++)
               {
                       fprintf(fp, "%c ", getVertex(i));
                       for (int j = 0; j < size; j++)
                              fprintf(fp, " %3d", getEdge(i, j));;
                       fprintf(fp, "\n");
               }
        }

        //파일 입력 함수
        void load(char *filename)
        {
               FILE *fp = fopen(filename, "r");;
               if (fp != NULL)
               {
                       int n, val;
                       fscanf(fp, "%d", &n); //정점의 전체 개수
                       for (int i = 0; i < n; i++)
                       {
                              char str[80];
                              fscanf(fp, "%s", str);
                              insertVertex(str[0]);
                              for (int j = 0; j < n; j++)
                              {
                                      int val;
                                      fscanf(fp, "%d", &val);
                                      if (val != 0)
                                              insertEdge(i, j);
                              }
                       }
                       fclose(fp);
               }
        }

        //파일 저장 함수
        void store(char *filename)
        {
               FILE *fp = fopen(filename, "w");
               if (fp != NULL)
               {
                       display(fp);
                       fclose(fp);
               }
        }
};