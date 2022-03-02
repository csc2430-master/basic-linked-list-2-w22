//
// Created by Carlos R. Arias on 3/2/22.
//

#ifndef BASIC_LINKED_LIST_2_W22_LINKED_LIST_H
#define BASIC_LINKED_LIST_2_W22_LINKED_LIST_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class LinkedList {
private:
    class Node{
    public:
        string data;
        Node* next;
    };
    LinkedList(const LinkedList& other);
    const LinkedList& operator=(const LinkedList& rhs);
    bool RemoveNotInHead(const string& value);
    Node* FindItem(const string& value)const;
    Node* FindItemBefore(const string& value)const;
    Node* _head;
    size_t _size;
public:
    LinkedList();
    ~LinkedList();
    void Prepend(const string& value);
    bool InsertAfter(const string& value, const string& after);
    bool RemoveItem(const string& value);
    bool Insert(size_t position, const string& value);
    bool Remove(size_t position, string& value);
    bool Get(size_t position, string& value)const;
    int Find(const string& value, size_t start = 0)const;
    void Write(ostream& output)const;
    size_t Size()const;
};


#endif //BASIC_LINKED_LIST_2_W22_LINKED_LIST_H
