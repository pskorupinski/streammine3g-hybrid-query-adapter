FILE(REMOVE_RECURSE
  "CMakeFiles/GenerateEvents"
  "../Event.pb.cpp"
  "../Event.pb.c1"
  "../Event.pb.cc"
  "../Event.pb.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/GenerateEvents.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
