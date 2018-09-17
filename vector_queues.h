/*================================================================
*
*   文件名称：vector_queues.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月17日
*   描    述：顺序表实现的队列
*   注    意：模板类声明和实现一般只能放在类中实现
*
================================================================*/


#ifndef _VECTOR_STACKS_H_
#define _VECTOR_STACKS_H_
#include<cstring>
#include<iostream>
template <class T>
class vector_queues{
	private:
		T* array;
		int len;
		int cap;
	public:
		//无参构造函数，栈的长度默认
		vector_queues(){
			len=0;
			cap=100;
			array=new T[cap];
		}
		//用户传入容器大小的带参构造函数
		vector_queues(int cap):cap(cap){
			len=0;
			array=new T[cap];
		}
		//析构函数
		~vector_queues(){
			delete[] array;
		}
		//向队列尾部插入
		void push(const T& data){
			if(len==cap) return;
			array[len]=data;
			++len;
		}
		//删除队列第一个元素
		void pop(){
			if(empty()) return;
			for(int i=0;i<len-1;i++){
				array[i]=array[i+1];
			}
			--len;
			
		}
		//返回队列最后一个元素
		T& back(){
			if(empty()) throw 1;
			return array[len-1];

		}
		//返回队列第一个元素
		T& front() const{
			if(empty()) throw 1;
			return array[0];
		}
		//判断容器是否为空
		bool empty() const{
			return !len;
		}
		//判断容器数据长度
		int size() const{
			return len;
		}
		//清空容器
		void clear(){
			len=0;
		}
		
};





#endif
