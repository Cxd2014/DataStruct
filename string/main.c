#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char const *argv[])
{
	int err;
	QString *str1;
	QString *str2;
	QString *mid;

	str1 = InitQString("photoShop");
	str2 = InitQString(" After Effects After");
	PrintQString(str1);
	PrintQString(str2);


	err = CopyQString(str1,str2);
	if(err == ERROR)
		printf("CopyQString error\n");
	PrintQString(str1);

	mid = MidQString(str2,1,5);
	PrintQString(mid);

	err = IndexQString(str1,"After",0);
	printf("postion = %d\n",err);

	err = DeleteQString(str1,err,5);
	if(err == ERROR)
		printf("DeleteQString error\n");
	PrintQString(str1);

	InsertQString(str1,10,"After");
	PrintQString(str1);

	ReplaceQString(str1,"After","cxd");
	PrintQString(str1);

	err = KMPIndexQString(str1,"Eff",0);
	printf("postion = %d\n",err);

	ClearQString(mid);
	ClearQString(str2);
	ClearQString(str1);
	return 0;
}