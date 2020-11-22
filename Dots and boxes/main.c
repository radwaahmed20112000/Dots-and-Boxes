#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

                                        //Global variables for printing
int z=0,v=0;
int p1[60]={0};/*saving index from player1 for colours*/

int p2[60]={0};/*saving index from player2 for colours*/


/*____________________________________*/

typedef struct {    //player 1 data/
    char name[20];
    int score ;
}comp1;
typedef struct {     //player 2 data/
    char name[20];
    int score ;
}comp2;
/*____________________________________*/

void top10(){int i,max,exist,j,u=0,k=0,r=0;
    int score2;
    char name2[100];
    char y[11][11];
    int x[10]={0};
    FILE *fp1 =fopen("Top10names.txt","r");
    FILE *fp2 =fopen("Top10scores.txt","r");
    char name[100][100];
    int score[100]={0};
    for(i=0;i<100;i++){
        fscanf(fp2,"%d",&score[i]);}
   int w=0; for(i=0;i<100;i++){
        fscanf(fp1,"%s",name[i]);w++;}
  char empty[10]="empty";
  int c;
   int sa;
   int q=0,v;
   int dubli[100] ;
   int scores[100];
   int max1=dubli[0];
    max = score[0];

   for(i=0;i<100&&u<10;i++){int high=0;
        for(j=0;j<100&&u<10;j++){
            if(score[j]>max){max=score[j];high++;c=j;}}
                  if(high!=0) {
                    x[k]= score[c];
                    score[c]=0;
                    k++;
                    strcpy(y[u],name[c]);
                    u++;
                    sa=max;
                    max=0;}


            else if(score[j]==sa){
                for(r=0;r<u;r++){
                    if(strcmp(name[j],y[r])==0){
                            exist++;
                    }
                }
                if(exist==0){
                    x[k]= score[j-1];
                    score[j-1]=0;
                    k++;
                    strcpy(y[u],name[j-1]);

                    u++;
                    sa=max;
                    max=0;
                }
            }
        }

    fclose(fp1);
    fclose(fp2);
    for(i=0;i<10;i++){
        printf("%s ",y[i]);
        printf("%d ",x[i]);
        printf("\n");
    }


}
/*____________________________________*/


void summary(int n,int m){//printing the summary of playing/
int i,j;
char xy[n][m]; //example array/
setcolor(5);
printf("                               SUMMARY               \n");
setcolor(7);
xy[0][0]=' '; /*to remain first cell empty */
 for(j=1;j<m;j++){ //fill first row by index of matrix/
 xy[0][j]= j+'0';
 }
for(i=1;i<n;i++){ //fill first column by index of matrix/
 xy[i][0]= i+'0';
 }

 for(i=1;i<n;i+=2){ /* fill dots*/
 for(j=1;j<m;j+=2){
 xy[i][j]=248;}}

  for(i=1;i<n;i+=2){ /* fill horizontal lines with spaces*/
 for(j=2;j<m;j+=2){

  xy[i][j]=' ';}}

  for(i=2;i<n;i+=2){ /* fill vertical lines spaces*/
 for(j=1;j<m;j+=2){
 xy[i][j]=' ';if(j+1<m){
 xy[i][j+1]=' ';}}}

 xy[5][2]=45;//horizontal line for example
xy[2][1]=124;//vertical line for example

printf("to enter your own line: enter its row first then its column\n");

 for(i=0;i<n;i++){ //printing the example array
    for(j=0;j<m;j++){
        printf("%c",xy[i][j]);
    }printf("\n");
 }
 printf("for the above horizontal line enter 5 then 2\n"); //printing instructions
  printf("for the above vertical line enter 2 then 1\n");

}
/*____________________________________*/

   void lower (char x[20]){   //converting any name to lower case
	 int n=strlen(x);
	 int i;
	 for(i=0;i<n;i++){
		if(x[i]>='A'&&x[i]<='Z'){
			x[i]=x[i]+32;
		}}
		}
//____________________________________

void save(int n,int m,char y[n][m],comp1 player1,comp2 player2,FILE *fp,int remainingmoves,int t2){
    int sav,i,j;
    fprintf(fp,"%s ",player1.name);
    fprintf(fp,"%s",player2.name);
    fprintf(fp,"\n");
    fprintf(fp,"%d ",player1.score);
    fprintf(fp,"%d ",player2.score);
    fprintf(fp,"%d ",remainingmoves);
    fprintf(fp,"%d ",z);
    fprintf(fp,"%d ",v);
    fprintf(fp,"%d",t2);
        for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            fprintf(fp,"%c",y[i][j]);}}
    fprintf(fp," ");
        for(i=0;i<40;i++){
            fprintf(fp,"%d",p1[i]);
        }
    fprintf(fp," ");
        for(i=0;i<40;i++){
            fprintf(fp,"%d",p2[i]);
        }

    fclose(fp);
}
//____________________________________/

void emptyfile(int n,int m,char y[n][m],comp1 player1,comp2 player2,int remainingmoves,int t2){ //checkind and choosing empty file to save/
    int size1,size2,size3;
    FILE *fp1= fopen("g1.txt","a");
    FILE *fp2=fopen("g2.txt","a");
    FILE *fp3=fopen("g3.txt","a");
    if(NULL != fp1) {
        fseek(fp1,0,SEEK_END);
        size1 =ftell(fp1);}
    if(NULL != fp2){
        fseek(fp2,0,SEEK_END);
        size2 =ftell(fp2); }
    if (NULL != fp3){
        fseek(fp3,0,SEEK_END);
        size3 =ftell(fp3);}
        if (0 == size1){
        save(n,m,y,player1,player2,fp1,remainingmoves,t2);}


        else if (0 == size2){
        save(n,m,y,player1,player2,fp2,remainingmoves,t2);}


        else if (0 == size3){
        save(n,m,y,player1,player2,fp3,remainingmoves,t2);
        }
        else{
        fclose(fp1);
        fp1 = fopen("g1.txt","w");

        save(n,m,y,player1,player2,fp1,remainingmoves,t2);
        }
}

//____________________________________/

void load(int n,int m,int *possiblemoves,char y[n][m],char player1[20],char player2[20],int *score1,int *score2,int *t1){ /*loading a saved game*/
    char temp[20];
    int h,k;
    int f,t;
    int v= *t1;
    h= *score1;
    k=*score2;
    int find_result=0,i,j,remainingmoves;
    printf("Enter player1 name :\n" );
    scanf("%s",player1);
    lower(player1);
    printf("Enter player2 name :\n" );
    scanf("%s",player2);
    lower(player2);
    FILE *fp1= fopen("g1.txt","r+");
    FILE *fp2=fopen("g2.txt","r+");
    FILE *fp3=fopen("g3.txt","r+");
    while(fgets(temp, 520, fp1) != NULL){
    if((strstr(temp, player1)) != NULL && (strstr(temp, player2)) != NULL) { //scanning from file 1/
    find_result++;
    fscanf(fp1,"%d %d",&h,&k);
    fscanf(fp1,"%d",&remainingmoves);
    fscanf(fp1,"%d",&f);
    fscanf(fp1,"%d",&t);
    fscanf(fp1,"%d",&v);
    for(i=0;i<n;i++){ //scanning grid from the file/
    for(j=0;j<m;j++){
            fscanf(fp1,"%c", &y[i][j]);}}
    for(i=0;i<40;i++){ //scanning p1 from the file/
        fscanf(fp1,"%d",&p1[i]);}
    for(i=0;i<40;i++){ //scanning p2 from the file/
        fscanf(fp1,"%d",&p2[i]);}
		    fclose(fp1);}else{break;}}

    if(find_result == 0) { //scanning from file 2/
    while(fgets(temp, 520, fp2)!= NULL){
    if((strstr(temp, player1)) != NULL && (strstr(temp, player2)) != NULL) {
    find_result++;
    fscanf(fp2,"%d %d",&h,&k);
    fscanf(fp2,"%d",&remainingmoves);
    fscanf(fp2,"%d",&f);
    fscanf(fp2,"%d",&t);
    fscanf(fp2,"%d",&v);
    for(i=0;i<n;i++){ //scanning grid from the file/
    for(j=0;j<m;j++){
            fscanf(fp2,"%c", &y[i][j]);}}
    for(i=0;i<40;i++){ //scanning p1 from the file/
        fscanf(fp2,"%d",&p1[i]);}
    for(i=0;i<40;i++){ //scanning p2 from the file/
        fscanf(fp2,"%d",&p2[i]);}
            fclose(fp2);}else{break;}}}

if(find_result == 0) { //scanning from file 3/
    while(fgets(temp, 520, fp3)!= NULL){
    if((strstr(temp, player1)) != NULL && (strstr(temp, player2)) != NULL) {
    find_result++;
    fscanf(fp3,"%d %d",&h,&k);
    fscanf(fp3,"%d",&remainingmoves);
    fscanf(fp3,"%d",&f);
    fscanf(fp3,"%d",&t);
    fscanf(fp3,"%d",&v);
    for(i=0;i<n;i++){ //scanning grid from the file/
    for(j=0;j<m;j++){
            fscanf(fp3,"%c", &y[i][j]);}}
    for(i=0;i<40;i++){ //scanning p1 from the file/
        fscanf(fp3,"%d",&p1[i]);}
    for(i=0;i<40;i++){ //scanning p2 from the file/
        fscanf(fp3,"%d",&p2[i]);}

        fclose(fp3);}}}
    if(find_result==0){ //the file not exist, go to start menu/
        printf("FILE NOT EXIST !");
        start_menu();}
    *possiblemoves = remainingmoves;
    *score1=h;
    *score2 =k;
    *t1 =v;
    z=f;
    v=t;
}
//____________________________________/
void search(int e[60],int x,int y,int z){ //search in p1 or p2 and remove the element if it found/
int i;
for(i=0;i<60;i++){
    if(e[i]==x||e[i]==y||e[i]==z){e[i]=0;}
}
}
//____________________________________/

void equality(int s[60],int p[60]){ //put an one d array to another one/
int i;
for(i=0;i<60;i++){ s[i]=p[i];}
}
//____________________________________/

void box_color(int p,int u1,int u2,int u3,int u4,int a,int b){ //putting the indexes of an complete box on the array of the player who complete the box/
int s[60];
int t[60];
int w,q;
         if(p==2){ while(z<60){ //saving player 1 index/
                    p1[z]=a*10+b;
                      z++;
                       break;}}


           if(p==1){ while(v<60){  //saving player 2 index/
                    p2[v]=a*10+b;
                     v++;
                     break;}}

if(p==2){ equality(s,p1);
            w=z;
           equality(t,p2);
            q=v;}
else { equality(s,p2);
       w=v;
       equality(t,p1);
       q=z; }
       if(u1==1){ //complete a a one box case/
        s[w]=(a-1)*10+(b-1);
        s[w+1]=(a+1)*10+(b-1);
        s[w+2]=(a)*10+(b-2);
        search(t,s[w],s[w+1],s[w+2]);
        w+=3;
       }
       if(u2==1){ //complete a a one box case/
        s[w]=(a-1)*10+(b+1);
        s[w+1]=(a+1)*10+(b+1);
        s[w+2]=(a)*10+(b+2);
        search(t,s[w],s[w+1],s[w+2]);
        w+=3;
       }
       if(u3==1){ //complete a a one box case/
        s[w]=(a-1)*10+(b-1);
        s[w+1]=(a-1)*10+(b+1);
        s[w+2]=(a-2)*10+(b);
        search(t,s[w],s[w+1],s[w+2]);
        w+=3;
       }
       if(u4==1){ //complete a a one box case/
        s[w]=(a+1)*10+(b-1);
        s[w+1]=(a+1)*10+(b+1);
        s[w+2]=(a+2)*10+(b);
        search(t,s[w],s[w+1],s[w+2]);
        w+=3;
       }

        if(p==2){ equality(p1,s);
            z=w;
           equality(p2,t);
            v=q;}
else { equality(p2,s);
       v=w;
       equality(p1,t);
       z=q; }



}

//_____________________________________/
void setcolor(int ForgC){ //setting color function/
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(
    STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO
    csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);}

        return;}

//____________________________________/

 void print(int n,int m,char y[n][m],int a,int b,int p){ //printing with colours/
int i,j;

int w=0,q=0,t=0,exists=0;


     for(i=0;i<m;i++){ //printing the first row with white color/
    setcolor(7);
    printf("%c",y[0][i]);
    setcolor(7);
 }
printf("\n");

   for(i=1;i<n;i++){ /* print the array*/
 for(j=0;j<m;j++){
        exists =0;
        t=i*10+j;
         if(j==0){   /*printing the first coloum */
                    setcolor(7);
                    printf("%c",y[i][0]);
                    setcolor(7);
                }
 else{ for(w=0;w<60;w++){if(t==p1[w]){ /*checking if the line played by player1 or not */
                    exists ++;
                setcolor(2);
                     printf("%c",y[i][j]);
                setcolor(7);
                break;}}

                 for(q=0;q<60;q++){if((t)==p2[q]){  /*checking if the line played by player2 or not */
                   exists ++;
                   setcolor(4);
                    printf("%c",y[i][j]);
                    setcolor(7);
                    break;}}

 if (exists==0){printf("%c",y[i][j]);
 }

 }} printf("\n");} /*printing  colorful array */
 }
//_____________________________________/


void undo(int d,int savingarray[d],int n,int m,char y[n][m],char x[n][m],int *a,int *b,int u1,int u2,int u3,int u4,int p){
    int i,j;
    char f;
    int h,k;
    y[savingarray[d-2]][savingarray[d-1]]=' ';
    box_color( p, u1, u2, u3, u4, a, b);
    print( n, m, y, a, b, p);

        printf("Enter 1,To redo\nEnter 2, to scan again "); //scanning input to redo or scan again/
        scanf("%c",&f);

        while ((f != '1' && f != '2')||(f>= 'A' && f<= 'Z')||(f>= 'a'&& f<= 'z')){ //checking that it is suitable input/
            printf("Enter the right number!");
            scanf("%c",&f);}
        if(f =='1'){ //if 1 redo/
            redo(d, savingarray,n,m,y,x);}
        else{printf("Enter row .... column"); //if 2 scan/
                scanf("%d %d",&h ,&k);

        while((x[h][k]==' ')||(y[h][k]!=' ')||(h>=n||h<=0||k>=m||k<=0)){ //checking empty possible places/
            printf("scan again:\n");
            scanf("%d %d",&h ,&k);
       }
        y[h][k]=x[h][k];
        *a=h;
        *b=k;}

}

//_____________________________________/

void redo(int d,int savingarray[d],int n,int m,char y[n][m],char x[n][m]){
    y[savingarray[d-2]][savingarray[d-1]]=x[savingarray[d-2]][savingarray[d-1]]; //return the deleted line/

}

//_____________________________________/

void play_withcomputer(int n,int m,int possiblemoves,char opt1){ //function to play with computer/
int score1=0;
int score2=0;
int a,b,c=0;
comp1 player1;
comp2 player2;
char optsave;
int u=1;int r=1;int t1;
int p=1;/* player p*/
int i,j;
int u1,u2,u3,u4;
 char x[n][m];
x[0][0]=' '; /*to remain first cell empty */
 for(j=1;j<m;j++){ //fill first row by index of matrix/
 x[0][j]= j+'0';
 }
for(i=1;i<n;i++){ //fill first column by index of matrix/
 x[i][0]= i+'0';
 }

 for(i=1;i<n;i+=2){ /* fill dots*/
 for(j=1;j<m;j+=2){
 x[i][j]=248;}}



  for(i=1;i<n;i+=2){ /* fill horizontal lines*/
 for(j=2;j<m;j+=2){

  x[i][j]=45;}}

  for(i=2;i<n;i+=2){ /* fill vertical lines*/
 for(j=1;j<m;j+=2){
 x[i][j]=124;if(j+1<m){
 x[i][j+1]=' ';}}}


char y[n][m]; //empty grid/

y[0][0]=' '; /*to remain first cell empty */
 for(j=1;j<m;j++){ //fill first row by index of matrix/
 y[0][j]= j+'0';
 }
for(i=1;i<n;i++){ //fill first column by index of matrix/
 y[i][0]= i+'0';
 }

 for(i=1;i<n;i+=2){ /* fill dots*/
 for(j=1;j<m;j+=2){
 y[i][j]=248;}}



  for(i=1;i<n;i+=2){ /* fill horizontal lines*/
 for(j=2;j<m;j+=2){

  y[i][j]=' ';}}

  for(i=2;i<n;i+=2){ /* fill vertical lines*/
 for(j=1;j<m;j+=2){
 y[i][j]=' ';if(j+1<m){
 y[i][j+1]=' ';}}}
if(opt1 =='3'){
    load(n,m,&possiblemoves,y,player1.name,player2.name,&score1,&score2,&t1);
}else{
summary(n,m); //printing the summary of playing/
printf("enter the first player name:\n"); //scaning names
scanf("%s",&player1.name);
lower(player1.name);
char r[20]="computer";
strcpy(player2.name,r);
 for(i=0;i<n;i++){ /* print the array*/
 for(j=0;j<m;j++){
 printf("%c",y[i][j]);}
 printf("\n");}
 setcolor(2);
 printf("%s's turn :",player1.name);//default start by player1/
 setcolor(7);
 t1 = time(NULL); //start time
 }
int savingindex[80]={0};
int d=0;
int min,sec,diff,t2;
while(c<possiblemoves){

if(p==1){
 printf("the row...col:\n");//scan index/
 scanf("%d %d",&a ,&b);


    while((x[a][b]==' ')||(y[a][b]!=' ')||(a>=n||a<=0||b>=m||b<=0)){ //checking empty possible places/
            printf("scan again:\n");
           scanf("%d %d",&a ,&b);
    }
    y[a][b]=x[a][b];
    c++;
    savingindex[d]=a; //fill the 1D array with index to use it in undo,redo/
    savingindex[d+1]=b;
    d=d+2;

         char e;
         int f;
    printf("remaining moves=%d\n",possiblemoves-c);
    printf("Enter 1 :For  Undo\n");
    printf("Enter 2 :To Continue\n");
    scanf(" %c",&e);
    while ((e != '1' && e != '2')||(e>= 'A' && e<= 'Z')||(e>= 'a'&& e<= 'z')){
        printf("Enter the right number!\n");
        scanf(" %c",&e);}
    if(e =='1'){
        undo(d, savingindex,n,m,y,x,&a,&b,0,0,0,0,p);}

u1=0,u2=0,u3=0,u4=0;
//checking completing boxes by one of the players/
if((y[a][b]==124)&&(b!=1)){ //vertical and not the first column/ /completing square left the line/
    if(y[a-1][b-1]!=' '&&y[a+1][b-1]!=' '&&y[a][b-2]!=' '){
       u1=1;
    }
}

if((y[a][b]==124)&&(b!=n-1)){ //vertical and not the last column/ /completing square right the line/
    if(y[a-1][b+1]!=' '&&y[a+1][b+1]!=' '&&y[a][b+2]!=' '){
        u2=1;
    }
}

if((y[a][b]=='-')&&(a!=1)){       //horizontal and not the first row/ /completing square above the line/
    if(y[a-1][b-1]!=' '&&y[a-1][b+1]!=' '&&y[a-2][b]!=' '){
        u3=1;
    }
}

if((y[a][b]=='-')&&(a!= n-1)){      //horizontal and not the last row/ /completing square under the line/
        if(y[a+1][b-1]!=' '&&y[a+1][b+1]!=' '&&y[a+2][b]!=' '){
            u4=1;
        }
}
box_color( p, u1, u2, u3, u4, a, b);

print( n, m, y, a, b, p);
printf("Enter 1,to Save the current game\nEnter 2,To continue\n"); //give option to save or not********
scanf(" %c",&optsave);
while((optsave !='1' && optsave != '2')||(optsave>= 'A' && optsave<= 'Z')||(optsave>= 'a'&& optsave<= 'z')){
    printf("Enter the Right number!\n");
    scanf(" %c",&optsave);
}
switch(optsave){  //save scores and game in file***********
case '1':
player1.score = score1;
player2.score = score2;

emptyfile(n,m,y,player1,player2,possiblemoves-c,t2);
exit(-1);              //if saved exit
}}


    else{

    while((x[u][r]==' ')||(y[u][r]!=' ')||(u>=n||u<=0||r>=m||r<=0)){ //checking empty possible places/

      if(r<m){r++;}       /* to make the computer play at the first empty element*/
       else if(u<n){u++;
       r=1;}
    }
    y[u][r]=x[u][r];
    a=u;
    b=r;
    if(r<m){r++;}
       else if(u<n){u++;
       r=1;}

    c++;
u1=0,u2=0,u3=0,u4=0;
//checking completing boxes by one of the players/
if((y[a][b]==124)&&(b!=1)){ //vertical and not the first column/ /completing square left the line/
    if(y[a-1][b-1]!=' '&&y[a+1][b-1]!=' '&&y[a][b-2]!=' '){
       u1=1;
    }
}

if((y[a][b]==124)&&(b!=n-1)){ //vertical and not the last column/ /completing square right the line/
    if(y[a-1][b+1]!=' '&&y[a+1][b+1]!=' '&&y[a][b+2]!=' '){
        u2=1;
    }
}

if((y[a][b]=='-')&&(a!=1)){       //horizontal and not the first row/ /completing square above the line/
    if(y[a-1][b-1]!=' '&&y[a-1][b+1]!=' '&&y[a-2][b]!=' '){
        u3=1;
    }
}

if((y[a][b]=='-')&&(a!= n-1)){      //horizontal and not the last row/ /completing square under the line/
        if(y[a+1][b-1]!=' '&&y[a+1][b+1]!=' '&&y[a+2][b]!=' '){
            u4=1;
        }
}
box_color( p, u1, u2, u3, u4, a, b);

print( n, m, y, a, b, p);}


    if(p==1){p=2;}//reverse turns/
    else{p=1;}



switch(p){     //increasing the score/
case 1:
    if(u1==1 || u2==1 || u3==1||u4==1){score2++; p=2; }
    if((u1==1&&u2==1)||(u3==1&&u4==1)){score2++; p=2;}
    break;
case 2:
     if(u1==1 || u2==1 || u3==1||u4==1){score1++; p=1;}
     if((u1==1&&u2==1)||(u3==1&&u4==1)){score1++;p=1;}
     break;
}
if(c<possiblemoves){if(p==1){ //printing the turn/
setcolor(2);
printf("%s's  turn\n",player1.name);
setcolor(7);
}
else {setcolor(4); printf("computer turn\n");setcolor(7);}}

t2 = time(NULL); //time/
diff = t2 -t1;
min= diff/60;
sec = diff - min*60;
setcolor(7);
printf("Time : Minutes = %d , Seconds = %d\n",min,sec);
setcolor(4);
printf("score %s = %d\n",player1.name,score1);
setcolor(2);
printf("score computer = %d\n",score2);
setcolor(7);
}
FILE *fp1 =fopen("Top10names.txt","a");
FILE *fp2 =fopen("Top10scores.txt","a");
fprintf(fp1,"% s ",player1.name);
fprintf(fp2,"%d ",score1);
fclose(fp1);
fclose(fp2);

if(score1>score2){setcolor(2); printf("the winner is :%s\n",player1.name); setcolor(7);}
     else if(score1<score2){setcolor(4); printf("the winner is :computer\n"); setcolor(7);}
    else {setcolor(7);printf("Tied\n");}
}
 //_____________________________________/

void play_game(int n,int m,int possiblemoves,char opt1){ //function to play a new game/
int score1=0;
int score2=0;
comp1 player1;
comp2 player2;
char optsave;
int a,b,c=0;
int t1;
int p=1;/* player p*/
int i,j;
 char x[n][m];
x[0][0]=' '; /*to remain first cell empty */
 for(j=1;j<m;j++){ //fill first row by index of matrix/
 x[0][j]= j+'0';
 }
for(i=1;i<n;i++){ //fill first column by index of matrix/
 x[i][0]= i+'0';
 }

 for(i=1;i<n;i+=2){ /* fill dots*/
 for(j=1;j<m;j+=2){
 x[i][j]=248;}}



  for(i=1;i<n;i+=2){ /* fill horizontal lines*/
 for(j=2;j<m;j+=2){

  x[i][j]=45;}}

  for(i=2;i<n;i+=2){ /* fill vertical lines*/
 for(j=1;j<m;j+=2){
 x[i][j]=124;if(j+1<m){
 x[i][j+1]=' ';}}}


char y[n][m]; //empty grid/

y[0][0]=' '; /*to remain first cell empty */
 for(j=1;j<m;j++){ //fill first row by index of matrix/
 y[0][j]= j+'0';
 }
for(i=1;i<n;i++){ //fill first column by index of matrix/
 y[i][0]= i+'0';
 }

 for(i=1;i<n;i+=2){ /* fill dots*/
 for(j=1;j<m;j+=2){
 y[i][j]=248;}}



  for(i=1;i<n;i+=2){ /* fill horizontal lines*/
 for(j=2;j<m;j+=2){

  y[i][j]=' ';}}

  for(i=2;i<n;i+=2){ /* fill vertical lines*/
 for(j=1;j<m;j+=2){
 y[i][j]=' ';if(j+1<m){
 y[i][j+1]=' ';}}}

if(opt1 =='3'){
    load(n,m,&possiblemoves,y,player1.name,player2.name,&score1,&score2,&t1);
}else{
summary(n,m);
printf("enter the first player name:\n"); //scaning names
scanf("%s",&player1.name);
lower(player1.name);
printf("enter the second player name:\n");
scanf("%s",&player2.name);
lower(player2.name);
 for(i=0;i<n;i++){ /* print the array*/
 for(j=0;j<m;j++){
 printf("%c",y[i][j]);}
 printf("\n");}
 setcolor(2);
 printf("%s's turn :",player1.name);//default start by player1/
 setcolor(7);
 t1 = time(NULL); //start time
 }

int savingindex[80]={0};

int d=0;
int min,sec,diff,t2;
while(c<possiblemoves){


 printf("the row...col:\n");//scan index/
 scanf("%d %d",&a ,&b);


    while((x[a][b]==' ')||(y[a][b]!=' ')||(a>=n||a<=0||b>=m||b<=0)){ //checking empty possible places/
            printf("scan again:\n");
           scanf("%d %d",&a ,&b);
    }
    y[a][b]=x[a][b];
    c++;
    if(p==1){p=2;}//reverse turns/
    else{p=1;}

    savingindex[d]=a; //fill the 1D array with index to use it in undo,redo/
    savingindex[d+1]=b;
    d=d+2;


    char e;
    printf("remaining moves=%d\n",possiblemoves-c);
    printf("Enter 1 :For  Undo\n");
    printf("Enter 2 :To Continue\n");
    scanf(" %c",&e);
    while ((e != '1' && e != '2')||(e>= 'A' && e<= 'Z')||(e>= 'a'&& e<= 'z')){
        printf("Enter the right number!\n");
        scanf(" %c",&e);}
    if(e =='1'){
        undo(d, savingindex,n,m,y,x,&a,&b,0,0,0,0,p);

       }



int u1=0,u2=0,u3=0,u4=0;
//checking completing boxes by one of the players/
if((y[a][b]==124)&&(b!=1)){ //vertical and not the first column/ /completing square left the line/
    if(y[a-1][b-1]!=' '&&y[a+1][b-1]!=' '&&y[a][b-2]!=' '){
       u1=1;
    }
}

if((y[a][b]==124)&&(b!=n-1)){ //vertical and not the last column/ /completing square right the line/
    if(y[a-1][b+1]!=' '&&y[a+1][b+1]!=' '&&y[a][b+2]!=' '){
        u2=1;
    }
}

if((y[a][b]=='-')&&(a!=1)){       //horizontal and not the first row/ /completing square above the line/
    if(y[a-1][b-1]!=' '&&y[a-1][b+1]!=' '&&y[a-2][b]!=' '){
        u3=1;
    }
}

if((y[a][b]=='-')&&(a!= n-1)){      //horizontal and not the last row/ /completing square under the line/
        if(y[a+1][b-1]!=' '&&y[a+1][b+1]!=' '&&y[a+2][b]!=' '){
            u4=1;
        }
}
box_color( p, u1, u2, u3, u4, a, b);

print( n, m, y, a, b, p);

switch(p){
case 1:
    if(u1==1 || u2==1 || u3==1||u4==1){score2++; p=2; }
    if((u1==1&&u2==1)||(u3==1&&u4==1)){score2++; p=2;}
    break;
case 2:
     if(u1==1 || u2==1 || u3==1||u4==1){score1++; p=1;}
     if((u1==1&&u2==1)||(u3==1&&u4==1)){score1++;p=1;}
     break;
}


if(c<possiblemoves){
if(p==1){
        setcolor(2);
printf("%s's turn\n",player1.name);
setcolor(7);}
else{
        setcolor(4);
printf("%s's turn\n",player2.name);
setcolor(7);}}
t2 = time(NULL);
diff = t2 -t1;
min= diff/60;
sec = diff - min*60;
setcolor(7);
printf("Time : Minutes = %d , Seconds = %d\n",min,sec); //print time in minutes and seconds
setcolor(2);
printf("score %s = %d\n",player1.name,score1);
setcolor(4);
printf("score %s = %d\n",player2.name,score2);
setcolor(7);
printf("Enter 1,to Save the current game\nEnter 2,To continue\n"); //give option to save or not********
scanf(" %c",&optsave);
while((optsave !='1' && optsave != '2')||(optsave>= 'A' && optsave<= 'Z')||(optsave>= 'a'&& optsave<= 'z')){
    printf("Enter the Right number!\n");
    scanf(" %c",&optsave);
}
switch(optsave){  //save scores and game in file***********
case '1':
player1.score = score1;
player2.score = score2;
emptyfile(n,m,y,player1,player2,possiblemoves-c,t2);
exit(-1);              //if saved exit
}

}
FILE *fp1 =fopen("Top10names.txt","a");
FILE *fp2 =fopen("Top10scores.txt","a");
fprintf(fp1,"% s ",player1.name);
fprintf(fp2,"%d ",score1);
fprintf(fp1,"% s ",player2.name);
fprintf(fp2,"%d ",score2);
fclose(fp1);
fclose(fp2);


if(score1>score2){setcolor(2); printf("the winner is :%s\n",player1.name); setcolor(7);}
     else if(score1<score2){setcolor(4); printf("the winner is :%s\n",player2.name); setcolor(7);}
    else {setcolor(7); printf("Tied\n");}
}
//_____________________________________/

void start_menu(){ //start menu/
	int n; int m; int possiblemoves;
	char opt1,opt2;
	char opt4;
	setcolor(2);
printf("                        DOTS and BOXES\n");
setcolor(7);
printf("Enter 1: To Start a Game  \n");
printf("Enter 2: TOP 10  \n");
printf("Enter 3: To Load a Game  \n");
printf("ENTRE 4: Quit a Game  \n");

scanf(" %c",&opt1);

while((opt1 != '1' && opt1 != '2' && opt1 != '3' && opt1 != '4')||(opt1>= 'A' && opt1<= 'Z')||(opt1>= 'a'&& opt1<= 'z')){    //EROR Entering invalid number/
printf("Enter the Right number!\n");
 scanf(" %c",&opt1);}
 switch(opt1){
 case '1' :

    printf("Enter 1, beginner\nEnter 2,for advanced\n");
    scanf(" %c",&opt2);
    while((opt2!= '1' && opt2 != '2')||(opt2>= 'A' && opt2<= 'Z')||(opt2>= 'a'&& opt2<= 'z')){   //EROR Entering invalid number/
    printf("Enter the right number!\n");
	scanf(" %c",&opt2);}
	switch(opt2){
		case '1':
			n=6;
			m=6;
			possiblemoves=12;
			break;
        case '2':
	    	n=10;
			m=10;
			possiblemoves=40;
			break;
	}

	printf("Enter 1,for two players\nEnter 2,for playing with computer\n");
    scanf(" %c",&opt4);
    while((opt4!= '1' && opt4 != '2')||(opt4>= 'A' && opt4<= 'Z')||(opt4>= 'a'&& opt4<= 'z')){   //EROR Entering invalid number/
            printf("Enter the right number!\n");
            scanf(" %c",&opt4);}
	switch(opt4){
		case '1':
			 play_game(n,m,possiblemoves,opt1);
			break;
        case '2':
	    	play_withcomputer(n,m,possiblemoves,opt1);
			break;
	}


 char opt3='0';
 printf("Enter 1, To Go Back to the Menu  \n ");
 printf("ENTRE 2, Quit the Game  \n ");
  scanf(" %c",&opt3);
int i;
for(i=0;i<40;i++){p1[i]=0;
p2[i]= 0;}
z=0;
v=0;
 while((opt3 != '1' && opt3 != '2')||(opt3>= 'A' && opt3<= 'Z')||(opt3>= 'a'&& opt3<= 'z') ){ //EROR Entering invalid number/
printf("Enter the Right number!\n");
 scanf(" %c",&opt3);}

 switch (opt3){ //finishing a game/
 case '1'://start menu/
     start_menu();
     break;
     case '2':/*exit */
   exit(-1);
 }

case '2'://top 10/
    top10();
    break;
case '3':
printf("Enter 1,for beginner\nEnter 2,for advanced\n");
    scanf(" %c",&opt2);
    while((opt2!= '1' && opt2 != '2')||(opt2>= 'A' && opt2<= 'Z')||(opt2>= 'a'&& opt2<= 'z')){   //EROR Entering invalid number/
    printf("Enter the right number!\n");
	scanf(" %c",&opt2);}
	switch(opt2){
		case '1':
			n=6;
			m=6;
			possiblemoves=12;
			break;
        case '2':
	    	n=10;
			m=10;
			possiblemoves=40;
			break;
	}
	printf("Enter1, two players\nEnter 2,for playing with computer\n");
    scanf(" %c",&opt4);
    while((opt4!= '1' && opt4 != '2')||(opt4>= 'A' && opt4<= 'Z')||(opt4>= 'a'&& opt4<= 'z')){   //EROR Entering invalid number/
    printf("Enter the right number!\n");
	scanf(" %c",&opt4);}
switch(opt4){
    case '1':
    play_game(n,m,possiblemoves,opt1); //load/
    break;
    case '2':
        play_withcomputer(n,m,possiblemoves,opt1);}
case '4'://exit/
    exit(-1);

}}
//_____________________________________/
int main(){
start_menu();
return 0;
}
