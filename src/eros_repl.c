/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include "prompt_win.h"
#else
#include <editline/readline.h>
#endif

#include "eros_context.h"
#include "eros_defines.h"
#include "eros_eval.h"
#include "eros_parser.h"
#include "eros_print.h"
#include "eros_repl.h"
#include "eros_repl_cmds.h"

#define PROGRAM_REPL_HELP "Type '.help' for more information"

int eros_repl(eros_input_t* input)
{
  //TODO: load input (files)
  UNUSEDP(input);

  eros_context_t* context = eros_context_new();

  //TODO: add builtins to context
  // eros_builtins(context);

  printf("\n%s repl %s (%s)\n%s\n\n", PROGRAM_NAME, PROGRAM_VERSION, COMPILE_DATE, PROGRAM_REPL_HELP);

  while (1) {
    char* line = readline("> ");
    add_history(line);

    if      (strcmp(line, ".help") == 0)     { CMD(help);    }
    else if (strcmp(line, ".exit") == 0)     { CMD(exit);    }
    else if (strcmp(line, ".license") == 0)  { CMD(license); }
    else {
      UNUSEDP(context);
      //eros_value_t* result = eros_parser_parse(context, line);
      //if (result) {
      //  eros_value_t* value = eros_eval(context, result);
      //  eros_println(value);
      //  eros_value_delete(value);
      //}
    }

    free(line);
  }

  return 0;
}
