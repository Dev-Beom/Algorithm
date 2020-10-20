#pragma once
#include "CustomerQueue.h"

class BankSimulator
{
    int nSimulation;
    double probArrival;
    int tMaxService;
    int totalWaitTime;
    int nCustomers;
    int nServedCustomers;

    LinkedQueue que;

    double Random()
    {
        return rand() / (double)RAND_MAX;
    }

    bool IsNewCustomer()
    {
        return Random() > probArrival;
    }

    int RandServiceTime()
    {
        return (int)(tMaxService * Random()) + 1;
    }

    void InsertCustomer(int arrivalTime)
    {
        Customer a(++nCustomers, arrivalTime, RandServiceTime());
        printf("  고객 %d 방문 (서비스 시간: %d분)\n", a.id, a.tArrival, a.tService);
        que.enqueue(new Node(a));
    }

public:
    BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0) {}

    void readSimulationParameters()
    {
        printf("시뮬레이션 할 최대 시간 (예: 10) = ");
        scanf("%d", &nSimulation);

        printf("단위시간에 도착하는 고객 수 (예: 0.5) = ");
        scanf("%lf", &probArrival);

        printf("한 고객에 대한 최대 서비스 시간 (예: 5) = ");
        scanf("%d", &tMaxService);

        printf("====================================================\n");
    }

    void run()
    {
        int clock = 0;
        int serviceTime = -1;

        while (clock < nSimulation)
        {
            clock++;
            printf("현재시각 = %d\n", clock);

            if (IsNewCustomer())
                InsertCustomer(clock);
            if (serviceTime > 0)
                serviceTime--;
            else
            {
                if (que.isEmpty())
                    continue;
                Customer a = que.dequeue()->getData();
                nServedCustomers++;
                totalWaitTime += clock - a.tArrival;
                printf("  고객 %d 서비스 시작 (대기시간: %d분)\n", a.id, clock - a.tArrival);
                serviceTime = a.tService - 1;
            }
        }
    }

    void printStat()
    {
        printf("=================================================\n");
        printf("  서비스 받은 고객수      = %d\n", nServedCustomers);
        printf("  전체 대기 시간          = %d분\n", totalWaitTime);
        printf("  서비스고객 평균대기시간 = %-5.2f분\n",
               (double)totalWaitTime / nServedCustomers);
        printf("  현재 대기 고객 수       = %d\n", nCustomers - nServedCustomers);
    }
};