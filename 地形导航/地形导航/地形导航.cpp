#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

bool isPeak(int grid[64][64], int r , int c);

int main(void){
	int nrows,ncols; //定义行数和列数
	int map[64][64];

	string filename; //定义文件名
	ifstream file;

	cout<<"请输入文件名: \n";
	cin>>filename;
	file.open(filename.c_str());

	if(file.fail()){					//文件输入错误返回真
		cout<<"打开输入文件出错.\n";
		system("pause");
		exit(1);
	}

	file>>nrows>>ncols; //输出行数,和列数

	if(nrows>64 || ncols>64){
		cout<<"网格太大,调整程序.\n";
		system("pause");
		exit(1);
	}
	//从数据文件读取数据到二维数组
	for(int i=0; i<nrows-1; i++){
		for(int j=0;j<ncols; j++){
			file>>map[i][j];
		}
	}

	//判断是否是一个峰点
	for(int i=1; i<nrows-1; i++){
		for(int j=1; j<ncols-1; j++){
			if(isPeak(map, i, j)){
				cout<<"峰点出现在行:"<<i<<",列:"<<j<<endl;
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