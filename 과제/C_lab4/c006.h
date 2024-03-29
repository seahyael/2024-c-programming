#ifndef _CLASSES_H_
#define _CLASSES_H_

struct clothes{
    char name[100];
    char color[100];
    int type;
    //int season;
};

int loadData(struct clothes* c[]);
void callClothes(struct clothes* c[], int num);
void searchClothes(struct clothes*c[],char search[], int num);
void findClothes(struct clothes*c[], int num);
int addCloth(struct clothes*c[], struct clothes*t, int index, int num);
int createClothes(struct clothes* c[], int num);
void listClothes(struct clothes* c[], int num);
int minusClothes(struct clothes*c[],int num, int delete);
void updateClothes(struct clothes*c[], int num);
int deleteClothes(struct clothes*c[],int num);
void saveChannels(struct clothes* c[], int size);

#endif