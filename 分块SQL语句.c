void Pattern();       //������

/*�ٶ�pattern�������¹��ܣ�
  1.�ɽ�����������ѭ�� ��������Ϊmatcher
  2.�ɹ��ҵ�һ����ϵģ�������Ϊflag=1������Ϊmatcherfind 
  3.Matcherfind�ҵ�ƥ��Ľ�����漴��matcher����ѭ���� 
  4.�ٶ�matchergroup��i�� �Ĺ��ܼ�Ϊ���ص�i����������ַ��� 
*/ 

int sqllength(){     //�������ݿ�����ļ����ֽڳ��� 
	int i=0; 
	while(sql!=EOF){   
		i++;
	} 
	return i;
}


/*substring��ʵ��*/ 
char* substring(char *ch, int pos, int i)
{
    char* p=ch ;
    char* s = (char*)malloc(sizeof(char)*(int)( i-pos));//ͨ��malloc������һ��length���ȵ��ַ����飬���ص����ַ�ָ�롣 
    int i; 
    p = p + pos;//��pָ��ָ��posλ�á� 
    for (i = 0; i < length; i++)
    {
      subch[i] = *(p++);//ѭ��������ֵ���顣 
    }
    s[i-pos] = '\0';
  return s;  
}

/*�ֿ�*/ 
/*������ʽ�и�ɹ��󣬽����ݿ��ļ�start body end �ֿ� */ 

void split(){         
 // Pattern pattern=Pattern.compile(segmentRegExp,Pattern.CASE_INSENSITIVE);
 
  /*ʹ�ò����ִ�Сд�Ĳ��� ��sql�����ǵ�������ʽsegmentRegExpƥ��*/ 
    
   int i=0; 
�� for(i=0;i<=sqllength();i++){
�� char shortSql[]=substring(sql,0, i);          //��ȡ��0��i���ַ��� 
��

   char start[]='\0';
   char body[]='\0';
   char end[]='\0';//start body end������Ϊ��
    
����matcher(shortSql);//ѭ�����н�������ƥ��  /Matcher matcher=pattern.matcher(shortSql)/

����while(matcherfind()){     //�ҵ�һ��ɹ�����ΪBool����
 
����start=matchergroup(1);
����body=matchergroup(2);
����end=matchergroup(3);// Ƭ�ο�ʼ�����塢������־�ֱ�start body end 

����   
����return;
����} 
  }
  

	
}
//����ʵ��������ʽ ��������������// 
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