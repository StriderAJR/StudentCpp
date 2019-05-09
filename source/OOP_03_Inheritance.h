// –ассматриваемые темы:
// Ќаследование

#pragma once
#include <iostream>
using namespace std;

namespace Inheritance
{
   class Parent
   {
      int parentPrivate;
   protected:
      int parentProtected;
   public:
      int parentPublic;
   };

   class ChildPrivate : Parent
   {
   public:
      ChildPrivate() : Parent() // рекомендуетс€ вызывать конструктор родительского класса
      {
         // parentPrivate = 0; // недоступно
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   class ChildProtected : protected Parent
   {
   public:
      ChildProtected() : Parent()
      {
         // parentPrivate = 0; // недоступно
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   class ChildPublic : public Parent
   {
   public:
      ChildPublic() : Parent()
      {
         // parentPrivate = 0; // недоступно
         parentProtected = 1;
         parentPublic = 2;
      }
   };

   /*
    * “аблица изменени€ доступности полей при различных модификаторах наследовани€:
    * 
    * 
    * |  ћодификатор    |       ћодификатор наследовани€    |
    * |  видимости в    |-----------------------------------|
    * |  базовом классе |   public  | protected |  private  |
    * -------------------------------------------------------
    * |     public      |   public  | protected |  private  |
    * -------------------------------------------------------
    * |   protected     | protected | protected | protected |
    * -------------------------------------------------------
    * |    private      | недоступно| недоступно| недоступно|
    * -------------------------------------------------------
    * 
    * NB: приватные пол€ родител€ недоступны даже в классе потомке!
    */

   int main()
   {
      ChildPrivate cPrivate;
      // cout << cPrivate.parentPrivate << endl;   // недоступно
      // cout << cPrivate.parentProtected << endl; // недоступно
      // cout << cPrivate.parentPublic << endl;    // недоступно

      ChildProtected cProtected;
      // cout << cProtected.parentPrivate << endl;    // private, поэтому недоступно
      // cout << cProtected.parentProtected << endl;  // protected, поэтому недоступно
      // cout << cProtected.parentPublic << endl;     // protected, поэтому недоступно

      ChildPublic cPublic;
      // cout << cPublic.parentPrivate << endl;    // private, поэтому недоступно
      // cout << cPublic.parentProtected << endl;  // protected, поэтому недоступно
      cout << cPublic.parentPublic << endl;     // public

      return 0;
   }
}
