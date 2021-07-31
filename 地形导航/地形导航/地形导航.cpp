#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

bool isPeak(int grid[64][64], int r , int c);

int main(void){
	int nrows,ncols; //��������������
	int map[64][64];

	string filename; //�����ļ���
	ifstream file;

	cout<<"�������ļ���: \n";
	cin>>filename;
	file.open(filename.c_str());

	if(file.fail()){					//�ļ�������󷵻���
		cout<<"�������ļ�����.\n";
		system("pause");
		exit(1);
	}

	file>>nrows>>ncols; //�������,������

	if(nrows>64 || ncols>64){
		cout<<"����̫��,��������.\n";
		system("pause");
		exit(1);
	}
	//�������ļ���ȡ���ݵ���ά����
	for(int i=0; i<nrows-1; i++){
		for(int j=0;j<ncols; j++){
			file>>map[i][j];
		}
	}

	//�ж��Ƿ���һ�����
	for(int i=1; i<nrows-1; i++){
		for(int j=1; j<ncols-1; j++){
			if(isPeak(map, i, j)){
				cout<<"����������:"<<i<<",��:"<<j<<endl;
			}
		}
	}
	system("pause");

	file.close();
	return 0;
}

bool isPeak(int grid[64][64], int r , int c){
	if((grid[r][c]>grid[r-1][c]&&
		grid[r][c]>grid[r+1][c]&&
		grid[r][c]>grid[r][c-1]&&
		grid[r][c]>grid[r][c+1]
		)){
			return true;
		}else{
			return false;
		}
}