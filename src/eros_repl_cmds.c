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

#include "eros_defines.h"
#include "eros_repl_cmds.h"

void CMD(help)()
{
  puts("\n\
repl commands:\n\
\n\
  .help       shows this message\n\
  .exit       exits from repl\n\
  .license    shows license\n\
");
}

void CMD(exit)(eros_context_t* context)
{
  context->is_alive = 0;
  eros_context_seterror(context, NULL);
}

void CMD(license)()
{
  printf("\n\
       DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE\n\
                   Version 2, December 2004\n\
\n\
Copyright (C) %s %s <%s>\n\
\n\
Everyone is permitted to copy and distribute verbatim or modified\n\
copies of this license document, and changing it is allowed as long\n\
as the name is changed.\n\
\n\
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE\n\
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION\n\
\n\
0. You just DO WHAT THE FUCK YOU WANT TO.\n\
\n", COMPILE_YEAR, PROGRAM_AUTHOR, PROGRAM_AUTHOR_EMAIL);
}
