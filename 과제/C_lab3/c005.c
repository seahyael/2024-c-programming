// Enter your student ID and Fullname
//22300045 권세아

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 
void saveChannels(struct st_channel* c[], int size);
void saveReport(struct st_channel* c[], int size);

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
    int i = 0, j = 0;
    float sum[5] = {}, average[5] = {};
	int coun[5] = {}, top[5] = {}, topName[5] = {};
    for(j = 0; j<size; j++){
        for(i = 0; i<5; i++){
            if(c[j]->level == i){
                coun[i]++;//count channel number
                sum[i] += c[j]->count;//total of peoples in a level
            }
			if(c[j]->count>top[i] && c[j]->level == i){
				top[i] = c[j]->count;//top channel's size
				topName[i] = j;//top channel's name
			}
        }
    }
    
    for(i = 0; i<5; i++){
		average[i] = sum[i]/coun[i];
        printf("%s : %d channels. Average %.1f peoples. Top channel : %s (%d peoples)\n"
                ,LNAME[i],coun[i],average[i],c[topName[i]]->name,c[topName[i]]->count);
    }
}

void pickupRandomChannels(struct st_channel* c[], int size){
	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");
	int num = 0, ran = 0;
	scanf("%d",&num);
	for(int i = 0; i<num; i++){
		ran = rand() % size;
		printf("[%d] %s (%s level, %d peoples)\n"
				, ran+1, c[ran]->name, LNAME[c[ran]->level], c[ran]->count);
	}
}

void searchChannel(struct st_channel* c[], int size){
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");
	int choose = 0;
	int from = 0, to = 0, coun = 0;
	char names[1000];
	scanf("%d",&choose);
	if(choose == 1){
		printf("> Enter the range of peoples (from ~ to) > ");
		scanf("%d %d", &from, &to);
		printf("> Result:\n");
		for(int i = 0; i<size; i++){
			if(c[i]->count >= from && c[i]->count <=to){
				coun ++;
				printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
			}
		}
		printf("> %d channels are found.\n",coun);
	}
	else if(choose == 2){
		printf("> Enter a names > ");
		scanf("%s",names);
		printf("> Result:\n");
		for(int i = 0; i<size; i++){
			if(strstr(c[i]->name, names) != NULL){
				coun ++;
				printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
			}
		}
		printf("> %d channels are found.\n",coun);
	}
}

void updateChannel(struct st_channel* c[], int size){
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");
	int number = 0;
	scanf("%d",&number);
	if(number>size){
		printf("> Wrong number.\n");
	}
	else{
		number -= 1;
		printf("> Channel Info.\n");
		printf("[%2d] %-20s %10d peoples [%s] \n",number+1, c[number]->name, c[number]->count,LNAME[c[number]->level]);
		printf("> Enter a new name of channel > ");
		scanf("%s", c[number]->name);
		printf("> Enter a new amount of peoples > ");
		scanf("%d",&c[number]->count);
		c[number]->level = findLevel(c[number]->count);
		printf("> Channel info. is modified.\n");
	}
}

int deleteChannel(struct st_channel* c[], int size){
	int no, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");
	int number = 0;
	scanf("%d",&number);
	if(number>size){
		printf("> Wrong number.\n");
	}
	else{
		number -= 1;
		printf("> Channel Info.\n");
		printf("[%2d] %-20s %10d peoples [%s] \n",number+1, c[number]->name, c[number]->count,LNAME[c[number]->level]);
		printf("> Do you want to delete the channel? (1:Yes 0:No) > ");
		scanf("%d", &yesno);
		if(yesno == 0) printf("> Canceled.\n");
		else if(yesno == 1){
			strcpy(c[number]->name,c[size-1]->name);
			c[number]->level = c[size-1]->level;
			c[number]->count = c[size-1]->count;
			size -= 1;
			printf("> Channel is deleted.\n");
		}
	}
	return size;
}


void makeReport(struct st_channel* c[], int size){
	saveChannels(c,size);
	printf("> All information of channels are saved into channels.txt.\n");
	saveReport(c,size);
	printf("> Channel Statistics are saved into report.txt.\n");
}

void saveReport(struct st_channel* c[], int size){
	FILE* file;
	file = fopen("report.txt", "w");
	fprintf(file,"Channel List\n");
	for(int i=0; i<size; i++){
		fprintf(file,"[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
	fprintf(file,"Statistics of Channels");
	int i = 0, j = 0;
    float sum[5] = {}, average[5] = {};
	int coun[5] = {}, top[5] = {}, topName[5] = {};
    for(j = 0; j<size; j++){
        for(i = 0; i<5; i++){
            if(c[j]->level == i){
                coun[i]++;//count channel number
                sum[i] += c[j]->count;//total of peoples in a level
            }
			if(c[j]->count>top[i] && c[j]->level == i){
				top[i] = c[j]->count;//top channel's size
				topName[i] = j;//top channel's name
			}
        }
    }
    
    for(i = 0; i<5; i++){
		average[i] = sum[i]/coun[i];
        fprintf(file, "%s : %d channels. Average %.1f peoples. Top channel : %s (%d peoples)\n"
                ,LNAME[i],coun[i],average[i],c[topName[i]]->name,c[topName[i]]->count);
    }
	fclose(file);	
}

void saveChannels(struct st_channel* c[], int size){
	FILE* file;
	file = fopen("channels.txt", "w");
	for(int i=0; i<size; i++){
		fprintf(file, "%s %d\n",c[i]->name, c[i]->count);
	}
	fclose(file);	
}