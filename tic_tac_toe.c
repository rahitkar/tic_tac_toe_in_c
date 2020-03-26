#include <stdio.h>

void draw_board (char box_values[]) {
  int row, column, counter=0;
  for(row=0; row <3; row++) {
    for(column=0; column <3; column++){
      printf("%c", box_values[counter]);
      printf("___|");
      counter++;
    }
    printf("\n");
  }
}

void show_state (char box_values[]) {
  int a,b,c;
  int possibilities[4][3] = {{0,4,8}, {1,4,7}, {2,4,6}, {3,4,5}};

  for(int index=0; index < 4; index++) {
    a = box_values[possibilities[index][0]];
    b = box_values[possibilities[index][1]];
    c = box_values[possibilities[index][2]];
    if(a == b && a == c){ 
    printf("%c has won\n", a);
    } 
  }
}

int main(void) {
  int box_num, move;
  char symble= 88, box_values[9], state;

  for(int index=0; index < 9; index++) {
    box_values[index] = index + 49;
  }

  draw_board(box_values);
  show_state(box_values);
for(move=1; move<10; move++){
  if (move%2==0)
  {
    symble = 79;
  } else
  {
    symble= 88;
  }

  printf("player %c's turn\n", symble);
  printf("write the box number: ");
  scanf("%d", &box_num);
  box_values[box_num -1]= symble;
  draw_board(box_values);
  show_state(box_values);
}
  
  return 0;
}