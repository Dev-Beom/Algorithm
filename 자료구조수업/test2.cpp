#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 256

class AdjMatGraph {
protected:
   int size;
   char vertices[MAX];
   int adj[MAX][MAX]; //정적할당

public:
   AdjMatGraph() { reset(); }
   char getVertex(int i) { return vertices[i]; }
   int getEdge(int i, int j) { return adj[i][j]; }
   void setEdge(int i, int j, int val) { adj[i][j] = val; }

   bool isEmpty() { return size == 0; }
   bool isFull() { return size >= MAX; }

   void reset() {
      size = 0;
      for (int i = 0; i < MAX; i++) {
         for (int j = 0; j < MAX; j++) {
            setEdge(i, j, 0);
         }
      }
   }

   void insertVertex(char name) {
      if (!isFull())vertices[size++] = name;
      else cout << "Error: 그래프 점점 개수 초과" << endl;
   }

   void insertEdge(int u, int v) { // 간선 삽입 ( 무방향 그래프 )
      setEdge(u, v, 1);
      setEdge(v, u, 1);
   }

   void deleteVertex(char name) {
      int index = 0;
      if (isEmpty()) return;
      else {
         for (int i = 0; i < size; i++) {
            if (vertices[i] == name) {
               index = i;
               for (int j = i; j < size - 1; j++) {
                  vertices[j] = vertices[j + 1];
               }
               break;
            }
         }
      }
      int adjtmp[MAX][MAX] = {0, };
      int a=0;
      int b=0;
      for(int i=0;i<size;i++){
         b=0;
         if(i!=index){
            for(int j=0;j<size;j++){
               if(j!=index){
                adj[a][b] = adj[i][j];
                b++;
               }
               else{continue;}
            }a++;
         }
      }
      size--;
      for(int i = size ;i<MAX;i++){
         for(int j = size ; j< MAX;j++){
            adj[i][j] = 0;
         }
      }
   }

   void display() {                              
      for (int i = 0; i < size; i++) {
         cout << vertices[i] << " ";
         for (int j = 0; j < size; j++) {            
            cout << adj[i][j] << " ";
         }
         cout << endl;
      }
      cout << endl;
   }
};

int main() {
   AdjMatGraph g;
   for (int i = 0; i < 4; i++) {
      g.insertVertex('A' + i);
   }
   g.insertEdge(0, 1);
   g.insertEdge(0, 3);
   g.insertEdge(1, 2);
   g.insertEdge(1, 3);
   g.insertEdge(2, 3);
   cout << "인접 행렬로 표현한 그래프" << endl;
   g.display();

   g.deleteVertex('A');
   g.display();
   return 0;
}