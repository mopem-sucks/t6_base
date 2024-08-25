#include <codecvt>
#include <format>
#include <iostream>
#include <locale>
#include <string>

#include <WinReg/WinReg.hpp>

class SteamRegistry {
  static constexpr const char *STEAM_REG_KEY_PATH =
      "SOFTWARE\\WOW6432Node\\Valve\\Steam";
  static constexpr const char *STEAM_INSTALL_PATH_KEY = "InstallPath";

public:
  SteamRegistry()
      : steam_reg_key{HKEY_LOCAL_MACHINE,
                      converter.from_bytes(STEAM_REG_KEY_PATH)} {}

  std::string get_steam_install_path() {
    const auto steam_install_path_key =
        converter.from_bytes(STEAM_INSTALL_PATH_KEY);
    return converter.to_bytes(
        steam_reg_key.GetStringValue(steam_install_path_key));
  }

private:
  winreg::RegKey steam_reg_key;
  using wstr_utf8_convert = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<wstr_utf8_convert, wchar_t> converter;
};

int main(int argc, char *argv) {
  const auto steam_install_path = SteamRegistry().get_steam_install_path();
  std::cout << steam_install_path << "\n";
  return 0;
}