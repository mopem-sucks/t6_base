add_library(
  T6BaseSteamStub
  SHARED
  entry.cpp
  stub.cpp
)

set_target_properties(
  T6BaseSteamStub
  PROPERTIES
  OUTPUT_NAME steam_api
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)