//task 6.1 Var 29

#ifndef _MAIN_H_
#define _MATH_H_
#include <string>
bool IsStrEven(const std::string& str);
#endif

----------------------------

#include "Stack.cpp"
#include ".\Binary_tree\set1\set1.h"
#include <string>
#include <iostream>

using namespace std;

bool IsStrEven(const string& str)
{
    int sum = 0;
    for (auto& i : str)
    {
        sum += (int)i;
    }
    return (sum % 2 == 0) ? true : false;
}

int main()
{
    Set1<string> binaryTree;
    cout << "Enter amount of elements in binary tree: ";
    int size;
    cin >> size;
    for (auto i = 0; i < size; ++i)
    {   
        string temp;
        cin >> temp;
        binaryTree.Insert(temp);
    }
    Stack<string> stackOfStr;
    for (auto& str : binaryTree.GetLeaves())
    {
        if (IsStrEven(str.second))
        {
            stackOfStr.Push(str.second);
        }
    }
    system("pause");
    return 0;  
}

------------------------------------------------


#include ".\List\List.h"
template<typename T>
class Stack
{
    private:
    List<T> stack_;

    public:
    ~Stack()
    {
        stack_.Clear();
    }
    bool IsEmpty() const {return stack_.IsEmpty();}
    void Push(const T& data)
    {
        stack_.PushBack(data);
    }
    T Pop()
    {
        auto result = Top();
        stack_.PopBack();
        return result;
    }
    T Top() const
    {
        return *(--stack_.end());
    }
    T& Top()
    {
        return *(--stack_.end());
    }

};
--------------------------------------------
#pragma once

#include <initializer_list>
#include <iterator>
#include <utility>

template<class T>
class List {
private:
    class Node {
    public:
        Node *next_;
        Node *previous_;
        T data_;

        Node(const T& data = T{}, Node *previous = nullptr, Node *next = nullptr) {
            this->data_ = data;
            this->next_ = next;
            this->previous_ = previous;
        }

        ~Node() {};
    };

    unsigned int size_;
    Node *tail_;
    Node *head_;
public:
    List(const unsigned int&);

    List(const std::initializer_list<T>&);

    List(List<T>&);

    List(List<T>&&);

    List();

    ~List();

    void PushBack(const T& data);

    void PushFront(const T& data);

    void PopBack();

    void PopFront();

    void Clear();

    bool IsEmpty() const;

    unsigned int GetSize() const;

    T& operator[](const unsigned int& index);

    T operator[](const unsigned int& index) const ;

    List<T>& operator=(const List<T>&);

    List<T>& operator=(const List<T>&&);

    class Iterator : std::iterator<std::bidirectional_iterator_tag, T> {
    private:
        Node* object_;
        List<T>* list_;
    public:
        Iterator() : object_(nullptr), list_(nullptr) {
        }

        Iterator(const Iterator& other) : object_(other.object_), list_(other.list_) {
        }

        Iterator(List<T>* list, Node *value) : object_(value), list_(list) {
        }

        T *operator->() {
            return object_;
        }

        Iterator& operator++() {
            if (object_ == list_->head_)
                ++object_;
            else 
                object_ = object_->next_;
            return *this;
        }

        Iterator& operator=(const Iterator& other) {
            object_ = other.object_;
            return *this;
        }

        Iterator& operator++(int) {
            if (object_ == list_->head_)
                ++object_;
            else 
                object_ = object_->next_;
            return *this;
        }

        Iterator& operator--() {
            if (object_ != list_->head_ + 1) {
                object_ = object_->previous_;
            } else {
                --object_;
            }
            return *this;
        }

        Iterator& operator--(int) {
            if (object_ != list_->head_ + 1) {
                object_ = object_->previous_;
            } else {
                --object_;
            }
            return *this;
        }

        T& operator*() {
            return object_->data_;
        }

        T operator*() const {
            return object_->data_;
        }

        bool operator==(const Iterator& other) {
            return (object_ == other.object_);
        }

        bool operator!=(Iterator& other) {
            return !(object_ == other.object_);
        }
    };

    Iterator begin();

    Iterator end();
};

template<class T>
List<T>::List(const unsigned int& size) {
    tail_ = head_ = nullptr;
    size_ = size;
    for (unsigned int i = 0; i < size; ++i) {
        PushBack(T{});
    }
    return;
}

template<class T>
List<T>::List(List<T>&& other) {
    tail_ = other.tail_;
    head_ = other.head_;
    size_ = other.size_;
    other.head_ = other.tail_ = nullptr;
    other.size_ = 0;
    return;

}

template<class T>
List<T>::List(const std::initializer_list<T>& listOfValues) {
    tail_ = head_ = nullptr;
    size_ = 0;
    for (const auto& element : listOfValues) {
        PushBack(element);
    }
    return;
}

template<class T>
List<T>::List(List<T>& object) {
    tail_ = head_ = nullptr;
    size_ = 0;
    for (auto& element : object) {
        PushBack(element); 
    }
    return;
}

template<class T>
List<T>::List() {
    tail_ = head_ = nullptr;
    size_ = 0;
    return;
}

template<class T>
List<T>::~List() {
    Clear();
    return;
}

template<class T>
void List<T>::PushBack(const T& data) {
    if (!head_) {
        tail_ = head_ = new Node(data);
        ++size_;
    } else {
        head_->next_ = new Node(data, head_, nullptr);
        Node *temp = head_;
        head_ = head_->next_;
        if (!tail_) {
            tail_ = temp;
        }
        ++size_;
    }
    return;
}

template<class T>
void List<T>::PushFront(const T& data) {
    if (!head_) {
        tail_ = head_ = new Node(data);
        ++size_;
    } else {
        if (!tail_) {
            tail_ = new Node(data, nullptr, head_);
            head_->previous_ = tail_;
        } else {
            tail_->previous_ = new Node(data, nullptr, tail_);
            Node *temp = tail_;
            tail_ = tail_->previous_;
            temp->previous_ = tail_;
        }
        ++size_;
    }
    return;
}

template<class T>
void List<T>::PopBack() {
    Node *temp = head_->previous_;
    delete head_;
    head_ = temp;
    --size_;
    return;
}

template<class T>
void List<T>::PopFront() {
    Node *temp = tail_->next_;
    delete tail_;
    tail_ = temp;
    --size_;
    return;
}

template<class T>
void List<T>::Clear() {
    while (head_) {
        PopBack();
    }
    head_ = tail_ = nullptr;
    return;
}

template<class T>
unsigned int List<T>::GetSize() const {
    return size_;
}

template<class T>
bool List<T>::IsEmpty() const {
    return (size_ == 0);
}

template<class T>
T& List<T>::operator[](const unsigned int& index) {
    Node *temp = tail_;
    unsigned int counter = 0;
    while (counter != index) {
        temp = temp->next_;
        ++counter;
    }
    return temp->data_;
}

template<class T>
T List<T>::operator[](const unsigned int& index) const { 
    Node *temp = tail_;
    unsigned int counter = 0;
    while (counter != index) {
        temp = temp->next_;
        ++counter;
    }
    return temp->data_;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other) {
    Clear();
    tail_ = head_ = nullptr;
    size_ = 0;
    for (int i = 0; i < other.size(); ++i) {
        PushBack(other[i]);
    }
    return *this;
}

template<class T>
List<T>& List<T>::operator=(const List<T>&& other) {
    Clear();
    tail_ = other.tail_;
    head_ = other.head_;
    size_ = other.size_;
    other.head_ = other.tail_ = nullptr;
    other.size_ = 0;
    return *this;
}

template<class T>
typename List<T>::Iterator List<T>::begin() {
    return Iterator(this, tail_);
}

template<class T>
typename List<T>::Iterator List<T>::end() {
    return Iterator(this, head_ + 1);
}
-------------------------------------
#ifndef _SET_H_
#define _SET1_H_
#include "..\map1\map1.h"
#include "..\map1\map1.cpp"
using namespace std;
template<typename T>
class Set1
{
private:
	Map1<T, T> set_;

public:
	Set1()
	{

	}
	~Set1()
	{
		set_.Clear();
	}
	void Insert(T data)
	{
		set_.Insert(make_pair(data, data));
	}
	auto Remove(T data)
	{
		return set_.Remove(data);
	}
	auto GetSize()
	{
		return set_.GetSize();
	}
	auto IsEmpty()
	{
		return set_.IsEmpty();
	}
	void Clear()
	{
		set_.Clear();
	}
	void Print()
	{
		set_.Print();
	}
	auto GetLeaves()
	{
		return set_.GetLeaves();
	}
	class Iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		typename Map1<T, T> :: Iterator it;
	public:
		Iterator() {

		}
		Iterator(const typename Map1<T, T>::Iterator& other)
		{
			this->it = other;
		}
		Iterator(const Set1<T>::Iterator& other){
			this->it = other.it;
		}
		// auto operator->() {
		// 	return ->it;
		// }
		Iterator& operator++() {
			++it;
			return *this;
		}
		Iterator& operator=(const Iterator& other) {
			this->it = other.it;
			return *this;
		}
		Iterator& operator++(T) {
			++it;
			return *this;
		}
		Iterator& operator-- () {
			--it;
			return *this;
		}
		Iterator& operator--(T) {
			--it;
			return *this;
		}
		T& operator*() {
			return *it;
		}
		T operator*() const {
			return *it;
		}
		bool operator==(const Iterator& other) {
			return (it == other.it);
		}
		bool operator!=(Iterator& other) {
			return !(it == other.it);	
		}

	};

	Iterator begin() {
	    return set_.begin();
    }
    Iterator end() {
	    return set_.end();
	}

};

#endif
------------------------------------------
#pragma once
#include ".\map2\map2.cpp"
#include ".\map2\map2.h"
using namespace std;
template<typename T>
class Set2
{
private:
	Map2<T, T> set_;

public:
	Set2()
	{

	}
	~Set2()
	{
		set_.Clear();
	}
	void Insert(T data)
	{
		set_.Insert(make_pair(data, data));
	}
	auto Remove(T data)
	{
		return set_.Remove(data);
	}
	auto GetSize()
	{
		return set_.GetSize();
	}
	auto IsEmpty()
	{
		return set_.IsEmpty();
	}
	void Clear()
	{
		set_.Clear();
	}
	void Print()
	{
		set_.Print();
	}
	class Iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		typename Map2<T, T> :: Iterator it;
	public:
		Iterator() {

		}
		Iterator(const typename Map2<T, T>::Iterator& other)
		{
			this->it = other;
		}
		Iterator(const Set2<T>::Iterator& other){
			this->it = other.it;
		}
		// auto operator->() {
		// 	return ->it;
		// }
		Iterator& operator++() {
			++it;
			return *this;
		}
		Iterator& operator=(const Iterator& other) {
			this->it = other.it;
			return *this;
		}
		Iterator& operator++(T) {
			++it;
			return *this;
		}
		Iterator& operator-- () {
			--it;
			return *this;
		}
		Iterator& operator--(T) {
			--it;
			return *this;
		}
		T& operator*() {
			return *it;
		}
		T operator*() const {
			return *it;
		}
		bool operator==(const Iterator& other) {
			return (it == other.it);
		}
		bool operator!=(Iterator& other) {
			return !(it == other.it);	
		}

	};

	Iterator begin() {
	    return set_.begin();
    }
    Iterator end() {
	    return set_.end();
	}

};

---------------------------------------
#pragma once
#include <utility>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
template <typename T1, typename T2>
class Map2
{
protected: 
class Node;
private:
    
    Node* root_;
    size_t size_;

    list<Node*> list_of_nodes_;

    Node* Insert_(const pair<T1, T2>&, Node*, Node*);
    void Clear_(Node*);
    void Print_(Node*);
 	static Node* Next(Node*);
    Node* Previous(Node*);
    void CopyTree(Node*);
    void LeftOrRightParent(Node*, Node*);
    Node* Find_(const T1&, Node*);
	Node* FindMin()
	{
		Node* temp = root_;
		while (temp->left_)
		temp = temp->left_;
		return temp;
	}
	Node* FindMax()
	{
		Node* temp = root_;
		while (temp->right_)
		temp = temp->right_;
		return temp;
	}
    void AddToList(Node*);
    void RemoveFromList(Node*);

public:
    Map2();
    Map2(Map2<T1, T2>&&);
    Map2(const Map2<T1, T2>&);
    ~Map2();
    void Insert(const pair<T1, T2>&);
    T2& operator[](const T1&);
    T2 operator[](const T1&) const;
    Map2<T1, T2>& operator=(Map2<T1, T2>&&);
    Map2<T1, T2>& operator=(const Map2<T1, T2>&);
    bool Remove(const T1&);
    void Print();
    void Clear();
    bool IsEmpty() const;
    size_t GetSize() const;

    class Iterator : std::iterator<std::bidirectional_iterator_tag, T1>
    {
    private:
		Map2<T1, T2>* tree_;
		Node* object_;
	public:
		Iterator() : object_(nullptr), tree_(nullptr) {
		}
		Iterator(const Iterator& other) : object_(other.object_), tree_(other.tree_){
		}
		Iterator(Node* value, Map2<T1, T2>* tree) : object_(value), tree_(tree) {
		}
		Node* operator->() {
			return object_;
		}
		Iterator& operator++() {
			if (object_ == tree_->FindMax()) ++object_;
			else object_ = *(++find(this->tree_->list_of_nodes_.begin(), this->tree_->list_of_nodes_.end(), this->object_));
			return *this;
		}
		Iterator& operator=(const Iterator& other) {
			object_ = other.object_;
			tree_ = other.tree_;
			return *this;
		}
		Iterator& operator++(T1) {
			if (object_ == tree_->FindMax()) ++object_;
			else object_ = *(++find(this->tree_->list_of_nodes_.begin(), this->tree_->list_of_nodes_.end(), this->object_));
			return *this;
		}
		Iterator& operator-- () {
            if (object_ == tree_->FindMax() + 1) --object_;
			else object_ = *(--find(this->tree_->list_of_nodes_.begin(), this->tree_->list_of_nodes_.end(), this->object_));
			return *this;
		}
		Iterator& operator--(T1) {
			if (object_ == tree_->FindMax() + 1) --object_;
			else object_ = *(--find(this->tree_->list_of_nodes_.begin(), this->tree_->list_of_nodes_.end(), this->object_));
			return *this;
		}
		T2& operator*() {
			return object_->data_.second;
		}
		T2 operator*() const {
			return object_->data_.second;
		}
		bool operator==(const Iterator& other) {
			return (object_ == other.object_);
		}
		bool operator!=(Iterator& other) {
			return !(object_ == other.object_);	
		}
	};
    Iterator begin() {
	    return Iterator(this->FindMin(), this);
    }
    Iterator end() {
	    return Iterator(this->FindMax() + 1, this);
    }

};
---------------------------------------
#include "map1.h"

    template <typename T1, typename T2>
    class Map1<T1, T2>::Node
    {
    public:
        pair<T1, T2> data_;
        Node* left_;
        Node* right_;
        Node* parent_;
        Node(const pair<T1, T2>& data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) : data_(data), left_(left), right_(right), parent_(parent) {}
    };

    template <typename T1, typename T2>
    typename Map1<T1, T2>::Node* Map1<T1, T2>::Insert_(const pair<T1, T2>& data, Node* temp, Node* parent)
    {
        if (!temp) {
            temp = new Node(data, parent);
            if (parent)
            if (parent->data_.first > data.first) parent->left_ = temp;
                else parent->right_ = temp;
            if (!root_)
                root_ = temp;
            ++size_;
        }
        else {
            parent = temp;
            if (data.first <= temp->data_.first)
                temp->left_ = Insert_(data, temp->left_, parent);
            else
                temp->right_ = Insert_(data, temp->right_, parent);
        }
        return temp;
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::Clear_(Node* temp)
    {
        if (temp) {
            Clear_(temp->left_);
            Clear_(temp->right_);
            delete temp;
        }
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::GetLeaves_(Node* temp, vector<pair<T1, T2>>& answer)
    {
        if (!temp->left_ && !temp->right_)
        {
            answer.push_back(temp->data_);
        }
        if (temp->right_) GetLeaves_(temp->right_, answer);
        if (temp->left_) GetLeaves_(temp->left_, answer);
        
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::Print_(Node* temp)
    {
        if (temp) {
            Print_(temp->left_);
            cout << temp->data_.second << ' ';
            Print_(temp->right_);
        }
    }

    template <typename T1, typename T2>
    typename Map1<T1, T2>::Node* Map1<T1, T2>::Next(Node* temp)
    {
        if (temp->right_) {
            temp = temp->right_;
            while (temp->left_)
                temp = temp->left_;
        }
        else if (temp->parent_)
        {
            Node* temp1 = temp->parent_;
            while (temp->data_.first >= temp1->data_.first)
            temp1 = temp1->parent_;
            temp = temp1;
        } else return nullptr;
        return temp;
    }

    template <typename T1, typename T2>
    typename Map1<T1, T2>::Node* Map1<T1, T2>::Previous(Node* temp)
    {
        if (temp->left_) {
            temp = temp->left_;
            while (temp->right_)
                temp = temp->right_;
        }
        else if (temp->parent_)
        {
            Node* temp1 = temp->parent_;
            while (temp->data_.first <= temp1->data_.first)
            temp1 = temp1->parent_;
            temp = temp1;
        } else return nullptr;
        return temp;
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::CopyTree(Node* temp)
    {
        if (!temp)
            return;
        Insert(temp->data_);
        CopyTree(temp->left_);
        CopyTree(temp->right_);
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::LeftOrRightParent(Node* temp, Node* value)
    {
        if (temp->parent_->data_.first >= temp->data_.first)
            temp->parent_->left_ = value;
        else
            temp->parent_->right_ = value;
    }

    template <typename T1, typename T2>
    typename Map1<T1, T2>::Node* Map1<T1, T2>::Find_(const T1& key, Node* temp)
    {
        if (!temp)
            return temp;
        if (key == temp->data_.first)
            return temp;
        else if (key < temp->data_.first)
            Find_(key, temp->left_);
        else if (key > temp->data_.first)
            Find_(key, temp->right_);
        return root_;
    }

    template <typename T1, typename T2>
    Map1<T1, T2>::Map1() : root_(nullptr), size_(0) {}

    template <typename T1, typename T2>
    Map1<T1, T2>::Map1(Map1<T1, T2>&& other)
    {
        root_ = other.root_;
        size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0;
    }

    template <typename T1, typename T2>
    Map1<T1, T2>::Map1(const Map1<T1, T2>& other)
    {
        root_ = nullptr;
        size_ = 0;
        CopyTree(other.root_);
    }

    template <typename T1, typename T2>
    Map1<T1, T2>::~Map1()
    {
        Clear();
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::Insert(const pair<T1, T2>& data)
    {
        Insert_(data, root_, nullptr);
    }

    template <typename T1, typename T2>
    T2& Map1<T1, T2>::operator[](const T1& key)
    {
        if (Node* temp = Find_(key, root_))
            return temp->data_.second;
        else {
            throw 1;
        }
    }

    template <typename T1, typename T2>
    T2 Map1<T1, T2>::operator[](const T1& key) const
    {
        if (Node* temp = Find_(key, root_))
            return temp->data_.second;
        else {
            throw 1;
        }
    }

    template <typename T1, typename T2>
    Map1<T1, T2>& Map1<T1, T2>::operator=(Map1<T1, T2>&& other)
    {
        Clear();
        root_ = other.root_;
        size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0;
        return *this;
    }

    template <typename T1, typename T2>
    Map1<T1, T2>& Map1<T1, T2>::operator=(const Map1<T1, T2>& other)
    {
        Clear();
        CopyTree(other->root_);
        return *this;
    }

    template <typename T1, typename T2>
    bool Map1<T1, T2>::Remove(const T1& key)
    {
        auto temp = Find_(key, root_);
        if (!temp)
            return false;
        if (temp->left_ == temp->right_ && temp->right_ == nullptr && temp != root_) {
            LeftOrRightParent(temp, nullptr);
            delete temp;
        }
        else if (temp->left_ && !temp->right_ && temp != root_) {
            LeftOrRightParent(temp, temp->left_);
            temp->left_->parent_ = temp->parent_;
            delete temp;
        }
        else if (!temp->left_ && temp->right_ && temp != root_) {
            LeftOrRightParent(temp, temp->right_);
            temp->right_->parent_ = temp->parent_;
            delete temp;
        }
        else if (size_ > 1)
        {
            Node* subst;
            if ((subst = Next(temp)) || (subst = Previous(temp))) {
                T1 KeyCopy = subst->data_.first;
                temp->data_.second = subst->data_.second;
                Remove(subst->data_.first);
                temp->data_.first = KeyCopy;
                ++size_;
            }
        }
        else
        {
            delete temp;
            root_ = nullptr;
        }
        --size_;
        return true;
    }

    template <typename T1, typename T2>
    void Map1<T1, T2>::Print()
    {
        cout << size_ << " | ";
        Print_(root_);
        cout << endl;
    }

    template <typename T1, typename T2>
    vector<pair<T1, T2>> Map1<T1, T2>::GetLeaves()
    {
        vector<pair<T1, T2>> answer;
        GetLeaves_(root_, answer);
        return answer;
    }
    
    template <typename T1, typename T2>
    void Map1<T1, T2>::Clear()
    {
        Clear_(this->root_);
        this->root_ = nullptr;
        this->size_ = 0;
    }

    template <typename T1, typename T2>
    bool Map1<T1, T2>::IsEmpty() const
    {
        return (size_ == 0);
    }

    template <typename T1, typename T2>
    size_t Map1<T1, T2>::GetSize() const
    {
        return size_;
    }
--------------------------------------------------
#ifndef _MAP_H_
#define _MAP_H_
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
using std::pair;
using std::vector;
using std::cout;
using std::endl;
template <typename T1, typename T2>
class Map1
{
protected: 
class Node;
private:
    
    Node* root_;
    size_t size_;

    Node* Insert_(const pair<T1, T2>&, Node*, Node*);
    void Clear_(Node*);
	void GetLeaves_(Node*, vector<pair<T1, T2>>&);
    void Print_(Node*);
 	static Node* Next(Node*);
    Node* Previous(Node*);
    void CopyTree(Node*);
    void LeftOrRightParent(Node*, Node*);
    Node* Find_(const T1&, Node*);
	Node* FindMin()
	{
		Node* temp = root_;
		while (temp->left_)
		temp = temp->left_;
		return temp;
	}
	Node* FindMax()
	{
		Node* temp = root_;
		while (temp->right_)
		temp = temp->right_;
		return temp;
	}

public:
    Map1();
    Map1(Map1<T1, T2>&&);
    Map1(const Map1<T1, T2>&);
    ~Map1();
    void Insert(const pair<T1, T2>&);
    T2& operator[](const T1&);
    T2 operator[](const T1&) const;
    Map1<T1, T2>& operator=(Map1<T1, T2>&&);
    Map1<T1, T2>& operator=(const Map1<T1, T2>&);
    bool Remove(const T1&);
    void Print();
    void Clear();
	vector<pair<T1, T2>> GetLeaves();
    bool IsEmpty() const;
    size_t GetSize() const;

    class Iterator : std::iterator<std::bidirectional_iterator_tag, T1>
    {
    private:
		Map1<T1, T2>* tree_;
		Node* object_;
	public:
		Iterator() : object_(nullptr), tree_(nullptr) {
		}
		Iterator(const Iterator& other) : object_(other.object_), tree_(other.tree_){
		}
		Iterator(Node* value, Map1<T1, T2>* tree) : object_(value), tree_(tree) {
		}
		Node* operator->() {
			return object_;
		}
		Iterator& operator++() {
			if (object_ == tree_->FindMax())
				++object_;
			else
				object_ = tree_->Next(object_);
			return *this;
		}
		Iterator& operator=(const Iterator& other) {
			object_ = other.object_;
			tree_ = other.tree_;
			return *this;
		}
		Iterator& operator++(T1) {
			if (object_ == tree_->FindMax())
				++object_;
			else
				object_ = tree_->Next(object_);
			return *this;
		}
		Iterator& operator-- () {
			if (object_ == tree_->FindMax() + 1)
				--object_;
			else
				object_ = tree_->Previous(object_);
			return *this;
		}
		Iterator& operator--(T1) {
				if (object_ == tree_->FindMax())
				--object_;
			else
				object_ = tree_->Previous(object_);
			return *this;
		}
		T2& operator*() {
			return object_->data_.second;
		}
		T2 operator*() const {
			return object_->data_.second;
		}
		bool operator==(const Iterator& other) {
			return (object_ == other.object_);
		}
		bool operator!=(Iterator& other) {
			return !(object_ == other.object_);	
		}
	};
    Iterator begin() {
	    return Iterator(this->FindMin(), this);
    }
    Iterator end() {
	    return Iterator(this->FindMax() + 1, this);
    }

};
#endif