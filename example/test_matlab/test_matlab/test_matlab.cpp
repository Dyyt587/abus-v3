//调用MATLAB函数绘制函数曲线
#include "stdio.h"
#include <math.h>
#include "engine.h" //添加MATLAB引擎头文件
#include <string.h>
#pragma comment(lib,"libeng.lib")
#pragma comment(lib,"libmx.lib")
#pragma comment(lib,"libmat.lib")
int main()
{
	//定义x,y数组并赋初值
	const int N = 20;
	double x[N], y[N];
	for (int i = 0; i < N; i++)
	{
		x[i] = i + 1;
		y[i] = x[i] * x[i];
	}
	Engine* ep;     //定义MATLAB引擎指针变量
	if (!(ep = engOpen(NULL))) //打开MATLAB引擎
	{
		printf("can't start MATLAB engine!");
		exit(1);
	}
	//利用MATLAB API mxCreateDoubleMatrix函数生成矩阵，即申请空间，MATLAB引擎中使用mxArray类型数据

	mxArray* xx = mxCreateDoubleMatrix(1, N, mxREAL);//1行N列，mxREAL为实双精度矩阵
	mxArray* yy = mxCreateDoubleMatrix(1, N, mxREAL);
	//mxGetPr获取指向输入、输出矩阵数据的指针
	memcpy(mxGetPr(xx), x, N * sizeof(double));//将数组 x 复制到 mxarray 数组 xx 中，即给xx数组赋值
	memcpy(mxGetPr(yy), y, N * sizeof(double));

	engPutVariable(ep, "xx", xx);//将 mxArray 数组 xx 写入到 Matlab 工作空间，命名为 xx 
	engPutVariable(ep, "yy", yy);

	engEvalString(ep, "plot(xx, yy);");//通过引擎调用MATLAB中plot(x,y)函数，绘制函数曲线
	engEvalString(ep, "xlabel('x axis');");
	engEvalString(ep, "ylabel('y axis');");
	mxDestroyArray(xx); //释放内存
	mxDestroyArray(yy);//释放内存
	printf("e");
	system("pause");
	engClose(ep);
	return 0;
}