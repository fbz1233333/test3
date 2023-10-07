#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <filesystem>
#include <queue>
#include <deque>

namespace fs = std::filesystem;

#define COLOR_NONE "\033[m"
#define COLOR_RED "\033[0;32;31m"
#define COLOR_LIGHT_RED "\033[1;31m"
#define COLOR_GREEN "\033[0;32;32m"
#define COLOR_LIGHT_GREEN "\033[1;32m"
#define COLOR_BLUE "\033[0;32;34m"
#define COLOR_LIGHT_BLUE "\033[1;34m"
#define COLOR_DARY_GRAY "\033[1;30m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_LIGHT_CYAN "\033[1;36m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_LIGHT_PURPLE "\033[1;35m"
#define COLOR_BROWN "\033[0;33m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_LIGHT_GRAY "\033[0;37m"
#define COLOR_WHITE "\033[1;37m"

#ifdef _WIN32
#include <Windows.h>

#define LOGI(fmt, ...) std::printf(COLOR_NONE "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "info", ##__VA_ARGS__)
#define LOGE(fmt, ...) std::printf(COLOR_RED "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "error", ##__VA_ARGS__)
#define LOGD(fmt, ...) std::printf(COLOR_GREEN "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "debug", ##__VA_ARGS__)
#define LOGW(fmt, ...) std::printf(COLOR_YELLOW "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "warning", ##__VA_ARGS__)
#endif

#ifdef __linux__
#include <unistd.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ipc.h>
#include <sys/acct.h>
#include <sys/auxv.h>

#ifdef __ANDROID__
#include <android/log.h>
#include <android_native_app_glue.h>
#include <android/asset_manager.h>

#define LOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "info", fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "error", fmt, ##__VA_ARGS__)
#define LOGD(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "debug", fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "warning", fmt, ##__VA_ARGS__)

#else
#define LOGI(fmt, ...) printf(COLOR_NONE "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "info", ##__VA_ARGS__)
#define LOGE(fmt, ...) printf(COLOR_RED "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "error", ##__VA_ARGS__)
#define LOGD(fmt, ...) printf(COLOR_GREEN "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "debug", ##__VA_ARGS__)
#define LOGW(fmt, ...) printf(COLOR_YELLOW "[%s] [%s] " fmt COLOR_NONE "\n", __TIMESTAMP__, "warning", ##__VA_ARGS__)

#endif
#endif

#pragma warning(disable : 4305)
#pragma warning(disable : 4005)
#pragma warning(disable : 4244)

#define OUT_LOG(x, y)                        \
    {                                        \
        std::ofstream ofs(y, std::ios::out); \
        ofs << x;                            \
        ofs.flush();                         \
        ofs.close();                         \
    }                                        \