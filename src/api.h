#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define PostureMouvingController_DLLIMPORT __declspec(dllimport)
#  define PostureMouvingController_DLLEXPORT __declspec(dllexport)
#  define PostureMouvingController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define PostureMouvingController_DLLIMPORT __attribute__((visibility("default")))
#    define PostureMouvingController_DLLEXPORT __attribute__((visibility("default")))
#    define PostureMouvingController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define PostureMouvingController_DLLIMPORT
#    define PostureMouvingController_DLLEXPORT
#    define PostureMouvingController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef PostureMouvingController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define PostureMouvingController_DLLAPI
#  define PostureMouvingController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef PostureMouvingController_EXPORTS
#    define PostureMouvingController_DLLAPI PostureMouvingController_DLLEXPORT
#  else
#    define PostureMouvingController_DLLAPI PostureMouvingController_DLLIMPORT
#  endif // PostureMouvingController_EXPORTS
#  define PostureMouvingController_LOCAL PostureMouvingController_DLLLOCAL
#endif // PostureMouvingController_STATIC