// Подключаем все подпрограммы
#include "Basics_1_FirstProgram.h"
#include "Basics_2.1_Variables.h"
#include "Basics_2.2_GlobalVariables.h"
#include "Basics_2.3_LocalVariables.h"
#include "Basics_2.4_LocalGlobalVariables.h"
#include "Basics_3_Cycles.h"
#include "Basics_4_Functions.h"
#include "Basics_5_Pointers.h"
#include "Basics_6.1_References.h"
#include "Basics_6.2_ReferencesVsPointers.h"
#include "Basics_7.1_StaticArray.h"
#include "Basics_7.2_DynamicArray.h"
#include "Basics_7.3_Strings.h"
#include "Basics_7.4_TwoDimArray.h"
#include "Basics_7.5_MultDimArray.h"
#include "Basics_7.6_DynamicArray.h"
#include "Basics_7.7_TwoDimDynamicArray.h"
#include "Basics_8_FileIO.h"
#include "Basics_9_Structures.h"
#include "Basics_10_Unions.h"
#include "Basics_11_Enum.h"
#include "Basics_Extra_01_StructEnum.h"
#include "Basics_Extra_02_StructArray.h"
#include "Basics_Extra_03_StructList.h"
#include "Basics_Extra_04_PassParams.h"

#include "OOP_01.1_Classes.h"
#include "OOP_01.2_Encapsulation.h"
#include "OOP_01.3_ClassLifeCycle.h"
#include "OOP_01.4_CopyConstructor.h"
#include "OOP_02_OperatorOverloading.h"
#include "OOP_03_Inheritance.h"
#include "OOP_04.1_VirtualFunctions.h"
#include "OOP_04.2_AbstactClass.h"
#include "OOP_05_Polymorph.h"
#include "OOP_Extra_AssocArray.h"

#include "Templates_1_Templates.h"
#include "Templates_2_TemplateList.h"
#include "Templates_Extra_AssocArrayTemplate.h"

#include "Zzz_AdvancedStreamIO.h"
#include "Zzz_ConsoleDraw.h"
#include "Zzz_ConsoleLanguage.h"

#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "Rus");



    Strings::main();
//    Cycles::main();
//    StructArray::main();
//    ConsoleDraw::main();
//    AssocArray::main();
//    Polymorph::main();
//    ClassArray::main();
//    ConsoleLanguage::main();
//    Unions::main();
//    FileInputOutput::main();
//    Variables::main();
//    GlobalVariables::main();
//    LocalVariables::main();

//	Classes::main();
//    Encapsulation::main();
    // ClassLifeCycle::main();
//    Functions::main();
    FoolProtection::main();

    return 0;
}