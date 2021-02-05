#include <iostream>

using namespace std;

class Person
{
private:
    int weight;
    int height;
    int ranking;
    char name;

public:
    Person()
    {
        weight = 0;
        height = 0;
        ranking = 0;
    }

    void setPersonInfo(int weight, int height, char name)
    {
        this->weight = weight;
        this->height = height;
        this->name = name;
    }
    void setRanking(int ranking)
    {
        this->ranking = ranking;
    }

    void showPersonInfo()
    {
        cout << name;
        cout << " <" << weight;
        cout << " , " << height;
        cout << "> "
             << "Ranking: " << ranking << endl;
    }
    int getWeight()
    {
        return weight;
    }
    int getHeight()
    {
        return height;
    }
    int getRanking()
    {
        return ranking;
    }
    char getName()
    {
        return name;
    }
};

int main(int argc, char *argv[])
{
    cout << "start" << endl;

    int length;
    char name;
    int weight;
    int height;

    cin >> length;
    int rank = 0;

    Person *parr = new Person[length];
    for (int i = 0; i < length; i++)
    {
        cout << i << " : "
             << "name: ";
        cin >> name;
        cout << i << " : "
             << "weight: ";
        cin >> weight;
        cout << i << " : "
             << "height: ";
        cin >> height;
        parr[i].setPersonInfo(weight, height, name);
    }
    cout << "input Value ? " << endl;
    for (int i = 0; i < length; i++)
    {
        parr[i].showPersonInfo();
    }
    cout << "Set Ranking ? " << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (parr[i].getWeight() < parr[j].getWeight() && parr[i].getHeight() < parr[j].getHeight())
            {
                rank++;
            }
        }
        parr[i].setRanking(rank + 1);
        rank = 0;
    }
    for (int i = 0; i < length; i++)
    {
        parr[i].showPersonInfo();
    }
    return 0;
}
