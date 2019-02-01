#!/bin/bash
`type -p clang-format{-8,-7,-6.0,} | head -n 1` -i `find "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition"/{src,lib} -type f -iname '*.cpp' -or -iname '*.h'`
