/* * * * * * * * * * * * ArrayList in C * * * * * * * * * * * * * **
*By: Rafael Araújo                                                 *
*                                                                  *
*->Info:                                                           *
*                                                                  *
*The goal here is to practice some concepts learned in Data        *
*Structure class, in this case, simulate the properties and        *
* functionalities of an ArrayList. in this program, I'll be       *
*adding some extra functions to allow the user to interact with    *
*the list, the user be able to:                                    *
*                                                                  *
*1. Initialize the structure.                                      *
*2. Make the basic CRUD Operations                                 *
*3. See all the elements in the structure.                         *
*4. See how many elements are in the structure.                    *
*5. And more.                                                      *
*                                                                  *
*->Copyright Notice:                                               *
*                                                                  *
*Copyright 2019 Rafael Araújo                                      *
*                                                                  *
*Permission is hereby granted, free of charge, to any person       *
*obtaining a copy of this software and associated documentation    *
*files (the "Software"), to deal in the Software without           *
*restriction, including without limitation the rights to use,      *
*copy, modify, merge, publish, distribute, sublicense, and/or      *
*sell copies of the Software, and to permit persons to whom the    *
*Software is furnished to do so, subject to the following          *
*conditions:                                                       *
*                                                                  *
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,   *
*EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES   *
*OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND          *
*NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT       *
*HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,      *
*WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
*FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     *
*OTHER DEALINGS IN THE SOFTWARE.                                   *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

//Header files
#include<stdio.h>
#include<stdlib.h>
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  
//Constants
#define MAX_LENGTH 10
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  
//Global Variables
typedef int ELEMENT;

typedef struct{
	ELEMENT value;
	ELEMENT* current;
	ELEMENT* nextElement;
}NODE;

typedef NODE* NODE2;

typedef struct{
	NODE elements[MAX_LENGTH];
	ELEMENT length;
}ARRAYLIST;

ARRAYLIST* list;

char command; 

NODE input; 

int search;

ELEMENT update;

int functionCall = -1; //If the list is not initialized, this will be used to alert the user to initialize it.
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  
//Function signatures
void setLinkedList(ARRAYLIST* list);
int getLength(ARRAYLIST* list);
void listCommands();
void setValue(ARRAYLIST* list, NODE value);
void menu();
void getList(ARRAYLIST* list);
void getOrderedList(ARRAYLIST* list);
int findValue(ARRAYLIST* list, int value);
int findValueByIndex(ARRAYLIST* list, int index);
void updateValueByIndex(ARRAYLIST* list, int index, ELEMENT newValue);
void removeFromList(ARRAYLIST* list, int index);
void orderLookup(ARRAYLIST* list);
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

//Main
int main(void){
	list = (ARRAYLIST*)malloc(sizeof(ARRAYLIST));
	printf("       ---ArrayList implementation in C---\n");
	printf("Tip: The '>>' appears when you can type a command.\n");
	printf("Tip: The '>' appears when you need to type inputs to the functions.\n\n");
	printf("Press 'h' for help.\n");
	menu();
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void menu(){
    //listCommands();
    //getchar();
	//printf("Select an option from the menu.\n");
    
	printf(">>");
	scanf("%s", &command);
	
	switch(command){
		case 'h':
			listCommands();
			menu();
		case 's':
			setLinkedList(list);
			menu();
		case 'n':
			if(getLength(list)==-1){
				printf("Error: list needs to be initialized.\n");
			}else{
				printf("Number of elements in the list: %d\n>", getLength(list));
			}
			menu();
		case 'a':
			system("CLS");
			printf("Please, enter a value to be added: \n>");
			scanf("%d", &input);
			setValue(list, input);
			menu();
		case 'p':
			getList(list);
			menu();
		case 'o':
			getOrderedList(list);
			menu();
		case 'f':
			system("CLS");
			if(functionCall==-1){
				printf("Error: list empty or uninitialized.\n");
				menu();
			}else{
				printf("Please, enter a number: \n>");
				scanf("%d", &search);
				int auxSearch = findValue(list, search);
				if(auxSearch!=-1){
					printf("Value found, list index: %d\n", auxSearch);
				}else{
					printf("Error, value not found.\n");
				}
			}
			menu();
		case 'i':
			system("CLS");
			if(functionCall!=-1){
				printf("Please, enter a number: \n>");
				scanf("%d", &search);
				if(findValueByIndex(list, search)==-1){
					printf("Error: value not found or index invalid.\n");
				}else{
					printf("list[%d]: %d\n", search, findValueByIndex(list, search));
				}
			}else{
				printf("Error: list needs to be initialized.\n");
			}
			menu();
		case 'u': 
			system("CLS");
			if(functionCall!=-1){
				printf("Please, select the position of list to be updated: ");
				printf("(From %d to %d):\n>", 0, list->length-1);
				scanf("%d", &search);
				
				printf("Please, enter the new value for this position: \n>");
				scanf("%d", &update);
				updateValueByIndex(list, search, update);
				menu();
			}else{
				printf("Error: list empty or uninitialized.\n");
				menu();
			}
		case 'd':
			system("CLS");
			if(functionCall==-1){
				printf("Error: list empty or unitialized.\n");
				menu();
			}else{
				printf("Please, enter the index of list to be removed: (from %d to %d)\n>", 0, list->length-1);
				scanf("%d", &search);
				removeFromList(list, search);
				menu();
			}
		case 'l':
			system("CLS");
			if(functionCall==-1){
				printf("Error: list empty or uninitialized.\n");
				menu();
			}else{
				orderLookup(list);
			}
		case 'x':
			printf("\nProgram Closed");
			exit(0);
		default:
			system("CLS");
			printf("Invalid command, press 'h' for help.\n");
			menu();
	}	
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void listCommands(){
	system("CLS");
	printf("List of valid commands: \n\n");
	printf("'h' -> Help.\n");
	printf("'s' -> Initializes the list.\n");
	printf("'n' -> Get the number of elements in the list.\n");
	printf("'a' -> Add a value to the end of the list. \n");
	printf("'p' -> Prints the list on the screen.\n");
	printf("'o' -> Shows the order of elements.\n");
	printf("'f' -> Checks if a value is in the list and returns it's index.\n");
	printf("'i' -> Locates a value from the list by a given index.\n");
	printf("'u' -> Update a value of the list.\n");
	printf("'d' -> Removes a value from the list.\n");
	printf("'l' -> Shows the previous and next elements of a element in the list.\n");
	
	printf("\n");
	printf("'x' -> Close the program.\n");
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void setLinkedList(ARRAYLIST* list){
	system("CLS");
	list->length=0;
	functionCall = 1;
	printf("Linked List initialized.\n");
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

int getLength(ARRAYLIST* list){
	system("CLS");
	if(functionCall!=-1){
		return list->length;
	}else{
		return -1;
	}
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void setValue(ARRAYLIST* list, NODE value){
	functionCall = 1;
	system("CLS");
	if(list->length==0){
		list->elements[list->length] = value;
		
		list->elements[list->length].current = list->elements[list->length].current; //(ELEMENT)
		
		list->length++;
		printf("Element added.\n");
	}else if(list->length>0 && list->length<MAX_LENGTH){
		list->elements[list->length] = value;
		list->elements[list->length].current = list->elements[list->length].current; // (ELEMENT)
		list->elements[list->length-1].nextElement = list->elements[list->length].current;
		list->length++;
		printf("Element added.\n");
	}else if(!(list->length<0 && list->length==0 && list->length>0)){
		printf("Error: list empty or uninitialized.\n");
		functionCall = -1;	
	}else{
		printf("List full.\n");	
	}
		
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void getList(ARRAYLIST* list){
	int i;
	
	system("CLS");
	printf("Linked List: \n\n");
	if(functionCall==-1){
		printf("Error: list empty or uninitialized.\n");
	}else{
		for(i=0;i<list->length;i++){
			printf("%d", list->elements[i].current);
			if(i!=list->length-1){
				printf("->");
			}else{
				printf("->X");
			}
		}
	}
	printf("\n");
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void getOrderedList(ARRAYLIST* list){
	int i;
	
	system("CLS");
	printf("Order of elements:\n\n");
	if(functionCall==-1){
		printf("Error: list empty or uninitialized.\n");
	}else{
		printf("Current -> Next\n");
		for(i=0;i<list->length;i++){
			if(i!=list->length-1){
				printf("%d  %d -> %d\n", list->elements[i].value,  list->elements[i].current, list->elements[i].nextElement);
			}else{
				printf("%d -> X\n", list->elements[i].current);
			}
		}
	}
	
	printf("\n");
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

int findValue(ARRAYLIST* list, int value){
	int i, index;
	int found = 0;
	
	system("CLS");
	printf("Searching...\n");
	if(functionCall!=-1){
		for(i=0;i<list->length;i++){
			if(*list->elements[i].current==value){
				found = 1;
				index = i;
				break;
			}else{
				found = -1;
			}
		}
	}else{
		found = -1;
	}
	
	if(found==1){
		return index;
	}else{
		return found;
	}
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

int findValueByIndex(ARRAYLIST* list, int index){
	int i;
	
	system("CLS");
	printf("Searching...\n");
	if(index<=list->length && index>=0){
		return *list->elements[index].current;
	}else{
		return -1;
	}
}

//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void updateValueByIndex(ARRAYLIST* list, int index, ELEMENT newValue){
	system("CLS");
	char confirmation;
	
	if(index<=list->length && index>=0){
		printf("Confirm changes?(y/n): %d->%d\n", list->elements[index].current, newValue);
		printf(">");
		scanf("%s", &confirmation);
			switch(confirmation){
				case 'y':
					list->elements[index].value = newValue;
					*list->elements[index].current = (ELEMENT)list->elements[index].value;
					list->elements[index-1].nextElement = list->elements[index].current;
					printf("Changes saved.\n");
					menu();
				case 'n':
					printf("Changes not saved.\n");
					menu();
				default:
					printf("invalid command. Press 'y' or 'n' to continue.\n>");
					scanf("%s", &confirmation);
			}
		}else{
			printf("Error: list index invalid.\n");
		}
	}
	
//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  
	
void removeFromList(ARRAYLIST* list, int index){
		int i;
		char confirmation;
		NODE aux;
		
		if(functionCall==-1){
			printf("Error: list empty or uninitialized.\n");
			menu();
		}else{
				if(index<0 || index>list->length-1){
				printf("Error: list index invalid. Try again.\n");
				menu();
			}else{
				printf("Do you want to remove item %d?(y/n)\n>", list->elements[index].current);
				scanf("%s", &confirmation);
				switch(confirmation){
					case 'y':
						for(i = index;i<list->length-1;i++){
							list->elements[i] = list->elements[i+1];
						}
						list->length--;
						list->elements[index-1].nextElement = list->elements[index].current;
						printf("Item removed.\n");
						menu();
					case 'n':
						printf("Item not removed.\n");
						menu();
					default:
						printf("Error: invalid command. Press 'y' or 'n' to continue.\n>");
						scanf("%s", &confirmation);
				}
			}
		}
	}
	
//--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  

void orderLookup(ARRAYLIST* list){
	system("CLS");
	
	printf("Please, enter a list index (from %d to %d): \n>", 0, list->length-1);
	scanf("%d", &search);
	
	if(search>=0 && search<list->length){
		if(search==0){
			printf("\nOrder of elements:\n\n");
			printf("Previous|Actual|Next\n");
			printf("X       |%d    |%d\n", list->elements[search].current, list->elements[search].nextElement);
			menu();
		}else if(search == list->length-1){
			printf("\nOrder of elements:\n\n");
			printf("Previous|Actual|Next\n");
			printf("%d       |%d    |X\n", list->elements[search-1].current, list->elements[search].current);
			menu();
		}else{
			printf("\nOrder of elements:\n\n");
			printf("Previous|Actual|Next\n");
			printf("%d       |%d    |%d\n", list->elements[search-1].current, list->elements[search].current, list->elements[search].nextElement);
			menu();
		}
	}else{
		printf("Error: Index invalid.\n");
		menu();
	}
}
