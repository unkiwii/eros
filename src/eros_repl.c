#ifdef _WIN32
#include "prompt_win.h"
#else
#include <editline/readline.h>
#endif

#include "eros_ast_node.h"
#include "eros_context.h"
#include "eros_defines.h"
#include "eros_error.h"
#include "eros_eval.h"
#include "eros_logger.h"
#include "eros_parser.h"
#include "eros_print.h"
#include "eros_repl.h"
#include "eros_repl_cmds.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_REPL_HELP "Type '.help' for more information"

status_code_t eros_repl_stop(eros_context_t* context)
{
  status_code_t status = 0;
  if (context->error) {
    LOGE("FATAL: %s", context->error);
    status = EROS_ERR_CONTEXT;
  }

  eros_context_delete(context);
  return status;
}

status_code_t eros_repl(eros_input_t* input)
{
  //TODO: load input (files)

  eros_context_t* context = eros_context_new();

  //TODO: add builtins to context
  // eros_builtins(context);

  printf("\n%s repl %s (%s)\n%s\n\n", PROGRAM_NAME, PROGRAM_VERSION, COMPILE_DATE, PROGRAM_REPL_HELP);

  while (context->is_alive) {
    char* line = readline("> ");

    /* do not add empty lines to history */
    if (line && *line) {
      add_history(line);
    }

    if      (strcmp(line, ".help") == 0)     { CMD(help)();         }
    else if (strcmp(line, ".exit") == 0)     { CMD(exit)(context);  }
    else if (strcmp(line, ".license") == 0)  { CMD(license)();      }
    else {
      LOGD("evaluating '%s'", line);
      eros_parser_parse(context, line);
      eros_ast_node_t* result = eros_context_getparser(context)->result;
      if (result) {
        eros_ast_node_delete(result);
      /*   eros_value_t* value = eros_eval(context, result); */
      /*   eros_println(value); */
      /*   eros_value_delete(value); */
      }
    }

    free(line);
  }

  clear_history();

  return eros_repl_stop(context);
}

/*
Copyright (c) 2014-2017 Lucas Gabriel Sánchez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
