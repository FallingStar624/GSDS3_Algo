/*
다시 풀기!
*/
#include <stdio.h>
#include <string.h>

char lt[600001];
char rt[600001];
int lenlt = 0;
int lenrt = 0;

void move_left() {
	if(lenlt > 0)
		rt[lenrt++] = lt[--lenlt];
}

void move_right() {
	if(lenrt > 0)
		lt[lenlt++] = rt[--lenrt];
}

void delete() {
	if(lenlt > 0)
		lenlt--;
}

void insert(char ch) {
	lt[lenlt++] = ch;
}

void refresh() {
	while(lenrt --)
		lt[lenlt++] = rt[lenrt];
	lt[lenlt] = 0;
}

void readline(char* buf, int* len) {
	int k;
	gets(buf);
	k = strlen(buf);
	while(buf[k-1]=='\r' || buf[k-1]=='\n')
		buf[--k] = 0;
	*len = k;
}

int main() {
	int n;
	char buf[10];
	readline(lt, &lenlt);
	scanf("%d\n", &n);
	while(n--) {
		gets(buf);
		switch(buf[0]) {
		case 'L' :
			move_left();
			break;
		case 'D' :
			move_right();
			break;
		case 'B' :
			delete();
			break;
		case 'P' :
			insert(buf[2]);
			break;
		}
	}
	refresh();
	printf("%s\n", lt);
}