#include <iostream>

using namespace std;

class numbered
{
public:
	numbered() { mysn = seq++; }
	numbered(const numbered &) { mysn = seq++; }
	int mysn;
private:
	static int seq;
};

int numbered::seq = 0;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}