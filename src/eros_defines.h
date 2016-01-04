/*     DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2016 Lucas Gabriel Sanchez <unkiwii@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.   */

#ifndef EROS_DEFINES_H
#define EROS_DEFINES_H

#define UNUSED(arg) (void*)arg

#ifndef PROGRAM_NAME
  #define PROGRAM_NAME "eros"
#endif

#ifndef PROGRAM_VERSION
  #define PROGRAM_VERSION "0.0.1"
#endif

#ifndef PROGRAM_AUTHOR
  #define PROGRAM_AUTHOR "Lucas Gabriel Sanchez"
#endif

#ifndef PROGRAM_AUTHOR_EMAIL
  #define PROGRAM_AUTHOR_EMAIL "unkiwii@gmail.com"
#endif

#ifndef COMPILE_YEAR
  #define COMPILE_YEAR "2016"
#endif

#ifndef COMPILE_MONTH
  #define COMPILE_MONTH "Dec"
#endif

#ifndef COMPILE_DAY
  #define COMPILE_DAY "31"
#endif

#ifndef COMPILE_DATE
  #define COMPILE_DATE COMPILE_MONTH " " COMPILE_DAY ", " COMPILE_YEAR
#endif

#endif // EROS_DEFINES_H
