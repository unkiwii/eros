# empty lines at the begining of a file are illegal
# the first line must be a comment, a 'use' or a statement
# but can't be any 'use' after a statement

# Good imports:

#  file use (uncompiled file, source code)
use aFile.nl

#  library use (compiled file, binary)
use aLib.nlib

# you can put an empty line between use clauses (but just 1)
# here, we use files in subfolders ...
use foo/aFile.nl
use foo/bar/aLib.nlib

# ... and here, in parant (or sibling) folders
use ../aFile.nl
use ../../aLib.nlib
use ../foo/aFile.nl
use ../foo/bar/aLib.nlib

# Bad imports (should not highlight the 'use' keyword):

# can't use a type name as a file name
use BadFileName.nl

# can't use underscores (_) or any other strange char
use under_score.nl
use minus-name.nl
use asterisk*in*names.nl

# can't use constants (ALL CAPS) names as file name
use ALLCAPS.nl
use ALL_CAPS_UNDERSCORE.nl

# there must be always an extension (to know if it's code or libray)
use noExtension

# there are only 2 possible extensions: nl and nlib
use badExtension.X
use badExtension.nlX
use badExtension.nlibX

# paths must be valid
use .../bad.nl
use ..////a.nl

# can't use '../' after a folder name
use a/../b.nl


# more than 1 empty line is illegal
use file.nl
