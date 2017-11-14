#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

queue<int>q;
//priority_queue<int,vector<int>,greater<int>>q;
//优先队列的话，会按照数值大小有顺序的输出
//此处为了理解，暂时就用简单队列
int topsort() 
{
	//Searching the zero-indegree vertex
	for (int i=1;i<=n;i++) 
	{
		if(indegree[i]==0) 
		{
			q.push(i);
		}
	}

	int temp;
	//While the queue is not empty, do the following sort process
	while (!q.empty()) 
	{
		//To pop the front vertex in the queue and print it
		temp=q.front(); //如果是优先队列，这里可以是top()
		printf("%d->",temp);
		q.pop();

		//Refresh the indegree of the related vertices
		for (int i=1;i<=n;i++) //遍历从temp出发的每一条边，入度--
		{
			if (map[temp][i]!=0) 
			{
				indegree[i]--;
				if (indegree[i]==0) 
					q.push(i);
			}
		}
	}
}








