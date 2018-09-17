/*================================================================
*   
*   文件名称：list_queues.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月17日
*   描    述：C++中通过链表的队列的实现
*   注    意：模板类声明和实现一般只能放在类中实现
*
================================================================*/


#ifndef _LIST_QUEUES_H_
#define _LIST_QUEUES_H_

#include<iostream>

template <typename T>

class list_queues{
	private:
		typedef struct _Node{
			T data;
			_Node* next;
		}Node;
		Node* head;
		Node* tail;
		int cap;
		int len;
	
	public:
		//没有容量限制栈的构造函数
		list_queues():cap(-1),len(0){
			head=new Node;
			tail=head;
			head->next=NULL;
		}
		//有容量限制栈的构造函数
		list_queues(int cap):cap(cap),len(0){
			head=new Node;
			tail=head;
			head->next=NULL;
		}

		//析构函数
		~list_queues(){
			while(head!=NULL){
				Node* temp=head->next;
				delete temp;
				head=temp;
			}		
		}

		//清空栈
		void clear(){
			Node* temp=head->next;
			while(temp!=NULL){
				Node* buf=temp->next;
				delete temp;
				temp=buf;				
			}
			head->next=NULL;
			tail=head;
			len=0;
		}
		//进入队列
		void push(const T& data_buf){
			if(len==cap) return;
			Node* temp=new Node;
			temp->data=data_buf;
			temp->next=tail->next;
			tail->next=temp;
			tail=temp;

			++len;
		}
		
		//出栈
		void pop(){
			if(empty()) return;
			Node* temp=head->next;
			head->next=temp->next;
			delete[] temp;
			--len;
		}

		//获得队头元素
		T& front() const{
			if(empty()) throw 1;
			return head->next->data;
		}
		T& back() const{
			if(empty()) throw 1;
			return tail->data;
		}

		//判断栈是否为空
		bool empty() const{
			return !head->next;
		}

		//获得栈的长度
		int size() const{
			int cnt=0;
			Node* temp=head->next;
			while(temp!=NULL){
				temp=temp->next;
				++cnt;
			}
			return cnt;
		}

		

		

};
    
    
    
    
    
#endif
