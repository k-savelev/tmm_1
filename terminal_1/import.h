#pragma once
#ifdef NILSENDLL_EXPORTS
#define NILSENDLL_API __declspec(dllexport)
#else
#define NILSENDLL_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif
    int calculation(struct data* p);
#ifdef __cplusplus
}
#endif