/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#ifndef EROS_VALUE_H
#define EROS_VALUE_H

#include "eros_fwd.h"

/** types of values in the language **/
enum {
  EROS_VALUE_MODULE
};

char* eros_value_name(int type);

struct eros_value
{
  /* type of the value (number, string, type, etc) */
  int type;

  //TODO: put all 'values' inside an union
  char* str;
};

void eros_value_delete(eros_value* value);

eros_value* eros_value_module(char* name);

#endif // EROS_VALUE_H
