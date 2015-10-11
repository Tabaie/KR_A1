all: main.c Record.o Record.h TreeNode.o
	gcc TreeNode.o Record.o main.c -lm -o Tree


Record.o: Record.c Record.h
	gcc -c Record.c
	
TreeNode.o: TreeNode.c TreeNode.h
	gcc -c TreeNode.c
