#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

//0：终端输出   1：文件输出 
#define Fout 0

#if !Fout
#define fout cout
#endif



int main(){
	cout<<"请输入多重指针的个数：";
	int n;
	cin>>n;
#if Fout
	ofstream fout;
	string fname = "./Test_ManyPointer.cpp";
	fout.open(fname.c_str());
#else
	cout<<"//以下是完整代码："<<endl;
#endif
	fout<<"#include<iostream>"<<endl
		<<"using namespace std;"<<endl
#if Fout
		<<endl
#endif
		<<"int main(){"<<endl
		<<"\t"<<"int n=10;"<<endl
		<<"\t"<<"int *p0;"<<endl
		<<"\t"<<"p0 = &n;"<<endl;
	fout<<"\t"<<"int";
	for(int i=1;i<=n;i++){
		fout<<" ";
		for(int j=0;j<i;j++)
			fout<<"*";
		fout<<"*p"<<i<<",";
	}
	fout<<" nu;"<<endl;
	for(int i=0;i<n;i++){
	    fout<<"\t"<<"p"<<i+1<<" = &p"<<i<<";"<<endl;
	}
	fout<<"\t"<<"cout<<\"通过\"<<"<<n<<"<<\"重指针，访问到 n = \"<< ";
	for(int j=0;j<=n;j++)
		fout<<"*";
	fout<<"p"<<n<<";"<<endl;
	fout<<"\t"<<"return 0;"<<endl<<"}";
#if Fout
	fout.close();
	cout<<"note: 使用命令 “g++ "<<fname<<"” 即可进行编译！";
#endif
	return 0;
}
