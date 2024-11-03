#include <bits/stdc++.h>
using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog()
    {
        logList.push_back(0);
        currentState = logList.begin();
    }
    DataLog(const int &data)
    {
        logList.push_back(data);
        currentState = logList.begin();
    }

    void addCurrentState(int number)
    {
        *currentState += number;
    }
    void subtractCurrentState(int number)
    {
        *currentState -= number;
    }
    void save()
    {
        auto it = currentState;
        ++it;
        logList.erase(it, logList.end());

        logList.push_back(*currentState);
        currentState = --logList.end();
    }
    void undo()
    {
        if (currentState != logList.begin())
            --currentState;
    }
    void redo()
    {
        auto it = currentState;
        ++it;
        if (it != logList.end())
            ++currentState;
    }

    int getCurrentStateData()
    {
        return *currentState;
    }

    void printLog()
    {
        for (auto i = logList.begin(); i != logList.end(); i++)
        {
            if (i == currentState)
                cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

void sample_1()
{
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.undo();
    log.printLog();
}

void sample_2()
{
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.subtractCurrentState(5);
    log.printLog();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();

    sample_1();
    cout << endl;
    sample_2();

    cerr << "\nExecuted time: " << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}