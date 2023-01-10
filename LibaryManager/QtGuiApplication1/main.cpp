#include "page_preview.h"
#include <QtWidgets/QApplication>
#include "Global.h"
#include "Db.h"
#include "console.h"
#include"Borrowed_Manager.h"
#include"pg_LoginWidget.h"
Db* db = nullptr;

using namespace std;

vector<int>r;

void dfs(int x, vector<vector<int>>& Link)
{
	if (x == 0)
		return;
	dfs(Link[x][0], Link);
	r.push_back(x);
	dfs(Link[x][1], Link);
}

int main(int argc, char *argv[])
{
	vector<vector<int>>res{ {1,2,3},{2,4,0},{3,0,0},{4,0,0} };
	vector<vector<int>>link(4 + 1, vector<int>(2, 0));
	vector<int>q(5, 1);
	for (int i = 0; i < res.size(); i++)
	{
		link[res[i][0]][0] = res[i][1];
		link[res[i][0]][1] = res[i][2];
	}

	dfs(1, link);

	QApplication a(argc, argv);
	db = new Db();
	//page_preview w;
	//Borrowed_Manager w;
	//console w;
	pg_LoginWidget w;
	w.show();
	
	return a.exec();
}
