#include <Windows.h>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

BOOL WINAPI DllMain(HINSTANCE instance_handle, DWORD reason, LPVOID _reserved) {
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    try {
      auto logger = spdlog::basic_logger_mt("t6_base", "t6_base.log");
      spdlog::set_level(spdlog::level::debug);
      logger->debug("DllMain_Process_Attach");
    } catch (const std::exception &e) {
      MessageBoxA(nullptr, "ERROR", "Failed to allocate T6Base logger", MB_OK);
      _Exit(1);
    }
    break;
  case DLL_PROCESS_DETACH:
    spdlog::drop_all();
    break;
  }
  return TRUE;
}