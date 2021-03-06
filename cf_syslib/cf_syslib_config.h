#ifndef CF_SYSLIB_CONFIG_H_INCLUDED
#define CF_SYSLIB_CONFIG_H_INCLUDED

#ifdef _MSC_VER

   /// MSVC compiler
   // disabling warning 4251 is the only practical way to deal with dll-export issues according to M$
   #pragma warning (disable:4251) // class "XX" needs to have dll-interface to be used by clients of class "YY"

   #ifdef CF_SYSLIB_IMPLEMENTATION
      #define CF_SYSLIB_PUBLIC __declspec(dllexport)
      #define CF_SYSLIB_EXTERN
   #else
      #define CF_SYSLIB_PUBLIC __declspec(dllimport)
      #define CF_SYSLIB_EXTERN extern
   #endif
   #define CF_SYSLIB_PRIVATE

#elif __GNUC__

   /// gnu gcc

   #define CF_SYSLIB_PUBLIC  __attribute__ ((visibility("default")))
   #define CF_SYSLIB_PRIVATE __attribute__ ((visibility("hidden")))
   #define CF_SYSLIB_EXTERN

#else

  #error "Unknown compiler"

#endif


#endif // CF_SYSLIB_CONFIG_H_INCLUDED

