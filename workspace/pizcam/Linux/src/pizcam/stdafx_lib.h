#if defined(_WIN32) || defined(_WIN64)
#ifndef _UNICODE
#ifdef _DEBUG
#pragma comment(lib, "nafxcwd.lib")
#pragma comment(lib, "libcmtd.lib")
#else
#pragma comment(lib, "nafxcw.lib")
#pragma comment(lib, "libcmt.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "uafxcwd.lib")
#pragma comment(lib, "libcmtd.lib")
#else
#pragma comment(lib, "uafxcw.lib")
#pragma comment(lib, "libcmt.lib")
#endif
#endif
#endif //defined(_WIN32) || defined(_WIN64)
