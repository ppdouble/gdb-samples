#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int bool;
#define true 1
#define false 0

typedef struct {
    struct hashlist *head;
    struct hashlist *tail;
} MyHashSet;

typedef struct hashlist{
    int key;
    struct hashlist *prev;
    struct hashlist *next;
} hashlist_t;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *mySet = (MyHashSet *)malloc(sizeof(MyHashSet));
    mySet->head = NULL;
    mySet->tail = mySet->head;
    return mySet;
}

hashlist_t* myHashSetFind(MyHashSet* obj, int key) {
    if (NULL == obj->head) {
        return NULL;
    }
    struct hashlist *p, *q;
    p = obj->head;
    q = obj->tail;

    while (p!=q->next) {
        if (p == q && p->key == key) {
            return p;
        }
        if (p->key == key) {
            return p;
        }
        if (q->key == key) {
            return q;
        }
        p = p->next;
        q = q->prev;
    }
    return NULL;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    hashlist_t *ele, *newElement; ele = NULL; newElement = NULL;
    ele =myHashSetFind(obj, key);
    if (NULL != ele) {  // exists in set
        return;
    }
    newElement = (hashlist_t*)malloc(sizeof(hashlist_t));
    newElement->key = key;
    newElement->next = NULL;
    newElement->prev = NULL;
    if (NULL ==  obj->head) { // empty set
        obj->head = newElement;
        obj->tail = obj->head;
    } else {    // unordered. added to tail
        newElement->prev = obj->tail;
        obj->tail->next = newElement;
        obj->tail = newElement;
    }

}

void myHashSetRemove(MyHashSet* obj, int key) {
    hashlist_t* ele; ele = NULL;
    ele =myHashSetFind(obj, key);
    if (NULL == ele) {  // not exists in set
        return;
    }
    if (obj->head == ele && obj->tail == ele) { // only one element in set
        obj->head = NULL;
        obj->tail = NULL;
    }
    if (obj->head == ele) {
        ele->next->prev = NULL;
        obj->head = ele->next;
    } else if (obj->tail == ele) {
        ele->prev->next = NULL;
        obj->tail = ele->prev;
    } else {
        ele->prev->next = ele->next;
        ele->next->prev = ele->prev;
    }

    free(ele);
    ele = NULL;

}


/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {

    hashlist_t *res; res = NULL;
    res = myHashSetFind(obj, key);
    if (NULL != res) {
        return true;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    if (NULL == obj->head) {
        return;
    }
    struct hashlist *p, *q, *tp, *tq;
    p = NULL; q = NULL; tp = NULL; tq = NULL;
    p = obj->head;
    q = obj->tail;

    while (NULL != p) {
        if (p == q) {
            free(p);
            p = NULL;
            q = NULL;
            return;
        }
        if (p->next == q) {
            free(p);
            free(q);
            p = NULL;
            q = NULL;
            return;
        }
        tp = p;
        tq = q;
        p = p->next;
        q = q->prev;
        free(tp);
        free(tq);
        tp = NULL;
        tq = NULL;

    }
    obj->head = NULL;
    obj->tail = NULL;
    free(obj);
    obj = NULL;
    return;
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

int main (char *argv[], int argc) {
	MyHashSet *obj = myHashSetCreate();
	myHashSetAdd(obj, 1);
	myHashSetAdd(obj, 2);
	myHashSetFree(obj);
}
