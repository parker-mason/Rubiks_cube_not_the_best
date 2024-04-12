#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct face face;
typedef struct cubie cubie;
typedef struct cube cube;

enum notation {
  U = 0,
  D,
  F,
  B,
  L,
  R
};

enum color {
  WHITE = 0,
  YELLOW,
  GREEN,
  BLUE,
  ORANGE,
  RED
};

enum render_mode {
  CULLED = 0,
  UNCULLED
};

struct face {
  enum color color; 
  enum render_mode render_mode;
};

struct cubie {
  int x;
  int y;
  int z;
  struct face *faces[6];
};

struct cube {
  struct cubie *cubies[3][3][3];
};

void           cube_rotate_x( struct cube *cube_p, int dir, enum notation side );
void           cube_rotate_y( struct cube *cube_p, int dir, enum notation side );
void           cube_rotate_z( struct cube *cube_p, int dir, enum notation side );
void           cube_print( struct cube *cube_p );
char           render_face( struct face *face_p );
void           cubie_roatate_x( struct cubie *cubie_p, int dir, enum notation side );
void           cubie_roatate_y( struct cubie *cubie_p, int dir, enum notation side );
void           cubie_roatate_z( struct cubie *cubie_p, int dir, enum notation side );
struct cube *  cube_init( void );
struct cubie * cubie_init( int x, int y, int z );
struct face *  face_init( enum color color, enum render_mode render_mode );


int main( void ) {
  struct cube *cube = cube_init(  );
  cube_print( cube );
  cube_rotate_x( cube, 10, R );
  return 0;
}


void           cube_rotate_x( struct cube *cube_p, int dir, enum notation side ) {
  if ( dir < -1 || dir > 1 || cube_p == NULL ) {
    return;
  }

  if ( side == R ) {
    cubie_roatate_x( cube_p->cubies[2][0][2], dir, side );
    cubie_roatate_x( cube_p->cubies[1][0][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][0][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][1][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[1][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[2][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[2][1][2], dir, side );
    
  } else if ( side == L ) {
    cubie_roatate_x( cube_p->cubies[0][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[1][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][1][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][1][0], dir, side );
  } else {
    return;
  }
}

void           cube_rotate_y( struct cube *cube_p, int dir, enum notation side ) {
  if ( dir < -1 || dir > 1 || cube_p == NULL ) {
    return;
  }

  if ( side == U ) {
    cubie_roatate_x( cube_p->cubies[0][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[1][0][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][0][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][1][2], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[1][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[2][2][2], dir, side );
    cubie_roatate_x( cube_p->cubies[2][1][2], dir, side );

  } else if ( side == D ) {
    cubie_roatate_x( cube_p->cubies[0][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[1][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][0][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][1][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[2][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir, side );
    cubie_roatate_x( cube_p->cubies[0][1][0], dir, side );
  } else {
    return;
  }
}

void           cube_rotate_z( struct cube *cube_p, int dir, enum notation side ) {
  if ( dir < -1 || dir > 1 || cube_p == NULL ) {
    return;
  }

  if ( side == F ) {
    cubie_roatate_x( cube_p->cubies[2][0][2], dir );
    cubie_roatate_x( cube_p->cubies[1][0][2], dir );
    cubie_roatate_x( cube_p->cubies[0][0][2], dir );
    cubie_roatate_x( cube_p->cubies[0][1][2], dir );
    cubie_roatate_x( cube_p->cubies[0][2][2], dir );
    cubie_roatate_x( cube_p->cubies[1][2][2], dir );
    cubie_roatate_x( cube_p->cubies[2][2][2], dir );
    cubie_roatate_x( cube_p->cubies[2][1][2], dir );

  } else if ( side == B ) {
    cubie_roatate_x( cube_p->cubies[0][0][0], dir );
    cubie_roatate_x( cube_p->cubies[1][0][0], dir );
    cubie_roatate_x( cube_p->cubies[2][0][0], dir );
    cubie_roatate_x( cube_p->cubies[2][1][0], dir );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir );
    cubie_roatate_x( cube_p->cubies[2][2][0], dir );
    cubie_roatate_x( cube_p->cubies[0][2][0], dir );
    cubie_roatate_x( cube_p->cubies[0][1][0], dir );
  } else {
    return;
  }
}

/*
         #
     #       #
 #       #       #
@    #       #    !
    @    #    !
@       @ !       !
    @         !
@       @ !       !
    @         !
        @ !

0 1 2 34 5 6
. - : =! # @
white yellow orange green blue red
*/

void           cube_print( struct cube *cube_p ) {
  printf( "\t\t %c\n", render_face( cube_p->cubies[0][0][0]->faces[0] ) );
  printf( "\t %c\t     %c\n", render_face( cube_p->cubies[0][1][0]->faces[U] ), render_face( cube_p->cubies[0][0][1]->faces[U] ) );
  printf( " %c\t     %c\t     %c\n", render_face( cube_p->cubies[2][0][0]->faces[U] ), render_face( cube_p->cubies[1][0][1]->faces[U] ), 
                                     render_face( cube_p->cubies[0][0][2]->faces[U] ) );
  printf( "%c\t %c\t     %c\t  %c\n", render_face( cube_p->cubies[2][0][0]->faces[F] ), render_face( cube_p->cubies[2][0][2]->faces[U] ), 
                                      render_face( cube_p->cubies[1][0][2]->faces[U] ), render_face( cube_p->cubies[0][0][2]->faces[R] ) );
  printf( "\t%c\t %c\t  %c\n", render_face( cube_p->cubies[2][0][1]->faces[F] ), render_face( cube_p->cubies[2][0][2]->faces[U] ), 
                               render_face( cube_p->cubies[2][1][2]->faces[R] ) );
  printf( "%c\t    %c %c\t      %c\n", render_face( cube_p->cubies[2][1][0]->faces[F] ), render_face( cube_p->cubies[2][0][2]->faces[F] ), 
                                       render_face( cube_p->cubies[2][0][2]->faces[R] ), render_face( cube_p->cubies[0][1][2]->faces[R] ) );
  printf( "\t%c\t\t  %c\n", render_face( cube_p->cubies[2][1][1]->faces[F] ), render_face( cube_p->cubies[1][1][2]->faces[R] ) );
  printf( "%c\t    %c %c\t      %c\n", render_face( cube_p->cubies[2][2][0]->faces[F] ), render_face( cube_p->cubies[2][1][2]->faces[F] ), 
                                       render_face( cube_p->cubies[2][1][2]->faces[R] ), render_face( cube_p->cubies[0][2][2]->faces[R] ) );
  printf( "\t%c\t\t  %c\n", render_face( cube_p->cubies[2][2][1]->faces[F] ), render_face( cube_p->cubies[1][2][2]->faces[R] ) );
  printf( "\t\t%c %c\n", render_face( cube_p->cubies[2][2][2]->faces[F] ), render_face( cube_p->cubies[2][2][2]->faces[R] ) );
}

char           render_face( struct face *face_p ) {
  if ( face_p->render_mode == CULLED ) {
    return ' ';
  } 
  if ( face_p->color == WHITE ) {
    return '.';
  } else if ( face_p->color == YELLOW ) {
    return '-';
  } else if ( face_p->color == GREEN ) {
    return '!';
  } else if ( face_p->color == BLUE ) {
    return '#';
  } else if ( face_p->color == ORANGE ) {
    return '=';
  } else if ( face_p->color == RED ) {
    return '@';
  } else {
    return ' ';
  }
}

void           cubie_roatate_x( struct cubie *cubie_p, int dir, enum notation side ) {
  if ( dir < -1 || dir > 1 || cubie_p == NULL ) {
    return;
  }

  struct cubie cubie_temp;
  cubie_temp.x = ( *cubie_p ).x;
  cubie_temp.y = ( *cubie_p ).y;
  cubie_temp.z = ( *cubie_p ).z;
  for ( int i = 0; i < 6; i++ ) {
    cubie_temp.faces[i] = ( *cubie_p ).faces[i];
  }

  if ( side == U || side == D ) {
    if ( dir == 1 ) {
      ( *cubie_p ).faces[F] = cubie_temp.faces[R];
      ( *cubie_p ).faces[B] = cubie_temp.faces[L];
      ( *cubie_p ).faces[L] = cubie_temp.faces[F];
      ( *cubie_p ).faces[R] = cubie_temp.faces[B];
    } else if ( dir == -1 ) {
      ( *cubie_p ).faces[F] = cubie_temp.faces[L];
      ( *cubie_p ).faces[B] = cubie_temp.faces[R];
      ( *cubie_p ).faces[L] = cubie_temp.faces[B];
      ( *cubie_p ).faces[R] = cubie_temp.faces[F];
    }
  } else if ( side == F || side == B) {
    if ( dir == 1 ) {
      ( *cubie_p ).faces[U] = cubie_temp.faces[L];
      ( *cubie_p ).faces[D] = cubie_temp.faces[R];
      ( *cubie_p ).faces[L] = cubie_temp.faces[D];
      ( *cubie_p ).faces[R] = cubie_temp.faces[U];
    } else if ( dir == -1 ) {
      ( *cubie_p ).faces[U] = cubie_temp.faces[R];
      ( *cubie_p ).faces[D] = cubie_temp.faces[L];
      ( *cubie_p ).faces[L] = cubie_temp.faces[U];
      ( *cubie_p ).faces[R] = cubie_temp.faces[D];
    }
  } else if ( side == L || side == R ) {
    if ( dir == 1 ) {
      ( *cubie_p ).faces[U] = cubie_temp.faces[F];
      ( *cubie_p ).faces[D] = cubie_temp.faces[B];
      ( *cubie_p ).faces[F] = cubie_temp.faces[D];
      ( *cubie_p ).faces[B] = cubie_temp.faces[U];
    } else if ( dir == -1 ) {
      ( *cubie_p ).faces[U] = cubie_temp.faces[B];
      ( *cubie_p ).faces[D] = cubie_temp.faces[F];
      ( *cubie_p ).faces[F] = cubie_temp.faces[U];
      ( *cubie_p ).faces[B] = cubie_temp.faces[D];
    } 
  } else {
    return;
  }
}

void           cubie_roatate_y( struct cubie *cubie_p, int dir ) {
  if ( dir < -1 || dir > 1 || cubie_p == NULL ) {
    return;
  }

  struct cubie cubie_temp;
  cubie_temp.x = ( *cubie_p ).x;
  cubie_temp.y = ( *cubie_p ).y;
  cubie_temp.z = ( *cubie_p ).z;
  for ( int i = 0; i < 6; i++ ) {
    cubie_temp.faces[i] = ( *cubie_p ).faces[i];
  }

  if ( dir == 1 ) {
    ( *cubie_p ).faces[F] = cubie_temp.faces[R];
    ( *cubie_p ).faces[B] = cubie_temp.faces[L];
    ( *cubie_p ).faces[L] = cubie_temp.faces[F];
    ( *cubie_p ).faces[R] = cubie_temp.faces[B];
  } else if ( dir == -1 ) {
    ( *cubie_p ).faces[F] = cubie_temp.faces[R];
    ( *cubie_p ).faces[B] = cubie_temp.faces[L];
    ( *cubie_p ).faces[L] = cubie_temp.faces[F];
    ( *cubie_p ).faces[R] = cubie_temp.faces[B];
  } else {
    return;
  }
}

void           cubie_roatate_z( struct cubie *cubie_p, int dir ) {
  if ( dir < -1 || dir > 1 || cubie_p == NULL ) {
    return;
  }

  struct cubie cubie_temp;
  cubie_temp.x = ( *cubie_p ).x;
  cubie_temp.y = ( *cubie_p ).y;
  cubie_temp.z = ( *cubie_p ).z;
  for ( int i = 0; i < 6; i++ ) {
    cubie_temp.faces[i] = ( *cubie_p ).faces[i];
  }

  if ( dir == 1 ) {
    ( *cubie_p ).faces[U] = cubie_temp.faces[L];
    ( *cubie_p ).faces[D] = cubie_temp.faces[R];
    ( *cubie_p ).faces[L] = cubie_temp.faces[D];
    ( *cubie_p ).faces[R] = cubie_temp.faces[U];
  } else if ( dir == -1 ) {
    ( *cubie_p ).faces[U] = cubie_temp.faces[R];
    ( *cubie_p ).faces[D] = cubie_temp.faces[L];
    ( *cubie_p ).faces[L] = cubie_temp.faces[U];
    ( *cubie_p ).faces[R] = cubie_temp.faces[D];
  } else {
    return;
  }
}

struct cube *  cube_init( void ) {
  struct cube *cube = malloc( sizeof( struct cube ) );
  for ( int i = 0, z = -1; i < 3; i++ ) {
    for ( int j = 0, y = -1; j < 3; j++ ) {
      for ( int k = 0, x = -1; k < 3; k++ ) {
        cube->cubies[i][j][k] = cubie_init( x, y, z );
        x++;
      }
      y++;
    }
    z++;
  }
  return cube;
}

struct cubie * cubie_init( int x, int y, int z ) {
  struct cubie *cubie = malloc( sizeof( struct cubie ) );
  cubie->x = x;
  cubie->y = y;
  cubie->z = z;
  for ( int i = 0; i < 6; i++ ) {
    cubie->faces[i] = face_init( i, UNCULLED );
  }
  return cubie;
}

struct face *  face_init( enum color color, enum render_mode render_mode ) {
  struct face *face = malloc( sizeof( struct face ) );
  face->color = color;
  face->render_mode = render_mode;
  return face;
}
