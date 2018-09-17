/*================================================================
*   
*   文件名称：test.cpp
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月17日
*   描    述：两个队列的测试
*
================================================================*/


#include<iostream>
#include"list_queues.h"
#include"vector_queues.h"
int main(){
	////////////链表队列类模板的测试/////////////
	std::cout<<"下面是链表类模板的测试"<<std::endl;
    list_queues<int> lq;
	lq.push(1);
	lq.push(2);
	lq.pop();
	lq.push(4);
	lq.push(99);

	std::cout<<lq.front()<<std::endl;	
	std::cout<<lq.back()<<std::endl;

	std::cout<<lq.size()<<std::endl;
	lq.clear();
	std::cout<<lq.size()<<std::endl;
	if(lq.empty()){
		std::cout<<"队列为空！"<<std::endl;
	}
	////////////顺序表队列类模板的测试//////////
	std::cout<<"下面是顺序表队列类模板的测试"<<std::endl;
	vector_queues<int> vq;
	vq.push(1);
	vq.push(2);
	vq.pop();
	vq.push(4);
	vq.push(99);

	std::cout<<vq.front()<<std::endl;	
	std::cout<<vq.back()<<std::endl;

	std::cout<<vq.size()<<std::endl;
	vq.clear();
	std::cout<<vq.size()<<std::endl;
	if(vq.empty()){
		std::cout<<"队列为空！"<<std::endl;
	}

    
   
    
    
    return 0;
}
