#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
class matrix{
public:	
	int line;//�������� 
	int row;//�������� 
	MatrixXd mat;//����
	matrix(){
		line=0;
		row=0;
	}
	matrix(int x,int y){//�����캯�� 
		if(x>0&&y>0){
			line=x;
			row=y;
		}
		mat.resize(x,y);
	}
	matrix(const class matrix& m){
		line=m.line;
		row=m.row;
		mat=m.mat;
	}
	
	void deleteLine(int select_line){
		//����:ָ���е��±����� 
		//����ɾ�������о�����ָ������ 
		//�������
		MatrixXd tempMat;
		line=line-1;
		tempMat.resize(line,row);
		int j=0;
		for(int i=0;i<=line;i++)
			if(i==select_line)
				continue;
			else tempMat.row(j++)=mat.row(i);
		this->mat=tempMat;
	}
	void deleteRow(int select_row){
		//����:ָ���е��±����� 
		//����ɾ�������о�����ָ������ 
		//�������
		MatrixXd tempMat;
		row=row-1;
		tempMat.resize(line,row);
		int j=0;
		for(int i=0;i<=row;i++)
			if(i==select_row)
				continue;
			else tempMat.col(j++)=mat.col(i);
		this->mat=tempMat;
	}
	void deleteDisjunction(int select_attribute){
		//���룺ָ�����Ե�DF�±�����
		//�����������еľ���洢�ĺ��и����Ե���ȡʽ(�Ӻ���ǰ)ɾ��
		//������� 
		int time=0;
		for(int i=1;i<line;i++)
			if(mat(i,select_attribute)!=0)
				time++;
		MatrixXd tempMat(line-time,row);
		int j=0;
		for(int i=1;i<line;i++){
			if(mat(i,select_attribute)==0)
				tempMat.row(j++)=mat.row(i);
		}
		line=line-time; 
		mat=tempMat;
	}
	bool deleteAttribute(int select_attribute){
		//���룺ָ�����Ե�DF�±�����
		//�������ڶ����еľ���洢�ĺ��и����Ե���ȡʽ���д���ɾ�������ԣ� 
		//������Ƿ��пյ���ȡʽ ��flag=true��ʾ���п���ȡʽ�������ʾû�� 
		bool flag=false;
		for(int i=1;i<line;i++){
			if(mat(i,select_attribute)!=0){
				mat(i,select_attribute)=0;
				for(int j=0;j<row;j++){ 
					flag=flag|(bool)mat(i,j);//ֻҪ��һ��Ϊ1����ô�ͱ�������ȡʽ��Ϊ�� 
					if(flag) break;
				}
				if(!flag){//��ǰ��ȡʽΪ�� 
					flag=true;
					return flag;
				} 
			}
		}
	}
};
//int main()
//{
//    matrix m(2,2);
//    m.mat(0,0) = 3;
//    m.mat(1,0) = 2.5;
//   	m.mat(0,1) = -1;
//    m.mat(1,1) = m.mat(1,0) + m.mat(0,1);
//    std::cout <<"mat\n"<< m.mat << std::endl;
//    std::cout <<"mat\n"<< m.mat << std::endl;
//    std::cout<< "mat block\n"<<m.mat.block(0,0,1,1)<<std::endl;
//    std::cout<< "mat col\n"<<m.mat.col(1)<<std::endl;
//    std::cout<<"mat row 0\n"<<m.mat.row(0)<<std::endl;
////    m.mat.row(0)=m.mat.row(1);
////    std::cout<< "mat row 0\n"<<m.mat.row(0)<<std::endl;
////    m.deleteLine(0);
////    std::cout <<"mat\n"<< m.mat << std::endl;
//	m.deleteRow(0);
//	std::cout <<"mat\n"<< m.mat << std::endl;
//    return 0;
//}

