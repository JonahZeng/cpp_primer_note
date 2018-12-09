#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main(void)
{
    pair<string, int> p;
    vector< pair<string, int> > container;
    cout<<"input first:";
    while(cin>>p.first>>p.second)
    {
        container.push_back(p);
        cout<<"input next:";
    }

    vector< pair<string, int> >::iterator it = container.begin();
    for(;it != container.end(); it++)
    {
        cout<<it->first<<":"<<it->second<<endl;
    }
    return 0;
}