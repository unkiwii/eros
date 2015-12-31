#ifndef EROS_CONTEXT_H
#define EROS_CONTEXT_H

#include "eros_fwd.h"

struct eros_context
{
  eros_parser* parser;
};

eros_context* eros_context_new(void);

void eros_context_delete(eros_context* context);

#endif // EROS_CONTEXT_H
