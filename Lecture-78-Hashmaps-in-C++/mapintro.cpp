#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("sanket", 3);
    m.insert(p);

    // 2
    pair<string, int> q("Mondal", 2);
    m.insert(q);

    // 3
    m["mera"] = 1;

    // what will happen
    m["mera"] = 2;

    cout << m["mera"] << endl;
    cout << m.at("sanket") << endl;

    cout << m["unknownkey"] << endl;
    cout << m.at("unknownkey") << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("mera") << endl;

    // erase
    m.erase("Mondal");
    cout << m.size() << endl;

    // iterator
    map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}