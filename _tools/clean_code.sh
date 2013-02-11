#!/bin/bash

##
# Title:          Useful Unix functions
# Description:    For this script to work correctly, you should use it when you're at the root of the project with the terminal (eg: you@you:/path/to/root-project$ bash _tools/clean_code.sh)
#
# Author:         Pierre-Henry Soria <pierrehs@hotmail.com>
# Copyright      (c) 2012, Pierre-Henry Soria. All Rights Reserved.
##


# Deleting temporary files
find . -type f \( -name "*~" -or -name "*.swp" -or -name ".directory" -or -name "._*" -or -name ".DS_Store*" -or -name "Thumbs.db" \) -exec rm {} \;

# Cleaning the code
find . -type f \( -name "*.c" -or -name "*.cpp" -or -name "*.h" -or -name "*.hpp" -or -name "*.xml" -or -name "*.xsl" -or -name "*.sh" -or -name "*.phs" \) | xargs perl -wi -pe 's/\s+$/\n/'
find . -type f \( -name "*.c" -or -name "*.cpp" -or -name "*.h" -or -name "*.hpp" -or -name "*.xml" -or -name "*.xsl" -or -name "*.sh" -or -name "*.phs" \) | xargs perl -wi -pe 's/\t/    /g'
