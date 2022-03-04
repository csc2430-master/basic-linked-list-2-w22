//
// Created by Carlos R. Arias on 3/2/22.
//

#include "linked_list.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;

bool LinkedList::RemoveNotInHead(const string &value) {
    if (_head->data == value)
        return false;
    Node* itemBefore = FindItemBefore(value);
    if (itemBefore == nullptr)
        return false;
    Node* toDelete = itemBefore->next;
    itemBefore->next = toDelete->next;
    toDelete->next = nullptr;
    delete toDelete;
    _size--;
    return true;
}

LinkedList::Node *LinkedList::FindItem(const string &value) const {
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next){
        if (tmp->data == value)
            return tmp;
    }
    return nullptr;
}

LinkedList::Node *LinkedList::FindItemBefore(const string &value) const {
    if (_head->data == value)
        return nullptr;

    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next){
        if (tmp->next != nullptr)
            if (tmp->next->data == value)
                return tmp;
    }
    return nullptr;
}

LinkedList::LinkedList() {
    _head = nullptr;
    _size = 0;
}

LinkedList::~LinkedList() {
    Node* tmp = _head;
    while (_head != nullptr){
        _head = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        tmp = _head;
    }
}

void LinkedList::Prepend(const string &value) {
    Node* neo = new Node;
    neo->data = value;
    neo->next = nullptr;

    if (_head == nullptr)
        _head = neo;
    else{
        neo->next = _head;
        _head = neo;
    }
    _size++;
}
/**
 *
 * @param value what to insert
 * @param after where to insert it after
 * @return
 */
bool LinkedList::InsertAfter(const string &value, const string &after) {
    Node* item = FindItem(after);
    if (item == nullptr)
        return false;
    Node* neo = new Node;
    neo->data = value;
    neo->next = nullptr;
    neo->next = item->next;
    item->next = neo;
    _size++;
    return false;
}

bool LinkedList::RemoveItem(const string &value) {
    Node* tmp = nullptr;
    if (_head->data == value){
        tmp = _head->next;
        _head->next = nullptr;
        delete _head;
        _head = tmp;
        _size--;
        return true;
    }else{
        bool deleted = RemoveNotInHead(value);
        if (deleted){
            _size--;
        }
        return deleted;
    }
}

bool LinkedList::Insert(size_t position, const string &value) {
    if (position > _size)
        return false;
    Node* neo = new Node;
    neo->data = value;
    neo->next = nullptr;

    if (_head == nullptr){
        _head = neo;
    }else if (position == 0){
        Prepend(value);
    }else{
        Node* tmp = _head;
        for (int i = 0; i < position - 1; ++i) {
            tmp = tmp->next;
        }
        neo->next = tmp->next;
        tmp->next = neo;
    }
    _size++;
    return true;
}

bool LinkedList::Remove(size_t position, string &value) {
    if (position >= _size)
        return false;
    Node* tmp = _head;
    for (int i = 0; i < position - 1; ++i) {
        tmp = tmp->next;
    }
    value = tmp->next->data;
    Node* toDelete = tmp->next;
    tmp->next = toDelete->next;
    toDelete->next = nullptr;
    delete toDelete;
    return true;
}

bool LinkedList::Get(size_t position, string &value) const {
    if (position >= _size)
        return false;
    Node* tmp = _head;
    for (int i = 0; i < position; ++i) {
        tmp = tmp->next;
    }
    value = tmp->data;
    return true;
}

int LinkedList::Find(const string &value, size_t start) const {
    if (start >= _size)
        return -1;
    Node* tmp = _head;
    for (int i = start; i < _size; ++i) {
        if (tmp->data == value)
            return i;
        tmp = tmp->next;
    }
    return -1;
}

void LinkedList::Write(ostream &output) const {
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next)
        output << tmp->data << "\n";
}

size_t LinkedList::Size() const {
    return _size;
}


LinkedList::LinkedList(const LinkedList& other){

}
const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    return *this;
}
