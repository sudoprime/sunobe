#include <kera.h>

int main()
{
	kmodprobe("./bin/test.so");

	cout << "Press enter to exit..." << endl;
	cin.get();
	return 0;
}
