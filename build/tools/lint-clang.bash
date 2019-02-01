#!/bin/bash
`type -p clang-tidy{-8,-7,-6.0,} | head -n 1` `find "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition"/{lib,src} -type f -iname '*.cpp'` -p "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/build" "-header-filter=`echo '/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/src/(../include|../lib|../src)/.*' | sed 's/\\//\\\\\//g'`"
