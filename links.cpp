#include "links.hpp"

void ToMorritowLink::Discord(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}