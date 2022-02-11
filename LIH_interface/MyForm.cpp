#include "MyForm.h"

#include "MyForm.h"
#include <iostream>
//#include "EpcDLL.h"


#pragma comment(lib, "EpcDLL.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(cli::array<System::String^>^ args)
{

    /*  EPC_Str256Ptr ErrorMessage = NULL;
      EPC_INT32 Amplifier = 3;
      EPC_INT32 ADBoard = 3;
      LIH_OptionsPtr OptionsPtr;
      EPC_INT32 OptionsSize;

      OptionsPtr->UseUSB = true;

      int gain = 0;


      LIH_InitializeInterface(ErrorMessage,
          Amplifier,
          ADBoard,
          OptionsPtr,
          OptionsSize);



      LIH_Shutdown();*/



    Console::WriteLine("Test");


    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LIHinterface::MyForm form;
    Application::Run(% form);


}
