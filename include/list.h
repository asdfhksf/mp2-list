#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
  // здесь могут быть конструкторы, методы, деструктор Node

  Node(DataType d = 0, Node* n = NULL);
  Node(const Node& node2);
  bool operator==(const Node& node2) const;
};

class List
{
  // любые поля
  Node* head;
public:
  List();
  List(const List& list2);
  List& operator=(const List& list2);
  ~List();

  void InsertToHead(const DataType& d); // вставить элемент d первым
  void InsertToTail(const DataType& d); // вставить элемент d последним
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  void Delete(const DataType& d); // удалить звено со значением data = d
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  void Clean(); // удалить все звенья
  int GetSize(); // узнать число звеньев в списке
  Node* GetHead(); // получить указатель на первое звено списка

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
  bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif