/*
은행 서비스 시뮬레이션 프로그램을 참고하여 자동으로 시뮬레이션 할 수 있는 프로그램을 설계하고 구현하라
*/
#include "CircularSimulator.h"
 
int main(void)
{
        srand((unsigned)time(NULL));
        CircularSimulator sim;
        sim.readSimulationParameters();
        sim.run();
        sim.printStat();
        return 0;
}
