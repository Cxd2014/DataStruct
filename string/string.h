/* 串的基本操作 */
#define ERROR -1
#define TRUE  1

typedef struct{
	char *ch;    //若是非空串，则按串长分配存储区，否则 ch 为 NULL   
	int length;  //串的长度
}QString;

/* 串的初始化 成功返回串的指针，失败返回 NULL*/
QString *InitQString(char *s);

/* 打印串中的字符 无返回值*/
void PrintQString(QString *str);

/* 清空字符串 无返回值 */
void ClearQString(QString *str);

/* 将 str2 复制到 str1 后面 成功返回 TRUE，失败返回 ERROR*/
int CopyQString(QString *str1,QString *str2);

/* 删除 str 中第pos个字符后的长度为len的子串 成功返回 TRUE 失败返回 ERROR */
int DeleteQString(QString *str,int pos,int len);

/* 在 pos 个字符后插入字符串s 成功返回 TRUE 失败返回 ERROR*/
int InsertQString(QString *str,int pos,char *s);

/* 比较串 若 str1>str2则返回值>0 若 str1 == str2则返回值=0 若str1<str2则返回值<0*/
int CompareQString(QString *str1,QString *str2);

/* 取子串函数 成功返回串 str 的第 pos 个字符起长度为 len 的子串，失败返回 NULL */
QString *MidQString(QString *str,int pos,int len);

/* 查找串str中第pos个位置后的字符串S，成功返回子串 S 在主串中的位置，若不存在则返回ERROR */
int IndexQString(QString *str,char *S,int pos);

/* 串替换 将串 str 中的串 s 替换为串 t 成功返回TRUE 失败返回 ERROR */
int ReplaceQString(QString *str,char *s,char *t);

/* KMP算法实现字符串查找 */
//参考 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
int KMPIndexQString(QString *str,char *s,int pos);