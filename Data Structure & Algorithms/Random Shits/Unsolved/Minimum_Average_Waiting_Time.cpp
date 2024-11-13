/*
Tieu owns a pizza restaurant and he manages it in his own way. While in a normal restaurant, a customer is served by following the first-come, first-served rule, Tieu simply minimizes the average waiting time of his customers. So he gets to decide who is served first, regardless of how sooner or later a person comes.

Different kinds of pizzas take different amounts of time to cook. Also, once he starts cooking a pizza, he cannot cook another pizza until the first pizza is completely cooked. Let's say we have three customers who come at time t=0, t=1, & t=2 respectively, and the time needed to cook their pizzas is 3, 9, & 6 respectively. If Tieu applies first-come, first-served rule, then the waiting time of three customers is 3, 11, & 16 respectively. The average waiting time in this case is (3 + 11 + 16) / 3 = 10. This is not an optimized solution. After serving the first customer at time t=3, Tieu can choose to serve the third customer. In that case, the waiting time will be 3, 7, & 17 respectively. Hence the average waiting time is (3 + 7 + 17) / 3 = 9.

Help Tieu achieve the minimum average waiting time. For the sake of simplicity, just find the integer part of the minimum average waiting time.

Input Format

The first line contains an integer N, which is the number of customers.
In the next N lines, the ith line contains two space separated numbers Ti and Li. Ti is the time when ith customer order a pizza, and Li is the time required to cook that pizza.

The  customer is not the customer arriving at the  arrival time.

Output Format

Display the integer part of the minimum average waiting time.
Constraints

1 ≤ N ≤ 105
0 ≤ Ti ≤ 109
1 ≤ Li ≤ 109
Note

The waiting time is calculated as the difference between the time a customer orders pizza (the time at which they enter the shop) and the time she is served.

Cook does not know about the future orders.
*/
#include </Users/macbook/C++/Contests/set_up.h>

#define order second
#define cook first

void solve(int test_case)
{
    int n;
    cin >> n;
    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; i++)
        cin >> customers[i].order >> customers[i].cook;

    sort(all(customers));

    long long time = 0, wait = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (time < customers[i].order)
            time = customers[i].order;
        time += customers[i].cook;
        wait += time - customers[i].order;
    }

    cout << "Case #" << test_case << ": " << wait / n << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    int test_cases;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve(test_case);

    return 0;
}