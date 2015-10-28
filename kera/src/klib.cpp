#include <kera.h>

void kprintf( string str )
{
	cout << str;
	return;
}

void exit_with_error( string str )
{
	kprintf(str);
	kprintf("\n");
	exit(1);
}

void kconsole( string str )
{
	kprintf(str);
	kprintf("\n");
}
