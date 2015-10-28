#include <stdio.h>
#include <kmod.h>

void init() {
	register_module();
	send("./bin/test.so", (void *)1);
	void *ret = recv();
	if(ret)
		fprintf(stderr, "got recv\n");

	return;
}

void fini() {
	return;
}
