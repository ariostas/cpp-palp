set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(
  docs
  cpp-palp/global.hpp
  cpp-palp/lg.hpp
  cpp-palp/mori.hpp
  cpp-palp/nef.hpp
  cpp-palp/rat.hpp
  cpp-palp/subpoly.hpp
  "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
  WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
