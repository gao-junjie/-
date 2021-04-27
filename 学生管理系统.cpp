#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<algorithm>
using namespace std;

typedef struct user	{
	char username[100];		//�û��� 
	char password[100];		//���� 
}user;

typedef struct users {
	char username[100];		//�û��� 
	char password[100];		//���� 
	struct users* next;
}Users;

typedef struct node {
	char name[50];			//����
	char number[50];		//ѧ�� 
	char Class[50];			//רҵ�༶ 
	int Chinese;			//���ĳɼ� 
	int Math; 				//��ѧ�ɼ� 
	int English;			//Ӣ��ɼ�		 
	struct node *next;
}Node; 

bool cmp(int a,int b) {    			//��sort()�ı�Ϊ�Ӵ�С���� 
	return a > b;        			//���شӴ�С������
}

Users* userhead = (Users*)malloc(sizeof(Users));
Node* head = (Node*)malloc(sizeof(Node));
char PersonalNumber[50];			//ѧ������ѧ�� 
char classname[50]; 				//ѧ�����˰༶ 
char PersonalName[50];				//ѧ���������� 

void face1();						//ѡ��ͬ�û���¼ҳ�� 
void StudentInterFace();			//ѧ����¼ҳ�� 
void TeacherInterFace();			//��ʦ��¼ҳ�� 
void AdministratorInterFace();		//����Ա��¼ҳ�� 
void RegisterFace();				//ѧ���û�ע��ҳ�� 
void TeacherRegisterFace();			//��ʦ�û�ע��ҳ�� 
void StudentSystemMenu();			//ѧ��ϵͳҳ�� 
void TeacherSystemMenu();			//��ʦϵͳҳ�� 
void AdministratorSystemMenu();		//����Աϵͳҳ��     		 
void PersonalInformation();			//���������Ϣ
void read();						//��ȡ�༶�ļ� 
void DisplayList();					//�������ɼ�
void DisplayPersonalInformation();	//������˳ɼ� 
void PersonalGradeAnalysis();		//�������˳ɼ� 
void TeacherInformation();			//�����ʦ��Ϣ
void AddStudentInformation();		//�����µ�ѧ����Ϣ 
void DeleteStudentInformation();	//ɾ��ѧ����Ϣ				
void ChangeStudentInformation();	//�޸�ѧ����Ϣ				
void SearchStudentInformation();	//��ѯѧ����Ϣ				
void save();						//����ѧ����Ϣ				
void ClassGradeAnalysis();			//�����༶�ɼ�	
void InterTeacherSystem();			//����Ա�����ʦϵͳ 
void AddAccounts();					//�����˺ż����� 
void DeleteAccounts();				//ɾ���˺ż����� 
void SaveAccounts();				//�����û��˺ż����� 
void ReadAccounts();				//��ȡ�û��˺ż����� 
void DisplayAccounts();				//��������û��˺ż�����
void ChangeAccount();				//�޸��û�����
void SearchAccount();				//�����û��˺ż�����
void ReenterStudentInformation();   //����¼��ѧ����Ϣ 

int main() {	
	head -> next = NULL; 
	face1();
	return 0;
}
void face1() {
	fflush(stdin);
	printf("============ �� ѡ �� �� ¼ �� ʽ ============\n\n\n\n");
	printf("\t1.\t ѧ �� �� ¼  \n\n");
	printf("\t2.\t �� ʦ �� ¼  \n\n");
	printf("\t3.\t�� �� Ա �� ¼\n\n");
	printf("\t4.\t ѧ �� ע ��   \n\n");
	printf("\t5.\t �� ʦ ע ��   \n\n");
	printf("\t0.\t   ��   ��   \n\n\n"); 
	printf("��ѡ��");
	char facekey[100];
	scanf("%s",&facekey);
	//face1key = getchar() - '0';
	//fflush(stdin);
	//scanf("%c",&face1key);			//ѡ��ͬϵͳ 
	//face1key = getch() - 48;			//ѡ��ͬϵͳ
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
		printf("\n\n\t## ��Чָ�� ���������� ##");
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
	printf("\n\n     ѧ����¼     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### �ļ�Ϊ�գ�����ע�ᣡ#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//ת��ע�����	 
	}
	fclose(fp); 
	fp = fopen("StudentAccounts.txt","r");
	printf("\n �û��� :");
	scanf("%s",name);
	printf("\n ��  �� :");
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
		printf("\n\n============ ��½�ɹ��� ============\n");
		Sleep(800);
		system("cls");
		PersonalInformation();
	}
	else {
		printf("\n\n\n ##### ����������벻��ȷ ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  ������ת����ҳ......");
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
	printf("\n\n     ��ʦ��¼     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### �ļ�Ϊ�գ�����ע�ᣡ#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//ת��ע�����	 
	}
	fclose(fp); 
	fp = fopen("TeacherAccounts.txt","r");
	printf("\n �û��� :");
	scanf("%s",name);
	printf("\n ��  �� :");
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
		printf("\n\n============ ��½�ɹ��� ============\n");
		Sleep(800);
		system("cls");
		TeacherInformation();
	}
	else {
		printf("\n\n\n ##### ����������벻��ȷ ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  ������ת����ҳ......");
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
	printf("\n\n     ����Ա��¼     \n\n");
	if (fp == NULL) {
		printf("\n\n\t  ##### �ļ�Ϊ�գ�����ע�ᣡ#####"); 
		Sleep(800);
		system("cls");
		RegisterFace(); 						//ת��ע�����	 
	}
	fclose(fp); 
	fp = fopen("AdministratorAccounts.txt","r");
	printf("\n���������Ա��Կ :");
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
		printf("\n\n\n\n============ ��½�ɹ��� ============\n");
		Sleep(800);
		system("cls");
		AdministratorSystemMenu();
	}
	else {
		printf("\n\n\n\t ##### ������Ĺ���Ա��Կ����ȷ ####\n");
		printf("\n===================================\n\n");
		printf("\n\n\t  ������ת����ҳ......");
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
	printf("\n\t   ��ѧ �� �� �� ע �᡿     \n");
	printf("\n�������û�����");
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
		printf("\n\n\n\t##### ���û����Ѵ��ڣ����������룡#####"); 
		Sleep(1000);
		system("cls");
		RegisterFace(); 
	}
	else {	
		while (1) {
			printf("\n����������  ��");
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
		printf("\n\n\n\t ##### ע��ɹ� ####\n");
		printf("\n\t======================\n\n");
		printf("\n\n\t������ת����ҳ......");
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
	printf("\n\t  ���� ʦ �� �� ע �᡿     \n");
	printf("\n�������û�����");
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
		printf("\n\n\n\t##### ���û����Ѵ��ڣ����������룡#####"); 
		Sleep(1000);
		system("cls");
		TeacherRegisterFace(); 
	}
	else {	
		while (1) {
			printf("\n����������  ��");
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
		printf("\n\n\n\t ##### ע��ɹ� ####\n");
		printf("\n\t======================\n\n");
		printf("\n\n\t������ת����ҳ......");
		Sleep(1000);
		system("cls"); 
		face1();	
	}
}
void StudentSystemMenu() {
	fflush(stdin);
	system("cls"); 
	read();
	printf("============ �� ӭ ʹ �� ѧ �� ϵ ͳ ҳ �� ============\n\n\n");
	printf("\t1.\t  ��  ��  ��  ѯ\n\n");
	printf("\t2.\t �� ѯ �� �� �� ��\n\n");
	printf("\t3.\t  ��  ��  ��  ��\n\n");
	printf("\t0.\tע������������½ҳ��\n\n\n\n");
	printf("\t��ѡ��");
	char key;
	key = getchar() - '0';			//ѡ��ͬ����
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
			printf("\n\n\t## ��Чָ�� ���������� ##");
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
	printf("============ �� ӭ ʹ �� �� ʦ ϵ ͳ ҳ �� ============\n\n\n");
	printf("\t1.\t �����µ�ѧ����Ϣ\n\n");
	printf("\t2.\t ɾ �� ѧ �� �� Ϣ\n\n");
	printf("\t3.\t �� �� ѧ �� �� Ϣ\n\n");
	printf("\t4.\t �� ѯ ѧ �� �� Ϣ\n\n");
	printf("\t5.\t �� �� �� �� �� ��\n\n");
	printf("\t6.\t �� �� �� �� �� ��\n\n");
	printf("\t7.\t ��   ��   ��   ��\n\n");
	printf("\t0.\tע������������½ҳ��\n\n\n\n");
	printf("\t��ѡ��");
	char key;
	key = getchar() - '0';			//ѡ��ͬ����
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
			printf("\n\n\n\n\t\t\t ======== �ѳɹ�������Ϣ ========\n\n\n\n\n");
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
			printf("\n\n\t## ��Чָ�� ���������� ##");
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
	printf("============ �� ӭ ʹ �� �� �� Ա ϵ ͳ ҳ �� ============\n\n\n");
	printf("\t1.\t �����ʦ�˽�����Ϣ�޸�\n\n");
	printf("\t2.\t  �� �� �� �� �� �� ��\n\n");
	printf("\t3.\t  ɾ �� �� �� �� �� ��\n\n");
	printf("\t4.\t  �� �� �� �� �� �� ��\n\n");
	printf("\t5.\t  �� �� �� �� �� �� ��\n\n");
	printf("\t6.     �� �� �� �� �� �� �� �� ��\n\n");
	printf("\t7.     �� �� �� �� �� �� �� �� ��\n\n");
	printf("\t8.\t �� �� ¼ �� ѧ �� �� Ϣ\n\n");
	printf("\t0.\t  ע������������½ҳ��\n\n\n\n");
	printf("\t��ѡ��");
	char key;
	key = getchar() - '0';			//ѡ��ͬ����
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
			printf("\n\n\n\t ====== �ѱ���ɹ� ======\n\n\n");
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
			printf("\n\n\t## ��Чָ�� ���������� ##");
			Sleep(800);
			system("cls");
			fflush(stdin);
			AdministratorSystemMenu();	
	}
}
void PersonalInformation() {
	printf("\t========== ������Ϣ ==========\n\n\n");
	printf("\t  ѧ    ��  ��");
	scanf("%s",PersonalNumber);
	printf("\n");
	printf("\t  ��    ��  ��");
	scanf("%s",PersonalName);
	printf("\n");
	printf("\tר ҵ �� �� ��");
	scanf("%s",classname);
	if (strcmp(classname,"����1��") == 0 || strcmp(classname,"����2��") == 0 || strcmp(classname,"����3��") == 0 ||strcmp(classname,"����4��") == 0 ||strcmp(classname,"����5��") == 0) {
		read();
		Node* q = head -> next;
		while (q != NULL) {
			if (strcmp(PersonalNumber,q -> number) == 0 && strcmp(PersonalName,q -> name) == 0) {
				StudentSystemMenu();
			}
			q = q -> next;
		} 
	}
	printf("\n\n\n\n\n\t\t\t   ### ������Ϣ���� ������������һ�� ###\n"); 
	Sleep(1000);
	system("cls");
	face1();
}
void read() {
	char classname1[10];
	if (strcmp(classname,"����1��") == 0) {
		strcpy(classname1,"class1");
	} 
	if (strcmp(classname,"����2��") == 0) {
		strcpy(classname1,"class2");
	} 
	if (strcmp(classname,"����3��") == 0) {
		strcpy(classname1,"class3");
	}
	if (strcmp(classname,"����4��") == 0) {
		strcpy(classname1,"class4");
	}
	if (strcmp(classname,"����5��") == 0) {
		strcpy(classname1,"class5");
	}
	char name1[50];				//����
	char number1[50];			//ѧ�� 
	char Class1[50];			//רҵ�༶ 
	int Chinese1;				//���ĳɼ� 
	int Math1; 					//��ѧ�ɼ� 
	int English1;				//Ӣ��ɼ�	
	FILE *fp;  
	if (strcmp(classname1,"class1") == 0) {
    	fp = fopen("class1.txt","rb"); 			//��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	 	if (fp == NULL) {
       	 	printf("�����ڴ��ļ�\n");  
        	exit(0);                 			 //��ֹ����  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class1.txt","rb"); 			//��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    	if (FP == NULL) {  
        	printf("�޷����ļ�\n");  
        	exit(0); 							//��ֹ����  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(pnew -> number, number1);		//�Ѻ��ߵ����ݿ�����ǰ����
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//�����µĽڵ�
			p -> next = pnew;
			p = pnew;
            
            if(j == b)  
               break;  
            j++;  
        }
        fclose(FP);   					 //�ر��ļ� 
	} 
	if (strcmp(classname1,"class3") == 0) {
    	fp = fopen("class3.txt","rb");	 //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	 	if (fp == NULL) {
       	 	printf("�����ڴ��ļ�\n");  
        	exit(0);                 	 //��ֹ����  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class3.txt","rb"); 	//��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    	if (FP == NULL) {  
        	printf("�޷����ļ�\n");  
        	exit(0); 					//��ֹ����  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(pnew -> number, number1);		//�Ѻ��ߵ����ݿ�����ǰ����
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//�����µĽڵ�
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //�ر��ļ� 
	}
	if (strcmp(classname1,"class2") == 0) {
    	fp = fopen("class2.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	 	if (fp == NULL) {
       	 	printf("�����ڴ��ļ�\n");  
        	exit(0);                  //��ֹ����  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class2.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    	if (FP == NULL) {  
        	printf("�޷����ļ�\n");  
        	exit(0); //��ֹ����  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(pnew -> number, number1);		//�Ѻ��ߵ����ݿ�����ǰ����
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//�����µĽڵ�
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //�ر��ļ� 
	} 
	if (strcmp(classname1,"class4") == 0) {
    	fp = fopen("class4.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	 	if (fp == NULL) {
       	 	printf("�����ڴ��ļ�\n");  
        	exit(0);                  //��ֹ����  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class4.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    	if (FP == NULL) {  
        	printf("�޷����ļ�\n");  
        	exit(0); //��ֹ����  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(pnew -> number, number1);		//�Ѻ��ߵ����ݿ�����ǰ����
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//�����µĽڵ�
			p -> next = pnew;
			p = pnew;
            
  
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //�ر��ļ� 
	}
	if (strcmp(classname1,"class5") == 0) {
    	fp = fopen("class5.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	 	if (fp == NULL) {
       	 	printf("�����ڴ��ļ�\n");  
        	exit(0);                  //��ֹ����  
   	 	}   
    	int i = 0;  
    	while (!feof(fp)) {
        	fscanf(fp,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
        	i++;  
    	}
    	fclose(fp);  
    	FILE *FP;  
		FP = fopen("class5.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    	if (FP == NULL) {  
        	printf("�޷����ļ�\n");  
        	exit(0); //��ֹ����  
    	}  
    	int b = i-1;  
    	int j = 1;  
    	Node* p = head;
        while (!feof(FP)) {  
            fscanf(FP,"%s %s %s %d %d %d",name1, number1, Class1, &Chinese1, &Math1, &English1);
            Node* pnew = (Node*)malloc(sizeof(Node));
            strcpy(pnew -> name, name1);			//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(pnew -> number, number1);		//�Ѻ��ߵ����ݿ�����ǰ����
            strcpy(pnew -> Class, Class1);
            pnew -> Chinese = Chinese1;
            pnew -> Math = Math1;
            pnew -> English = English1;
                    
            pnew -> next = NULL;					//�����µĽڵ�
			p -> next = pnew;
			p = pnew;
            
            if (j == b)  
               break;  
            j++;  
        }
        fclose(FP);    //�ر��ļ� 
	}
} 
void DisplayList() {
	Node *q = head -> next;
	printf("������������������������������������������������������������������������\n");
  	printf("|  ��  ��  |  ѧ  ��  |  ר ҵ �� ��  |  ��  ��  |  ��  ѧ  |  Ӣ  ��  |\n");
  	printf("������������������������������������������������������������������������\n");
	if (q == NULL) {  
		printf("\t\t   ### ��û�������Ϣ���������Ϣ ###\n"); 
		printf("\n\n");
		printf("\t\t=========================================================\n");
		printf("\t\t=========================================================\n");
		printf("\n\n"); 
		printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
		getch();
		StudentSystemMenu();
    }  
    while (q) {   
		printf("|  %-6s  |  %s   |    %s    |  %5d   |  %5d   |  %5d   |\n",q -> name,q -> number,q -> Class,q -> Chinese,q -> Math,q -> English);  
		printf("������������������������������������������������������������������������\n");
  		q = q -> next;  
    }
    //system("pause");
  	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 	
}
void DisplayPersonalInformation() {
	Node* q = head -> next;
	while (q != NULL) {
		if (strcmp(q -> number,PersonalNumber) == 0) {
			printf("\n\n\t\t\t ====== �� �� �� �� ======\n\n\n\n\n"); 
			printf("\t\t\t ��     ��  ��%s\n\n",q -> name);
			printf("\t\t\t ѧ     ��  ��%s\n\n",q -> number);
			printf("\t\t\tר ҵ �� �� ��%s\n\n",q -> Class);
			printf("\t\t\t ��     ��  ��%d\n\n",q -> Chinese);
			printf("\t\t\t ��     ѧ  ��%d\n\n",q -> Math);
			printf("\t\t\t Ӣ     ��  ��%d\n\n",q -> English);
			break;
		}
		q = q->next;
	} 
	if (q == NULL) {
		printf("\n\n\n\n\t\t   ### ��Ϣ������ ���ܸ�����Ϣ���� ###\n"); 
		printf("\n");
		printf("\t\t=======================================================\n");
	}
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
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
	printf("\n\t============ �� �� �� �� ============\n\n\n\n");
	printf("\t�� �� �� �� �� �� �� �� �� ��%d\n\n",ChineseGradeRank);
	printf("\t�� ѧ �� �� �� �� �� �� �� ��%d\n\n",MathGradeRank);
	printf("\tӢ �� �� �� �� �� �� �� �� ��%d\n\n",EnglishGradeRank);
	printf("\t��  ��  ��  ��  ��  ��  �� ��%d\n\n",TotalGradeRank);
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	StudentSystemMenu();
}
void TeacherInformation() { 
	printf("\t========== ��ʦ��Ϣ ==========\n\n\n");

	printf("\n");
	printf("\t�� �� ר ҵ �� �� ��");
	scanf("%s",classname);
	if (strcmp(classname,"����1��") == 0 || strcmp(classname,"����2��") == 0 || strcmp(classname,"����3��") == 0 ||strcmp(classname,"����4��") == 0 ||strcmp(classname,"����5��") == 0) {
		TeacherSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### ������Ϣ���� ������������һ��###\n"); 
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
			printf("\n\n\t\t\t======= ����ѧ����Ϣ =======\n\n\n\n");
			printf("\t  ѧ     ��  ��");
			scanf("%s",pnew -> number);
			while (p1 != NULL) {
				if (strcmp(pnew -> number, p1 -> number) == 0) {
					printf("\n\n\n\t\t### ��ѧ���Ѵ��� ���������� ###\n\n\n");
					Sleep(1000); 
					system("cls");
					AddStudentInformation();
				}
				p1 = p1 -> next;
			}
			printf("\n\t  ��     ��  ��");
			scanf("%s",pnew -> name);
			printf("\n\t ר ҵ �� �� ��");
			scanf("%s",pnew -> Class);
			printf("\n\t �� �� �� �� ��");
			scanf("%d",&pnew -> Chinese);
			printf("\n\t �� ѧ �� �� ��");
			scanf("%d",&pnew -> Math);
			printf("\n\t Ӣ �� �� �� ��");
			scanf("%d",&pnew -> English);
			pnew -> next = NULL;
			q -> next = pnew;
			q = pnew;
		}
		q = q -> next;
	}
	save();
	printf("\n\n\n\n\t\t\t======= ����ѧ����Ϣ�ɹ� =======\n\n\n");
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	TeacherSystemMenu();
} 
void DeleteStudentInformation() {
	char DeleteNumber[50];
	char DeleteName[50];
	printf("\n\n\t ======== �����뼴��ɾ����ѧ���������Ϣ =======\n\n");
	printf("\n\tѧ   �ţ� ");
	scanf("%s",DeleteNumber);
	printf("\n\t��   ���� ");
	scanf("%s",DeleteName);
	Node* q = head;
	Node* pnew = head -> next;
	while (pnew != NULL) {
		if (strcmp(DeleteNumber, pnew -> number) == 0 && strcmp(DeleteName,pnew -> name) == 0) {
			q -> next = pnew -> next;
			free(pnew);
			save();
			printf("\n\n\t\t ===== ɾ���ɹ��� =====\n\n");
			printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
			getch(); 
			TeacherSystemMenu();
		}
		q = pnew;
		pnew = pnew -> next;
	}
	if (pnew == NULL) {
		printf("\n\n\t\t### δ�ҵ�������Ϣ �������������Ϣ���� ###"); 
	}
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	TeacherSystemMenu();
}
void ChangeStudentInformation() {
	char ChangeNumber[50];
	int choice;
	Node* q = head -> next;
	printf ("\n\n\n\t������Ҫ������Ϣ��ѧ����ѧ�� ��");
	scanf("%s",ChangeNumber);
	while (q != NULL) {
		if (strcmp(ChangeNumber, q -> number) == 0) {
			printf("\n\n\t ===== ��ѧ����Ϣ���� =====\n\n\n");
			printf("\t ��     ��  ��%s\n\n",q -> name);
			printf("\t ѧ     ��  ��%s\n\n",q -> number);
			printf("\tר ҵ �� �� ��%s\n\n",q -> Class);
			printf("\t ��     ��  ��%d\t",q -> Chinese);
			printf("\n\n\t�Ƿ�������ĳɼ���1.���ǣ�     2.����\t\t�����룺");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t���ĺ�����ĳɼ�Ϊ��");
				scanf("%d",&q -> Chinese); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### ��Чָ�� ���������������һ�� ###");
				getch(); 
				TeacherSystemMenu();
			}
			printf("\n\t ��     ѧ  ��%d\t",q -> Math);
			printf("\n\n\t�Ƿ������ѧ�ɼ���1.���ǣ�     2.����\t\t�����룺");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t���ĺ����ѧ�ɼ�Ϊ��");
				scanf("%d",&q -> Math); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### ��Чָ�� ���������������һ�� ###");
				getch(); 
				TeacherSystemMenu();
			}
			printf("\n\t Ӣ     ��  ��%d\t",q -> English);
			printf("\n\n\t�Ƿ����Ӣ��ɼ���1.���ǣ�     2.����\t\t�����룺");
			scanf("%d",&choice);
			if (choice == 1) {
				printf("\n\t���ĺ��Ӣ��ɼ�Ϊ��");
				scanf("%d",&q -> English); 
			}
			else if (choice == 2) {
			}
			else {
				printf("\n\n\n\t\t### ��Чָ�� ���������������һ�� ###");
				getch(); 
				TeacherSystemMenu();
			}
			save();
			printf("\n\n\n\t\t=========== ������Ϣ�ɹ� ===========");
			printf("\n\n\n\t\t\t### ���������������һ�� ###");
			getch(); 
			TeacherSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\t\t### δ�ҵ���ѧ����Ϣ ���������������һ�� ###");
		getch(); 
		TeacherSystemMenu();
	}
}
void SearchStudentInformation() {
	Node* q = head -> next;
	char SearchNumber[50];
	printf("\n\n\t������Ҫ��ѯ��ѧ��ѧ�� ��");
	scanf("%s",SearchNumber);
	while (q != NULL) {
		if (strcmp(SearchNumber,q -> number) == 0) {
			printf("\n\n\n\t\t\t ====== �� ѧ �� �� �� Ϣ ======\n\n\n\n\n"); 
			printf("\t\t\t ��     ��  ��%s\n\n",q -> name);
			printf("\t\t\t ѧ     ��  ��%s\n\n",q -> number);
			printf("\t\t\tר ҵ �� �� ��%s\n\n",q -> Class);
			printf("\t\t\t ��     ��  ��%d\n\n",q -> Chinese);
			printf("\t\t\t ��     ѧ  ��%d\n\n",q -> Math);
			printf("\t\t\t Ӣ     ��  ��%d\n\n",q -> English);
			break;
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\t\t\t\t   ### ��Ϣ������ ���ܸ�����Ϣ���� ###\n"); 
		printf("\n");
		printf("\t\t\t\t===========================================================\n");
	}
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	TeacherSystemMenu();
}
void save() {
	char classname1[10];
	if (strcmp(classname,"����1��") == 0) {
		strcpy(classname1,"class1");
	} 
	if (strcmp(classname,"����2��") == 0) {
		strcpy(classname1,"class2");
	} 
	if (strcmp(classname,"����3��") == 0) {
		strcpy(classname1,"class3");
	}
	if (strcmp(classname,"����4��") == 0) {
		strcpy(classname1,"class4");
	}
	if (strcmp(classname,"����5��") == 0) {
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
	printf("\n\n\t\t\t ========== �� �� �� �� �� �� ==========\n\n\n\n");
	printf("\t���ļ������� ��%d\t�����ʣ�%.2f %%\t\t����90�ּ��������� ��%d\n\n",ChinesePass,ChinesePass * 100.0/ All,ChineseHighest);
	printf("\t��ѧ�������� ��%d\t�����ʣ�%.2f %%\t\t��ѧ90�ּ��������� ��%d\n\n",MathPass,MathPass * 100.0 / All,MathHighest);
	printf("\tӢ�Ｐ������ ��%d\t�����ʣ�%.2f %%\t\tӢ��90�ּ��������� ��%d\n\n",EnglishPass,EnglishPass * 100.0 / All,EnglishHighest);
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	TeacherSystemMenu(); 
}
void InterTeacherSystem() {
	printf("\n\n\t��������Ҫ�����רҵ�༶ ��");
	scanf("%s",classname);
	if (strcmp(classname,"����1��") == 0 || strcmp(classname,"����2��") == 0 || strcmp(classname,"����3��") == 0 ||strcmp(classname,"����4��") == 0 ||strcmp(classname,"����5��") == 0) {
		TeacherSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### ������Ϣ���� ������������һ��###\n"); 
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
	printf("\n\t===== �����û��˺ż����� =====\n\n\n\n");
	printf("\n\t�������û�����");
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
		printf("\n\n\n\t##### ���û����Ѵ��ڣ����������룡#####"); 
		Sleep(1000);
		system("cls");
		AddAccounts(); 
	}
	else {	
		while (1) {
			printf("\n\t����������  ��");
			gets(code);
			fp = fopen("StudentAccounts.txt","a"); 
			fprintf(fp,"%s %s\n",name, code);
			fclose(fp);
			break;
		}
		printf("\n\n\n\t ##### ��ӳɹ� ####\n");
		printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
		getch(); 
		AdministratorSystemMenu();	
	}
} 
void DeleteAccounts() {
	char DeleteAccounts[100];
	printf("\n\n\t ======== ��ɾ �� �� �š� =======\n\n");
	printf("\n\t �� �� �� �� �� ");
	scanf("%s",DeleteAccounts);
	Users* q = userhead;
	Users* pnew = userhead -> next;
	while (pnew != NULL) {
		if (strcmp(DeleteAccounts, pnew -> username) == 0) {
			q -> next = pnew -> next;
			free(pnew);
			SaveAccounts();
			printf("\n\n\t\t ===== ɾ���ɹ��� =====\n\n");
			printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = pnew;
		pnew = pnew -> next;
	}
	if (pnew == NULL) {
		printf("\n\n\t\t### δ�ҵ����û� �������������Ϣ���� ###"); 
	}
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
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
	fp = fopen("StudentAccounts.txt","rb"); 			//��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
   	if (fp == NULL) {
       	printf("�����ڴ��ļ�\n");  
        exit(0);                 			 			//��ֹ����  
   	}   
    int i = 0;  
    while (!feof(fp)) {
        fscanf(fp,"%s %s",username1, password1);
        i++;  
    }
    fclose(fp);  
    FILE *FP;  
	FP = fopen("StudentAccounts.txt","rb"); 			//��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt
    if (FP == NULL) {  
        printf("�޷����ļ�\n");  
        exit(0); 										//��ֹ����  
    }  
    int b = i-1;  
	int j = 1;  
   	Users* p = userhead;
    while (!feof(FP)) {  
        fscanf(FP,"%s %s",username1, password1);
        Users* pnew = (Users*)malloc(sizeof(Users));
        strcpy(pnew -> username, username1);			//�Ѻ��ߵ����ݿ�����ǰ����  
        strcpy(pnew -> password, password1);			//�Ѻ��ߵ����ݿ�����ǰ����
                    
        pnew -> next = NULL;							//�����µĽڵ�
		p -> next = pnew;
		p = pnew;
            
        if(j == b)  
            break;  
        j++;  
    }
    fclose(FP);   										//�ر��ļ� 
}
void DisplayAccounts() {
	Users* q = userhead -> next;
	int i = 1; 
	printf("������������������������������������������\n");
  	printf("| ��� |    ��    ��    |    ��    ��    |\n");
  	printf("������������������������������������������\n");
  	if (q == NULL) {  
		printf("\t\t   ### ��û�������Ϣ���������Ϣ ###\n"); 
		printf("\n\n");
		printf("\t\t=========================================================\n");
		printf("\t\t=========================================================\n");
		printf("\n\n"); 
		printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
		getch();
		AdministratorSystemMenu();
    } 
	while (q != NULL) {
		printf("| %-4d |   %-10s   |   %-10s   |\n",i,q -> username,q -> password);  
		printf("������������������������������������������\n");
		i++;
  		q = q -> next; 
	}
	printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
	getch(); 
	AdministratorSystemMenu();
}
void ChangeAccount() {
	Users* q = userhead -> next;
	char ChangeUsername[100];
	printf("\n\n\t ������Ҫ���ĵ��û��˺� ��");
	scanf("%s",ChangeUsername); 
	while (q != NULL) {
		if (strcmp(ChangeUsername,q -> username) == 0) {
			printf("\n\n\t    ԭ   ��   ��    ��%s",q -> password);
			printf("\n\n\t  ��   ��   ��   �� ��");
			scanf("%s",q -> password); 
			SaveAccounts();
			printf("\n\n\t====== �޸ĳɹ� ======"); 
			printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\n\t\t### δ�ҵ����û���Ϣ ���������������һ�� ###");
		getch(); 
		AdministratorSystemMenu();
	} 
}
void SearchAccount() {
	Users* q = userhead;
	char SearchUsername[100];
	printf("\n\n\t ������Ҫ���ҵ��û��˺� ��");
	scanf("%s",SearchUsername); 
	while (q != NULL) {
		  if (strcmp(SearchUsername,q -> username) == 0) {
			printf("\n\n\t  ��     ��  ��%s",q -> password);
			printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
			getch(); 
			AdministratorSystemMenu();
		}
		q = q -> next;
	}
	if (q == NULL) {
		printf("\n\n\n\n\t\t### δ�ҵ����û���Ϣ ���������������һ�� ###");
		getch(); 
		AdministratorSystemMenu();
	}
} 
void ReenterStudentInformation() {
	int choice;
	printf("\n\t\t=========== �� �� ¼ �� ==========="); 
	printf("\n\n\t�����루����¼��ѧ����Ϣ�ģ�רҵ�༶ ��");
	scanf("%s",classname);
	if (strcmp(classname,"����1��") == 0 || strcmp(classname,"����2��") == 0 || strcmp(classname,"����3��") == 0 ||strcmp(classname,"����4��") == 0 ||strcmp(classname,"����5��") == 0) {
		read();
		Node *q, *end;
		end = head;
		do {
			q = (Node*)malloc(sizeof(Node));
			printf("\n\n\t ��    �� ��");
			scanf("%s",q -> name);
			printf("\n\t ѧ    �� ��");
			scanf("%s",q -> number);
			strcpy(q -> Class,classname);
			printf("\n\t ��    �� ��");
			scanf("%d",&q -> Chinese);
			printf("\n\t ��    ѧ ��");
			scanf("%d",&q -> Math);
			printf("\n\t Ӣ    �� ��");
			scanf("%d",&q -> English);
			q -> next = NULL;
			end -> next = q;		//β���½�� 
			end = q;	
			printf("\n\n\t��ѡ���Ƿ����¼����һλѧ����1.���ǣ�\t2.����");
			scanf("%d",&choice);
		} while (choice == 1);
		q -> next == NULL;
		save();
		printf("\n\n\t====== ¼��ɹ� ======"); 
		printf("\n\n\n\n\t\t\t## �����������������һ�� ##");
		getch(); 
		AdministratorSystemMenu();
	}
	printf("\n\n\n\n\n\t\t\t   ### ������Ϣ���� ������������һ��###\n"); 
	Sleep(1000);
	system("cls");
	AdministratorSystemMenu();
}

