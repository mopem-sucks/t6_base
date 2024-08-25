add_library(WinReg INTERFACE)

target_include_directories(
  WinReg
  INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/WinReg"
)

find_package(Threads REQUIRED)

add_library(spdlog INTERFACE)

target_include_directories(
  spdlog
  INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include"
)

target_link_libraries(spdlog INTERFACE Threads::Threads)