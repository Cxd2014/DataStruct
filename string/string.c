#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* 串的初始化 成功返回串的指针，失败返回 NULL*/
QString *InitQString(char *s)
{
	int i = 0;
	int j = 0;
	QString *str;

	str = (QString *)malloc(sizeof(QString));
	if(str == NULL)
		return NULL;

	while(*(s+i) != '\0') //求字符串的长度
		i++;

	if(i == 0){ //判断字符串是否为空
		str->ch = NULL;
		str->length = 0;
	}else{
		str->ch = (char *)malloc(i*sizeof(char));
		if(str->ch == NULL)
			return NULL;

		for(j = 0;j < i;j++)
			str->ch[j] = *(s+j);
		str->length = i;
	}
	return str;
}

/* 打印串中的字符 无返回值*/
void PrintQString(QString *str)
{
	int i;
	for(i = 0;i < str->length;i++)
		printf("%c",str->ch[i]);
	printf("\n");
}

/* 清空字符串 无返回值 */
void ClearQString(QString *str)
{
	if(str->ch != NULL){
		free(str->ch);
		str->ch = NULL;
	}
	str->length = 0;
}

/* 将 str2 复制到 str1 后面 成功返回 str1 的指针，失败返回 NULL*/
int CopyQString(QString *str1,QString *str2)
{
	int i;

	str1->ch = realloc(str1->ch,(sizeof(char)*(str2->length + str1->length)));
	if(str1->ch == NULL)
		return ERROR;

	for(i = 0;i<(str2->length);i++)
		str1->ch[str1->length + i] = str2->ch[i];

	str1->length = str1->length + str2->length;
	return TRUE;
}

/* 删除 str 中第pos个字符后的长度为len的子串 成功返回 TRUE 失败返回 ERROR */
int DeleteQString(QString *str,int pos,int len)
{
	int i;
	if(pos >= str->length || len>(str->length-pos))
		return ERROR;
	i = pos + len;
	while(i < str->length){
		str->ch[i-len] = str->ch[i];
		i++;
	}
	str->length = str->length - len;
	str->ch = (char *)realloc(str->ch,sizeof(char)*(str->length));//重新分配内存
	if(str->ch == NULL)
		return ERROR;
	return TRUE;
}

/* 在 pos 个字符后插入字符串s 成功返回 TRUE 失败返回 ERROR*/
int InsertQString(QString *str,int pos,char *s)
{
	int len=0;
	int j = 0;
	int l = str->length;

	if(pos > str->length)
		return ERROR;
	while(*(s+len) != '\0') //求字符串的长度
		len++;

	str->ch = (char *)realloc(str->ch,sizeof(char)*(str->length + len));//重新分配内存
	if(str->ch == NULL)
		return ERROR;

	/* 将pos后面的字符移到最后面 */
	for(j = (str->length + len);j >= (pos+len);j--)
		str->ch[j] = str->ch[l--];

	/* 插入字符串到pos位置 */
	for(j = 0;j < len;j++)
		str->ch[pos+j] = *(s+j);
	
	str->length = str->length + len;
	return TRUE;
}

/* 若 str1>str2则返回值>0 若 str1 == str2则返回值=0 若str1<str2则返回值<0*/
int CompareQString(QString *str1,QString *str2)
{
	int i;
	for(i = 0; i<(str1->length) && i<(str2->length); i++)
		if(str1->ch[i] != str2->ch[i])
			return (str1->ch[i] - str2->ch[i]);
	return (str1->length - str2->length);
}

/* 成功返回串 str 的第 pos 个字符起长度为 len 的子串 mid，失败返回 NULL */
QString *MidQString(QString *str,int pos,int len)
{
	if(pos<0 || pos>=str->length || len<=0 || len>(str->length-pos))
		return NULL;

	QString *mid;
	int i; 

	mid = (QString *)malloc(sizeof(QString));
	if(mid == NULL)
		return NULL;

	mid->ch = (char *)malloc(sizeof(char)*len);
	if(mid->ch == NULL)
		return NULL;

	for(i = 0;i < len;i++)
		mid->ch[i] = str->ch[pos+i];
	mid->length = len;
	return mid;
}

/* 查找串str中第pos个位置后的字符串S，成功返回子串 S 在主串中的位置，若不存在则返回-1 */
int IndexQString(QString *str,char *S,int pos)
{
	int i = pos;
	int j = 0;
	int len = 0;

	while(*(S+len) != '\0') //求字符串的长度
		len++;

	if(*S == '\0' || str->length == 0)
		return ERROR;

	while(i < (str->length)){
		if(str->ch[i] == *(S+j)){
			i++;
			j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
		if(j == len) //找到了
			return (i-len);
	} 
	return ERROR;
}

/* 串替换 将串 str 中的串 s 替换为串 t 成功返回TRUE 失败返回 ERROR */
int ReplaceQString(QString *str,char *s,char *t)
{
	int pos = 0;
	int i = 0;
	int len = 0;

	while(*(s+len) != '\0') //求字符串的长度
		len++;

	pos = IndexQString(str,s,pos);
	while(pos != ERROR){
		DeleteQString(str,pos,len); //先删除
		InsertQString(str,pos,t);   //在插入
		pos = IndexQString(str,s,pos);
	}
	return TRUE;
}

/* 求模式串 T 的 next 函数值，存入数组 next 中 */
void GetNext(QString *str,int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while(i < str->length){
		if(j == 0 || str->ch[i] == str->ch[j]){
			i++;
			j++;
			if(str->ch[i] != str->ch[j])
				next[i] = j;
			else
				next[i] == next[j];
		}else
			j = next[j];
	}
	/*
	for(i=0;i<(str->length);i++)
		printf("%d ",next[i]);
	printf("\n");
	*/
}

/* KMP算法实现字符串查找 */
// 参考 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
int KMPIndexQString(QString *str,char *s,int pos)
{
	QString *T;
	int *next;
	int i = pos;
	int j = 1;
	T = InitQString(s);
	InsertQString(T,0," ");
	InsertQString(str,0," ");

	next = (int *)malloc((T->length)*sizeof(int));
	if(next == NULL)
		return ERROR;
	GetNext(T,next); //得到模式串的 next 函数
	
	while(i<=(str->length-1) && j<=(T->length-1)){
		if(j==0 || str->ch[i]==T->ch[j]){
			i++;
			j++;
		}else
			j = next[j];
	}
	if(j > T->length - 1)
		return (i - T->length);
	else
		return ERROR;
}