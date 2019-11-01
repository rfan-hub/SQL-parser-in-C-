#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//去除尾部空格
char* rtrim(char* str)
{
	if (str == NULL || *str == '\0')
		return str;
	int len = strlen(str);
	char* p = str + len - 1;
	while (p >= str && ((*p) == ' ' || (*p) == '\r' || (*p) == '\n' || (*p) == '\t')) {
		*p = '\0';
		p--;
	}
	return str;
}

//去除首部空格
char* ltrim(char* str) {
	if (str == NULL || *str == '\0')
		return str;
	int len = 0;
	char* p = str;
	while (*p != '\0' && ((*p) == ' ' || (*p) == '\r' || (*p) == '\n' || (*p) == '\t')) {
		++p;
		++len;
	}
	memmove(str, p, strlen(str) - len + 1);
	return str;
}

//去除首尾空格
char* c_trim(char* str)
{
	str = rtrim(str);
	str = ltrim(str);
	return str;
}

char* c_replace(char* src, char a, char* t)
{
	int flag = 0;
	while (*src != '\0') {
		if (*src != a) {
			flag = 0;
			*t = *src;
			t++;
			src++;
		}
		else {
			flag++;
			src++;
			if (flag == 1) {
				*t++ = ' ';
			}
		}

	}
	*t = '\0';
	return t;
}

char* replaceall(char* src, char* t)
{
	c_replace(src, ' ', t);
	c_replace(t, '	', t);
	return t;
}

char* c_strlwr(char* src)
{
	char* p = src;
	while (*p != '\0') {
		if (*p >= 'A' && *p <= 'Z') {
			*p += 32;
			p++;
		}
		else
			p++;
	}
	return src;
}

char* c_preDo(char* str, char* t) 
{
	replaceall(str, t);
	c_strlwr(t);
	c_trim(t);
	return t;
}

int main()
{
	char a[] = "SELECT			c1,c2,c3 FROM table1   WHERE id > 1 and id < 100";
	char p[100];
	c_preDo(a, p);
	printf("预处理之前:\n%s\n", a);
	printf("预处理之后:\n%s\n", p);
	return 0;
}