# include <stdio.h>
# include <malloc.h>


# define HEAD 1
# define TAIL 0
# define FAIL 0
# define SUSSCESS 1


typedef int Value;
typedef struct Entry{
	struct Entry *next,*prev;
	Value value;
}DoubleLink;


DoubleLink* create(DoubleLink* head);
DoubleLink* insert(DoubleLink* node);
int delete(DoubleLink* node, DoubleLink* head);
DoubleLink* search(DoubleLink* head, Value value);
void print(DoubleLink* start);
Value input();
int countNode(DoubleLink* head);


int main(){
	DoubleLink *head = NULL;
	Value val = 0;
	int cnt = 0;
	printf("创建双向链表\n输入节点数\n");
	scanf("%d", &cnt);
	head = create(head);
	for(; cnt > 1; cnt--){
	    create(head);
    }
	printf("输入搜索值\n");
	scanf("%d", &val);
	DoubleLink* find = search(head, val);
	if(find)
		printf("找到\n");
		printf("是否删除（y/n）");
		fflush(stdin);
		char del;
		scanf("%c", &del);
		if('y' == del || 'Y' == del){
		    delete(find, head);
        }-
		printf("未找到\n");
	printf("打印链表\n");
	print(head);
	printf("节点数%d\n", countNode(head));
	
	return 0;
}


Value input(){
	Value val;
	printf("输入值\n");
	scanf("%d", &val);
	return val;
}


DoubleLink* create(DoubleLink* head){
	if(!head){
		head = (DoubleLink*)malloc(sizeof(DoubleLink));
		head->next = head;
		head->prev = head;
		head->value = input();
	}else{
		DoubleLink *p = head->prev;
		insert(p);
	}
	return head;
}


DoubleLink* insert(DoubleLink* node){
	if(!node){
		return NULL;
	}
	DoubleLink* newnode = (DoubleLink*)malloc(sizeof(DoubleLink));
	newnode->next = node->next;
	node->next = newnode;
	newnode->prev = newnode->next->prev;
	newnode->next->prev = newnode;
	newnode->value = input();
	return newnode;
}


int delete(DoubleLink* node, DoubleLink* head){
    if(head == node){
        head = node->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
	free(node);
	return SUSSCESS;
}


DoubleLink* search(DoubleLink* head, Value value){
	DoubleLink* p = head;
	do{
		if(p->value == value){
			return p;
		}
		p = p->next;
	}while(p != head);
	return NULL;
}


int countNode(DoubleLink* head){
    int count = 0;
    DoubleLink* p = head;
    do{
        p = p->next;
        count++;
    }while(head != p);
    return count;
}


void print(DoubleLink* head){
	DoubleLink* p = head;
	do{
		printf("%d\n", p->value);
		p = p->next;
	}while(p != head);
}
