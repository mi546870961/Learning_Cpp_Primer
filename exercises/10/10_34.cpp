#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v{1, 2, 3, 4, 5};
	for(auto it = v.crbegin(); it != v.crend(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}