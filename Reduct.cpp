#include<iostream>
using namespace std;
class Reduct{
// Լ����,�������顢������������
// ������ΪԼ�򡢳���ΪԼ�򳤶�
public:
	int length;//Լ�򳤶�
    int* attribute;//Լ���а��������ԣ�Ϊһ�������飩
    Reduct(){
    	length=0;
    	attribute=NULL;
	}
    Reduct(int num_attr,const int len){//���캯����������߱������Ը�����Լ�򳤶�
		length=len;
		attribute=new int[len];
		for(int i=0;i<len;i++)
			attribute[i]=0;
    }
    ~Reduct(){
    	delete[] attribute;
	}
    Reduct(const class Reduct& Red){
    	length=Red.length;
    	attribute=Red.attribute;
	}
};
    
