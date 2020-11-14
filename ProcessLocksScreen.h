#ifndef HEADER_ProcessLocksScreen
#define HEADER_ProcessLocksScreen
/*
htop - ProcessLocksScreen.h
(C) 2020 htop dev team
Released under the GNU GPLv2, see the COPYING file
in the source distribution for its full text.
*/

#include "InfoScreen.h"

#include <stdlib.h>


typedef struct ProcessLocksScreen_ {
   InfoScreen super;
   pid_t pid;
} ProcessLocksScreen;

typedef struct FileLocks_Data_ {
   char* data[4];
   int id;
   unsigned int dev[2];
   uint64_t inode;
   uint64_t start;
   uint64_t end;
} FileLocks_Data;

typedef struct FileLocks_LockData_ {
   FileLocks_Data data;
   struct FileLocks_LockData_* next;
} FileLocks_LockData;

typedef struct FileLocks_ProcessData_ {
   bool error;
   struct FileLocks_LockData_* locks;
} FileLocks_ProcessData;

extern const InfoScreenClass ProcessLocksScreen_class;

ProcessLocksScreen* ProcessLocksScreen_new(const Process* process);

void ProcessLocksScreen_delete(Object* this);

#endif
