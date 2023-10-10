add_executable(poly.x poly.cpp)
target_compile_features(poly.x PRIVATE cxx_std_17)
target_link_libraries(poly.x PRIVATE cpp-palp_lib)

add_executable(class.x class.cpp)
target_compile_features(class.x PRIVATE cxx_std_17)
target_link_libraries(class.x PRIVATE cpp-palp_lib)

add_executable(cws.x cws.cpp)
target_compile_features(cws.x PRIVATE cxx_std_17)
target_link_libraries(cws.x PRIVATE cpp-palp_lib)

add_executable(nef.x nef.cpp)
target_compile_features(nef.x PRIVATE cxx_std_17)
target_link_libraries(nef.x PRIVATE cpp-palp_lib)

add_executable(mori.x mori.cpp)
target_compile_features(mori.x PRIVATE cxx_std_17)
target_link_libraries(mori.x PRIVATE cpp-palp_lib)
