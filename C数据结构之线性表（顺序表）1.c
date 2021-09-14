#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10

typedef struct //˳���Ĵ洢�ṹ
{
    int *elem;    //��̬����ռ��ܵ�ַ
    int length;   //���Ա�ǰ����
    int listsize; //���Ա���󳤶�
} SqList;

int InitList(SqList *L);                        //��������Ա�L
int DestoryList(SqList *L);                     //�������Ա�L
int ClearList(SqList *L);                       //������Ա�L
int ListEmpty(SqList L);                        //�ж����Ա��Ƿ�Ϊ��
int Length(SqList L);                           //�����Ա�Ԫ�ظ���
int GetElem(SqList L, int i, int *e);           //����λ��Ϊi��Ԫ�أ���e����
int LocateElem(SqList L, int e);                //����Ԫ��e,���ص�һ�γ��ֵ�λ��
int PriorElem(SqList L, int cur_e, int *pre_e); //��pre_e����cur_e��ǰ��
int NextElem(SqList L, int cur_e, int *next_e); //��next_e����cur_e�ĺ��
int ListInsert(SqList *L, int i, int e);        //��Ԫ��e�����λ��i;
int ListDelete(SqList *L, int i, int *e);       //ɾ��λ��i��Ԫ�أ���e������ֵ
int ListTraverse(SqList L);                     //��������������L
int menu();                                     //�˵�

int main()
{
    SqList L;
    int i, e, pre_e, next_e; //i���λ��e���Ԫ��ֵ��pre_e���e��ǰ����nexrt_e���e�ĺ��
    int option;
    menu();
    do
    {
        printf("\n����ѡ��\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            InitList(&L);
            printf("��ʼ���ɹ�\n");
            break;
        case 2:
            DestoryList(&L);
            printf("���ٳɹ�\n");
            break;
        case 3:
            ClearList(&L);
            printf("��ճɹ�\n");
            break;
        case 4:
            if (ListEmpty(L)) //����ֵΪ1Ϊ��
                printf("���Ա�Ϊ��\n");
            else
                printf("���Ա�Ϊ��\n");
            break;
        case 5:
            printf("���Ա�ǰ����Ϊ%d\n", Length(L));
            break;
        case 6:
            printf("�������λ��i\n");
            scanf("%d", &i);
            GetElem(L, i, &e);
            break;
        case 7:
            printf("����Ҫ���ҵ�Ԫ��e\n");
            scanf("%d", &e);
            LocateElem(L, e);
            break;
        case 8:
            printf("����Ҫ���ҵ�Ԫ��e\n");
            scanf("%d", &e);
            PriorElem(L, e, &pre_e);
            break;
        case 9:
            printf("����Ҫ���ҵ�Ԫ��e\n");
            scanf("%d", &e);
            NextElem(L, e, &next_e);
            break;
        case 10:
            printf("�������λ��i��Ԫ��e\n");
            scanf("%d%d", &i, &e);
            if (i < 1 || i > L.length + 1)
            {
                printf("����λ��Ƿ�\n");
                break;
            }
            ListInsert(&L, i, e);
            break;
        case 11:
            printf("������Ҫɾ����λ��i\n");
            scanf("%d", &i);
            if (i < 1 || i > L.length)
            {
                printf("ɾ��λ��Ƿ�\n");
                break;
            }
            e = ListDelete(&L, i, &e);
            printf("ɾ����\n");
            ListTraverse(L);
            printf("\nɾ��Ԫ��Ϊ%d\n", e);
            break;
        case 12:
            printf("�������Ϊ��\n");
            ListTraverse(L);
            break;
        case 13:
            break;
        default:
            printf("����ѡ��Ϸ�\n");
            break;
        }
    } while (option != 13); //option==13�˳�
    return 0;
}

int InitList(SqList *L) //��ʼ������
{
    L->elem = (int *)malloc(MAX * sizeof(int)); //��̬�����ڴ�
    if (!L->elem)
    {
        printf("��̬�����ڴ�ʧ��\n");
        exit(0);
    }
    L->length = 0; //��ʼ������Ϊ0
    L->listsize = MAX;
    return 0;
}

int DestoryList(SqList *L) //���ٲ���
{
    if (L->elem)
        free(L->elem); //�ͷſռ�
    L->elem = NULL;    //ָ��ָ��
    return 0;
}

int ClearList(SqList *L) //��ղ���
{
    L->length = 0;
    return 0;
}

int ListEmpty(SqList L) //�ж��Ƿ�Ϊ�ղ���

{
    if (L.length == 0)
        return 1;
    else
        return 0;
}

int Length(SqList L) //
{
    return L.length;
}

int GetElem(SqList L, int i, int *e) //��λ����Ҳ���
{
    if (i < 1 || i > L.length)
    {
        printf("λ��%d���Ϸ�\n", i);
        return 0;
    }
    else
    {
        printf("Ԫ��ֵΪ%d\n", L.elem[i - 1]);
        return *e = L.elem[i - 1];
    }
}

int LocateElem(SqList L, int e) //��λ�ò��Ҳ���
{
    int i, flag = 1; //flag��־��û�ҵ�Ϊ1
    for (i = 0; i < L.length; i++)
        if (L.elem[i] == e)
        {
            flag = 0;
            printf("����Ԫ��λ��Ϊ%d", i + 1);
            return i + 1; //�ҵ�����λ�����
        }
    if (flag)
    {
        printf("��ѯ�޹�");
        return 0; //ʧ�ܷ���0
    }
}

int PriorElem(SqList L, int cur_e, int *pre_e) //��ǰ������
{
    int i, k = -1; //k���cur_e��ǰ���������꣬��ʼ��ֵΪ-1
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == cur_e)
        {
            k = i - 1;
            break;
        }
    }
    if (k > -1) //��ǰ��
    {
        *pre_e = L.elem[k];
        printf("ǰ��Ԫ��Ϊ%d\n", *pre_e);
        return *pre_e;
    }
    else //��ǰ��
    {
        printf("��ѯ�޹�\n");
        return 0;
    }
}

int NextElem(SqList L, int cur_e, int *next_e) //���̲���
{
    int i, k = -1; //k���cure_e�ĺ���������꣬��ʼֵΪ-1
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == cur_e)
        {
            k = i + 1;
            break;
        }
    }
    if (k > 0 && k < L.length) //û��Ԫ�غ������Ϊ0�����һ��Ԫ��Ҳû�к��
    {
        *next_e = L.elem[k];
        printf("���Ԫ��Ϊ%d\n", next_e);
        return *next_e;
    }
    else //�޺��
    {
        printf("��ѯ�޹�\n");
        return 0;
    }
}

int ListInsert(SqList *L, int i, int e) //�������
{
    if (i < 1 || i > L->length + 1)
    {
        printf("����λ��%d���Ϸ�\n", i);
        return 0;
    }
    if (L->length == L->listsize) //˳�������
    {
        printf("˳�������,����ʧ��\n");
        return 0;
    }
    for (int k = L->length; k > i - 1; k--) //λ��i��֮���Ԫ��ȫ������
    {
        L->elem[k] = L->elem[k - 1];
        L->elem[i - 1] = e;
        L->length++; //��ǰ���ȼ�һ
    }
    return e;
}

int ListDelete(SqList *L, int i, int *e) //ɾ������
{
    if (i < 1 || i > L->length)
    {
        printf("λ��%d���Ϸ�\n", i);
        return 0;
    }
    *e = L->elem[i - 1];
    for (int k = i - 1; k < L->length; k++) //λ��i��֮���Ԫ��ȫ��ǰ��
        L->elem[k] = L->elem[k + 1];
    L->length--; //����1
    return *e;
}

int ListTraverse(SqList L) //��������Ԫ��
{
    if (ListEmpty(L))
    {
        printf("˳���Ϊ��\n");
        return 0;
    }
    for (int i = 0; i < L.length; i++)
        printf("%-5d", L.elem[i]);
    return 0;
}

int menu()

{
    printf("\n\n\n**************************************�˵�**********************************************\n");
    printf("****************************************************************************************\n");
    printf("**********1����ʼ��InitList(*L),2������DestoryList(*L)**********\n");
    printf("**********3�����ClearList(*L) ,4���б��ListEmpty(L)**********\n");
    printf("**********5�����Length(L),6����λ����GetElem(L,i,*e)**********\n");
    printf("**********7����ֵ����LocateElem(L,e),8����ǰ��PriorElem(L, cur_e,*pre_e)**********\n");
    printf("**********9������NextElem(L,cur_e,*next_e),10������ListInsert(*L, i, e)**********\n");
    printf("**********11��ɾ��ListDelete(*L, i,*e),12������(���)ListTraverse(L)**********\n");
    printf("**********13���˳�\n");
    return 0;
}
