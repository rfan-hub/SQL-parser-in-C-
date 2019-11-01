void Pattern();       //正则函数

/*假定pattern已有如下功能：
  1.可进行正则分配的循环 ，方法设为matcher
  2.成功找到一组符合的，并返回为flag=1；函数为matcherfind 
  3.Matcherfind找到匹配的结果后，随即回matcher进行循环， 
  4.假定matchergroup（i） 的功能即为返回第i个括号里的字符串 
*/ 

int sqllength(){     //计算数据库调用文件的字节长度 
	int i=0; 
	while(sql!=EOF){   
		i++;
	} 
	return i;
}


/*substring的实现*/ 
char* substring(char *ch, int pos, int i)
{
    char* p=ch ;
    char* s = (char*)malloc(sizeof(char)*(int)( i-pos));//通过malloc来分配一个length长度的字符数组，返回的是字符指针。 
    int i; 
    p = p + pos;//是p指针指向pos位置。 
    for (i = 0; i < length; i++)
    {
      subch[i] = *(p++);//循环遍历赋值数组。 
    }
    s[i-pos] = '\0';
  return s;  
}

/*分块*/ 
/*正则表达式切割成功后，将数据库文件start body end 分块 */ 

void split(){         
 // Pattern pattern=Pattern.compile(segmentRegExp,Pattern.CASE_INSENSITIVE);
 
  /*使用不区分大小写的操作 用sql与我们的正则表达式segmentRegExp匹配*/ 
    
   int i=0; 
　 for(i=0;i<=sqllength();i++){
　 char shortSql[]=substring(sql,0, i);          //截取从0到i的字符串 
　

   char start[]='\0';
   char body[]='\0';
   char end[]='\0';//start body end都设置为空
    
　　matcher(shortSql);//循环进行进行正则匹配  /Matcher matcher=pattern.matcher(shortSql)/

　　while(matcherfind()){     //找到一组成功返回为Bool类型
 
　　start=matchergroup(1);
　　body=matchergroup(2);
　　end=matchergroup(3);// 片段开始、主体、结束标志分别start body end 

　　   
　　return;
　　} 
  }
  

	
}
//部分实现正则表达式 不包含上述功能// 
int pattern(){ 
 int matchhere(char *,char *);
 
 int matchstar(int c,char *regexp,char *text){
  char *t;
  for(t = text; *t != '\0' &&(*t == c || c=='.');t++);
  do{
   if(matchhere(regexp,t))
   return 1;
  }while(t-->text);
  return 0;
 }
 
 int matchhere(char *regexp, char *text) {
  if (regexp[0] == '\0') {
   return 1;
  }
  if (regexp[1] == '*') {
   return matchstar(regexp[0], regexp + 2, text);
  }
  if (regexp[0] == '$' && regexp[1] == '\0') {
   return *text == '\0';
  }
  if((text[0] != '\0')&&(regexp[0]=='.'|| regexp[0]==text[0])) {
   return matchhere(regexp+1,text+1);
  }
  return 0;
 }
 
 int match(char *regexp, char *text) {
  if (regexp[0] == '^')
   return matchhere(regexp + 1, text);
  do {
   if (matchhere(regexp, text)) {
    return 1;
   }
  } while (*text++ != '\0');
  return 0;
 }
 }
 
 
  return 0
 } 