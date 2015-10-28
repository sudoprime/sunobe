#include <kera.h>
#include <dlfcn.h>
#include <thread>

typedef void(*func_t)();

struct module {
	std::thread::id id;
	string name;
	func_t init;
	func_t fini;
};

std::list<struct module *> modules;
std::mutex mod_mut;

void register_module()
{
	modules.back()->id = std::this_thread::get_id();
	mod_mut.unlock();
}

string mod_id()
{
	std::thread::id id = std::this_thread::get_id();

	std::list<struct module *>::iterator i = modules.begin(); 
	while( i != modules.end() ) {
		if( id == (*i)->id ) {
			return (*i)->name;
		}
		++i;
	}
	return NULL;
}

int kmodprobe( string file )
{
	void *handle;
	char *error;

	handle = dlopen( file.c_str(), RTLD_NOW);
	if((error = dlerror()) != NULL) {
		kconsole(error);
		return 1;
	}
	
	func_t init = (func_t)dlsym(handle, "init");
	if((error = dlerror()) != NULL) {
		kconsole(error);
		return 1;
	}
	func_t fini = (func_t)dlsym(handle, "fini");
	if((error = dlerror()) != NULL) {
		kconsole(error);
		return 1;
	}

	struct module *mod = new struct module;
	mod->name = file;
	mod->fini = fini;
	mod->init = init;

	modules.push_back(mod);

	mod_mut.lock();
	std::thread t = std::thread(init);
	t.detach();
	mod_mut.lock(); // hacky way to get thread_id from child. be carefull. 
	mod_mut.unlock();

	return 0;
}
