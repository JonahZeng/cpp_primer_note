#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec(10,5);
	for(vector<int>::iterator iter = vec.begin(); iter!=vec.end(); iter++)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
