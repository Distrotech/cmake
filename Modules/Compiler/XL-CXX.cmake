include(Compiler/XL)
__compiler_xl(CXX)
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT "${CMAKE_CXX_FLAGS_MINSIZEREL_INIT} -DNDEBUG")

# -qthreaded     = Ensures that all optimizations will be thread-safe
# -qhalt=e       = Halt on error messages (rather than just severe errors)
set(CMAKE_CXX_FLAGS_INIT "-qthreaded -qhalt=e")

set(CMAKE_CXX_COMPILE_OBJECT
  "<CMAKE_CXX_COMPILER> -+ <DEFINES> <FLAGS> -o <OBJECT> -c <SOURCE>")

set(CMAKE_CXX11_COMPILER_FEATURES)

include("${CMAKE_ROOT}/Modules/Compiler/CxxFeatureTesting.cmake")

if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.1)
   set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "-qlanglvl=extended0x")
   record_cxx_compiler_features("-qlanglvl=extended0x" CMAKE_CXX11_COMPILER_FEATURES)
endif()


set(CMAKE_CXX_COMPILER_FEATURES
  ${CMAKE_CXX11_COMPILER_FEATURES}
)
