// ��������������� ����:
// ������������ ������

#pragma once
#include <iostream>
using namespace std;

namespace DynamicArray
{
   void main()
   {
      /*
      * ����, �� ������������ ��������� �����������. 
      * ������ ���� ������� � ������������.
      * 
      * �������� � ������������ ������� ����������� � ������������ ������
      * � ���, ��� ������ �� ��� ��������.
      * 
      * ����������� - � �����,
      * ������������ - � ����.
      * 
      * ��������� ������ ������������ ��������� ���������, ������������ ��� �����������.
      * 
      * ���� ������������� ������� � ���, ��� ����������� ���, ��� ����� ��������� �������.
      * ��� ���� ������������ �������� � ��������� ����, �� � ������������ �����������
      * ���������� ���� � ����... Sad, but true.
      * 
      * ��� ��������� ��� ��������� � ������� ������������, �� ���� ��������, ������������
      * � ������� �� ������������ ������ (�� ������������) ������ �� ����.
      * 
      * ���� ��� �������� ������� �� ������ � ������������ ������� (�����):
      * 1. �������� ������
      * 2. ����������� ������
      */

      /*
       * 1. ��������� ������
       * ��� ��������� ������ ���� �������� new.
       * 
       * �������� new ����������� ������ ��� �������� ������. �� ������ ����������, ��� ������
       * � ���������� ���� ����, ���� �� ���. ������� �������, ��� new "�������" ������ - �������,
       * �� �� �� ������� ��� ����� ������ ����������� ������ (� ����, ���� �� �����). ������
       * ���� ��� �� new. ����� ����, ������ ��� ������������� ���������� ���������� ������������
       * �������� � ������ ������� ���������: ��������� ����� ����� "���� ����� ������" �� ���
       * ����� ������ �����, � ����� ������ ������������.
       * 
       * �.�. ������ � ��������� ����. �� �� "�����" ��� ���� ���������. ���������� ��� ����� ���������,
       * ��������� ���������� ��� ������������ ������ ��� ����� �����������������, ������ �����-��
       * �������� �� �� ����� ��������������.
       * 
       * ���� - ��� ������ ������, �� ���������� ��� �������� � ����� ���������. ������ ��� �����
       * ������������ ���-�� ��� ���-��. ��� ������ � ������� ���������, ��� ��������� � ���� 
       * ������ ���� �������������.
       * 
       * �������, ��� ����������, ���� �� ��������� �����-�� ������ �� ������ � ����, � �����
       * ��������� ��� ������ ������ ������� � �������� ��� ������? ��� ��������� � ����� ��������������,
       * � ������ ������.
       * 
       * ����� ������ �� �����������, ������������� �������� �������� "��������������" ������.
       * 
       * ��� �������������� ������ ��������� ������ ���������� "��������" ��� ������������� ����.
       * ����� ����������������� ������ ��������� ��� ���, ���� ������� �� �����, ������ ��� ������
       * ������ �������� ������ �� ������ ����������� ���������.
       * 
       * ��� ��� ������ �������� new. �� ����������� ������������ ����� ������ � ����.
       * 
       * ������, ������.
       * 
       * �������� new ��� ����� �� �������������� "�����". �� ����� ���� �� ������ ����� ����������
       * �������� �-��� ��������� ������ malloc(size_to_allocate);
       * 
       * malloc ���������������� ��� memory allocate
       * memory - ������
       * allocate - ��������, ���������������
       * 
       * � �������� ��������� malloc ��������� ���-�� ����, ������� ����� ��������.
       * 
       * new float;
       * 
       * ������������� ������������ � 
       * 
       * malloc( sizeof(float) );
       * 
       * � ��� �� �������� �������� new � �-��� malloc? ��� ��� ������� �����, ��� ����� ��������������� ������.
       * ����� ������. ����� ���������� � ������ ������ ����, ��������� ����������� � ��������� ������� � ������,
       * � ��� �� �������������.
       * 
       * �++ �����, ������� �������� ���. ��� �� ����� ���� �� ����� ����������. �� ��� ����� ��� ������� ����.
       * ����� � ������������ �������� ���� c# � java �������� � ������� �� ����� ������� ����������.
       */

      float* ptr1 = new float; // ��������������� sizeof(float) ���� ������ � ����
      *ptr1 = 1.5;
      cout << "*ptr1 = " << *ptr1 << endl;

      /*
       * ����, ��� ��� ���������.
       * 
       * �� ������� ���������. ����� � ������� ��������� new �������� ������ ��� ������ ������
       * ���� ������ float (4 ��� ������� ��� ���� - ������ ����� ��������� sizeof(float),
       * ����� ������ �����). � ����� ���������� ������ ���������� � ��������� ptr1.
       * 
       * ��� �����:
       * 
       * ptr1 - ��� ��������� ���������� � ����� ��������� � �����
       * �������� new - ������� ������ � ����, �� � �����
       * 
       * 
       *        ����           |            ����
       *                       |
       *    0xFFFC2, ptr1      |           0xFAA01
       *    |-----------|      |         |---------|
       *    |  0xFAA01  |      |         |   1.5   |
       *    |-----------|      |         |---------|
       *    
       *  ��� ����� ��������� ���������� ptr1 ����� ����������, ����� ���������� �� ���� ����.
       *  � ��� ������ � ����... ���. ������ ��� ��� ��������������� �� ��� ����� �� ������������.
       *  ��� ������ ��� � ����������.
       *  
       *  ��������� ��� ����� ���.
       *  
       *        ����           |            ����
       *                       |
       *                       |           0xFAA01
       *                       |         |---------|
       *                       |         |   1.5   |
       *                       |         |---------|
       *                       
       * ���� ��������� �� ����� ���������� ptr1, � ��� ����������������� ������� � ������ ��� � ��������
       * �����������������. ��������� �� ����� ������������ ��� ������ ��������.
       * 
       * �� � �� ������ �� ����� ������� �� ���� ������. �� �� �������� �����, ��� ��� ������ ��������.
       * 
       * �������, ����� ���������� ���������, ��� ������ ���������� ��������� ��, � ��� ����� � ����,
       * ����� ������������, ������� � ������������ ������� �������� � ��. �� �� ������ ������, �����
       * ���� ��������� ��������� �� ����� �������������� �����, �������� ������ � �.�.?
       * 
       * ��� ��������, ����� ��������� ���� �� 1��, 2��, 3�� ������ ������ ��������� �����, ����� ���
       * ������ ������ ���� �������� �� ������? �������, �� ��������. ������� �� ���� �������� ���,
       * ��� �� ���������, �.�. � ������ ����� ���������.
       */

      /*
       * 2. ������������� ������
       * 
       * ����� ����� �������� ��������� �� ����� ������ �������� ��� ������ � ���� ��� ������
       * �������� delete.
       * 
       * delete � �������� ��������� ��������� ��������� (�����, �����) �� �� ������� ������,
       * ������� ����� �����������.
       * 
       * ������, delete ����� ��� � new �� ����� ���� ��������� �-��� ������������� ������ free,
       * ������� ��� �������� ��������� ���������.
       * 
       * delete pointer;
       * 
       * ������������
       * 
       * free(pointer);
       * 
       * ������� ��������� � ������������ ������� ���������� �������:
       * ������� new ����� ���� delete. �������� ���-�� new? ������, ����� ���-�� ��� ������ �����������. ����� �����.
       * 
       * ��, ���� �� �������� ���������, �� ��� ����� ����� ���� 1 ����� � ������, �� ����
       * ���� �� ��������������� ������ ��� float, � ��� ����� ������ 1 �����!
       * 
       * ����������, ����������� ������ 1 ����? � ����� ��� � ����� ����� ������ � ������������
       * ��� ��������� ������?
       * 
       * ��� ������. ������������ ����������� � ��� ��� ������������.
       * 
       * <����������_���_�����������>
       * 
       * �� ����� ���� ��� �������������� ������, ��� ��� ������������� �������� ���������
       * �� �� ������ ����������������� ������, � �� ���������... ������ ��� � ����� ������ ������
       * �������� ��� ���������� ���������� � ������. � ���� ���������� �������� ����� ���������� ������,
       * ��� ������, ��� ������� ���������� ������ ���������� � ��������� ��� ����������.
       * 
       *      0xFAA00   0xFAA01   0xFAA02   0xFAA03   0xFAA04 
       *    |----------|---------|---------|---------|---------|
       *    |����������|    x    |    x    |    x    |    x    |
       *    |----------|---------|---------|---------|---------|
       *                    ^
       *                    |
       *           �� �������� �� ����
       *            ����� ���� ������
       *    
       * ������, ���������� ����� �������� �� 1 ���� ������, �� ��� �������� ������ ����������� � �����������,
       * �� ����� ������� ���������� ��� ����� ��� ������. �� ��� �������� ������ ������������, ���
       * ���������� �������� 1 ���� ������.
       * 
       * ������� ����� �� ���������� � delete ��������� ���������, ��������� ������� ������ ��� �����,
       * ��������� �� ���������� ������ ���������� �� ������ ���������� ������ � ���������� 
       * ��� 4 ��� ������� ��� ���� �����.
       * 
       * </����������_���_�����������>
       * 
       * ��� ��� �� ����� ���� ���������� ������ ���������� � ���, ��� ����� ��� ������ ����
       * ��������������� ������ � �������������� ��� ������������ �� ������, ������� ������
       * ������� � ������� ������ ���� ��������, � ������� ������ ����� �����������.
       */

      delete ptr1;

      /*
       * ����� ������������� ������, ���� "������" � ������ ���������.
       * ��������������, ���� �� ���������� ���������� � ����� ������ ��� ���,
       * ��� ����� �� ������������, ��������� ��������� � ����� � �������
       * "Access violation", ��� � ������� �������� �������� "� ���� ��� ���� ���� �����".
       * 
       * �� ������ ���, �++ ������ �� ������ ��������� �������, ����� �������� ���,
       * ��� �� ������� ����-�� �� ����. ������ ��������������� �������� ���,
       * �� �������� �� ����� ���������� � ���-������ �����, ����� �� ��� �� ����
       * �������� ��� � ����... ��� ������ � ����������� �� ����������� ������ � ����.
       */

      // cout << "*ptr1 = " << *ptr1 << endl; // ��� ����� ������ ������� ����������

      /*
       * �����, �����. �� ������� ����������, �� ��� ���� ����������.
       * 
       * ��� ������������ ������� �������� � ����, �� ������ ��� ��� �������� � ������������
       * ����� �� ����, �������. �� � ��� �� ������. -_- ����� �������.
       */

      int* array1 = new int[5];

      /*
       * ����, ������ ��������� � ������ �������. ������ �������� ���������.
       * 
       * new int[5];
       * 
       * ��� ��������� ��������� ������ ��� ������, ��������� �������� �������� int
       * � ����� ����� 5 ����.
       * 
       * ����� malloc ������������ ���:
       * 
       * malloc( sizeof(int) * 5 );
       * 
       * ����� ������� ��������� 20 ���� ������.
       * 
       * ��� � �������� ����� �������������� ������, �������� new ������ ��� ���������
       * ��������� �� ������ ���������� ������� ������.
       * 
       * ��� �� �� ����� ���� � �� ������������ ���������, ��� ���� ��� ������� ��������
       * ������� ������ �������. ������ �������� �� � �����, � ��� � ����.
       * 
       * ������, �������� ��� ����� ������� �������� � �������, �� �� ������ ����� �������.
       * 
       * ������� ��� ������ ��������� ������ ���� int. ������ ��� �������, ����� �� �������
       * ��� �������� ������ ��� int.
       * 
       * ��� ��� ����� ��� � �������� �������� 
       * 
       * int* array1 - ��������� �� ��� ������ int.
       * 
       * �� � � ������ ��� ��� ���������� ��������� ����� ���:
       * 
       *        ����           |            ����
       *                       |
       *    0xFFFC2, array1    |           0xFAA01   0xFAA02   0xFAA03   0xFAA04   0xFAA05
       *    |-----------|      |         |---------|---------|---------|---------|---------|
       *    |  0xFAA01  |      |         |   xxx   |   xxx   |   xxx   |   xxx   |   xxx   |
       *    |-----------|      |         |---------|---------|---------|---------|---------|
       *                                      0         1         2         3         4
       *                                      ^
       *                                      |
       *                                    array1
       *                                      
       */

      // � ����� ������ � �������� ��� ������� ������� �� �� ����������, �� �� ������
      // �� ��������� �� ����������� ��������
      array1[0] = 11;
      array1[1] = 12;
      array1[2] = 13;
      array1[3] = 14;
      array1[4] = 15;

      for (int i = 0; i < 5; i++) cout << "array1[" << i << "] = " << array1[i] << " ";

      // �� �������� ����������� ������
      int* ptr = array1;
      delete[] array1;

      /*
       * "��� �� �����?" �������� ��, ������ delete[], "����� � delete ������� �������� []"
       * 
       * ���� ������, �� delete[] ������ ���� ������, ���� ��������� ������ ���� ����� new[],
       * � ��������� ��� ��������.
       * 
       * delete �������������� ����������, ���� ������ ���������� � ������� new.
       * 
       * ������ �������� ��� �������� ��� �� �����: 
       * 
       * ��� �������� �� ������� ����� ������, �� �� ������������ ������� ����� delete � delete[],
       * �������� ��� �������� ������� ��� ����� ���������. �� ��� ������, ����� ����� ���������
       * ���������������� ���� ������, ������, ��� �������� � delete � delete[] ����� �������
       * ������ ������� ���������� � ����������� ������.
       * 
       * ���������� ��������� ������������ �����������. ���� ������ ���� �������� ��� ������,
       * �� � ������������ ��� ������ ����� ��� ��� �������.
       * 
       * ������, ����� ����� delete ��� ������� �������� �������� ������ ����� � ������� 
       * "��������� ���� ��������"
       */
   }
}