add_executable(t6_base_launcher launcher.cpp)

target_link_libraries(
  t6_base_launcher
  PRIVATE
  WinReg
)