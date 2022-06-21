#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;
//=============動態紀錄卡片============= 
class Node{
  public:
  string data;
  Node* next;
};
class LinkedList{
	public:
	Node* head;
	void addLast(string data){
		if(head == NULL){
			Node* a = new Node();
			a->data = data;
			head = a;
		}else{
			Node* now = head;
			while(now->next != NULL){
				now = now->next;
			}
			Node* a = new Node();
			a->data = data;
			now->next = a;
		}
	}
	void toString(){
		Node* now = head;
		while(now != NULL){
			cout << "Node ->" << now->data <<"\n";
			now = now->next;
		}
	}
	bool hasKey(string id){
		Node* now = head;
		while(now != NULL){
			if(now->data == id){
				return true;
			}
			now = now->next;
		}
		return false;
	}
};
//======================================================================
//=============================紀錄每筆卡片錯誤次數===================== 
class Hash{
	public: 
	string key;
	int value;
};
class HashNode{
	public:
	Hash* data;
	HashNode* next;
};
class HashMap{
	public:
	HashNode* head;
	void add(string key,int value){
		if(head == NULL){
			Hash* a = new Hash();
			a->key = key;
			a->value = value;
			HashNode* b = new HashNode();
			b->data = a;
			head = b;
		}else{
			HashNode* now = head;
			while(now->next !=NULL){
				now= now->next;
			}
			Hash* a = new Hash();
			a->key = key;
			a->value = value;
			HashNode* b = new HashNode();
			b->data = a;
			now->next=b;
		}
	}
	void remove(string key){
		HashNode* now = head;
		if(head->data->key == key){
			head = head->next;
		}else{
			while(now !=NULL){
				if(now->next->data->key == key){
					HashNode* c = now->next->next;
					now->next = c;
				}
				now= now->next;
			}
		}
	}
	int getValue(string key){
		HashNode* now = head;
		while(now !=NULL){
			if(now->data->key == key)return now->data->value;
			now = now->next;
		}
		return -1;
	}
	bool hasKey(string key){
		HashNode* now = head;
		while(now !=NULL){
			if(now->data->key == key)return true;
			now = now->next;
		}
		return false;
	}
	void toString(){
		HashNode* now = head;
		while(now != NULL){
			cout << "Node: key ->" << now->data->key <<" value -> " << now->data->value <<"\n";
			now = now->next;
		}
	}
};
//===================================================================================================

	LinkedList* list = new LinkedList();
	HashMap* map = new HashMap();
int main(){
	for(int i = 0;i<10000;i++){
		stringstream ss;
		ss << i;
		list->addLast(ss.str());
	}
	
	list->toString();
}

