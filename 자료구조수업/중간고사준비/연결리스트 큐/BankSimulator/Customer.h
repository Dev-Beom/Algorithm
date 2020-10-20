#pragma once

struct Customer
{
    int id;
    int tArrival;
    int tService;
    Customer(int i = 0, int tArr = 0, int tServ = 0) : id(i), tArrival(tArr), tService(tServ) {}
};
