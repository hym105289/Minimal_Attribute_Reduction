#include<iostream>
#include "matrix.cpp"
using namespace std;
extern class Reduct reduct,MinReduct;
void CAMARDF(class matrix& DF){
//����˵�������㷨ʵ���ܽܵ���СԼ����ȡ�㷨�� 
//����:�����ڰ�����ϵ����ȡʽ��
//���:��СԼ��
//����������СԼ��ʹ����չ�ɽ��п�ȼ�֦,ʹ���������ռ�ı�����ȼ�֦ 
	class matrix Sig;
//Sig����Ĵ洢������һ��Ϊ������DT�е��±꣬
//					�ڶ���Ϊ������DF���±꣬
//					������Ϊ���Եĳ��ִ���
	computeSIG(Sig,DF);//�������Գ��ֵ�Ƶ�ʣ�������������
	int i=0;
	while ((Sig.mat(3,i)>1 && i<Sig.row)||i==0){
		//��ȼ�֦ 
		if reduct.length+1==minReduct.length
			return;
		//��ʱԼ��洢�м��������ִ��������ԣ�ʵ����Ϊ̰���㷨 
		reduct.attribute(sig_attr(1,i))=1;
		reduct.length++;
		//��ʼ��ȵݹ飬ɾ�����и�Ԫ�ص�������ȡʽ 
		class matrix tempDF=DF;
		tempDF.deleteDisjunction(Sig.mat(2,i)); 
		if(tempDF.line==0){
			if(reduct.length<minReduct.length)
				minReduct=reduct;
		}
		else{
			CAMARDF(tempDF);
		} 
		//���������֦����ȡ����ɾ����Ԫ��
		bool flag=DF.deleteAttribute(Sig.mat(2,i));
		if(flag){//������ȡʽΪ��
			reduct.attribute(Sig.mat(1,i))=0;
        	reduct.length--;
			return;
		}
		reduct.attribute(Sig.mat(1,i))=0;
    	reduct.length--;
    	i=i+1;	
	}
	
}
