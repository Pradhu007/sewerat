#include  <iostream>
#include <locale>
#include <ostream>
#include <stdio.h>



#if APPLE
// Include specific Apple modules
#elif _WIN32
#include <Windows.h>
#include <iostream>
#include <string>
#include <lmcons.h>
#include <winbase.h>
#include <winnt.h>
#pragma comment(lib, "user32.lib")

using namespace std;
#endif


void hardwareinfo(){

  SYSTEM_INFO hardwareinfo;
  GetSystemInfo(&hardwareinfo);
  std:cout << "Number of Processors:" << hardwareinfo.dwNumberOfProcessors << endl;
  cout << "Processor Type:" << hardwareinfo.dwProcessorType << endl;

}


void TargetOS() {

    #if __APPLE__
	     printf("Target OS: Apple");
	#elif _WIN32
	    printf("Target OS:Windows\n");
	#elif __LINUX__
	      printf("Target OS: Linux");
	
	#else
	     printf("Unknown OS");
	#endif
	// general code
	

  
}



    



bool TargetUsername(){
    TCHAR username[UNLEN+1];
    DWORD usernamelen= UNLEN + 1;
    GetUserName((TCHAR*)username,&usernamelen);
    
    std:cout << "Username:" << username << endl;

    return true;


}


bool TargetComputerName(){

    TCHAR compname[UNLEN+1];
    DWORD compname_len = UNLEN + 1;
    GetComputerName((TCHAR*)compname,&compname_len);
    std:cout << "Computer Name:" << compname <<endl;
    return true;

}

int main() {
#if APPLE
  // apple specific cTargetusernameode
#elif _WIN32

TargetOS();
TargetUsername();
TargetComputerName();
hardwareinfo();















  
#elif LINUX
  // linux specific code

#else
  // general code or warning
#endif
  // general code
  return 0;
}
