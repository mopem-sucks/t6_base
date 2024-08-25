#pragma once
#ifndef T6_BASE_STEAMSTUB_API_H
#define T6_BASE_STEAMSTUB_API_H

#include "types.h"

#ifdef _WIN32
#define T6_BASE_STEAM_API extern "C" __declspec(dllexport)
#else
#define T6_BASE_STEAM_API
#endif

// Based on:
// https://github.com/SteamRE/open-steamworks/blob/f65c043/Open%20Steamworks/Steamclient.h

T6_BASE_STEAM_API bool SteamAPI_Init();

T6_BASE_STEAM_API void
SteamAPI_RegisterCallResult(CCallbackBase *callback,
                            SteamAPICall api_call_handle);

T6_BASE_STEAM_API void SteamAPI_RegisterCallback(CCallbackBase *callback,
                                                 int callback_id);

T6_BASE_STEAM_API bool SteamAPI_RestartAppIfNecessary(uint32_t self_app_id);

T6_BASE_STEAM_API void SteamAPI_RunCallbacks();

T6_BASE_STEAM_API void SteamAPI_Shutdown();

T6_BASE_STEAM_API void
SteamAPI_UnregisterCallResult(CCallbackBase *callback,
                              SteamAPICall api_call_handle);

T6_BASE_STEAM_API void SteamAPI_UnregisterCallback(CCallbackBase *callback);

T6_BASE_STEAM_API ISteamApps005 *SteamApps();

T6_BASE_STEAM_API ISteamFriends013 *SteamFriends();

T6_BASE_STEAM_API ISteamGameServer011 *SteamGameServer();

T6_BASE_STEAM_API bool
SteamGameServer_Init(uint32_t ip, uint16_t port, uint16_t game_port,
                     uint16_t spectator_port, uint16_t query_port,
                     SteamServerMode server_mode, const char *game_dir,
                     const char *version_str);

T6_BASE_STEAM_API void SteamGameServer_RunCallbacks();

T6_BASE_STEAM_API void SteamGameServer_Shutdown();

T6_BASE_STEAM_API ISteamNetworking005 *SteamNetworking();

T6_BASE_STEAM_API ISteamUser016 *SteamUser();

T6_BASE_STEAM_API ISteamUserStats011 *SteamUserStats();

T6_BASE_STEAM_API ISteamUtils005 *SteamUtils();

#endif