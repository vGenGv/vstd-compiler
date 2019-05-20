#include <iostream>
using namespace std;

#include <vmap.h>

int main(int argc, char *argv[])
{
	cout << "Test begin!" << endl << endl;

	vstd::VMapEdge<int, int> edge1, edge2(12);
	edge1 = edge2;
	vstd::VMapVertex<int, int> ver1(1), ver2;
	ver1.addEdge(&edge1);
	ver2 = ver1;
	cout << ver2.data() << endl;
	cout << (ver2.hasEdge(&edge2)) << endl;

	cout << endl << "Test over! Press any key to continue..." << endl;
	cin.get();
	return 0;
}
