#include <stdint.h>

#include <spdlog/spdlog.h>

#ifdef _WIN32
#define T6_BASE_STEAM_API extern "C" __declspec(dllexport)
#else
#define T6_BASE_STEAM_API
#endif

enum SteamServerMode {
  STEAM_SERVER_MODE_INVALID,
  STEAM_SERVER_MODE_NO_AUTH,
  STEAM_SERVER_MODE_AUTH_ONLY,
  STEAM_SERVER_MODE_AUTH_SECURE,
};

using SteamAPICall = uint64_t;

constexpr SteamAPICall STEAM_API_CALL_INVALID = 0;

class ISteamApps005;

class ISteamFriends013;

class ISteamGameServer011;

class ISteamNetworking005;

class ISteamUser016;

class ISteamUserStats011;

class ISteamUtils005;

class CallbackBase;

T6_BASE_STEAM_API bool SteamAPI_Init() {
  spdlog::get("t6_base")->debug("SteamAPI_Init");
  spdlog::get("t6_base")->flush();
  return true;
}

T6_BASE_STEAM_API void
SteamAPI_RegisterCallResult(CallbackBase *callback,
                            SteamAPICall api_call_handle) {
  spdlog::get("t6_base")->debug("SteamAPI_RegisterCallResult");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API void SteamAPI_RegisterCallback(CallbackBase *callback,
                                                 int callback_id) {
  spdlog::get("t6_base")->debug("SteamAPI_RegisterCallback");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API bool SteamAPI_RestartAppIfNecessary(uint32_t self_app_id) {
  spdlog::get("t6_base")->debug("SteamAPI_RestartAppIfNecessary");
  spdlog::get("t6_base")->flush();
  return false;
}

T6_BASE_STEAM_API void SteamAPI_RunCallbacks() {
  spdlog::get("t6_base")->debug("SteamAPI_RunCallbacks");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API void SteamAPI_Shutdown() {
  spdlog::get("t6_base")->debug("SteamAPI_Shutdown");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API void
SteamAPI_UnregisterCallResult(CallbackBase *callback,
                              SteamAPICall api_call_handle) {
  spdlog::get("t6_base")->debug("SteamAPI_UnregisterCallResult");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API void SteamAPI_UnregisterCallback(CallbackBase *callback) {
  spdlog::get("t6_base")->debug("SteamAPI_UnregisterCallback");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API ISteamApps005 *SteamApps() {
  spdlog::get("t6_base")->debug("SteamApps");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API ISteamFriends013 *SteamFriends() {
  spdlog::get("t6_base")->debug("SteamFriends");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API ISteamGameServer011 *SteamGameServer() {
  spdlog::get("t6_base")->debug("SteamGameServer");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API bool
SteamGameServer_Init(uint32_t ip, uint16_t port, uint16_t game_port,
                     uint16_t spectator_port, uint16_t query_port,
                     SteamServerMode server_mode, const char *game_dir,
                     const char *version_str) {
  spdlog::get("t6_base")->debug("SteamGameServer_Init");
  spdlog::get("t6_base")->flush();
  return true;
}

T6_BASE_STEAM_API void SteamGameServer_RunCallbacks() {
  spdlog::get("t6_base")->debug("SteamGameServer_RunCallbacks");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API void SteamGameServer_Shutdown() {
  spdlog::get("t6_base")->debug("SteamGameServer_Shutdown");
  spdlog::get("t6_base")->flush();
}

T6_BASE_STEAM_API ISteamNetworking005 *SteamNetworking() {
  spdlog::get("t6_base")->debug("SteamNetworking");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API ISteamUser016 *SteamUser() {
  spdlog::get("t6_base")->debug("SteamUser");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API ISteamUserStats011 *SteamUserStats() {
  spdlog::get("t6_base")->debug("SteamUserStats");
  spdlog::get("t6_base")->flush();
  return nullptr;
}

T6_BASE_STEAM_API ISteamUtils005 *SteamUtils() {
  spdlog::get("t6_base")->debug("SteamUtils");
  spdlog::get("t6_base")->flush();
  return nullptr;
}