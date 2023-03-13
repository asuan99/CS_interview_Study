# CS_Study 자료구조(3월 9일)

# 자료구조

## 트라이(Trie)란 무엇인가요?

- 자료 조사
    
    **트라이(Trie)**
    
     문자열을 저장하고 검색하는 자료구조 중 하나로, 문자열 검색을 빠르게 하기위한 이진 검색 트리 구조이다. 
    
    - 예시
        
        there, their, answer, any, bye가 저장된 트라이 구조
        
        ![Untitled](CS_Study%20%E1%84%8C%E1%85%A1%E1%84%85%E1%85%AD%E1%84%80%E1%85%AE%E1%84%8C%E1%85%A9(3%E1%84%8B%E1%85%AF%E1%86%AF%209%E1%84%8B%E1%85%B5%E1%86%AF)%200df0edb3cd724eb097b8c5e48e6945f2/Untitled.png)
        
        문자열 탐색 과정
        
        1. root의 child부터 시작한다.
        2. child에 첫번째 문자가 저장되어 있는지 체크한다.
        3. 저장되어 있다면 해당 child로 내려간다.
        4. 다음 문자가 child에 저장되어 있을때까지 반복한다.
        5. 검색하려는 문자열의 길이가 leaf의 레벨과 딱 떨어지면 
        
        삽입 과정
        
        1. root는 비워둔다
        2. 삽입하려는 첫글자가 root의 child로 저장되어있으면 해당 child를 따라 내려간다.(없으면 첫글자를 sibling으로 삽입한다.)
        3. 동일한 문자가 있을경우 그냥 다음글자로 내려가고, 동일한 문자가 없을경우 새로운 문자를 child의 sibling로 삽입한다.
        4. 맨 마지막 글자를 체크 또는 삽입할때까지 반복한다.
        
    
    트라이는 키워드 검색 외에도, 자동 완성 기능, 텍스트 압축, 유전자 정보 분석 등에서도 활용됩니다. 
    
    트라이의 단점으로는, 저장되는 문자열의 길이가 길어질수록 트리의 깊이가 깊어지며 메모리 사용량이 증가할 수 있다는 것이 있습니다.
    
- 답변
    
    문자열을 저장하는 이진 검색 트리 구조로 문자열 탐색이 빠르다는 특징이 있다. 문자열의 최대길이가 M이라 가정하였을때 트라이의 탐색 시간은 O(M)으로 기존의 트리(O(Mlogn))의 탐색 속도보다 빠르다. 
    
    하지만 , 문자열의 길이가 길수록 트리의 깊이가 깊어진다는 단점이 있어 편향된 트리가 만들어 질 수 있다.  
    
- 코드 (c++)
    - (1) .h
        
        ```cpp
        #pragma once
        #include <iostream>
        #include <vector>
        using namespace std;
        class Node
        {
        public:
        	char data;
        	vector<Node*> siblings;
        };
        class Trie
        {
        private:
        	Node* root = new Node;
        public:
        	void push(string str) {
        		insert(str, 0, root);
        	}
        	void insert(string str, int idx, Node* node)
        	{
        		if (idx >= str.length()) return;
        		int next = -1;
        		for (int i = 0; i < node->siblings.size(); i++) {
        			if (str[idx] == node->siblings[i]->data) {//동일한 문자가 있는 경우
        				next = i;
        				break;
        			}
        		}
        		if (next != -1)
        			insert(str, idx + 1, node->siblings[next]);
        		else//동일한 문자가 없는경우, 자식으로 추가
        		{
        			Node* newNode = new Node;
        			newNode->data = str[idx];
        			node->siblings.push_back(newNode);
        			insert(str, idx + 1, newNode);
        		}
        	}
        
        	bool search(string str)
        	{
        		return findWord(str, 0, root);
        	}
        
        	bool findWord(string str, int idx, Node* node)
        	{
        		if (!node->siblings.empty() && idx >= str.length()) return false;
        		if (idx >= str.length()) return true;
        		int next = -1;
        		for (int i = 0; i < node->siblings.size(); i++) {
        			if (str[idx] == node->siblings[i]->data) {
        				next = i;
        				break;
        			}
        		}
        		if (next != -1)//동일한 문자가 있음
        			return findWord(str, idx + 1, node->siblings[next]);
        		else//검색 실패
        			return false;
        	}
        
        	void print() {
        		order(root, 1);
        	}
        	void order(Node* node, int depth)
        	{
        		for (int i = 0; i < node->siblings.size(); i++)
        		{
        			cout << "(" << depth << ") " << node->siblings[i]->data << " ";
        			if (!node->siblings[i]->siblings.empty()) {
        				order(node->siblings[i], depth + 1);
        			}
        			else cout << endl;
        		}
        	}
        };
        ```
        
    - (2) .cpp
        
        ```cpp
        #include "header.h"
        int main(){
        	Trie* trie = new Trie;
        	trie->push("there");
        	trie->push("their");
        	trie->push("answer");
        	trie->push("any");
        	trie->push("bye");
        	trie->print();
        
        	vector<string> v{"ans","banana","answer","bye","byeyo","a"};
        	for (int i = 0; i < v.size(); i++)
        	{
        		if (trie->search(v[i])) cout << "검색 O : " << v[i] << endl;
        		else cout << "검색 X : " << v[i] << endl;
        	}
        	return 0;
        }
        ```
        
    
- Refernce
    
    Beth의 공부 블로그([트라이](https://it-and-life.tistory.com/166))
    
- 추가질문 : 긴 문자열을 저장하는 구조는 ???(조)
    
    긴 문자열을 저장하기 좋은 자료구조로는 대표적으로 B-Tree 와 접미사Tree가 있다. 하지만 두 자료구조 모두 대용량의 데이터를 저장하는데는 효과적이지만 검색속도가 트라이에 비해 느리다. 따라서 두 자료구조보다는 트라이를 압축한 구조인 **압축 트라이**를 많이 사용한다.