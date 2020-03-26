#include <stdio.h>

void draw_board (char box_values[]) {
  int row, column, counter=0;
  for(row=0; row <3; row++) {
    for(column=0; column <3; column++){
      if (row != 2)
      {
      printf("_%c_", box_values[counter]);
      } else
      {
      printf(" %c ", box_values[counter]);
      }
           
      if (column != 2)
      {
        printf("|");
      }

      counter++;
    }
    printf("\n");
  }
  printf("\n");
}

int get_status (char box_values[]) {
  int a,b,c;
  int possibilities[4][3] = {{0,4,8}, {1,4,7}, {2,4,6}, {3,4,5}};

  for(int index=0; index < 4; index++) {
    a = box_values[possibilities[index][0]];
    b = box_values[possibilities[index][1]];
    c = box_values[possibilities[index][2]];
    if(a == b && a == c){ 
    return 1;
    } 
  }
  return 0;
}

int main(void) {
  int box_num, move;
  char symble[2]= {88,79}, box_values[9], toggle = 0;

  for(int index=0; index < 9; index++) {
    box_values[index] = index + 48;
  }

  printf("     Let's begain\nThe tic_tac_toe journey\n\n");
  draw_board(box_values);

for(move=1; move<10; move++){
  printf("player %c's turn\n", symble[toggle]);
  printf("write the box number: ");
  scanf("%d", &box_num);
  box_values[box_num]= symble[toggle];
  draw_board(box_values);

  if(get_status(box_values)){
    printf("%c has won\n", symble[toggle]);
    return 0;
  };
  toggle = !toggle;
}
  printf("game draw\n");
  return 0;
}