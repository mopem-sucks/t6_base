#include <format>

#include <Windows.h>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

// TODO(mopem): Move to separate tracing module.
void t6_base_init_logger(spdlog::level::level_enum level) {
  try {
    auto logger = spdlog::basic_logger_mt("t6_base", "t6_base.log");
    logger->set_level(level);
    // TODO(mopem): Remove this once game doesn't crash!
    logger->flush_on(level);
    spdlog::set_default_logger(logger);
  } catch (const spdlog::spdlog_ex &ex) {
    const auto message =
        std::format("Failed to allocate T6Base logger: {}", ex.what());
    MessageBoxA(nullptr, "ERROR", message.c_str(), MB_OK);
    exit(EXIT_FAILURE);
  }
}

void t6_base_logger_uninit() { spdlog::drop_all(); }

BOOL WINAPI DllMain(HINSTANCE instance_handle, DWORD reason, LPVOID _reserved) {
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    t6_base_init_logger(spdlog::level::debug);
    spdlog::debug("DllMain_Process_Attach");
    break;
  case DLL_PROCESS_DETACH:
    spdlog::debug("DllMain_Process_Detach");
    t6_base_logger_uninit();
    break;
  }
  return TRUE;
}