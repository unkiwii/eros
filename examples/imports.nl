# empty lines at the begining of a file are illegal
# the first line must be a comment or an 'import'

# Good imports
#  file import
import aFile.nl
#  library import
import aLib.nlib

# you can put an empty line between imports (but just 1)
# here, we import files in subfolders ...
import foo/aFile.nl
import foo/bar/aLib.nlib

# ... and here, in parant folders
import ../aFile.nl
import ../../aLib.nlib
import ../foo/aFile.nl
import ../foo/bar/aLib.nlib

# Bad imports
import BadFileName.nl
import noExtension
import badExtension.X
import badExtension.nlX
import badExtension.nlibX


# more than 1 empty line is illegal
import file.nl
