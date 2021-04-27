#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<algorithm>
using namespace std;

typedef struct user	{
	char username[100];		//用户名 
	char password[100];		//密码 
}user;

typedef struct users {
	char username[100];		//用户名 
	char password[100];		//密码 
	struct users* next;
}Users;

typedef struct node {
	char name[50];			//姓名
	char number[50];		//学号 
	char Class[50];			//专业班级 
	int Chinese;			//语文成绩 
	int Math; 				//数学成绩 
	int English;			//英语成绩		 
	struct node *next;
}Node; 

bool cmp(int a,int b) {    			//将sort()改变为从大到小排序 
	return a > b;        			//返回从大到小的排序
}

Users* userhead = (Users*)malloc(sizeof(Users));
Node* head = (Node*)malloc(sizeof(Node));
char PersonalNumber[50];			//学生个人学号 
char classname[50]; 				//学生个人班级 
char PersonalName[50];				//学生个人姓名 

void face1();						//选择不同用户登录页面 
void StudentInterFace();			//学生登录页面 
void TeacherInterFace();			//教师登录页面 
void AdministratorInterFace();		//管理员登录页面 
void RegisterFace();				//学生用户注册页面 
void TeacherRegisterFace();			//教师用户注册页面 
void StudentSystemMenu();			//学生系统页面 
void TeacherSystemMenu();			//教师系统页面 
void AdministratorSystemMenu();		//管理员系统页面     		 
void PersonalInformation();			//输入个人信息
void read();						//读取班级文件 
void DisplayList();					//输出本班成绩
void DisplayPersonalInformation();	//输出个人成绩 
void PersonalGradeAnalysis();		//分析个人成绩 
void TeacherInformation();			//输入教师信息
void AddStudentInformation();		//增加新的学生信息 
void DeleteStudentInformation();	//删除学生信息				
void ChangeStudentInformation();	//修改学生信息				
void SearchStudentInformation();	//查询学生信息				
void save();						//保存学生信息				
void ClassGradeAnalysis();			//分析班级成绩	
void InterTeacherSystem();			//管理员进入教师系统 
void AddAccounts();					//增加账号及密码 
void DeleteAccounts();				//删除账号及密码 
void SaveAccounts();				//保存用户账号及密码 
void ReadAccounts();				//读取用户账号及密码 
void DisplayAccounts();				//输出所有用户账号及密码
void ChangeAccount();				//修改用户密码
void SearchAccount();				//查找用户账号及密码
void ReenterStudentInformation();   //重新录入学生信息 

int main() {	
	head -> next = NULL; 
	face1();
	return 0;
}
void face1() {
	fflush(stdin);
	printf("============ 请 选 择 登 录 方 式 ============\n\n\n\n");
	printf("\t1.\t 学 生 登 录  \n\n");
	printf("\t2.\t 教 师 登 录  \n\n");
	printf("\t3.\t管 理 员 登 录\n\n");
	printf("\t4.\t 学 生 注 册   \n\n");
	printf("\t5.\t 教 师 注 册   \n\n");
	printf("\t0.\t   退   出   \n\n\n"); 
	printf("请选择：");
	char facekey[100];
	scanf("%s",&facekey);
	//face1key = getchar() - '0';
	//fflush(stdin);
	//scanf("%c",&face1key);			//选择不同系统 
	//face1key = getch() - 48;			//选择不同系统
	if (strcmp(facekey,"1") == 0){ 
		system("cls");
		StudentInterFace();
		}
	else if (strcmp(facekey,"2") == 0) {
		system("cls");
		TeacherInterFace();
		}
	else if (strcmp(facekey,"3") == 0){
		system("cls");
		AdministratorInterFace();
		}
	else if (strcmp(facekey,"4") == 0){
		system("cls");
		RegisterFace(); 
		}
	else if (strcmp(facekey,"5") == 0){
		system("cls");
		TeacherRegisterFace(); 
		}
	else if (strcmp(facekey,"0") == 0){
		system("cls");
		exit(0);
		}
	else {
		printf("\n\n\t## 无效指令 请重新输入 ##");
		Sleep(800);
		system("cls");
		fflush(stdin);
		face1();
	}
} 
void StudentInterFace() {
	FILE *fp;
	int i = 0;
	char ch;
	struct user a;
	char code[20];
	char name[20];
	int	flag = 0;
	fp = fopen("StudentAccounts.txt","r");
	printf("================================\n");
	printf("\n\n     学生登录     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### 文件为空！请先注册！#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//转到注册界面	 
	}
	fclose(fp); 
	fp = fopen("StudentAccounts.txt","r");
	printf("\n 用户名 :");
	scanf("%s",name);
	printf("\n 密  码 :");
	while ((ch = getch()) != '\r') {
		if (ch == '\b') {
			if (i != 0) {
				printf("\b \b");
			    i--;	
			}
		}
		else {
			putchar('*');
			code[i++] = ch;
		}			
	}
	code[i] = '\0';
	while (!feof(fp)) {
		fscanf(fp,"%s %s\n",a.username,a.password); 
		if (strcmp(name,a.username) == 0 && strcmp(code,a.password) == 0) {
			flag = 1;
			break;
		} 
	}
	fclose(fp); 
	if (flag) {
		printf("\n\n============ 登陆成功！ ============\n");
		Sleep(800);
		system("cls");
		PersonalInformation();
	}
	else {
		printf("\n\n\n ##### 您输入的密码不正确 ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  即将跳转至首页......");
		Sleep(1000);
		system("cls");
		face1();			
	}
}
void TeacherInterFace()	{
	FILE *fp;
	int i = 0;
	char ch;
	struct user a;
	char code[20];
	char name[20];
	int	flag = 0;
	fp = fopen("TeacherAccounts.txt","r");
	printf("================================\n");
	printf("\n\n     教师登录     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### 文件为空！请先注册！#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//转到注册界面	 
	}
	fclose(fp); 
	fp = fopen("TeacherAccounts.txt","r");
	printf("\n 用户名 :");
	scanf("%s",name);
	printf("\n 密  码 :");
	while ((ch = getch()) != '\r') {
		if (ch == '\b') {
			if (i != 0) {
				printf("\b \b");
			    i--;	
			}
		}
		else {
			putchar('*');
			code[i++] = ch;
		}			
	}
	code[i] = '\0';
	while (!feof(fp)) {
		fscanf(fp,"%s %s\n",a.username,a.password); 
		if (strcmp(name,a.username) == 0 && strcmp(code,a.password) == 0) {
			flag = 1;
			break;
		} 
	}
	fclose(fp);
	if (flag) {
		printf("\n\n============ 登陆成功！ ============\n");
		Sleep(800);
		system("cls");
		TeacherInformation();
	}
	else {
		printf("\n\n\n ##### 您输入的密码不正确 ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  即将跳转至首页......");
		Sleep(1000);
		system("cls");
		face1(); 			
	}
}
void AdministratorInterFace() {
	FILE *fp;
	int i = 0;
	char ch;
	char SecretCode[20];
	char code[20];
	int	flag = 0;
	fp = fopen("AdministratorAccounts.txt","r");
	printf("================================\n");
	printf("\n\n     管理员登录     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### 文件为空！请先注册！#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//转到注册界面	 
	}
	fclose(fp); 
	fp = fopen("AdministratorAccounts.txt","r");
	printf("\n请输入管理员密钥 :");
	while ((ch = getch()) != '\r') {
		if (ch == '\b') {
			if (i != 0) {
				printf("\b \b");
			    i--;	
			}
		}
		else {
			putchar('*');
			code[i++] = ch;
		}			
	}
	code[i] = '\0';
	while (!feof(fp)) {
		fscanf(fp,"%s\n",SecretCode); 
		if (strcmp(code,SecretCode) == 0) {
			flag = 1;
			break;
		} 
	}
	fclose(fp);
	if (flag) {
		printf("\n\n\n\n============ 登陆成功！ ============\n");
		Sleep(800);
		system("cls");
		AdministratorSystemMenu();
	}
	else {
		printf("\n\n\n\t ##### 您输入的管理员密钥不正确 ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  即将跳转至首页......");
		Sleep(1000);
		system("cls");
		face1(); 			
	}
}
void RegisterFace() {
	FILE *fp;
	int i, j, flag = 0;
	char ch;
	struct user a;
	char name[20];
	char code[20];
	printf("\n\t   【学 生 用 户 注 册】     \n");
	printf("\n请输入用户名：");
	scanf("%s",name);
	fflush(stdin); 
	fp = fopen("StudentAccounts.txt","r");
	if (fp == NULL) {
		fp = fopen("StudentAccounts.txt","w");
		fclose(fp);
		fp = fopen("StudentAccounts.txt","r");
	}
	flag = 0;
	while (!feof(fp)) {
		fscanf(fp,"%s %s\n",a.username, a.password);
		if (strcmp(a.username,name) == 0) {
			flag = 1;
			break;
		}	
	}
	fclose(fp);
	if (flag == 1) {	
		printf("\n\n\n\t##### 该用户名已存在！请重新输入！#####"); 
		Sleep(1000);
		system("cls");
		RegisterFace(); 
	}
	else {	
		while (1) {
			printf("\n请输入密码  ：");
			while ((ch = getch()) != '\r') {
				if (ch == '\b') {
					if (i != 0) {
						printf("\b \b");
						i--;	
					}
				}
				else {
					putchar('*');
					code[i++] = ch;
				}
			}
			code[i] = '\0';
			i = 0;
			j = 0;
			fp = fopen("StudentAccounts.txt","a"); 
			fprintf(fp,"%s %s\n",name, code);
			fclose(fp);
			break;	
		}
		printf("\n\n\n\t ##### 注册成功 ####\n");
		printf("\n\t======================\n\n");
		printf("\n\n\t即将跳转至首页......");
		Sleep(1000);
		system("cls"); 
		face1();	
	}
}
void TeacherRegisterFace() {
	FILE *fp;
	int i, j, flag = 0;
	char ch;
	struct user a;
	char name[20];
	char code[20];
	printf("\n\t  【教 师 用 户 注 册】     \n");
	printf("\n请输入用户名：");
	scanf("%s",name);
	fflush(stdin); 
	fp = fopen("TeacherAccounts.txt","r");
	if (fp == NULL) {
		fp = fopen("TeacherAccounts.txt","w");
		fclose(fp);
		fp = fopen("TeacherAccounts.txt","r");
	}
	flag = 0;
	while (!feof(fp)) {
		fscanf(fp,"%s %s\n",a.username, a.password);
		if (strcmp(a.username,name) == 0) {
			flag = 1;
			break;
		}	
	}
	fclose(fp);
	if (flag == 1) {	
		printf("\n\n\n\t##### 该用户名已存在！请重新输入！#####"); 
		Sleep(1000);
		system("cls");
		TeacherRegisterFace(); 
	}
	else {	
		while (1) {
			printf("\n请输入密码  ：");
			while ((ch = getch()) != '\r') {
				if (ch == '\b') {
					if (i != 0) {
						printf("\b \b");
						i--;	
					}
				}
				else {
					putchar('*');
					code[i++] = ch;
				}
			}
			code[i] = '\0';
			i = 0;
			j = 0;
			fp = fopen("TeacherAccounts.txt","a"); 
			fprintf(fp,"%s %s\n",name, code);
			fclose(fp);
			break;	
		}
		printf("\n\n\n\t ##### 注册成功 ####\n");
		printf("\n\t======================\n\n");
		printf("\n\n\t即将跳转至首页......");
		Sleep(1000);
		system("cls"); 
		face1();	
	}
}
void StudentSystemMenu() {
	fflush(stdin);
	system("cls"); 
	read();
	printf("============ 欢 迎 使 用 学 生 系 统 页 面 ============\n\n\n");
	printf("\t1.\t  成  绩  查  询\n\n");
	printf("\t2.\t 查 询 本 班 成 绩\n\n");
	printf("\t3.\t  成  绩  分  析\n\n");
	printf("\t0.\t注销并返回至登陆页面\n\n\n\n");
	printf("\t请选择：");
	char key;
	key = getchar() - '0';			//选择不同功能
	switch (key) {
		case 1: 
			system("cls");
			DisplayPersonalInformation();
			break;
		case 2:
			system("cls");
			DisplayList();
			StudentSystemMenu();
			break;
		case 3:
			system("cls");
			PersonalGradeAnalysis();
			break;
		case 0:
			system("cls");
			face1(); 
			break;  
		default:
			printf("\n\n\t## 无效指令 请重新输入 ##");
			Sleep(800);
			system("cls");
			fflush(stdin);
			StudentSystemMenu(); 	
	}
}
void TeacherSystemMenu() {
	fflush(stdin);
	system("cls"); 
	read();
	printf("============ 欢 迎 使 用 教 师 系 统 页 面 ============\n\n\n");
	printf("\t1.\t 增加新的学生信息\n\n");
	printf("\t2.\t 删 除 学 生 信 息\n\n");
	printf("\t3.\t 修 改 学 生 信 息\n\n");
	printf("\t4.\t 查 询 学 生 信 息\n\n");
	printf("\t5.\t 输 出 本 班 成 绩\n\n");
	printf("\t6.\t 保 存 到 文 件 中\n\n");
	printf("\t7.\t 成   绩   分   析\n\n");
	printf("\t0.\t注销并返回至登陆页面\n\n\n\n");
	printf("\t请选择：");
	char key;
	key = getchar() - '0';			//选择不同功能
	switch (key) {
		case 1: 
			system("cls");
			AddStudentInformation(); 
			break;
		case 2:
			system("cls");
			DeleteStudentInformation();
			break;
		case 3:
			system("cls");
			ChangeStudentInformation();
			break;
		case 4:
			system("cls");
			SearchStudentInformation();
			break; 
		case 5:
			system("cls");
			DisplayList();
			TeacherSystemMenu();
			break;
		case 6:
			system("cls");
			save();
			printf("\n\n\n\n\t\t\t ======== 已成功保存信息 ========\n\n\n\n\n");
			Sleep(1000);
			TeacherSystemMenu();
			break;
		case 7:
			system("cls");
			ClassGradeAnalysis();
			break;
		case 0:
			system("cls");
			face1(); 
			break;  
		default:
			printf("\n\n\t## 无效指令 请重新输入 ##");
			Sleep(800);
			system("cls");
			fflush(stdin);
			TeacherSystemMenu(); 	
	}
}
void AdministratorSystemMenu() {
	fflush(stdin);
	system("cls"); 
	ReadAccounts();
	printf("============ 欢 迎 使 用 管 理 员 系 统 页 面 ============\n\n\n");
	printf("\t1.\t 进入教师端进行信息修改\n\n");
	printf("\t2.\t  增 加 账 号 及 密 码\n\n");
	printf("\t3.\t  删 除 账 号 及 密 码\n\n");
	printf("\t4.\t  修 改 账 号 及 密 码\n\n");
	printf("\t5.\t  查 找 账 号 及 密 码\n\n");
	printf("\t6.     保 存 所 有 账 号 及 密 码\n\n");
	printf("\t7.     输 出 所 有 账 号 及 密 码\n\n");
	printf("\t8.\t 重 新 录 入 学 生 信 息\n\n");
	printf("\t0.\t  注销并返回至登陆页面\n\n\n\n");
	printf("\t请选择：");
	char key;
	key = getchar() - '0';			//选择不同功能
	switch (key) {
		case 1: 
			system("cls");
			InterTeacherSystem();
			break;
		case 2:
			system("cls");
			AddAccounts(); 
			break;
		case 3:
			system("cls");
			DeleteAccounts(); 
			break;
		case 4:
			system("cls");
			ChangeAccount();
			break; 
		case 5:
			system("cls");
			SearchAccount();
			break;
		case 6:
			system("cls");
			SaveAccounts();
			printf("\n\n\n\t ====== 已保存成功 ======\n\n\n");
			Sleep(800);
			AdministratorSystemMenu();
			break;
		case 7:
			system("cls");
			DisplayAccounts();
			break;
		case 8:
			system("cls");
			ReenterStudentInformation();
			break;
		case 0:
			system("cls");
			face1(); 
			break;  
		default:
			printf("\n\n\t## 无效指令 请重新输入 ##");
			Sleep(800);
			system("cls");
			fflush(stdin);
			AdministratorSystemMenu();	
	}
}
void PersonalInformation() {
	printf("\t========== 个人信息 ==========\n\n\n");
	printf("\t  学    号  ：");
	scanf("%s",PersonalNumber);
	printf("\n");
	printf("\t  姓    名  ：");
	scanf("%s",PersonalName);
	printf("\n");
	printf("\t专 业 班 级 ：");
	scanf("%s",classname);
	if (strcmp(classname,"网络1班") == 0 || strcmp(classname,"网络2班") == 0 || strcmp(classname,"网络3班") == 0 ||strcmp(classname,"网络4班") == 0 ||strcmp(classname,"网络5班") == 0) {
		read();
		Node* q = head -> next;
		while (q != NULL) {
			if (strcmp(PersonalNumber,q -> number) == 0 && strcmp(PersonalName,q -> name) == 0) {
				StudentSystemMenu();
			}
			q = q -> next;
		} 
	}
	printf("\n\n\n\n\n\t\t\t   ### 输入信息有误 即将返回至上一步 ###\n"); 
	Sleep(1000);
	system("cls");
	face1();
}
void read() {
	char classname1[10];
	if (strcmp(classname,"网络1班") == 0) {
		strcpy(classname1,"class1");
	} 
	if (strcmp(classname,"网络2班") == 0) {
		strcpy(classname1,"class2");
	} 
	if (strcmp(classname,"网络3班") == 0) {
		strcpy(classname1,"class3");
	}
	if (strcmp(classname,"网络4班") == 0) {
		strcpy(classname1,"class4");
	}
	if (strcmp(classname,"网络5班") == 0) {
		strcpy(classname1,"class5");
	}
	char name1[50];				//姓名
	char number1[50];			//学号 
	char Class1[50];			//专业班级 
	int Chinese1;				//语文成绩 
	int Math1; 					//数学成绩 
	int English1;				//英语成绩	
	FILE *fp;  
	if (strcmp(classname1,"class1") == 0) {
    	fp = fopen("class1.txt","rb"); 			//以只读方式打开当前目录下的.txt  
   	 	if (fp == NULL) {
       	 	printf("不存在打开文件\n");  
        	exit(0);                 			 //终止程序  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class1.txt","rb"); 			//以只读方式打开当前目录下的.txt
    	if (FP == NULL) {  
        	printf("无法打开文件\n");  
        	exit(0); 							//终止程序  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//把后者的内容拷贝到前者中  
            strcpy(pnew -> number, number1);		//把后者的内容拷贝到前者中
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//插入新的节点
			p -> next = pnew;
			p = pnew;
            
            if(j == b)  
               break;  
            j++;  
        }
        fclose(FP);   					 //关闭文件 
	} 
	if (strcmp(classname1,"class3") == 0) {
    	fp = fopen("class3.txt","rb");	 //以只读方式打开当前目录下的.txt  
   	 	if (fp == NULL) {
       	 	printf("不存在打开文件\n");  
        	exit(0);                 	 //终止程序  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class3.txt","rb"); 	//以只读方式打开当前目录下的.txt
    	if (FP == NULL) {  
        	printf("无法打开文件\n");  
        	exit(0); 					//终止程序  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//把后者的内容拷贝到前者中  
            strcpy(pnew -> number, number1);		//把后者的内容拷贝到前者中
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//插入新的节点
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //关闭文件 
	}
	if (strcmp(classname1,"class2") == 0) {
    	fp = fopen("class2.txt","rb"); //以只读方式打开当前目录下的.txt  
   	 	if (fp == NULL) {
       	 	printf("不存在打开文件\n");  
        	exit(0);                  //终止程序  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class2.txt","rb"); //以只读方式打开当前目录下的.txt
    	if (FP == NULL) {  
        	printf("无法打开文件\n");  
        	exit(0); //终止程序  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//把后者的内容拷贝到前者中  
            strcpy(pnew -> number, number1);		//把后者的内容拷贝到前者中
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//插入新的节点
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //关闭文件 
	} 
	if (strcmp(classname1,"class4") == 0) {
    	fp = fopen("class4.txt","rb"); //以只读方式打开当前目录下的.txt  
   	 	if (fp == NULL) {
       	 	printf("不存在打开文件\n");  
        	exit(0);                  //终止程序  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class4.txt","rb"); //以只读方式打开当前目录下的.txt
    	if (FP == NULL) {  
        	printf("无法打开文件\n");  
        	exit(0); //终止程序  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//把后者的内容拷贝到前者中  
            strcpy(pnew -> number, number1);		//把后者的内容拷贝到前者中
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//插入新的节点
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //关闭文件 
	}
	if (strcmp(classname1,"class5") == 0) {
    	fp = fopen("class5.txt","rb"); //以只读方式打开当前目录下的.txt  
   	 	if (fp == NULL) {
       	 	printf("不存在打开文件\n");  
        	exit(0);                  //终止程序  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class5.txt","rb"); //以只读方式打开当前目录下的.txt
    	if (FP == NULL) {  
        	printf("无法打开文件\n");  
        	exit(0); //终止程序  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//把后者的内容拷贝到前者中  
            strcpy(pnew -> number, number1);		//把后者的内容拷贝到前者中
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//插入新的节点
			p -> next = pnew;
			p = pnew;
            
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //关闭文件 
	}
} 
void DisplayList() {
	Node *q = head -> next;
	printf("————————————————————————————————————\n");
  	printf("|  姓  名  |  学  号  |  专 业 班 级  |  语  文  |  数  学  |  英  语  |\n");
  	printf("————————————————————————————————————\n");
	if (q == NULL) {  
		printf("\t\t   ### 还没有相关信息，请添加信息 ###\n"); 
		printf("\n\n");
		printf("\t\t=========================================================\n");
		printf("\t\t=========================================================\n");
		printf("\n\n"); 
		printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
		getch();
		StudentSystemMenu();
    }  
    while (q) {   
		printf("|  %-6s  |  %s   |    %s    |  %5d   |  %5d   |  %5d   |\n",q -> name,q -> number,q -> Class,q -> Chinese,q -> Math,q -> English);  
		printf("————————————————————————————————————\n");
  		q = q -> next;  
    }
    //system("pause");
  	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 	
}
void DisplayPersonalInformation() {
	Node* q = head -> next;
	while (q != NULL) {
		if (strcmp(q -> number,PersonalNumber) == 0) {
			printf("\n\n\t\t\t ====== 你 的 成 绩 ======\n\n\n\n\n"); 
			printf("\t\t\t 姓     名  ：%s\n\n",q -> name);
			printf("\t\t\t 学     号  ：%s\n\n",q -> number);
			printf("\t\t\t专 业 班 级 ：%s\n\n",q -> Class);
			printf("\t\t\t 语     文  ：%d\n\n",q -> Chinese);
			printf("\t\t\t 数     学  ：%d\n\n",q -> Math);
			printf("\t\t\t 英     语  ：%d\n\n",q -> English);
			break;
		}
		q = q->next;
	} 
	if (q == NULL) {
		printf("\n\n\n\n\t\t   ### 信息不存在 可能个人信息有误 ###\n"); 
		printf("\n");
		printf("\t\t=======================================================\n");
	}
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	StudentSystemMenu();
} 
void PersonalGradeAnalysis() {
	int ChineseRank[601];
	int MathRank[601];
	int EnglishRank[601];
	int TotalScore[601];
	int PersonalChinese;
	int PersonalMath;
	int PersonalEnglish;
	int PersonalTotalScore;
	int ChineseGradeRank;
	int MathGradeRank;
	int EnglishGradeRank;
	int TotalGradeRank;
	int i = 0;
	Node *q = head -> next;
	while (q != NULL) {
		if (strcmp(q -> number,PersonalNumber) == 0) { 
			PersonalChinese = q -> Chinese;
			PersonalMath = q -> Math;
			PersonalEnglish = q -> English;
			PersonalTotalScore = PersonalChinese + PersonalMath + PersonalEnglish;
		}
		ChineseRank[i] = q -> Chinese;
		MathRank[i] = q -> Math;
		EnglishRank[i] = q -> English;
		TotalScore[i] = ChineseRank[i] + MathRank[i] + EnglishRank[i];
		i++;
		q = q->next;
	}
	sort(ChineseRank,ChineseRank + i,cmp);
	sort(MathRank,MathRank + i,cmp);
	sort(EnglishRank,EnglishRank + i,cmp);
	sort(TotalScore,TotalScore + i,cmp);
	for (int j = 0; j < i; j++) {
		if (PersonalChinese == ChineseRank[j]) {
			ChineseGradeRank = j + 1;
			break;
		}
	}
	for (int j = 0; j < i; j++) {
		if (PersonalMath == MathRank[j]) {
			MathGradeRank = j + 1;
			break;
		}
	}
	for (int j = 0; j < i; j++) {
		if (PersonalEnglish == EnglishRank[j]) {
			EnglishGradeRank = j + 1;
			break;
		}
	}
	for (int j = 0; j < i; j++) {
		if (PersonalChinese == ChineseRank[j]) {
			ChineseGradeRank = j + 1;
			break;
		}
	}
	for (int j = 0; j < i; j++) {
		if (PersonalTotalScore == TotalScore[j]) {
			TotalGradeRank = j + 1;
			break;
		}
	}
	printf("\n\t============ 成 绩 分 析 ============\n\n\n\n");
	printf("\t语 文 成 绩 在 本 班 排 名 ：%d\n\n",ChineseGradeRank);
	printf("\t数 学 成 绩 在 本 班 排 名 ：%d\n\n",MathGradeRank);
	printf("\t英 语 成 绩 在 本 班 排 名 ：%d\n\n",EnglishGradeRank);
	printf("\t总  分  在  本  班  排  名 ：%d\n\n",TotalGradeRank);
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	StudentSystemMenu();
}
void TeacherInformation() { 
	printf("\t========== 教师信息 ==========\n\n\n");

	printf("\n");
	printf("\t所 带 专 业 班 级 ：");
	scanf("%s",classname);
	if (strcmp(classname,"网络1班") == 0 || strcmp(classname,"网络2班") == 0 || strcmp(classname,"网络3班") == 0 ||strcmp(classname,"网络4班") == 0 ||strcmp(classname,"网络5班") == 0) {
		TeacherSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### 输入信息有误 即将返回至上一步###\n"); 
	Sleep(1000);
	system("cls");
	face1();
}
void AddStudentInformation() {
	Node *pnew;
	Node *q = head;
	Node *p1 = head -> next;
	while (q != NULL) {
		if (q -> next == NULL) {
			pnew = (Node*)malloc(sizeof(Node));
			printf("\n\n\t\t\t======= 新增学生信息 =======\n\n\n\n");
			printf("\t  学     号  ：");
			scanf("%s",pnew -> number);
			while (p1 != NULL) {
				if (strcmp(pnew -> number, p1 -> number) == 0) {
					printf("\n\n\n\t\t### 该学号已存在 请重新输入 ###\n\n\n");
					Sleep(1000); 
					system("cls");
					AddStudentInformation();
				}
				p1 = p1 -> next;
			}
			printf("\n\t  姓     名  ：");
			scanf("%s",pnew -> name);
			printf("\n\t 专 业 班 级 ：");
			scanf("%s",pnew -> Class);
			printf("\n\t 语 文 成 绩 ：");
			scanf("%d",&pnew -> Chinese);
			printf("\n\t 数 学 成 绩 ：");
			scanf("%d",&pnew -> Math);
			printf("\n\t 英 语 成 绩 ：");
			scanf("%d",&pnew -> English);
			pnew -> next = NULL;
			q -> next = pnew;
			q = pnew;
		}
		q = q -> next;
	}
	save();
	printf("\n\n\n\n\t\t\t======= 新增学生信息成功 =======\n\n\n");
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	TeacherSystemMenu();
} 
void DeleteStudentInformation() {
	char DeleteNumber[50];
	char DeleteName[50];
	printf("\n\n\t ======== 请输入即将删除的学生的相关信息 =======\n\n");
	printf("\n\t学   号： ");
	scanf("%s",DeleteNumber);
	printf("\n\t姓   名： ");
	scanf("%s",DeleteName);
	Node* q = head;
	Node* pnew = head -> next;
	while (pnew != NULL) {
		if (strcmp(DeleteNumber, pnew -> number) == 0 && strcmp(DeleteName,pnew -> name) == 0) {
			q -> next = pnew -> next;
			free(pnew);
			save();
			printf("\n\n\t\t ===== 删除成功！ =====\n\n");
			printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
			getch(); 
			TeacherSystemMenu();
		}
		q = pnew;
		pnew = pnew -> next;
	}
	if (pnew == NULL) {
		printf("\n\n\t\t### 未找到符合信息 可能是输入的信息有误 ###"); 
	}
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	TeacherSystemMenu();
}
void ChangeStudentInformation() {
	char ChangeNumber[50];
	int choice;
	Node* q = head -> next;
	printf ("\n\n\n\t请输入要更改信息的学生的学号 ：");
	scanf("%s",ChangeNumber);
	while (q != NULL) {
		if (strcmp(ChangeNumber, q -> number) == 0) {
			printf("\n\n\t ===== 该学生信息如下 =====\n\n\n");
			printf("\t 姓     名  ：%s\n\n",q -> name);
			printf("\t 学     号  ：%s\n\n",q -> number);
			printf("\t专 业 班 级 ：%s\n\n",q -> Class);
			printf("\t 语     文  ：%d\t",q -> Chinese);
			printf("\n\n\t是否更改语文成绩：1.（是）     2.（否）\t\t请输入：");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t更改后的语文成绩为：");
				scanf("%d",&q -> Chinese); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### 无效指令 按任意键返回至上一步 ###");
				getch(); 
				TeacherSystemMenu();
			}
			printf("\n\t 数     学  ：%d\t",q -> Math);
			printf("\n\n\t是否更改数学成绩：1.（是）     2.（否）\t\t请输入：");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t更改后的数学成绩为：");
				scanf("%d",&q -> Math); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### 无效指令 按任意键返回至上一步 ###");
				getch(); 
				TeacherSystemMenu();
			}
			printf("\n\t 英     语  ：%d\t",q -> English);
			printf("\n\n\t是否更改英语成绩：1.（是）     2.（否）\t\t请输入：");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t更改后的英语成绩为：");
				scanf("%d",&q -> English); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### 无效指令 按任意键返回至上一步 ###");
				getch(); 
				TeacherSystemMenu();
			}
			save();
			printf("\n\n\n\t\t=========== 更改信息成功 ===========");
			printf("\n\n\n\t\t\t### 按任意键返回至上一步 ###");
			getch(); 
			TeacherSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\t\t### 未找到该学生信息 按任意键返回至上一步 ###");
		getch(); 
		TeacherSystemMenu();
	}
}
void SearchStudentInformation() {
	Node* q = head -> next;
	char SearchNumber[50];
	printf("\n\n\t请输入要查询的学生学号 ：");
	scanf("%s",SearchNumber);
	while (q != NULL) {
		if (strcmp(SearchNumber,q -> number) == 0) {
			printf("\n\n\n\t\t\t ====== 该 学 生 的 信 息 ======\n\n\n\n\n"); 
			printf("\t\t\t 姓     名  ：%s\n\n",q -> name);
			printf("\t\t\t 学     号  ：%s\n\n",q -> number);
			printf("\t\t\t专 业 班 级 ：%s\n\n",q -> Class);
			printf("\t\t\t 语     文  ：%d\n\n",q -> Chinese);
			printf("\t\t\t 数     学  ：%d\n\n",q -> Math);
			printf("\t\t\t 英     语  ：%d\n\n",q -> English);
			break;
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\t\t\t\t   ### 信息不存在 可能个人信息有误 ###\n"); 
		printf("\n");
		printf("\t\t\t\t===========================================================\n");
	}
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	TeacherSystemMenu();
}
void save() {
	char classname1[10];
	if (strcmp(classname,"网络1班") == 0) {
		strcpy(classname1,"class1");
	} 
	if (strcmp(classname,"网络2班") == 0) {
		strcpy(classname1,"class2");
	} 
	if (strcmp(classname,"网络3班") == 0) {
		strcpy(classname1,"class3");
	}
	if (strcmp(classname,"网络4班") == 0) {
		strcpy(classname1,"class4");
	}
	if (strcmp(classname,"网络5班") == 0) {
		strcpy(classname1,"class5");
	}
	Node *p;
	FILE *fp;
	if (strcmp(classname1,"class1") == 0) {
		if ((fp = fopen("class1.txt","wt")) == NULL) {
			exit(1);
		}
		for (p = head -> next; p != NULL; p = p -> next) {
			fprintf(fp,"%s %s %s %d %d %d\n",p -> name, p -> number, p -> Class, p -> Chinese, p -> Math, p -> English);
		}
		fclose(fp);
	}
	if (strcmp(classname1,"class2") == 0) {
		if ((fp = fopen("class2.txt","wt")) == NULL) {
			exit(1);
		}
		for (p = head -> next; p != NULL; p = p -> next) {
			fprintf(fp,"%s %s %s %d %d %d\n",p -> name, p -> number, p -> Class, p -> Chinese, p -> Math, p -> English);
		}
		fclose(fp);
	}
	if (strcmp(classname1,"class3") == 0) {
		if ((fp = fopen("class3.txt","wt")) == NULL) {
			exit(1);
		}
		for (p = head -> next; p != NULL; p = p -> next) {
			fprintf(fp,"%s %s %s %d %d %d\n",p -> name, p -> number, p -> Class, p -> Chinese, p -> Math, p -> English);
		}
		fclose(fp);
	}
	if (strcmp(classname1,"class4") == 0) {
		if ((fp = fopen("class4.txt","wt")) == NULL) {
			exit(1);
		}
		for (p = head -> next; p != NULL; p = p -> next) {
			fprintf(fp,"%s %s %s %d %d %d\n",p -> name, p -> number, p -> Class, p -> Chinese, p -> Math, p -> English);
		}
		fclose(fp);
	}
	if (strcmp(classname1,"class5") == 0) {
		if ((fp = fopen("class5.txt","wt")) == NULL) {
			exit(1);
		}
		for (p = head -> next; p != NULL; p = p -> next) {
			fprintf(fp,"%s %s %s %d %d %d\n",p -> name, p -> number, p -> Class, p -> Chinese, p -> Math, p -> English);
		}
		fclose(fp);
	}
}
void ClassGradeAnalysis() {
	Node* q = head -> next;
	int ChinesePass = 0;
	int MathPass = 0;
	int EnglishPass = 0;
	int ChineseHighest = 0;
	int MathHighest = 0;
	int EnglishHighest = 0;
	int All = 0;
	while (q != NULL) {
		if (q -> Chinese >= 60) {
			ChinesePass++;
		}
		if (q -> Chinese >= 90) {
			ChineseHighest++;
		}
		if (q -> Math >= 60) {
			MathPass++;
		}
		if (q -> Math >= 90) {
			MathHighest++;
		}
		if (q -> English >= 60) {
			EnglishPass++;
		}
		if (q -> English >= 90) {
			EnglishHighest++;
		}
		All++;
		q = q -> next;
	}
	printf("\n\n\t\t\t ========== 本 班 成 绩 分 析 ==========\n\n\n\n");
	printf("\t语文及格人数 ：%d\t及格率：%.2f %%\t\t语文90分及以上人数 ：%d\n\n",ChinesePass,ChinesePass * 100.0/ All,ChineseHighest);
	printf("\t数学及格人数 ：%d\t及格率：%.2f %%\t\t数学90分及以上人数 ：%d\n\n",MathPass,MathPass * 100.0 / All,MathHighest);
	printf("\t英语及格人数 ：%d\t及格率：%.2f %%\t\t英语90分及以上人数 ：%d\n\n",EnglishPass,EnglishPass * 100.0 / All,EnglishHighest);
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	TeacherSystemMenu(); 
}
void InterTeacherSystem() {
	printf("\n\n\t请输入你要进入的专业班级 ：");
	scanf("%s",classname);
	if (strcmp(classname,"网络1班") == 0 || strcmp(classname,"网络2班") == 0 || strcmp(classname,"网络3班") == 0 ||strcmp(classname,"网络4班") == 0 ||strcmp(classname,"网络5班") == 0) {
		TeacherSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### 输入信息有误 即将返回至上一步###\n"); 
	Sleep(1000);
	system("cls");
	AdministratorSystemMenu();
}
void AddAccounts() {
	FILE *fp;
	int i, flag = 0;
	char ch;
	struct user a;
	char name[20];
	char code[20];
	printf("\n\t===== 新增用户账号及密码 =====\n\n\n\n");
	printf("\n\t请输入用户名：");
	scanf("%s",name);
	fflush(stdin); 
	fp = fopen("StudentAccounts.txt","r");
	if (fp == NULL) {
		fp = fopen("StudentAccounts.txt","w");
		fclose(fp);
		fp = fopen("StudentAccounts.txt","r");
	}
	flag = 0;
	while (!feof(fp)) {
		fscanf(fp,"%s %s\n",a.username, a.password);
		if (strcmp(a.username,name) == 0) {
			flag = 1;
			break;
		}	
	}
	fclose(fp);
	if (flag == 1) {	
		printf("\n\n\n\t##### 该用户名已存在！请重新输入！#####"); 
		Sleep(1000);
		system("cls");
		AddAccounts(); 
	}
	else {	
		while (1) {
			printf("\n\t请输入密码  ：");
			gets(code);
			fp = fopen("StudentAccounts.txt","a"); 
			fprintf(fp,"%s %s\n",name, code);
			fclose(fp);
			break;
		}
		printf("\n\n\n\t ##### 添加成功 ####\n");
		printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
		getch(); 
		AdministratorSystemMenu();	
	}
} 
void DeleteAccounts() {
	char DeleteAccounts[100];
	printf("\n\n\t ======== 【删 除 账 号】 =======\n\n");
	printf("\n\t 用 户 账 号 ： ");
	scanf("%s",DeleteAccounts);
	Users* q = userhead;
	Users* pnew = userhead -> next;
	while (pnew != NULL) {
		if (strcmp(DeleteAccounts, pnew -> username) == 0) {
			q -> next = pnew -> next;
			free(pnew);
			SaveAccounts();
			printf("\n\n\t\t ===== 删除成功！ =====\n\n");
			printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = pnew;
		pnew = pnew -> next;
	}
	if (pnew == NULL) {
		printf("\n\n\t\t### 未找到该用户 可能是输入的信息有误 ###"); 
	}
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	AdministratorSystemMenu();
}
void SaveAccounts() {
	FILE *fp;
	Users* p;
	if ((fp = fopen("StudentAccounts.txt","wt")) == NULL) {
			exit(1);
		}
	for (p = userhead -> next; p != NULL; p = p -> next) {
		fprintf(fp,"%s %s\n",p -> username, p -> password);
	}
	fclose(fp);
}
void ReadAccounts() {
	char username1[100];				
	char password1[100];		 	
	FILE *fp; 
	fp = fopen("StudentAccounts.txt","rb"); 			//以只读方式打开当前目录下的.txt  
   	if (fp == NULL) {
       	printf("不存在打开文件\n");  
        exit(0);                 			 			//终止程序  
   	}   
    int i = 0;  
    while (!feof(fp)) {
        fscanf(fp,"%s %s",username1, password1);
        i++;  
    }
    fclose(fp);  
    FILE *FP;  
	FP = fopen("StudentAccounts.txt","rb"); 			//以只读方式打开当前目录下的.txt
    if (FP == NULL) {  
        printf("无法打开文件\n");  
        exit(0); 										//终止程序  
    }  
    int b = i-1;  
	int j = 1;  
   	Users* p = userhead;
    while (!feof(FP)) {  
        fscanf(FP,"%s %s",username1, password1);
        Users* pnew = (Users*)malloc(sizeof(Users));
        strcpy(pnew -> username, username1);			//把后者的内容拷贝到前者中  
        strcpy(pnew -> password, password1);			//把后者的内容拷贝到前者中
                    
        pnew -> next = NULL;							//插入新的节点
		p -> next = pnew;
		p = pnew;
            
        if(j == b)  
            break;  
        j++;  
    }
    fclose(FP);   										//关闭文件 
}
void DisplayAccounts() {
	Users* q = userhead -> next;
	int i = 1; 
	printf("—————————————————————\n");
  	printf("| 序号 |    账    号    |    密    码    |\n");
  	printf("—————————————————————\n");
  	if (q == NULL) {  
		printf("\t\t   ### 还没有相关信息，请添加信息 ###\n"); 
		printf("\n\n");
		printf("\t\t=========================================================\n");
		printf("\t\t=========================================================\n");
		printf("\n\n"); 
		printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
		getch();
		AdministratorSystemMenu();
    } 
	while (q != NULL) {
		printf("| %-4d |   %-10s   |   %-10s   |\n",i,q -> username,q -> password);  
		printf("—————————————————————\n");
		i++;
  		q = q -> next; 
	}
	printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
	getch(); 
	AdministratorSystemMenu();
}
void ChangeAccount() {
	Users* q = userhead -> next;
	char ChangeUsername[100];
	printf("\n\n\t 请输入要更改的用户账号 ：");
	scanf("%s",ChangeUsername); 
	while (q != NULL) {
		if (strcmp(ChangeUsername,q -> username) == 0) {
			printf("\n\n\t    原   密   码    ：%s",q -> password);
			printf("\n\n\t  修   改   密   码 ：");
			scanf("%s",q -> password); 
			SaveAccounts();
			printf("\n\n\t====== 修改成功 ======"); 
			printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\n\t\t### 未找到该用户信息 按任意键返回至上一步 ###");
		getch(); 
		AdministratorSystemMenu();
	} 
}
void SearchAccount() {
	Users* q = userhead;
	char SearchUsername[100];
	printf("\n\n\t 请输入要查找的用户账号 ：");
	scanf("%s",SearchUsername); 
	while (q != NULL) {
		  if (strcmp(SearchUsername,q -> username) == 0) {
			printf("\n\n\t  密     码  ：%s",q -> password);
			printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\n\t\t### 未找到该用户信息 按任意键返回至上一步 ###");
		getch(); 
		AdministratorSystemMenu();
	}
} 
void ReenterStudentInformation() {
	int choice;
	printf("\n\t\t=========== 重 新 录 入 ==========="); 
	printf("\n\n\t请输入（重新录入学生信息的）专业班级 ：");
	scanf("%s",classname);
	if (strcmp(classname,"网络1班") == 0 || strcmp(classname,"网络2班") == 0 || strcmp(classname,"网络3班") == 0 ||strcmp(classname,"网络4班") == 0 ||strcmp(classname,"网络5班") == 0) {
		read();
		Node *q, *end;
		end = head;
		do {
			q = (Node*)malloc(sizeof(Node));
			printf("\n\n\t 姓    名 ：");
			scanf("%s",q -> name);
			printf("\n\t 学    号 ：");
			scanf("%s",q -> number);
			strcpy(q -> Class,classname);
			printf("\n\t 语    文 ：");
			scanf("%d",&q -> Chinese);
			printf("\n\t 数    学 ：");
			scanf("%d",&q -> Math);
			printf("\n\t 英    语 ：");
			scanf("%d",&q -> English);
			q -> next = NULL;
			end -> next = q;		//尾插新结点 
			end = q;	
			printf("\n\n\t请选择是否继续录入下一位学生：1.（是）\t2.（否）");
			scanf("%d",&choice);
		} while (choice == 1);
		q -> next == NULL;
		save();
		printf("\n\n\t====== 录入成功 ======"); 
		printf("\n\n\n\n\t\t\t## 按下任意键返回至上一步 ##");
		getch(); 
		AdministratorSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### 输入信息有误 即将返回至上一步###\n"); 
	Sleep(1000);
	system("cls");
	AdministratorSystemMenu();
}

