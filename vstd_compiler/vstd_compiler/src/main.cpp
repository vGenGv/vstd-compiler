#include <iostream>
using namespace std;

#include <vmap.h>

int main(int argc, char *argv[])
{
	cout << "Hello, world!" << endl;

	vstd::VMapEdge<int, int> edge1, edge2(12);
	edge1 = edge2;
	cout << edge1.data() << endl;

	cin.get();
	return 0;
}
