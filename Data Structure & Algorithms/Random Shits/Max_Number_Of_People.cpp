/*
A hotel has m rooms left, there are n people who want to stay in this hotel. You have to distribute the rooms so that as many people as possible will get a room to stay.
However, each person has a desired room size, he/she will accept the room if its size is close enough to the desired room size.
More specifically, if the maximum difference is k, and the desired room size is x, then he or she will accept a room if its size is between x - k and x + k
Determine the maximum number of people who will get a room to stay.

input:
vector<int> rooms: rooms[i] is the size of the ith room
vector<int> people: people[i] the desired room size of the ith person
int k: maximum allowed difference. If the desired room size is x, he or she will accept a room if its size is between x - k and x + k

output:
the maximum number of people who will get a room to stay.

Note: The iostream, vector and algorithm library are already included for you.

Constraints:
1 <= rooms.length, people.length <= 2 * 10^5
0 <= k <= 10^9
1 <= rooms[i], people[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool less_(int demand, int size, int diff) // i-th room's size is bigger
{
    return demand < size - diff;
}

bool more(int demand, int size, int diff) // i-th room's size is smaller
{
    return demand > size + diff;
}

bool ok(int demand, int size, int diff)
{
    return (!less_(demand, size,diff)) && (!more(demand, size, diff));
}

int maxNumberOfPeople(vector<int>& rs, vector<int>& pp, int k)
{
    sort(rs.begin(), rs.end());
    sort(pp.begin(), pp.end());
    
    int count = 0;
    for (int p = 0, r = 0; p < pp.size() && r < rs.size();)
    {
        if (ok(pp[p], rs[r], k))
        {
            count++;
            p++;
            r++;
        }
        else if (more(pp[p], rs[r], k))
            r++;
        else
            p++;
    }
    
    return count;
}

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t start = clock();
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for(int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for(int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';

    cerr << "Execution Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}