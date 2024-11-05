#include <iostream>
#include <string>
using namespace std;

string reverse(string s, int start)
{
    int n = s.length();
    if (start >= n)
        return "";

    int end = start;
    while (end < n && s[end] != ' ')
        end++;

    string word = s.substr(start, end - start);

    string rest = reverse(s, end + 1);

    if (rest.empty())
        return word;
    else
        return rest + " " + word;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    string s;
    getline(cin, s);
    cout << reverse(s, 0) << endl;

    cerr << "Execution Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}