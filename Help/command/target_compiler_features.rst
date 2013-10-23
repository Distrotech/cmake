target_compiler_features
------------------------

Add expected compiler features to a target.

::

  target_compiler_features(<target> <PRIVATE|PUBLIC|INTERFACE> <feature> [...])

Specify compiler features required when compiling a given target.  If the
feature is not listed in the :variable:`CMAKE_CXX_COMPILER_FEATURES` variable,
then an error will be reported by CMake.  If the use of the feature requires
an additional compiler flag, such as --std=c++11, the flag will be added
automatically.

The INTERFACE, PUBLIC and PRIVATE keywords are required to specify the
scope of the features.  PRIVATE and PUBLIC items will
populate the :prop_tgt:`COMPILER_FEATURES` property of <target>.  PUBLIC and
INTERFACE items will populate the :prop_tgt:`INTERFACE_COMPILER_FEATURES` property
of <target>.  Repeated calls for the same <target> append items in the order called.

The named <target> must have been created by a command such as
add_executable or add_library and must not be an IMPORTED target.

Arguments to target_compiler_features may use "generator expressions"
with the syntax "$<...>".
See the :manual:`cmake-generator-expressions(7)` manual for available
expressions.
