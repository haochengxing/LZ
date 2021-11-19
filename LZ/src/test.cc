#include"LZL-zip.h"
#include <windows.h>
#include <string>

int main(){

	char buf[1000] = {0};
	int count = 1000;
	GetCurrentDirectory(1000, (LPTSTR)buf); //得到当前工作路径
	//std::cout << buf << std::endl;
	wprintf(L"%s\n", buf);
	std::string path;
	for (size_t i = 0; i < count; i++)
	{
		if (buf[i]!='\0')
		{
			path.push_back(buf[i]);
		}
		
	}
	//path.append(buf);
	path.append("\\TestCompress.txt");

	//(buf + "/TestCompress.txt");

    //Please create this file by yourself;
    LZ_zip::LZL_zip zip(path);
    zip.encode();
    zip.decode();
}