#pragma once
#ifndef T6_BASE_STEAMSTUB_TYPES_H
#define T6_BASE_STEAMSTUB_TYPES_H

#include <cstdint>

enum SteamServerMode {
  STEAM_SERVER_MODE_INVALID,
  STEAM_SERVER_MODE_NO_AUTH,
  STEAM_SERVER_MODE_AUTH_ONLY,
  STEAM_SERVER_MODE_AUTH_SECURE,
};

class ISteamApps005;

class ISteamFriends013;

class ISteamGameServer011;

class ISteamNetworking005;

class ISteamUser016;

class ISteamUserStats011;

class ISteamUtils005;

class CCallbackBase;

using SteamAPICall = uint64_t;

constexpr SteamAPICall STEAM_API_CALL_INVALID = 0;

constexpr bool is_valid_call_handle(SteamAPICall call_handle) {
  return call_handle != STEAM_API_CALL_INVALID;
}

#endif