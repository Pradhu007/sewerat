#include <stdio.h>
#if APPLE
// apple
#elif _WIN32
#include <Windows.h>
#endif

int main() {
#if APPLE
  // apple specific code
#elif _WIN32
  HWND window;
  window =
      FindWindow("ConsoleWindowClass",
                 NULL); 
  ShowWindow(window, 0);
  MessageBoxA(NULL,
              "The program can't start because msvcrt.dll is missing from your "
              "computer. Try reinstalling the program to fix this problem. "
              "To compensate for the trouble caused, we will move this program "
              "to the recycling bin.",
              "Sony Vegas 15 Installer - Fatal Error", MB_ICONEXCLAMATION);

#elif LINUX
  // linux specific code
#elif BSD
  // BSD specific code
#else
  // general code or warning
#endif
  // general code
  return 0;
}
