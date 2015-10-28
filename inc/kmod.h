#ifndef KMOD_H
#define KMOD_H

void register_module();
int send(char *, void *);
void *recv();

#endif
