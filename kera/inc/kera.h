#ifndef KERA_H
#define KERA_H

#include <iostream>
using namespace std;
#include <cmath>
#include <list>
#include <mutex>

#include <stdlib.h>

// These functions will be accessible to modules
extern "C" {

	void kprintf( string );
	int kmodprobe( string );

	void init_mod();
	void exit_with_error( string );
	void kconsole( string );

	string mod_id();
	void register_module();

	int send( char *, void *);
	void *recv();
	void *recv_wait();

}

#endif
