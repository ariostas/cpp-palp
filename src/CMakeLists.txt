# Define list of headers and sources
set(HEADER_LIST
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/global.hpp"
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/lg.hpp"
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/mori.hpp"
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/nef.hpp"
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/rat.hpp"
  "${CPP-PALP_SOURCE_DIR}/include/cpp-palp/subpoly.hpp")
set(SOURCE_LIST
  class.cpp
  coord.cpp
  cws.cpp
  e_poly.cpp
  lg.cpp
  lgotwist.cpp
  mori.cpp
  moricone.cpp
  nef.cpp
  nefpart.cpp
  poly.cpp
  polynf.cpp
  rat.cpp
  singularinput.cpp
  subadd.cpp
  subdb.cpp
  subpoly.cpp
  vertex.cpp)

# We add them all to the library
add_library(cpp-palp_lib ${SOURCE_LIST} ${HEADER_LIST})

# Users of the library need the include directory too
target_include_directories(cpp-palp_lib PUBLIC ../include)

# Link the libraries it needs
target_link_libraries(cpp-palp_lib PRIVATE fmt::fmt)

# Needs at least C++17
target_compile_features(cpp-palp_lib PUBLIC cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header files"
  FILES ${HEADER_LIST}
)
