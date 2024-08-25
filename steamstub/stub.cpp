#include <spdlog/spdlog.h>

#include "api.h"

bool SteamAPI_Init() {
  spdlog::debug("SteamAPI_Init");
  return true;
}

void SteamAPI_RegisterCallResult(CCallbackBase *callback,
                                 SteamAPICall api_call_handle) {
  spdlog::debug("SteamAPI_RegisterCallResult");
}

void SteamAPI_RegisterCallback(CCallbackBase *callback, int callback_id) {
  spdlog::debug("SteamAPI_RegisterCallback");
}

bool SteamAPI_RestartAppIfNecessary(uint32_t self_app_id) {
  spdlog::debug("SteamAPI_RestartAppIfNecessary");
  return false;
}

void SteamAPI_RunCallbacks() { spdlog::debug("SteamAPI_RunCallbacks"); }

void SteamAPI_Shutdown() { spdlog::debug("SteamAPI_Shutdown"); }

void SteamAPI_UnregisterCallResult(CCallbackBase *callback,
                                   SteamAPICall api_call_handle) {
  spdlog::debug("SteamAPI_UnregisterCallResult");
}

void SteamAPI_UnregisterCallback(CCallbackBase *callback) {
  spdlog::debug("SteamAPI_UnregisterCallback");
}

ISteamApps005 *SteamApps() {
  spdlog::debug("SteamApps");
  return nullptr;
}

ISteamFriends013 *SteamFriends() {
  spdlog::debug("SteamFriends");
  return nullptr;
}

ISteamGameServer011 *SteamGameServer() {
  spdlog::debug("SteamGameServer");
  return nullptr;
}

bool SteamGameServer_Init(uint32_t ip, uint16_t port, uint16_t game_port,
                          uint16_t spectator_port, uint16_t query_port,
                          SteamServerMode server_mode, const char *game_dir,
                          const char *version_str) {
  spdlog::debug("SteamGameServer_Init");
  return true;
}

void SteamGameServer_RunCallbacks() {
  spdlog::debug("SteamGameServer_RunCallbacks");
}

void SteamGameServer_Shutdown() { spdlog::debug("SteamGameServer_Shutdown"); }

ISteamNetworking005 *SteamNetworking() {
  spdlog::debug("SteamNetworking");
  return nullptr;
}

ISteamUser016 *SteamUser() {
  spdlog::debug("SteamUser");
  return nullptr;
}

ISteamUserStats011 *SteamUserStats() {
  spdlog::debug("SteamUserStats");
  return nullptr;
}

ISteamUtils005 *SteamUtils() {
  spdlog::debug("SteamUtils");
  return nullptr;
}