#if 0
#include<iostream>
using namespace std;
using ElemType = char;
class List
{
private:
struct LNode {
	ElemType date;
	LNode* next = NULL;
};
LNode* head;
public:
	List():head{new LNode{}}{}
	LNode* locate(const int i)const {
		if (i < 0) return nullptr;
		LNode* p{ head };
		auto j{ 0 };
		while (p && j < i) {
			p = p->next;
			j++;
		}
		return p;
	}
	bool insert(const int i, const ElemType& e) {
		LNode* p = locate(i - 1);
		if (p) {
			LNode* q = new LNode;
			if (!q) return false;
			q->date = e;
			q->next = p->next;
			p->next = q;
			return true;
		}
		return false;
	}
	bool erase(const int i) {
		LNode* p = locate(i - 1);
		if (p) {
			LNode* q = p->next;
			p->next = q->next;
			delete q;
			return true;
		}
		return false;
	}
	void push_back(const ElemType& e) {
		LNode* p = locate(size());		
		LNode* q = new LNode;
		q->date = e;
		p->next = q;
		q->next = NULL;		
	}
	void pop_back() {
		LNode* p = locate(size()-1);	
		p->next = NULL;
	}
	bool push_front(const ElemType& e) {
		LNode* p = new LNode;
		if (!p) return false;
		p->date = e;
		p->next = head->next;
		head->next = p;
	}
	bool pop_front() {
		if (!head->next) return false;
		LNode* p = head->next;
		head->next = p->next;
		delete p;
	}
	bool get(const int i, ElemType& e)const {
		LNode* p = locate(i);
		if (p) {
			e = p->date;
			return true;
		}
		return false;
	}
	bool set(const int i, const ElemType e) {
		LNode* p = locate(i);
		if (p) {
			p->date = e;
			return true;
		}
		return false;
	}
	int size() const {
		LNode* p{ head };
		auto i{ 0 };
		p = p->next;
		while (p) {
			i++;
			p = p->next;
		}
		return i;
	}


};
void print(const List& v) {
	ElemType e;
	for (auto i = 1; i <= v.size(); i++) {
		v.get(i, e);
		cout << e << "\t";
	}
	cout << endl;
}
int main() {
	List v;
	v.push_front ( 'a');
	v.push_front ( 'b');
	v.push_front ( 'c');
	print(v);
	v.insert(1, 'd');
	print(v);
	ElemType e;
	v.get(1, e);
	cout << e << endl;
	v.set(1, 'f');
	print(v);
	v.push_back('z');
	print(v);
	v.pop_back();
	print(v);
}

#endif