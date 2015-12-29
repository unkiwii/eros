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

#include "nlprogram.h"
#include "nlrepl.h"
#include "nlrepl_cmd.h"

#define PROGRAM_REPL_HELP "Type '.help' for more information"

int nl_repl(nlinput* input)
{
  printf("\n%s repl %s (%s)\n%s\n\n", PROGRAM_NAME, PROGRAM_VERSION, COMPILE_DATE, PROGRAM_REPL_HELP);

  while (1) {
    char* line = readline("> ");
    add_history(line);

    if      (strcmp(line, ".help") == 0)      { cmd_help();       }
    else if (strcmp(line, ".quit") == 0)      { cmd_quit();       }
    else if (strcmp(line, ".license") == 0)   { cmd_license();    }
    else {
      // eval
      // print
    }

    free(line);
  }

  return 0;
}
