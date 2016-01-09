/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#include <stdlib.h>
#include <string.h>

#include "eros_value.h"
#include "eros_defines.h"

char* eros_value_name(int type)
{
  switch (type) {
    case EROS_VALUE_MODULE:  return "Module";
  }

  return "Unknown";
}

void eros_value_delete(eros_value* value)
{
  switch (value->type) {
    case EROS_VALUE_MODULE:
      free(value->str);
      break;
  }

  free(value);
}

eros_value* eros_value_module(char* name)
{
  eros_value* module = malloc(sizeof(eros_value));
  module->type = EROS_VALUE_MODULE;
  module->str = malloc(strlen(name) + 1);
  strcpy(module->str, name);
  return module;
}
