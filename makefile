lab0: LAB_0/main.c
	gcc LAB_0/main.c -o lab0 -lm
lab1: LAB_1/main.c
	gcc LAB_1/main.c -o lab1 -lm
lab2: LAB_2/main.c
	gcc LAB_2/main.c -o lab2 -lm
clean:
	rm -rf lab0