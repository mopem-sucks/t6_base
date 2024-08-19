#include "steam_api.h"

#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE instance_handle, DWORD reason, LPVOID _reserved) {
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    break;
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}