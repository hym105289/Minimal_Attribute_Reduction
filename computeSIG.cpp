#include<iostream>
#include"matrix.h"
using namespace std;
void computeSIG(class matrix& Sig,const class matrix& DF){
	 Sig=*(new matrix(3,DF.row));
	 Sig.mat.row(1)=DF.mat.row(1);//�洢DT������
	 for(int i=0;i<Sig.row;i++){//�������Ƶ�� 
	 	Sig.mat(2,i)=i;
	 	Sig.mat(3,i)=0;
	 	for(int j=0;j<line;j++)
	 		Sig.mat(3,i)+=DF.mat(j,i);
	 }
	 //�������Գ��ֵ�Ƶ�ʶ�����ѡ������
	 int index;
	 MatrixXd temp(3,1);
	 for(int i=0;i<row;i++){
	 	index=i;
	 	for(int j=i+1;j<row;j++){
	 		if(Sig.mat(3,index)<Sig.mat(3,j))
	 			index=j;
		 }
		 if(index!=i){
		 	temp=Sig.mat.col(index);
		 	Sig.mat.col(index)=Sig.mat.col(i);
		 	Sig.mat.col(i)=temp;
		 } 
	 } 
} 
