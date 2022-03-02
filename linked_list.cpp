//
// Created by Carlos R. Arias on 3/2/22.
//

#include "linked_list.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;

bool LinkedList::RemoveNotInHead(const string &value) {
    return false;
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

}

LinkedList::~LinkedList() {

}

void LinkedList::Prepend(const string &value) {

}

bool LinkedList::InsertAfter(const string &value, const string &after) {
    return false;
}

bool LinkedList::RemoveItem(const string &value) {
    return false;
}

bool LinkedList::Insert(size_t position, const string &value) {
    return false;
}

bool LinkedList::Remove(size_t position, string &value) {
    return false;
}

bool LinkedList::Get(size_t position, string &value) const {
    return false;
}

int LinkedList::Find(const string &value, size_t start) const {
    return 0;
}

void LinkedList::Write(ostream &output) const {

}

size_t LinkedList::Size() const {
    return 0;
}


LinkedList::LinkedList(const LinkedList& other){

}
const LinkedList& LinkedList::operator=(const LinkedList& rhs){

}
