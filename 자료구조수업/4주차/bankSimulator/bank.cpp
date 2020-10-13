// 04장-BankSimulator.cpp: 은행 시뮬레이션 프로그램
#include <time.h>

#include "BankSimulator.h"

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    BankSimulator sim;
    sim.readSimulationParameters();

    sim.run();
    sim.printStat();
    return 0;
}
