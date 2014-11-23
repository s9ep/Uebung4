#ifndef TOOLS_H 
#define TOOLS_H
#include <stdlib.h>
#include <stdio.h>

#define ASSERT(cond) if(!(cond)) { fprintf(stderr, "failed!! [%s: %u]: \"%s\"", __FILE__, __LINE__, #cond); abort(); }

#endif
