#pragma once
#ifndef T6_BASE_STEAMSTUB_CALLBACKS_H
#define T6_BASE_STEAMSTUB_CALLBACKS_H

#include "api.h"
#include "types.h"

// Based on:
// https://github.com/SteamRE/open-steamworks/blob/f65c043/Open%20Steamworks/CCallback.h

enum CallbackFlags : uint8_t {
  Uninitialized = 0,
  Registered = 1,
  GameServer = 2,
};

inline bool is_registered_flag_set(CallbackFlags flags) {
  return flags & CallbackFlags::Registered != 0;
}

inline bool is_gameserver_flag_set(CallbackFlags flags) {
  return flags & CallbackFlags::GameServer != 0;
}

class CCallbackBase {
public:
  CCallbackBase() : callback_flags{CallbackFlags::Uninitialized}, callback{0} {}

protected:
  CallbackFlags callback_flags;
  int callback;
};

template <typename T, typename P> class CCallResult : private CCallbackBase {
public:
  using FnPtr = T::*(P *, bool);

  CCallResult()
      : call_handle{STEAM_API_CALL_INVALID},
        callback_class{nullptr},
        callback_ptr{nullptr} {
    callback = P::Callback;
  }

  void Set(SteamAPICall call_handle, T *callback_class, FnPtr callback_ptr) {
    if (is_valid_call_handle(this->call_handle)) {
      SteamAPI_UnregisterCallResult(this, this->call_handle);
    }
    this->call_handle = call_handle;
    this->callback_class = callback_class;
    this->callback_ptr = callback_ptr;
    if (is_valid_call_handle(call_handle)) {
      SteamAPI_RegisterCallResult(this, this->call_handle);
    }
  }

  bool IsActive() const { return is_valid_call_handle(call_handle); }

  void Cancel() {
    if (is_valid_call_handle(call_handle)) {
      SteamAPI_UnregisterCallResult(this, call_handle);
      call_handle = STEAM_API_CALL_INVALID;
    }
  }

  ~CCallbackBase() { Cancel(); }

private:
  virtual void Run(void *param) {
    call_handle = STEAM_API_CALL_INVALID;
    (callback_class->*callback_ptr)(reinterpret_cast<P *>(param), false);
  }

  virtual void Run(void *param, bool io_failure, SteamAPICall call_handle) {
    if (call_handle == this->call_handle) {
      this->call_handle = nullptr;
      (callback_class->*callback_ptr)(reinterpret_cast<P *>(param), io_failure);
    }
  }

  int GetCallbackSizeBytes() { return sizeof(P); }

private:
  SteamAPICall call_handle;
  T *callback_class;
  FnPtr callback_ptr;
};

template <typename T, typename P, bool GAME_SERVER>
class CCallback : private CCallbackBase {
public:
  using FnPtr = T::*(P *);

  CCallback(T *callback_class, FnPtr callback_ptr)
      : callback_class{callback_class}, callback_ptr{callback_ptr} {
    if (callback_class != nullptr && callback_ptr != nullptr) {
      Register(callback_class, callback_ptr);
    }
  }

  ~CCallback() {
    if (is_registered_flag_set(callback_flags)) {
      Unregister();
    }
  }

  void Register(T *callback_class, FnPtr callback_ptr) {
    if (!callback_class || !callback_ptr) {
      return;
    }
    if (is_registered_flag_set(callback_flags)) {
      Unregister();
    }
    if constexpr (GAME_SERVER) {
      SetGameserverFlag();
    }
    this->callback_class = callback_class;
    this->callback_ptr = callback_ptr;
    SteamAPI_RegisterCallback(this, P::Callback);
  }

  void Unregister() { SteamAPI_UnregisterCallback(this); }

  void SetGameserverFlag() {
    callback_flags |= CCallbackBase::CallbackFlags::GameServer;
  }

private:
  virtual void Run(void *param) {
    (callback_class->*callback_ptr)(reinterpret_cast<P *>(param));
  }

  virtual void Run(void *param, bool _io_failure, SteamAPICall _call_handle) {
    (callback_class->*callback_ptr)(reinterpret_cast<P *>(param));
  }

  int GetCallbackSizeBytes() { return sizeof(P); }

private:
  T *callback_class;
  FnPtr callback_ptr;
};

#endif