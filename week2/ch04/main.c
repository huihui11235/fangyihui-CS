
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
typedef int Status;
#define HASHSIZE 6                          //定义散列表表长//
#define NULLKEY -32768

typedef struct {
	int *elem;
	int count;
} HashTable;

int x = 0;

Status initHashTable(HashTable *hash);
int hashFun(int key);


Status initHashTable(HashTable *hash) {
	//初始化散列表//
	int i;

	x = HASHSIZE;
	hash->count = x;
	hash->elem = (int *)malloc(x * sizeof(int));
	for (i = 0; i < x; i++)
		hash->elem[i] = NULLKEY;

	return TRUE;
}


int hashFun(int key) {
	return key % x; 					//除留余数法//
}

void insertHash(HashTable *hash, int key) {
	int addr = hashFun(key);
	while (hash->elem[addr] != NULLKEY) {
		addr = (addr + 1) % x;
	}
	hash->elem[addr] = key;
}

Status searchHash(HashTable hash, int key, int *addr) {
	*addr = hashFun(key);
	while (hash.elem[*addr] != key) {
		*addr = (*addr + 1) % x;
		if (hash.elem[*addr] == NULLKEY || *addr == hashFun(key))
			return FALSE;
	}

	return TRUE;
}

int main() {
	int arr[HASHSIZE] = { 12, 15, 31, 40, 68, 72};
	int key = 61;		//关键字//
	int addr;
	HashTable hash;

	initHashTable(&hash);

	//散列表查找关键字//
	for (int i = 0; i < x; i++)
		insertHash(&hash, arr[i]);

	int result = searchHash(hash, key, &addr);
	if (result)
		printf("查找 %d 的散列表地址为：%d \n\n", key, addr);
	else
		printf("查找 %d 失败。\n\n", key);


	for (int i = 0; i < x; i++) { //遍历
		key = arr[i];
		searchHash(hash, key, &addr);
		printf("查找 %d 的散列表地址为：%d \n", key, addr);
	}
	printf("\n");

	return 0;
}
