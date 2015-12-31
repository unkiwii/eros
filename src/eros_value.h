#ifndef EROS_VALUE_H
#define EROS_VALUE_H

#include "eros_fwd.h"

struct eros_value
{
  /* type of the value (number, string, expression, etc) */
  int type;
};

eros_value* eros_value_new(void);

void eros_value_delete(eros_value* value);

#endif // EROS_VALUE_H
