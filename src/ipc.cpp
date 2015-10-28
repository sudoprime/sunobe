#include <kera.h>

struct msg {
	void *data;
	string from;
	string to;
};

std::list<struct msg *> po_box;
std::mutex po_mut;

/* send() - sends a void pointer to "to" */
int send( char *to, void *data )
{
	if(!to)
		return 1;

	struct msg *msg = new struct msg;
	msg->data = data;
	msg->from = mod_id();
	msg->to.assign(to);

	po_mut.lock();
	po_box.push_back(msg);
	po_mut.unlock();

	return 0;
}

/* recv() - non-blocking receive */
void *recv()
{
	po_mut.lock();
	std::list<struct msg *>::iterator i = po_box.begin();
	while( i != po_box.end() ) {
		if( (*i)->to == mod_id() ) {
			void *ret = (*i)->data;
			po_box.erase(i);
			po_mut.unlock();
			return ret;
		}
		++i;
	}
	po_mut.unlock();
	return NULL;
}

/* recv_wait() - blocking receive */
void *recv_wait()
{
	kconsole("recv_wait() called.");
	return NULL;
}
