//시간복잡도 별 연산 횟수 그래프 : http://stackoverflow.com/questions/7830727/n-log-n-is-on
  #include <iostream>
  #include <ctime>
  #include <cstdlib>
  using namespace std;

  int algorithmA(int n);  //시간복잡도 O(1)
  int algorithmB(int n);  //시간복잡도 O(n)
  int algorithmC(int n);  //시간복잡도 O(n^2)
  int main(void)
  {
      clock_t startTime, endTime;
  
      double runTime;
      int n, result[3];
  
      cin >> n;

      startTime = clock();
      result[0] = algorithmA(n);
      endTime = clock();

      cout << "algorithmA Result: " << result[0] << endl;
      runTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
      cout << "algotirhmA calc time: " << runTime << endl;

      startTime = clock();
      result[1] = algorithmB(n);
      endTime = clock();
      
      cout << "algorithmB Result: " << result[1] << endl;
      runTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
      cout << "algorithmB calc time: " << runTime << endl;

      startTime = clock();
      result[2] = algorithmC(n);
      endTime = clock();
      
      cout << "algorithmC Result: " << result[2] << endl;
      runTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
      cout << "algorithmC calc time: " << runTime << endl;

      return 0;
  }

  int algorithmA(int n)
  {
      return n * n;
  }
  int algorithmB(int n)
  {
      int sum = 0;
      for (int i = 1; i <= n; i++)
          sum += n;
      return sum;
  }
  int algorithmC(int n)
  {
      int sum = 0;
      for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
              sum += 1;
      return sum;
  }